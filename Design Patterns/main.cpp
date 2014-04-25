#include <iostream>
#include "BusinessPublisher.h"
#include "SubscriberTypes.h"

using namespace std;
void testPublisher();
void testTemplate();

int main()
{
    testPublisher();
    return 0;
}


void testPublisher(){

    NewsPublisher testPublisher;
    BusinessPublisher baconGazette("The Bacon Gazette");

    cout << "CREATING SUBSCRIBERS" << endl;
//    RealSubscriber test("Test");
    PonyExpressSubscriber Aaron("A-aron");
    EmailSubscriber Tim("Ti-mo-thy");
    SMSSubscriber Denise("Den-ice");
    EmailSubscriber Blake("Ba-la-keh");

    cout << "ADD A-ARON to " << testPublisher.getPublisherName() << endl;
    testPublisher.attachSubscriber(Aaron);

    testPublisher.addNews("IT'S RAINING MEN!!!");
    testPublisher.notifyObservers();

    cout << "ADD BA-LA-KEH AND DEN-ICE to " << testPublisher.getPublisherName() << endl;
    testPublisher.attachSubscriber(Blake);
    testPublisher.attachSubscriber(Denise);
    testPublisher.addNews("HALLELUJAH, IT'S RAINING MEN!!!");
    testPublisher.notifyObservers();

    cout << "ADD TI-MO-THY to " << testPublisher.getPublisherName() << endl;
    testPublisher.attachSubscriber(Tim);
    testPublisher.addNews("AMEN!!!");
    testPublisher.notifyObservers();

    cout << "REMOVING DEN-ICE from " << testPublisher.getPublisherName() << endl;
    testPublisher.detachSubscriber(Denise);
    testPublisher.addNews("DUCK SIMULATOR NOW WITH FLYING DUCKS!!!");

    cout << "REMOVING A-ARON from" << testPublisher.getPublisherName() << endl;
    testPublisher.detachSubscriber(Aaron);

    cout << "ADDING A-ARON to " << baconGazette.getPublisherName() << endl;
    cout << "ADDING DEN-ICE to " << baconGazette.getPublisherName() << endl;

    baconGazette.attachSubscriber(Aaron);
    baconGazette.attachSubscriber(Denise);

    testPublisher.addNews("IT'S NO LONGER RAINING MEN!!!");
    baconGazette.addNews("BACON SALES UP TO 71% off!");

    testPublisher.notifyObservers();
    baconGazette.notifyObservers();
}
