# Компилятор
CXX = g++

# Флаги компиляции
CXXFLAGS = -std=c++17 -I./headers # Добавляем -I./headers для указания директории с заголовочными файлами
  
# Директории
SRCDIR = src
BINDIR = bin
HEADERSDIR = headers

# Имя исполняемого файла
TARGET = $(BINDIR)/coffee_machine

# Заголовочные файлы
HEADERS = $(HEADERSDIR)/coffee_machine.h $(HEADERSDIR)/ingredients.h $(HEADERSDIR)/recipe.h $(HEADERSDIR)/menu.h $(HEADERSDIR)/recipe_parser.h

# Исходные файлы
SRC = $(SRCDIR)/coffee_machine.cpp $(SRCDIR)/ingredients.cpp $(SRCDIR)/main.cpp $(SRCDIR)/recipe.cpp $(SRCDIR)/menu.cpp $(SRCDIR)/recipe_parser.cpp

# Объектные файлы
OBJ = $(SRC:.cpp=.o)

# Правило для сборки всех файлов
all: $(TARGET)

# Правило для создания исполняемого файла
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Правило для компиляции .cpp файлов в .o
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка всех сгенерированных файлов
# rm -f $(OBJ) $(TARGET)
# del /Q src\*.o bin\coffee_machine.exe
clean:
	del /Q src\*.o bin\coffee_machine.exe
	
# Запуск программы после сборки
run: $(TARGET)
	./$(TARGET)