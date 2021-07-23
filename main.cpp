#include <iostream>

char encoder(char currCh, int shift, char startCh, char endCh) {
    if (currCh + shift > endCh) {
        currCh =  startCh + (currCh + shift - endCh - 1);
    } else if (currCh + shift < startCh) {
        currCh = endCh - (startCh - (currCh + shift) - 1);
    } else {
        currCh += shift;
    }

    return currCh;
}

std::string encrypt_caesar(std::string str, int shift) {
  shift %= 26;
  for(unsigned int i = 0; i < str.length(); i++){        
        if (str[i] >= 'a' && str[i] <= 'z'){
            str[i] = encoder(str[i], shift, 'a', 'z');
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = encoder(str[i], shift, 'A', 'Z');
        }
    }
  return str;
}

std::string decrypt_caesar(std::string str, int shift) {
  return encrypt_caesar(str, -shift);
}

int main() {
  std::string inputString;
  int inputShift;
  std::cout << "Enter text to encrypt: ";
  std::getline(std::cin, inputString);
  std::cout << "Enter a shift for encryption: ";
  std::cin >> inputShift;

  std::cout << "encrypt: " << encrypt_caesar(inputString, inputShift);
  std::cout << std::endl;
  std::cout << "decrypt: " << decrypt_caesar(encrypt_caesar(inputString, inputShift), inputShift);
}

/*
Что нужно сделать
В древности для шифрования сообщений использовался такой способ: все буквы в сообщении сдвигались на одно и то же число позиций в алфавите. Число позиций могло быть как положительным, так и отрицательным и являлось параметром шифра. Если для сдвига на данное число позиций алфавита не хватает, то он зацикливается (то есть буква с номером 27 — это снова буква «a», буква с номером 28 — это «b» и так далее).

Например, слово abracadabra при сдвиге на 10 позиций превратится в klbkmknklbk. Этот простейший шифр называется шифром Цезаря. Регистр букв (заглавные и строчные) менять не нужно. Напишите функцию encrypt_caesar от строки и числа, которая возвращает исходную строку, зашифрованную шифром Цезаря с параметром, равным данному числу. Также напишите функцию decrypt_caesar, выполняющую обратное преобразование. Считаем, что входные строки состоят лишь из английских букв; если там содержатся и другие символы, то их надо игнорировать.
*/