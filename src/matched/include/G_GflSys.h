#ifndef ALETHEIA_G_GFLSYS_H
#define ALETHEIA_G_GFLSYS_H
/* _GflUse (arm9) */
struct GflHeaps;
struct GflSys {
    void *unk00;
    unsigned int unk04;
    void (*unk08)(void *);
    unsigned int unk0C;
    struct GflHeaps *heaps;
    void *unk14;
};
#endif
