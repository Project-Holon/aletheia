#ifndef ALETHEIA_G_VOTES_H
#define ALETHEIA_G_VOTES_H
/* _pBaseWork (arm9) */
struct Votes {
    unsigned short tag[8];
    unsigned char mask[8];
    unsigned char ready[8];
};
#endif
