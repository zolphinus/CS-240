#ifndef NEWS_PUBLISHER
#define NEWS_PUBLISHER
#include <string>
#include <list>

#define MAX_SUBSCRIBERS 20

class Subscriber;

class NewsPublisher{
public:
    NewsPublisher();
    ~NewsPublisher();
    void attachSubscriber(const Subscriber&);
    void detachSubscriber(const Subscriber&);
    void notifyObservers();
    void addNews(std::string);
    std::string getPublisherName();
    std::string getLatestNews();


protected:
    std::list <Subscriber> subscribers;
    std::list<Subscriber>::iterator iter_subscriber;
    std::string latestNews;
    std::string publisherName;
    int numSubscribers;

};

#endif // NEWS_PUBLISHER
