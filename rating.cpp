#include "rating.h"

Rating::Rating(int size, int maxStrSize) {
    this->size = size;
    this->surnames = new char * [this->size];
    this->subjects = new int * [this->size];
    for (int i = 0 ; i < this->size ; i++) {
        this->surnames[i] = new char [maxStrSize];
        this->subjects[i] = new int [5];
    }
    this->isContract = new int [this->size];
    this->averageRating = new float [this->size];
}

void Rating::resize() {

    char **resize_surnames = new char * [this->size * 2];
    int **resize_subjects = new int * [this->size * 2];

    int *resize_isContract = new int [this->size * 2];
    float *resize_averageRating = new float [this->size * 2];


    for (int i = 0 ; i < this->size ; i++) {
        resize_surnames[i] = new char [64];
        resize_subjects[i] = new int [5];

        for (int j = 0 ; j < 64 ; j++) {
            resize_surnames[i][j] = this->surnames[i][j];
            if (j < 5) resize_subjects[i][j] = this->subjects[i][j];
        }

        resize_isContract[i] = this->isContract[i];
        resize_averageRating[i] = this->averageRating[i];
    }
    for (int i = this->size ; i < this->size*2 ; i++) {
        resize_surnames[i] = new char [64];
        resize_subjects[i] = new int [5];
    }


    for (int i = 0 ; i < this->size ; i++) {
        delete [] this->surnames[i];
        delete [] this->subjects[i];
    }
    delete [] this->isContract;
    delete [] this->averageRating;


    this->size *= 2;
    this->surnames = resize_surnames;
    this->subjects = resize_subjects;
    this->isContract = resize_isContract;
    this->averageRating = resize_averageRating;
}

Rating::~Rating() {
    for (int i = 0 ; i < this->size ; i++) {
        delete []this->surnames[i];
        delete []this->subjects[i];
    }
    delete []this->isContract;
    delete []this->averageRating;
}
