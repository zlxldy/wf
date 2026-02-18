CXX = clang++
CXXFLAGS = -Wall -O2 --std=c++17
TARGET = wf
SOURCES = wf.cpp tf.cpp

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean: FORCE
	del $(TARGET)
FORCE: