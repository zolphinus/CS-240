#include "RealSubscriber.h"
#include "NewsPublisher.h"
#include <iostream>


void RealSubscriber::update(NewsPublisher& currentNewsPublisher){
    std::cout << "My name is " << myName << " and I 444am a(n) " << myMedium << " subscriber." << std::endl;
    std::cout << currentNewsPublisher.getPublisherName() << " just told me about :" << std::endl;
    std::cout << currentNewsPublisher.getLatestNews() << std::endl << std::endl;
}
