CC = g++
LDFLAGS = -lncurses

TARGET = SnakeGame
SRCS = main.cpp Snake.cpp SnakeGame.cpp Board.cpp Wall.cpp map.cpp Item.cpp Gate.cpp Obmanager.cpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CC) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)
