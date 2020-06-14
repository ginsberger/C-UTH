
#ifndef UNDERTHEHOODCC_CPP2C_ENCAPSULATION_DEFS_H
#define UNDERTHEHOODCC_CPP2C_ENCAPSULATION_DEFS_H


typedef struct Box Box;


void BoxDefaultConstractor(struct Box* box);
void BoxConstractorDouble(struct Box* box, double dim);
void BoxConstractorDoubleDoubleDouble(struct Box* box,double l, double w, double h);
void BoxDestractor(struct Box* box);
double BoxGetWidth(const struct Box* box);
double BoxGetLength(const struct Box* box);
double BoxGetHeight(const struct Box* box);
double BoxGetVolume(const struct Box* box);
Box* BoxOperatorMultipleAssignment(struct Box* box, double mult);




#endif //UNDERTHEHOODCC_CPP2C_ENCAPSULATION_DEFS_H

