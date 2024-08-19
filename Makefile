CXX = g++
CXXFLAGS = -std=c++2a `pkg-config --cflags gtkmm-3.0`
LDFLAGS = `pkg-config --libs gtkmm-3.0` -ljsoncpp -lcurl -Wall -Wextra -Wpedantic
INCLUDES = -Iinclude -I/usr/include/jsoncpp

TARGET = Analyse_Scanner_Cerebral.bin # Inclure les fichiers de dépendances s'ils existent
PACKAGES = $(shell find src -type d)
SRCFILES = $(foreach dir,$(PACKAGES),$(wildcard $(dir)/*.cpp))

# Création des listes d'objets et de dépendances
OBJS = $(SRCFILES:src/%.cpp=bin/%.o)
DEPS = $(SRCFILES:src/%.cpp=bin/%.dpp)

all: init recompile run

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

bin/%.o: src/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

bin/%.dpp: src/%.cpp
	@mkdir -p $(@D)
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -MM $< | sed 's|src/\(.*\)\.o|bin/\1.o bin/\1.dpp:|' > $@

compile: $(TARGET)

recompile: clean compile

init:
	@mkdir -p scan
	@mkdir -p bin
	@mkdir -p lib

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJS) $(DEPS)
	rm -rf lib/*.*
	rm -rf $(TARGET)

mrproper: clean
	rm -rf bin/*.*

.PHONY: all clean init run