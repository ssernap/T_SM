%clear all;

loadlibrary('dynamixel','dynamixel.h');
libfunctions('dynamixel');

%%reviza la conexion
BAUDNUM = 19;
COM=3; 
%%carga los ID y el puerto
ID1=2;
carga=0;
%%Reg Derivativo
RegP=26;
%%RegI
RegI=27;
%%RegD
RegD=28;
RegPos=30;
%definicion de la constantes 
CP=0;
CI=0;
CD=32;

  Prueba_Coneccion = calllib('dynamixel','dxl_initialize',COM,BAUDNUM);
  
  if (Prueba_Coneccion==0)
  fprintf('NO CONECTADO\n');
  else
  fprintf('CONECTADO\n');
  end

 calllib('dynamixel','dxl_write_byte',ID1,RegP,CP);
 calllib('dynamixel','dxl_write_byte',ID1,RegI,CI);
 calllib('dynamixel','dxl_write_word',ID1,RegD,CD);
 
 
  calllib('dynamixel','dxl_write_word',ID1,RegPos,2730);%2730
  pause(2)
 
  tic;
  t(1)=toc;
  Posicion(1)=calllib('dynamixel','dxl_read_word',ID1,36);
  t(2)=toc;
  Posicion(2)=calllib('dynamixel','dxl_read_word',ID1,36);
  calllib('dynamixel','dxl_write_word',ID1,RegPos,1095);%1095
 
  
  for i=2:300;
    t(i)=toc;
    Posicion(i)=calllib('dynamixel','dxl_read_word',ID1,36);    
  end
  
  
  plot(t,Posicion)
  

 calllib('dynamixel','dxl_write_byte',ID1,RegP,0);
 calllib('dynamixel','dxl_write_byte',ID1,RegI,0);
 calllib('dynamixel','dxl_write_word',ID1,RegD,32);
  
  
    calllib('dynamixel','dxl_write_word',ID1,RegPos,2730);%2730
  pause(2)
 