#ifndef ALETHEIA_G_QUEUE_H
#define ALETHEIA_G_QUEUE_H
/* sVramTransferTaskQueue (arm9) */
struct Queue {
    void *unk_00;
    unsigned int capacity;
    unsigned char pad_8[0x8];
    signed int total;
};
#endif
