clear; close all;

data1 = readtable('../datos/muestrasExp/perfiles_v1_700_300_P6_3.csv',...
    'VariableNamingRule','preserve');

data2 = readtable('../datos/muestrasExp/perfiles_v3_600_600_P6_R20_0.csv',...
    'VariableNamingRule','preserve');

data3 = readtable('../datos/muestrasExp/perfiles_v2_900_500_P5_2.csv',...
    'VariableNamingRule','preserve');

data1 = table2array(data1);
data1 = data1(2:end,:);

i = 0; % Perfiles efectivos
perfiles1 = [];

for kk = 0:max(data1(:,end))
    idx = find(data1(:,end)==kk);

    if length(idx) < 500
        continue
    end

    perfil = [data1(idx,2), i.*ones(length(idx),1),data1(idx,3)];
    perfiles1 = [perfiles1 ; perfil];
    i = i + 1;
end

data2 = table2array(data2);
data2 = data2(2:end,:);

i = 0; % Perfiles efectivos
perfiles2 = [];

for kk = 0:max(data2(:,end))
    idx = find(data2(:,end)==kk);

    if length(idx) < 500
        continue
    end

    perfil = [data2(idx,2), i.*ones(length(idx),1),data2(idx,3)];
    perfiles2 = [perfiles2 ; perfil];
    i = i + 1;
end

data3 = table2array(data3);
data3 = data3(2:end,:);

i = 0; % Perfiles efectivos
perfiles3 = [];

for kk = 0:max(data3(:,end))
    idx = find(data3(:,end)==kk);

    if length(idx) < 500
        continue
    end

    perfil = [data3(idx,2), i.*ones(length(idx),1),data3(idx,3)];
    perfiles3 = [perfiles3 ; perfil];
    i = i + 1;
end

figure(1); clf; 

ax1 = subplot(311);
[xx,yy] = meshgrid(linspace(-8,8,1000),...
        linspace(0,max(perfiles1(:,2)),1000)); 
vq = griddata(perfiles1(:,1)',perfiles1(:,2)',perfiles1(:,3)',xx,yy);
imagesc(vq'); 
colormap jet;
axis([0,1000,0,1000,0,10]);
set(gca,'xtick',[],'ytick',[]);

ax2 = subplot(312);
[xx,yy] = meshgrid(linspace(-8,8,1000),...
        linspace(0,max(perfiles2(:,2)),1000)); 
vq = griddata(perfiles2(:,1)',perfiles2(:,2)',perfiles2(:,3)',xx,yy);
imagesc(vq'); 
colormap jet;
axis([0,1000,0,1000,0,10]);
set(gca,'xtick',[],'ytick',[]);

ax3 = subplot(313);
[xx,yy] = meshgrid(linspace(-12,4,1000),...
        linspace(20,max(perfiles3(:,2)),1000)); 
vq = griddata(perfiles3(:,1)',perfiles3(:,2)',perfiles3(:,3)',xx,yy);
imagesc(vq'); 
colormap jet;
axis([0,1000,0,1000,0,10]);
set(gca,'xtick',[],'ytick',[]);

% Ajustar las posiciones de los subplots para hacer espacio para el colorbar
pos1 = get(ax1, 'Position');
pos2 = get(ax2, 'Position');
pos3 = get(ax3, 'Position');
set(ax1, 'Position', [pos1(1), pos1(2), pos1(3) * 0.9, pos1(4)]);
set(ax2, 'Position', [pos2(1), pos2(2), pos2(3) * 0.9, pos2(4)]);
set(ax3, 'Position', [pos3(1), pos3(2), pos3(3) * 0.9, pos3(4)]);

% Añadir un colorbar común a todos los subplots
c = colorbar;
c.Position = [pos1(1) + pos1(3) - 0.06, pos3(2), 0.03, pos1(2) + pos1(4) - pos3(2)];

% Añadir un label al colorbar si es necesario
c.Label.String = 'Altura [mm]';
c.Label.FontSize = 16;

set(gca,'FontSize',16);