#ifndef ALETHEIA_G_MGR_H
#define ALETHEIA_G_MGR_H
/* g_ClactSystem (arm9) */
struct Bank;
struct RecA;
struct RecB;
struct Slot;
struct Mgr {
    unsigned char pad_0[0xEC];
    void *field_EC;
    unsigned short unk_f0;
    unsigned short unk_f2;
    unsigned int unk_f4;
    unsigned int unk_0f8;
    unsigned int unk_0fc;
    struct Bank *head;
    void *unk_104;
    void *unk_108;
    struct Slot *owner_slots;
    struct RecA *owner_slots2;
    struct RecB *tb;
    unsigned short owner_count;
    unsigned short owner_count2;
    unsigned short pool_count;
    unsigned char pad_120[0x4];
};
#endif
