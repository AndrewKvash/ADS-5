// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"
int priority(char zn) {
switch (zn) {
case '(': return 0;
case ')': return 1;
case '-': return 2;
case '+': return 2;
case '*': return 3;
case '/': return 3;
case ' ': return 5;
default: return 4;
}
}

std::string infx2pstfx(std::string inf) {
TStack <char, 100> stack;
std::string resultat;

for (int i = 0; i < inf.size(); i++) {
if (priority(inf[i]) == 4) {
resultat.push_back(inf[i]);
resultat.push_back(' ');
}
else {
if (priority(inf[i]) == 0) {
stack.push(inf[i]);
}
else if (stack.isEmpty()) {
stack.push(inf[i]);
}
else if ((priority(inf[i]) > priority(stack.get()))) {
stack.push(inf[i]);
}
else if (priority(inf[i]) == 1) {
while (priority(stack.get()) != 0) {
resultat.push_back(stack.get());
resultat.push_back(' ');
stack.pop();
}
stack.pop();
}
else {
char a = priority(inf[i]);
char b = priority(stack.get());
while ((a <= b) && (!stack.isEmpty())) {
resultat.push_back(stack.get());
resultat.push_back(' ');
stack.pop();
}
stack.push(inf[i]);
}
}
}

while (!stack.isEmpty()) {
resultat.push_back(stack.get());
resultat.push_back(' ');
stack.pop();
}

for (int i = 0; i < resultat.size(); i++) {
if (resultat[resultat.size() - 1] == ' ') {
resultat.erase(resultat.size() - 1);
}

}
return resultat;
}

int calcul(char operation, int a, int b) {
switch (operation) {
case '+': return a + b;
break;
case '-': return b - a;
break;
case '*': return a * b;
break;
case '/': return b / a;
break;
}
return 0;
}

int eval(std::string pref) {
TStack <int, 100> stack2;
int znach, a, b = 0;
for (int i = 0; i < pref.size(); i++) {
if (pref[i] >= '0') {
stack2.push(pref[i] - '0');
}
else if (priority(pref[i]) <= 3) {
a = stack2.get();
stack2.pop();
b = stack2.get();
stack2.pop();
stack2.push(calcul(pref[i], a, b));
}
}
znach = stack2.get();
return znach;
return 0;
}
