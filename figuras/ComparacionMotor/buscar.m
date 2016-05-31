function Wo = buscar(XX,YY,target)
    i=1;
    largo=length(XX)-1;
%     busca punto de encuentro
    while(i<largo && (XX(i)-target)*(XX(i+1)-target)>0 )
    i=i+1;   
    end
%     reviza las esquinas
    if ((XX(i)-target)==0 )
    Wo=YY(i);
    return
    end
    if ((XX(i+1)-target)==0 )
    Wo=YY(i+1);
    return
    end
%     interpolacion

    Wo=YY(i)+(target-XX(i))*(YY(i+1)-YY(i))/(XX(i+1)-XX(i));
  

end