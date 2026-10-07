#ifndef ALETHEIA_G_CPSFRAGTABLE_H
#define ALETHEIA_G_CPSFRAGTABLE_H
/* g_021A8A64 (arm9) */
struct CPSFragTable {
    unsigned int ipfrom;
    unsigned short count;
    unsigned short id;
    unsigned short last;
    unsigned short size;
    unsigned short from[8];
    unsigned short end[8];
    unsigned int time;
    unsigned char *data;
    unsigned char *buf;
};
#endif
