#ifndef VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H
#define VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H

#include <iostream>
#include <string>
#include <regex>
#include <future>

#include "../../gen-cpp/BeveragePreferenceService.h"

#include "../ClientPool.h"
#include "../ThriftClient.h"
#include "../logger.h"

namespace vending_machine{

class BeveragePreferenceServiceHandler : public BeveragePreferenceServiceIf {
 public:
  BeveragePreferenceServiceHandler();
  ~BeveragePreferenceServiceHandler() override=default;

  void GetBeverage(std::string& _return, const BeverageType::type btype) override;
};

// Constructor
BeveragePreferenceServiceHandler::BeveragePreferenceServiceHandler() {

}

// Remote Procedure "PlaceOrder"

void BeveragePreferenceServiceHandler::GetBeverage(std::string& _return, const BeverageType::type btype) {
     // Your implementation goes here
     printf("GetBeveragePreference\n");

    // randomly select a weather
	if (btype == BeverageType::type::HOT) {
		int randBev = rand()%3;
		if (randBev == 0) {
			_return = "Cappucino";
		}
		else if (randBev == 1) {
			_return = "Latte";
		}
		else {
			_return = "Espresso";
		}
	}
	else {
		int randBev = rand()%3;
		if (randBev == 0) {
			_return = "Lemonade";
		}
		else if (randBev == 1) {
			_return = "Ice Tea";
		}
		else {
			_return = "Soda";
		}
	}
}

} // namespace vending_machine


#endif //VENDING_MACHINE_MICROSERVICES_WEATHERHANDLER_H

