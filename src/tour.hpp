#ifndef TOUR_HPP
#define TOUR_HPP

class Tour {

    static const int MAX_TOUR_SIZE = 21;

    private:
        int tourArray[MAX_TOUR_SIZE];
        int numCitiesInTour;
        double calculateTourCost();

    public:
        Tour(int permutation[], int numCitiesInTour);
        double getTourCost();
        void setTourCity(int cityIndex, int city);
        int getTourCity(int cityIndex);
        
};

#endif