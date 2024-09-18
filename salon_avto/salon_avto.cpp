#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

struct Car {
    std::string name;
    int year;
    double engineVolume;
    double price;

    bool operator==(const Car& other) const {
        return name == other.name && year == other.year && engineVolume == other.engineVolume && price == other.price;
    }
};

class AutoSalon {
private:
    std::vector<Car> cars;

public:
    void addCar(const Car& car) {
        cars.push_back(car);
    }

    void removeCar(const Car& car) {
        auto it = std::find(cars.begin(), cars.end(), car);
        if (it != cars.end()) {
            cars.erase(it);
        }
    }

    void displayCars() {
        for (const auto& car : cars) {
            std::cout << "Name: " << car.name << ", Year: " << car.year << ", Engine Volume: " << car.engineVolume << ", Price: " << car.price << std::endl;
        }
    }

    void sortByName() {
        std::sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
            return a.name < b.name;
            });
    }

    void sortByYear() {
        std::sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
            return a.year < b.year;
            });
    }

    void sortByEngineVolume() {
        std::sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
            return a.engineVolume < b.engineVolume;
            });
    }

    void sortByPrice() {
        std::sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
            return a.price < b.price;
            });
    }

    std::vector<Car> findByName(const std::string& name) {
        std::vector<Car> result;
        std::copy_if(cars.begin(), cars.end(), std::back_inserter(result), [&](const Car& car) {
            return car.name == name;
            });
        return result;
    }

    std::vector<Car> findByYear(int year) {
        std::vector<Car> result;
        std::copy_if(cars.begin(), cars.end(), std::back_inserter(result), [&](const Car& car) {
            return car.year == year;
            });
        return result;
    }

    std::vector<Car> findByEngineVolume(double volume) {
        std::vector<Car> result;
        std::copy_if(cars.begin(), cars.end(), std::back_inserter(result), [&](const Car& car) {
            return car.engineVolume == volume;
            });
        return result;
    }

    std::vector<Car> findByPrice(double price) {
        std::vector<Car> result;
        std::copy_if(cars.begin(), cars.end(), std::back_inserter(result), [&](const Car& car) {
            return car.price == price;
            });
        return result;
    }
};

int main() {
    AutoSalon salon;

    salon.addCar({ "Toyota Camry", 2020, 2.5, 25000.0 });
    salon.addCar({ "Honda Civic", 2018, 1.5, 18000.0 });
    salon.addCar({ "Ford Mustang", 2019, 5.0, 35000.0 });
    salon.addCar({ "Chevrolet Silverado", 2021, 5.3, 40000.0 });

    std::cout << "All cars:" << std::endl;
    salon.displayCars();
    std::cout << std::endl;

    std::cout << "Sorted by name:" << std::endl;
    salon.sortByName();
    salon.displayCars();
    std::cout << std::endl;

    std::cout << "Sorted by year:" << std::endl;
    salon.sortByYear();
    salon.displayCars();
    std::cout << std::endl;

    std::cout << "Sorted by engine volume:" << std::endl;
    salon.sortByEngineVolume();
    salon.displayCars();
    std::cout << std::endl;

    std::cout << "Sorted by price:" << std::endl;
    salon.sortByPrice();
    salon.displayCars();
    std::cout << std::endl;

    std::cout << "Cars found by name 'Toyota Camry':" << std::endl;
    auto toyotaCamrys = salon.findByName("Toyota Camry");
    for (const auto& car : toyotaCamrys) {
        std::cout << "Name: " << car.name << ", Year: " << car.year << ", Engine Volume: " << car.engineVolume << ", Price: " << car.price << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Cars found by year 2019:" << std::endl;
    auto cars2019 = salon.findByYear(2019);
    for (const auto& car : cars2019) {
        std::cout << "Name: " << car.name << ", Year: " << car.year << ", Engine Volume: " << car.engineVolume << ", Price: " << car.price << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
