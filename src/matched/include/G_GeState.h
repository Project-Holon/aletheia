#ifndef ALETHEIA_G_GESTATE_H
#define ALETHEIA_G_GESTATE_H
/* gNnsG3dGeState (arm9) */
struct GxList;
struct GeState {
    struct GxList *list;
    unsigned int busy;
    unsigned int f8;
};
#endif
