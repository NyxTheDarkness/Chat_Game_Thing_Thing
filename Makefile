SOURCES=$(shell find source -name "*.cpp" -or -name "*.c")
OBJECTS=$(SOURCES:%.cpp=%.o)
TARGET=game

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(LINK.cpp) $^ $(LOADLIBES) $(LDLIBS) -o $@

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJECTS)
