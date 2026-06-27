#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum DestinationType {
    DomesticShort,
    DomesticLong,
    International
};

string destinationName(DestinationType type) {
    switch (type) {
    case DomesticShort:
        return "DomesticShort";
    case DomesticLong:
        return "DomesticLong";
    case International:
        return "International";
    default:
        return "Unknown";
    }
}

double basePrice(DestinationType type) {
    switch (type) {
    case DomesticShort:
        return 10;
    case DomesticLong:
        return 100;
    case International:
        return 500;
    default:
        return 0;
    }
}

class Passenger {
private:
    string name;
    DestinationType destination;
    int luggageCount;

public:
    Passenger(string n = "", DestinationType d = DomesticShort, int luggage = 0)
        : name(n), destination(d), luggageCount(luggage) {}

    string getName() const { return name; }
    DestinationType getDestination() const { return destination; }
    int getLuggageCount() const { return luggageCount; }
};

class Team {
private:
    string name;
    DestinationType destination;
    vector<Passenger> passengers;
    int capacity;

public:
    Team(string n = "", DestinationType d = DomesticShort, int c = 6)
        : name(n), destination(d), capacity(c) {}

    bool canAccept(const Passenger& passenger) const {
        return passenger.getDestination() == destination &&
            (int)passengers.size() < capacity;
    }

    bool addPassenger(const Passenger& passenger) {
        if (!canAccept(passenger)) {
            return false;
        }

        passengers.push_back(passenger);
        return true;
    }

    const vector<Passenger>& getPassengers() const {
        return passengers;
    }

    string getName() const {
        return name;
    }

    DestinationType getDestination() const {
        return destination;
    }
};

class TicketOffice {
public:
    double ticketPrice(const Passenger& passenger) const {
        int extraLuggage = passenger.getLuggageCount() - 2;
        if (extraLuggage < 0) {
            extraLuggage = 0;
        }

        return basePrice(passenger.getDestination()) + extraLuggage * 100;
    }

    double printTeamTickets(const Team& team) const {
        double total = 0;
        const vector<Passenger>& passengers = team.getPassengers();

        cout << "Team: " << team.getName() << " " << destinationName(team.getDestination()) << endl;
        for (int i = 0; i < (int)passengers.size(); ++i) {
            double price = ticketPrice(passengers[i]);
            cout << "  " << passengers[i].getName();
            cout << " luggage=" << passengers[i].getLuggageCount();
            cout << " price=" << price << endl;
            total += price;
        }

        return total;
    }
};

bool joinAnyTeam(vector<Team>& teams, const Passenger& passenger) {
    for (int i = 0; i < (int)teams.size(); ++i) {
        if (teams[i].addPassenger(passenger)) {
            return true;
        }
    }

    return false;
}

int main() {
    vector<Team> teams;
    teams.push_back(Team("Short-A", DomesticShort));
    teams.push_back(Team("Long-A", DomesticLong));
    teams.push_back(Team("World-A", International));

    vector<Passenger> passengers;
    passengers.push_back(Passenger("Alice", DomesticShort, 1));
    passengers.push_back(Passenger("Bob", DomesticLong, 3));
    passengers.push_back(Passenger("Cindy", International, 2));
    passengers.push_back(Passenger("David", International, 5));
    passengers.push_back(Passenger("Eva", DomesticShort, 4));

    for (int i = 0; i < (int)passengers.size(); ++i) {
        bool ok = joinAnyTeam(teams, passengers[i]);
        if (!ok) {
            cout << passengers[i].getName() << " cannot join a team" << endl;
        }
    }

    TicketOffice office;
    double income = 0;

    cout << fixed << setprecision(2);
    for (int i = 0; i < (int)teams.size(); ++i) {
        income += office.printTeamTickets(teams[i]);
    }

    cout << "Total income: " << income << endl;

    return 0;
}
