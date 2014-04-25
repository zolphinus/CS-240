#include "SMSSubscriber.h"

SMSSubscriber::SMSSubscriber(std::string name){
    Subscriber::myMedium = "SMS";
    Subscriber::myName = name;
}

SMSSubscriber::SMSSubscriber(){

}



