/*
 * function: func_021F7FAC
 * address: 0x021F7FAC
 * packet: pkt_ov112_021F7FAC
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F4EB4 0x021F4EB4 thumb ov112
 *   table 0x020A1B38 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef struct { u16 count, pad; int index; } Tail;
extern s16 table[];
extern void func_020061F8(int);
extern void func_021F4EB4(int, int, s16, s16);
void func_021F7FAC(char *p, char *q) {
    Tail *t = (Tail *)(q + 0xf0);
    u16 angle = ((int)t->count << 11) % 65536;
    t->count++;
    if (t->count >= 0xb4) {
        *(int *)(q + 0x104) = 0;
        *(u8 *)(p + 0x43c) -= 1;
        if (*(u8 *)(p + 0x43c) == 0) func_020061F8(2);
        return;
    }
    func_021F4EB4(*(int *)(p + 0x10), *(int *)(q + 0x84 + t->index * 4),
                  table[(angle >> 4) * 2] / 8 + 1024,
                  table[(angle >> 4) * 2 + 1] / 8 + 1024);
}
