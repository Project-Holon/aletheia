#ifndef ALETHEIA_G_ARPENTRY_H
#define ALETHEIA_G_ARPENTRY_H
/* g_021A8384 (arm9) */
struct ArpEntry {
    unsigned long ip;
    unsigned char mac[6];
    unsigned short when;
};
#endif
