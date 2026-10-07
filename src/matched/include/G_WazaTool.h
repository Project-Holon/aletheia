#ifndef ALETHEIA_G_WAZATOOL_H
#define ALETHEIA_G_WAZATOOL_H
/* gWazaTool (arm9) */
struct Waza;
struct WazaTool {
    struct Waza **recs;
    unsigned short *vals;
    signed int count;
};
#endif
