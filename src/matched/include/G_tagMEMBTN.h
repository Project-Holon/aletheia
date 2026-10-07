#ifndef ALETHEIA_G_TAGMEMBTN_H
#define ALETHEIA_G_TAGMEMBTN_H
/* g_021DE508 (arm9) */
struct tagMEMBTN {
    void *cellButton[2];
    void *cellBack;
    void *task;
    void *release;
    unsigned short count;
    signed char input;
    unsigned char kind;
    unsigned char disable;
    unsigned char end;
};
#endif
