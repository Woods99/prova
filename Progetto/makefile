TARGET=master
OBJS=master.o giocatore.o 
TARGET2=master giocatore
FLAGS=-std=c89 -Wpedantic
CC=gcc



$(TARGET): $(OBJS)
	$(CC) $(OBJS) 

All: $(TARGET) 
	$(CC) $(OBJS) -o $(TARGET) #non va

All1: $(TARGET)
	$(CC) -std=c89 -Wpedantic $(TARGET).c giocatore.o -o $(TARGET)

$(TARGET2): $(OBJS)
	$(CC) $(OBJS)

prova1:$(OBJS)
	gcc giocatore.c -o giocatore
	gcc master.c -o master
	#-std=c89 -pedantic
	$(CC)  $(TARGET).c


#compilare prima gli export da shell
#ahahaha
