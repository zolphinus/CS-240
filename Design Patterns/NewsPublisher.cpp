#include "NewsPublisher.h"
#include "Subscriber.h"

NewsPublisher::NewsPublisher(){
    publisherName = "GENERIC NEWS CENTRAL";
    numSubscribers = 0;
    latestNews = "";
    iter_subscriber = subscribers.begin();
}

NewsPublisher::~NewsPublisher(){
    //declaration
}


void NewsPublisher::attachSubscriber(const Subscriber& newSubscriber){
    if (numSubscribers < MAX_SUBSCRIBERS){
            subscribers.push_back(newSubscriber);
            numSubscribers++;
    }
}


void NewsPublisher::detachSubscriber(const Subscriber& removeSubscriber){
    iter_subscriber = subscribers.begin();
    if (numSubscribers > 0){
            iter_subscriber = subscribers.erase(iter_subscriber);
    }
}


void NewsPublisher::notifyObservers(){
    for (iter_subscriber = subscribers.begin(); iter_subscriber != subscribers.end(); ++iter_subscriber){
            iter_subscriber->update(*this);
    }
}

void NewsPublisher::addNews(std::string newNews){
    latestNews = newNews;
}

std::string NewsPublisher::getLatestNews(){
    return latestNews;
}

std::string NewsPublisher::getPublisherName(){
    return publisherName;
}
