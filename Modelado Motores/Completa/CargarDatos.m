%%cargar datos

clear all
load('Cbarra_PID_40_5_5_2toc.mat')
Pos0_40_5_5=Posicion;
t0_40_5_5=t;
load('Cbarra_PID_0_10_10_2toc.mat')
Pos0_0_10_10=Posicion;
t0_0_10_10=t;
load('Cbarra420_PID_0_0_32_2toc.mat')
Pos420_0_0_32=Posicion;
t420_0_0_32=t;
load('Cbarra420_PID_0_10_10_2toc.mat')
Pos420_0_10_10=Posicion;
t420_0_10_10=t;


 Pos0_40_5_5=deg2rad(-(Pos0_40_5_5)/2730*240+187);
Pos420_0_0_32=deg2rad(-(Pos420_0_0_32)/2730*240+187);
Pos420_0_10_10=deg2rad(-(Pos420_0_10_10)/2730*240+187);