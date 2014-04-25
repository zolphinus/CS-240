#include "Subscriber.h"
#include "NewsPublisher.h"
#include <iostream>

Subscriber::Subscriber(){
    myName = "dummy";
    myMedium = "dummy";
}

Subscriber::~Subscriber(){

}


void Subscriber::update(NewsPublisher& currentNewsPublisher){
    std::cout << "My name is " << myName << " and I am a(n) " << myMedium << " subscriber." << std::endl;
    std::cout << currentNewsPublisher.getPublisherName() << " just told me about :" << std::endl;
    std::cout << currentNewsPublisher.getLatestNews() << std::endl << std::endl;
}

