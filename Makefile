CXX = g++
CXXFLAGS = -Wall -O2 --std=c++17 -static
TARGET = wf
SOURCES = wf.cpp tf.cpp item.hpp

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean:
	del $(TARGET).exe