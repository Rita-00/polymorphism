/*
Реализовать программу демонстрирующую предметную область "Пиццерия"
Заказ - это список из выбранных пользователем пицц.
Пицца - это блюдо, которое выбирает пользователь.
Пицца обладает именем(текст), описанием(текст), размером (один из вариантов 25, 30, 35, 40, который выбирает пользователь),
ценой(зависит от размера выбранной пиццы и ингредиентов).
Пользователь может подсолить любую пиццу N-раз или добавить сыра M-раз - это увеличивает цену в зависимости от вида и размера пиццы (формулу придумать на ваше усмотрение)
Заказ - формируется пользователем через консоль, возможность добавить пиццу, распечатать заказ в консоль.
Печать заказа - вывод всего списка выбранных пользователем пицц, с указанием названия, описания, N-соли и M-сыра, размера пиццы и стоимости пиццы с учётом всех параметров
В конце распечатанного заказа вывести итоговую сумму за заказ
*/
#include <iostream>
#include <vector>

using namespace std;

class Pizza {
protected:
  string name;
  string description;
  unsigned int size;
  unsigned int price;
  unsigned int salt;
  unsigned int cheese;

public:
  virtual string getName() const = 0;
  virtual string getDescription() const = 0;
  virtual unsigned int getPrice() const = 0;
  virtual unsigned int getSize() const = 0;
  virtual unsigned int getSalt() const = 0;
  virtual unsigned int getCheese() const = 0;
};

class Margarita : public Pizza {

public:
  Margarita(unsigned int size, unsigned int salt, unsigned int cheese) {
    this->name = "Маргарита";
    this->size = size;
    this->cheese = cheese;
    this->salt = salt;
  }
  string getName() const override { return "Маргарита"; };
  string getDescription() const override {
    return " (соус томатный, сыр Моцарелла, помидоры, базилик) ";
  };
  unsigned int getSize() const override { return size; }
  unsigned int getSalt() const override { return salt; }
  unsigned int getCheese() const override { return cheese; }
  unsigned int getPrice() const override {
    if (size == 25) {
      return 300 + getSalt() * 1 + getCheese() * 2;
    } else {
      return 300 + getSize() + getSalt() * 1 + getCheese() * 2;
    }
  }
};

class FourChesse : public Pizza {
public:
  FourChesse(unsigned int size, unsigned int salt, unsigned int cheese) {
    this->name = "Четыре сыра";
    this->size = size;
    this->cheese = cheese;
    this->salt = salt;
  }
  string getName() const override { return "Четыре сыра"; };
  string getDescription() const override {
    return " (сыр Моцарелла, сыр Эмменталь, сыр Горгонзола, сыр Пармезан) ";
  };
  unsigned int getSize() const override { return size; }
  unsigned int getSalt() const override { return salt; }
  unsigned int getCheese() const override { return cheese; }
  unsigned int getPrice() const override {
    if (size == 25) {
      return 400 + getSalt() * 1 + getCheese() * 1;
    } else {
      return 400 + getSize() + getSalt() * 1 + getCheese() * 1;
    }
  }
};

class Sicilian : public Pizza {
public:
  Sicilian(unsigned int size, unsigned int salt, unsigned int cheese) {
    this->name = "Сицилийская";
    this->size = size;
    this->cheese = cheese;
    this->salt = salt;
  }
  string getName() const override { return "Сицилийская"; };
  string getDescription() const override {
    return " (тунец, маслины, помидор, тёртый сыр) ";
  };
  unsigned int getSize() const override { return size; }
  unsigned int getSalt() const override { return salt; }
  unsigned int getCheese() const override { return cheese; }
  unsigned int getPrice() const override {
    if (size == 25) {
      return 350 + getSalt() * 1 + getCheese() * 3;
    } else {
      return 350 + getSize() + getSalt() * 2 + getCheese() * 3;
    }
  }
};

class FourSeason : public Pizza {
public:
  FourSeason(unsigned int size, unsigned int salt, unsigned int cheese) {
    this->name = "Четыре сезона";
    this->size = size;
    this->cheese = cheese;
    this->salt = salt;
  }
  string getName() const override { return "Четыре сезона"; };
  string getDescription() const override {
    return " (шампиньоны, морепродукты, салями, помидоры, сыр Моцарелла) ";
  };
  unsigned int getSize() const override { return size; }
  unsigned int getSalt() const override { return salt; }
  unsigned int getCheese() const override { return cheese; }
  unsigned int getPrice() const override {
    if (size == 25) {
      return 450 + getSalt() * 1 + getCheese() * 2;
    } else {
      return 450 + getSize() + getSalt() * 1 + getCheese() * 2;
    }
  }
};

class Classic : public Pizza {
public:
  Classic(unsigned int size, unsigned int salt, unsigned int cheese) {
    this->name = "Классическая";
    this->size = size;
    this->cheese = cheese;
    this->salt = salt;
  }
  string getName() const override { return "Классическая"; };
  string getDescription() const override {
    return " (шампиньоны, ветчина, базелик, помидоры, сыр Моцарелла) ";
  };
  unsigned int getSize() const override { return size; }
  unsigned int getSalt() const override { return salt; }
  unsigned int getCheese() const override { return cheese; }
  unsigned int getPrice() const override {
    if (size == 25) {
      return 325 + getSalt() * 1 + getCheese() * 2;
    } else {
      return 325 + getSize() + getSalt() * 1 + getCheese() * 2;
    }
  }
};

class Order {
  vector<const Pizza *> pizzas;

public:
  void add(const Pizza *pizza) { pizzas.push_back(pizza); }
  void print() {
    unsigned int endprice = 0;
    size_t size = pizzas.size();
    if (size == 0) {
      cout << "Вы не выбрали пиццу" << endl;
    } else {
      for (size_t i = 0, size = pizzas.size(); i < size; i++) {
        cout << (i + 1) << "." << pizzas[i]->getName()
             << pizzas[i]->getDescription() << " размер "
             << pizzas[i]->getSize() << ", количество соли - "
             << pizzas[i]->getSalt() << ", количество сыра - "
             << pizzas[i]->getCheese() << ". Цена за пиццу - "
             << pizzas[i]->getPrice() << endl;
        endprice = endprice + pizzas[i]->getPrice();
      }
      cout << "Итоговая цена " << endprice << endl;
    }
  }
};

int main() {
  cout << "Menu:" << endl;
  cout << "1. Margarita-300" << endl;
  cout << "2. FourChesse-400" << endl;
  cout << "3. Sicilian-350" << endl;
  cout << "4. FourSeason-450" << endl;
  cout << "5. Classic-325" << endl;

  Order order;

  cout << "Выберите пиццу" << endl;
  int choice;
  unsigned int size, salt, cheese;
  cin >> choice;
  while ((choice > 0) && (choice < 6)) {
    cout << "Введите размер пиццы, количество соли и сыра" << endl;
    cin >> size >> salt >> cheese;
    while ((size != 25) && (size != 30) && (size != 35) && (size != 40)) {
      cout << "Размер должен быть 25, 30, 35, 40" << endl;
      cin >> size;
    }
    switch (choice) {
    case 1:
      order.add(new Margarita(size, salt, cheese));
      break;
    case 2:
      order.add(new FourChesse(size, salt, cheese));
      break;
    case 3:
      order.add(new Sicilian(size, salt, cheese));
      break;
    case 4:
      order.add(new FourSeason(size, salt, cheese));
      break;
    case 5:
      order.add(new Classic(size, salt, cheese));
      break;
    }
    cin >> choice;
  };
  order.print();
  return 0;
}