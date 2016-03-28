  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtP)
    ;%
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% rtP.Gain_Gain
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.Fs_Gain
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.Fc_Gain
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.To_Gain
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.Constant_Value
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.Gain3_Gain
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtP.Gain_Gain_b1oehh4m53
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtP.Fs_Gain_gejxjpa1bz
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtP.Fc_Gain_ncx454w25g
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtP.To_Gain_oixd02jkdm
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtP.Constant_Value_nicvna5tcb
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtP.Gain3_Gain_oxdnjjsq1e
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtB)
    ;%
      section.nData     = 27;
      section.data(27)  = dumData; %prealloc
      
	  ;% rtB.mb32kofeaj
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.jygob3b3q4
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% rtB.og0vqabzz1
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 4;
	
	  ;% rtB.jrcr0hqppv
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 5;
	
	  ;% rtB.jsceoxumdg
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 6;
	
	  ;% rtB.bbrhi2aa4o
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 7;
	
	  ;% rtB.n3sk3m5mid
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 8;
	
	  ;% rtB.kxibtkeec5
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 9;
	
	  ;% rtB.enw5bh50ec
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 10;
	
	  ;% rtB.kq2v02wqsv
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 11;
	
	  ;% rtB.csph14lqqx
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 12;
	
	  ;% rtB.jvbzfyxc03
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 13;
	
	  ;% rtB.ijqtrjxdsh
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 14;
	
	  ;% rtB.bztakntxrl
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 18;
	
	  ;% rtB.p2zhwbrpql
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 19;
	
	  ;% rtB.enns31nw1s
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 20;
	
	  ;% rtB.jejwlkbmc2
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 21;
	
	  ;% rtB.dessyx1zav
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 22;
	
	  ;% rtB.ctssu21gdv
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 23;
	
	  ;% rtB.orlilvcezk
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 24;
	
	  ;% rtB.dbi3o4yn43
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 25;
	
	  ;% rtB.kcfeei3ce0
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 26;
	
	  ;% rtB.apvpvqneyh
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 27;
	
	  ;% rtB.bzizsky3i2
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 31;
	
	  ;% rtB.flitgoamze
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 32;
	
	  ;% rtB.ow1luaqdsv
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 33;
	
	  ;% rtB.ptrzoxc51k
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 34;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 4;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtDW)
    ;%
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% rtDW.px2h4fxqvc
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.gt0elxwjeb
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.j0qqzzt21t
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 47;
      section.data(47)  = dumData; %prealloc
      
	  ;% rtDW.gk0htlbrma
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.is0xydhs4l
	  section.data(2).logicalSrcIdx = 4;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.ka0rn1jqlo
	  section.data(3).logicalSrcIdx = 5;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.ix1x41bo4v
	  section.data(4).logicalSrcIdx = 6;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.aswm55dcsr
	  section.data(5).logicalSrcIdx = 7;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.akflnq5gjx
	  section.data(6).logicalSrcIdx = 8;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDW.b2mtd04ww2
	  section.data(7).logicalSrcIdx = 9;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDW.mxmjsp3mlq
	  section.data(8).logicalSrcIdx = 10;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtDW.nhl3ynb1oz
	  section.data(9).logicalSrcIdx = 11;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtDW.i4sxnucti0
	  section.data(10).logicalSrcIdx = 12;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtDW.hzmvsaoulo.LoggedData
	  section.data(11).logicalSrcIdx = 13;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtDW.depbo03vrk
	  section.data(12).logicalSrcIdx = 14;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtDW.bjxpzefqp3
	  section.data(13).logicalSrcIdx = 15;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtDW.g5mb0p1qhu
	  section.data(14).logicalSrcIdx = 16;
	  section.data(14).dtTransOffset = 13;
	
	  ;% rtDW.pcqktgmah0
	  section.data(15).logicalSrcIdx = 17;
	  section.data(15).dtTransOffset = 14;
	
	  ;% rtDW.nvguz3vz4c
	  section.data(16).logicalSrcIdx = 18;
	  section.data(16).dtTransOffset = 15;
	
	  ;% rtDW.eioh2xr3aq
	  section.data(17).logicalSrcIdx = 19;
	  section.data(17).dtTransOffset = 16;
	
	  ;% rtDW.khywewrhhg
	  section.data(18).logicalSrcIdx = 20;
	  section.data(18).dtTransOffset = 17;
	
	  ;% rtDW.gr25vq2fuc
	  section.data(19).logicalSrcIdx = 21;
	  section.data(19).dtTransOffset = 18;
	
	  ;% rtDW.mt2eznmsv5
	  section.data(20).logicalSrcIdx = 22;
	  section.data(20).dtTransOffset = 19;
	
	  ;% rtDW.aegvhv5w45
	  section.data(21).logicalSrcIdx = 23;
	  section.data(21).dtTransOffset = 20;
	
	  ;% rtDW.lwg50jsxft
	  section.data(22).logicalSrcIdx = 24;
	  section.data(22).dtTransOffset = 21;
	
	  ;% rtDW.j1rpvtehmk
	  section.data(23).logicalSrcIdx = 25;
	  section.data(23).dtTransOffset = 22;
	
	  ;% rtDW.lidhiurvks
	  section.data(24).logicalSrcIdx = 26;
	  section.data(24).dtTransOffset = 23;
	
	  ;% rtDW.kv4zbkviwj
	  section.data(25).logicalSrcIdx = 27;
	  section.data(25).dtTransOffset = 24;
	
	  ;% rtDW.d2gx0feb1q
	  section.data(26).logicalSrcIdx = 28;
	  section.data(26).dtTransOffset = 25;
	
	  ;% rtDW.ko5bzgm54o
	  section.data(27).logicalSrcIdx = 29;
	  section.data(27).dtTransOffset = 26;
	
	  ;% rtDW.hlaipun4ez
	  section.data(28).logicalSrcIdx = 30;
	  section.data(28).dtTransOffset = 27;
	
	  ;% rtDW.amndknbiec
	  section.data(29).logicalSrcIdx = 31;
	  section.data(29).dtTransOffset = 28;
	
	  ;% rtDW.kssewaxdx3
	  section.data(30).logicalSrcIdx = 32;
	  section.data(30).dtTransOffset = 29;
	
	  ;% rtDW.pminz14afl
	  section.data(31).logicalSrcIdx = 33;
	  section.data(31).dtTransOffset = 30;
	
	  ;% rtDW.jjrd2czqdm.LoggedData
	  section.data(32).logicalSrcIdx = 34;
	  section.data(32).dtTransOffset = 31;
	
	  ;% rtDW.jm0fzi1blb
	  section.data(33).logicalSrcIdx = 35;
	  section.data(33).dtTransOffset = 32;
	
	  ;% rtDW.op23awaojj
	  section.data(34).logicalSrcIdx = 36;
	  section.data(34).dtTransOffset = 33;
	
	  ;% rtDW.ioyxzcapgj
	  section.data(35).logicalSrcIdx = 37;
	  section.data(35).dtTransOffset = 34;
	
	  ;% rtDW.kahykihega
	  section.data(36).logicalSrcIdx = 38;
	  section.data(36).dtTransOffset = 35;
	
	  ;% rtDW.aom3mirt2x
	  section.data(37).logicalSrcIdx = 39;
	  section.data(37).dtTransOffset = 36;
	
	  ;% rtDW.aou51eikro
	  section.data(38).logicalSrcIdx = 40;
	  section.data(38).dtTransOffset = 37;
	
	  ;% rtDW.eufaiemnot
	  section.data(39).logicalSrcIdx = 41;
	  section.data(39).dtTransOffset = 38;
	
	  ;% rtDW.ewleodkp1x
	  section.data(40).logicalSrcIdx = 42;
	  section.data(40).dtTransOffset = 39;
	
	  ;% rtDW.m0fguvm2fm
	  section.data(41).logicalSrcIdx = 43;
	  section.data(41).dtTransOffset = 40;
	
	  ;% rtDW.dxrjr0gy3k
	  section.data(42).logicalSrcIdx = 44;
	  section.data(42).dtTransOffset = 41;
	
	  ;% rtDW.nfcjhvjxuy
	  section.data(43).logicalSrcIdx = 45;
	  section.data(43).dtTransOffset = 42;
	
	  ;% rtDW.osydjefyeb
	  section.data(44).logicalSrcIdx = 46;
	  section.data(44).dtTransOffset = 43;
	
	  ;% rtDW.alt2ulitdc
	  section.data(45).logicalSrcIdx = 47;
	  section.data(45).dtTransOffset = 44;
	
	  ;% rtDW.eerr0ropq4
	  section.data(46).logicalSrcIdx = 48;
	  section.data(46).dtTransOffset = 45;
	
	  ;% rtDW.gv4r4p2yf2
	  section.data(47).logicalSrcIdx = 49;
	  section.data(47).dtTransOffset = 46;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.nujczoxr2h
	  section.data(1).logicalSrcIdx = 50;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.mkghkkvf3s
	  section.data(2).logicalSrcIdx = 51;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.bcjys3m3es
	  section.data(1).logicalSrcIdx = 52;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 1897557679;
  targMap.checksum1 = 4222067273;
  targMap.checksum2 = 380769674;
  targMap.checksum3 = 563028228;

