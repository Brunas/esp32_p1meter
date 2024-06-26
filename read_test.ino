#ifdef TEST
String testTelegram = R""""(
/ESO5\253880853_A
0-0:1.0.0(240214101855W)
1-0:1.8.0(000360.152*kWh)
1-0:1.8.1(000232.998*kWh)
1-0:1.8.2(000081.859*kWh)
1-0:1.8.3(000009.963*kWh)
1-0:1.8.4(000035.332*kWh)
1-0:2.8.0(000007.296*kWh)
1-0:3.8.0(000014.422*kvarh)
1-0:4.8.0(000000.002*kvarh)
1-0:1.7.0(00.000*kW)
1-0:2.7.0(00.024*kW)
1-0:3.7.0(00.000*kvar)
1-0:4.7.0(00.000*kvar)
1-0:21.7.0(00.000*kW)
1-0:41.7.0(00.000*kW)
1-0:61.7.0(00.000*kW)
1-0:22.7.0(00.024*kW)
1-0:42.7.0(00.000*kW)
1-0:62.7.0(00.000*kW)
1-0:23.7.0(00.000*kvar)
1-0:43.7.0(00.000*kvar)
1-0:63.7.0(00.000*kvar)
1-0:24.7.0(00.000*kvar)
1-0:44.7.0(00.000*kvar)
1-0:64.7.0(00.000*kvar)
1-0:32.7.0(234.0*V)
1-0:31.7.0(000*A)
1-0:52.7.0(235.6*V)
1-0:51.7.0(000*A)
1-0:72.7.0(233.9*V)
1-0:71.7.0(000*A)
1-0:14.7.0(49.0*Hz)
1-0:13.7.0(-1.000)
1-0:33.7.0(-0.910)
1-0:53.7.0(1.000)
1-0:73.7.0(1.000)
0-0:96.7.21(00039)
0-0:96.13.0(73657450315F657874656E6465645F337068)
1-0:32.32.0(00001)
1-0:52.32.0(00001)
1-0:72.32.0(00001)
1-0:32.36.0(00000)
1-0:52.36.0(00000)
1-0:72.36.0(00000)
0-0:96.1.1(3830303433373030363231363133313235333932363432373030333336333638)
!7773
)"""";

bool readTestSerial() {
  int _index = 1;
  while (true) {
      String _line = getTestLine(testTelegram, '\n', _index);
      if (_line.isEmpty()) {
         return true;
      }
      int _len = _line.length();
      strcpy(telegram, _line.c_str());
      telegram[_len] = '\n';
      telegram[_len + 1] = 0;

      bool result = decodeTelegram(_len + 2);
      _index++;   
  }
}

String getTestLine(String data, char separator, int index) {
  int _found = 0;
  int _strIndex[] = {
    0, -1  };
  int _maxIndex = data.length()-1;
  for(int i=0; i<=_maxIndex && _found<=index; i++){
    if(data.charAt(i) == separator || i == _maxIndex) {
      _found++;
      _strIndex[0] = _strIndex[1]+1;
      _strIndex[1] = (i == _maxIndex) ? i+1 : i;
    }
  }
  return _found > index ? data.substring(_strIndex[0], _strIndex[1]) : "";
}
#endif