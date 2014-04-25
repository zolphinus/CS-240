#include "EmailSubscriber.h"

EmailSubscriber::EmailSubscriber(std::string name){
    Subscriber::myMedium = "E-Mail";
    Subscriber::myName = name;
}

EmailSubscriber::EmailSubscriber(){

}


