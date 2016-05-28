plot(Velradseg,TNm,'o','linewidth',2)
grid on
hold all
for i=1:400
I(i)=i/100;
T(i)=0.3625*I(i)+0.5781;
end

plot(I,T,'linewidth',2);