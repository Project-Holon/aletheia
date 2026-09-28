/*
 * function: func_02028E80
 * address:  0x02028E80
 * packet:   pkt_02028DCC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_02028DB8  0x02028DB8  thumb
 *   _s32_div_f     0x0209C0A4  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Cmd {
    u32 unk00;
    u32 unk04;
    u16 unk08;
    u16 unk0A;
};

struct Sys {
    u8         pad_00[0x28];
    struct Cmd queue[10];
    u8         tail;
    u8         head;
};

extern u32 func_02028DB8(struct Sys *s);

void func_02028E80(struct Sys *s)
{
    s32 tail = s->tail;

    if (func_02028DB8(s) != 0) {
        s->queue[tail].unk00 = 0;
        s->tail = (tail + 1) % 10;
    }
}
