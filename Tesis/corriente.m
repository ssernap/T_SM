clear all;

loadlibrary('dynamixel','dynamixel.h');
libfunctions('dynamixel');

%%reviza la conexion
BAUDNUM = 19;
COM=7; 
%%carga los ID y el puerto
ID1=1;
carga=0;
%%RegP
RegP=26;
%%RegI
RegI=27;
%%RegD
RegD=28;
RegPos=30;
CP=32;
CI=32;
CD=5;
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
  Corrien(1)=calllib('dynamixel','dxl_read_word',ID1,68);
  t(2)=toc;
  Corrien(2)=calllib('dynamixel','dxl_read_word',ID1,68);
  calllib('dynamixel','dxl_write_word',ID1,RegPos,1095);%1095
 
  
  for i=2:300;
    t(i)=toc;
    Corrien(i)=calllib('dynamixel','dxl_read_word',ID1,68);    
  end
  
  
  plot(t,Corrien)
  

 calllib('dynamixel','dxl_write_byte',ID1,RegP,0);
 calllib('dynamixel','dxl_write_byte',ID1,RegI,0);
 calllib('dynamixel','dxl_write_word',ID1,RegD,32);
  
  
    calllib('dynamixel','dxl_write_word',ID1,RegPos,2730);%2730
  pause(2)
 