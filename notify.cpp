// NOTIFYH20
//
// THIS IS A SIMPLE COMMAND LINE APPLICATION WHICH REMINDS THE USER TO DRINK WATER FREQUENTLY
//
// DEVELOPED BY: VIGNESHWAR K R 
//
// FILE NAME: NOTIFY.CPP

// IMPORTING REQUIRED LIBRARIES
#include<libnotify/notify.h>
#include<iostream>
#include <string>
#include <chrono>
#include <thread>
#include <functional>

// PLACE FOR USER CONFIGURABLE VARIABLES
char message[] = "Drink some water now !!";
int interval = 3;

// FUNCTION FOR HANDLING THE TIMER 
void timer_start(std::function<void(void)> func, unsigned int interval)
{
    std::thread([func, interval]() {
        while (true)
        {
            func();
            std::this_thread::sleep_for(std::chrono::milliseconds(interval));
        }
    }).detach();
}

// FUNCTION TO NOTIFY THE USER
void action()
{
      notify_init("Message");
      NotifyNotification* n = notify_notification_new("NotifyH2O",message,0);
      notify_notification_set_timeout(n,0);

      if(!notify_notification_show(n,0))
      {
          std:: cerr<<"Show failed"<<std::endl;
      }
}

int main(int argc, char * argv[])
{
    interval = interval*1000;

    timer_start(action, interval);    
    while(true);
}


