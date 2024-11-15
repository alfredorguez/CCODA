clear; close all;

data = readtable('../stepsModeloDinamico/v2/perfiles_v2_500_1000_P6_3.csv',...
    'VariableNamingRule','preserve');

data = table2array(data);
data = data(2:end,:);

i = 0; % Perfiles efectivos
perfiles = [];

for kk = 0:max(data(:,end))
    idx = find(data(:,end)==kk);

    if length(idx) < 500
        continue
    end

    perfil = [data(idx,2), i.*ones(length(idx),1),data(idx,3)];
    perfiles = [perfiles ; perfil];
    i = i + 1;
end

tm = 5e-3;
t = 0:tm:2.5;
u = 500.*(t<=1.5)+1000.*(t>1.5);

% Crear la figura
figure;

% Gráfica principal (superior)
ax1 = subplot(2, 1, [1 2]); % Usamos subplot para una configuración inicial
[xx,yy] = meshgrid(linspace(-11,3.5,1000),...
        linspace(0,max(perfiles(:,2)),1000)); 
vq = griddata(perfiles(:,1)',perfiles(:,2)',perfiles(:,3)',xx,yy);
imagesc(vq'); 
colormap jet;
axis([0,1000,0,1000,0,10]);
set(ax1,'xtick',[],'ytick',[]);

% Ajustar la posición de la gráfica principal
pos1 = get(ax1, 'Position');
set(ax1, 'Position', [pos1(1), pos1(2) + pos1(4) * 0.35, pos1(3), pos1(4) * 0.65]);

% Gráfica secundaria (inferior)
ax2 = axes('Position', [pos1(1), pos1(2) - pos1(4) * 0.005, pos1(3), pos1(4) * 0.25]);
plot(ax2, t, u, LineWidth=2);
grid(ax2,"on");
ylim([400 1200]);
yticks(400:200:1200);

% Alinear el colorbar con la gráfica principal
c = colorbar(ax1, 'Position', [pos1(1) + pos1(3) + 0.02, pos1(2), 0.03, pos1(4)]);

% Ajustar etiquetas y títulos si es necesario
xlabel(ax2, 'Tiempo [s]');
ylabel(ax2, 'Velocidad [mm/s]');
c.Label.String = 'Altura [mm]';
c.Label.FontSize = 12;

set(gca,"FontSize",12);

saveas(gcf, 'stepHilo3D.eps', 'epsc');