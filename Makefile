# Это комментарий, который говорит, что переменная CC указывает компилятор, используемый для сборки
CC=g++
CFLAGS=-c
EXECUTABLE=CarrierTest DaiseikaiTest
LIBS=HeatpumpIR.o IRSender.o IRSenderBitBang.o IRSenderBlaster.o IRSenderPWM.o 

all: $(EXECUTABLE) 



CarrierTest: CarrierTest.o CarrierHeatpumpIR.o $(LIBS)
			$(CC) CarrierTest.o CarrierHeatpumpIR.o HeatpumpIR.o IRSender.o IRSenderBitBang.o IRSenderBlaster.o IRSenderPWM.o -o CarrierTest

CarrierTest.o: ./examples/CarrierTest/CarrierTest.cpp
			$(CC) $(CFLAGS) ./examples/CarrierTest/CarrierTest.cpp

CarrierHeatpumpIR.o: CarrierHeatpumpIR.cpp
			$(CC) $(CFLAGS) CarrierHeatpumpIR.cpp




DaiseikaiTest: DaiseikaiTest.o ToshibaDaiseikaiHeatpumpIR.o CarrierHeatpumpIR.o $(LIBS)
			$(CC) DaiseikaiTest.o ToshibaDaiseikaiHeatpumpIR.o CarrierHeatpumpIR.o $(LIBS) -o DaiseikaiTest

DaiseikaiTest.o: ./examples/DaiseikaiTest/DaiseikaiTest.cpp
			$(CC) $(CFLAGS) ./examples/DaiseikaiTest/DaiseikaiTest.cpp

ToshibaDaiseikaiHeatpumpIR.o: ToshibaDaiseikaiHeatpumpIR.cpp 
			$(CC) $(CFLAGS) ToshibaDaiseikaiHeatpumpIR.cpp





HeatpumpIR.o: HeatpumpIR.cpp
			$(CC) $(CFLAGS) HeatpumpIR.cpp

IRSender.o: IRSender.cpp
			$(CC) $(CFLAGS) IRSender.cpp

IRSenderBitBang.o: IRSenderBitBang.cpp
			$(CC) $(CFLAGS) IRSenderBitBang.cpp

IRSenderBlaster.o: IRSenderBlaster.cpp
			$(CC) $(CFLAGS) IRSenderBlaster.cpp

IRSenderPWM.o: IRSenderPWM.cpp
			$(CC) $(CFLAGS) IRSenderPWM.cpp

clean:
	rm -rf *.o $(EXECUTABLE) 

