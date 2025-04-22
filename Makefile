# 编译器
CXX = g++

# 编译选项
CXXFLAGS = -Wall -g

# 目标文件
TARGET = game

# 源文件
SRCS = main.cpp map.apai1001(2).cpp user_control.cpp

# 生成的对象文件
OBJS = $(SRCS:.cpp=.o)

# 默认目标
all: $(TARGET)

# 链接目标
$(TARGET): $(OBJS)
    $(CXX) $(CXXFLAGS) -o $@ $^

# 编译规则
%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

# 清理
clean:
    rm -f $(OBJS) $(TARGET)