#ifndef ALETHEIA_G_ITRSTATE_H
#define ALETHEIA_G_ITRSTATE_H
/* g_021DE6A0 (arm9) */
struct ItrState {
    void (*func)(void);
    unsigned long mask;
};
#endif
