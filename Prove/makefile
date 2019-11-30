TARGET=main_shared
OBJS=main_shared.o giocatore.o pedina.o
TARGET2=main_shared giocatore 
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
	gcc pedina.c -o pedina
	gcc giocatore.c -o giocatore
	gcc main_shared.c -o main_shared
	#-std=c89 -pedantic
	$(CC)  $(TARGET).c


#compilare prima gli export da shell
#ahahaha
