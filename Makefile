all: CarrierTest 

CarrierTest: CarrierTest.o CarrierHeatpumpIR.o HeatpumpIR.o IRSender.o IRSenderBitBang.o IRSenderBlaster.o IRSenderPWM.o
			g++ CarrierTest.o CarrierHeatpumpIR.o HeatpumpIR.o IRSender.o IRSenderBitBang.o IRSenderBlaster.o IRSenderPWM.o -o CarrierTest

CarrierTest.o: ./examples/CarrierTest/CarrierTest.cpp
			g++ -c ./examples/CarrierTest/CarrierTest.cpp

CarrierHeatpumpIR.o: CarrierHeatpumpIR.cpp
			g++ -c CarrierHeatpumpIR.cpp

HeatpumpIR.o: HeatpumpIR.cpp
			g++ -c HeatpumpIR.cpp

IRSender.o: IRSender.cpp
			g++ -c IRSender.cpp

IRSenderBitBang.o: IRSenderBitBang.cpp
			g++ -c IRSenderBitBang.cpp

IRSenderBlaster.o: IRSenderBlaster.cpp
			g++ -c IRSenderBlaster.cpp

IRSenderPWM.o: IRSenderPWM.cpp
			g++ -c IRSenderPWM.cpp

