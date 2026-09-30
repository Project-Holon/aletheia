/*
 * function: func_021F7A98
 * address: 0x021F7A98
 * packet: pkt_ov112_021F7A98
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
extern void func_020061F8(int);
typedef struct { u16 count, pad; int index; } Tail;
void func_021F7A98(char *p, char *q) {
    Tail *tail = (Tail *)(q + 0xf0);
    s16 *v = *(s16 **)(q + 0xa8 + tail->index * 4);
    v[1] += 0x1000;
    tail->count += 1;
    if (tail->count >= 0xc0) {
        *(int *)(q + 0x104) = 0;
        *(u8 *)(p + 0x43c) -= 1;
        if (*(u8 *)(p + 0x43c) == 0) func_020061F8(2);
    }
}
