figure(1)
hold all
plot(t,deg2rad(-(Posicion)/2730*240+187),'b','linewidth',2)
hold all
plot(PosicionSimulacion.time,(PosicionSimulacion.signals.values),'r','linewidth',2)
grid on
xlabel('Tiempo(s)');
ylabel('Posicion(rad)');

figure(2)

for i=1:length(t)
    
    k(i)=deg2rad(-(Posicion(i))/2730*240+187)-buscar(PosicionSimulacion.time,PosicionSimulacion.signals.values,t(i));

end
hold all
plot(t(1:91),(k(1:91)),'b','linewidth',2);
grid on
xlabel('Tiempo(s)');
ylabel('error(rad)');