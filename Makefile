SOURCES=test_cstr.cpp test_getindex.cpp test_cttrie.cpp test_cttrie_print.cpp
EXEC=test_cstr test_getindex test_cttrie test_cttrie_print

CFLAGS=-Wall -O3
CXXFLAGS=-std=c++11
CPPFLAGS=$(CFLAGS) $(FLAGS)

OBJECTS=$(patsubst %.c,$(PREFIX)%$(SUFFIX).o,\
        $(patsubst %.cpp,$(PREFIX)%$(SUFFIX).o,\
$(SOURCES)))
DEPENDS=$(patsubst %.c,$(PREFIX)%$(SUFFIX).d,\
        $(patsubst %.cpp,$(PREFIX)%$(SUFFIX).d,\
        $(filter-out %.o,""\
$(SOURCES))))

all: $(EXEC)
ifneq "$(MAKECMDGOALS)" "clean"
  -include $(DEPENDS)
endif

clean:
	rm -f $(EXEC) $(OBJECTS) $(DEPENDS)

%.d: %.c
	@$(CC) $(CPPFLAGS) -MM -MT"$@" -MT"$*.o" -o $@ $<  2> /dev/null

%.d: %.cpp
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) -MM -MT"$@" -MT"$*.o" -o $@ $<  2> /dev/null

$(EXEC): %: %.o
	$(CXX) -o $@ $< $(LDFLAGS)

