function Th2=tercios(Th)
Th2=Th(1);
for i = 2:length(Th)-1
    Th2=[Th2,(2*Th(i-1)+Th(i))/3,Th(i)];
end

i=length(Th);
Th2=[Th2,(2*Th(i-1)+Th(i))/3,(Th(i-1)+2*Th(i))/3,Th(i)];
end