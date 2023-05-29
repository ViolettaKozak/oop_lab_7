#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TicketRequest {
private:
    string destinationStation;
    string date;
    string time;

public:
    TicketRequest(const string& destinationStation, const string& date, const string& time)
        : destinationStation(destinationStation), date(date), time(time) {
    }

    string getDestinationStation() const {
        return destinationStation;
    }

    string getDate() const {
        return date;
    }

    string getTime() const {
        return time;
    }
};

class Train {
private:
    int trainNumber;
    string startStation;
    string endStation;
    string data;
    float price;

public:
    Train(int trainNumber, const string& startStation, const string& endStation, float price, const string& data)
        : trainNumber(trainNumber), startStation(startStation), endStation(endStation), price(price), data(data){
    }

    int getTrainNumber() const {
        return trainNumber;
    }

    string getStartStation() const {
        return startStation;
    }

    string getEndStation() const {
        return endStation;
    }

    float getPrice() const {
        return price;
    }

    void getTrain() {
        cout << "Train " << trainNumber << ": start(" << startStation << ") data: " << data << "  price = " << price << endl;
    }
};

class RailwayTicketSystem {
private:
    vector<TicketRequest> ticketRequests;
    vector<Train> trains;

public:
    void addTicketRequest(const TicketRequest& ticketRequest) {
        ticketRequests.push_back(ticketRequest);
    }

    void addTrain(const Train& train) {
        trains.push_back(train);
    }

    Train findTrainForRequest(const TicketRequest& ticketRequest) const {
        for (const auto& train : trains) {
            if (train.getStartStation() == ticketRequest.getDestinationStation()) {
                return train;
            }
        }

        throw runtime_error("Train not found for the given request.");
    }

    float generateInvoice(const Train& train) const {
        return train.getPrice();
    }
};

int main() {
    RailwayTicketSystem ticketSystem;

    ticketSystem.addTrain(Train(1, "Station A", "Station B", 10.0, "2023-06-15"));
    ticketSystem.addTrain(Train(2, "Station B", "Station C", 15.0, "2023-05-29"));
    ticketSystem.addTrain(Train(3, "Station A", "Station C", 20.0, "2023-04-05"));
    ticketSystem.addTrain(Train(4, "Station C", "Station B", 25.0, "2023-05-06"));

    TicketRequest ticketRequest("Station C", "2023-05-30", "10:00");

    try {
        Train train = ticketSystem.findTrainForRequest(ticketRequest);
        train.getTrain();
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
