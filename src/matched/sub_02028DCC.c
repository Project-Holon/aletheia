/*
 * function: func_02028DCC
 * address:  0x02028DCC
 * packet:   pkt_02028DCC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   _s32_div_f  0x0209C0A4  arm
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
    u8          pad_00[0x28];
    struct Cmd  queue[10];
    u8          tail;
    volatile u8 head;
};

u8 func_02028DCC(struct Sys *s, u32 target)
{
    s32 curr = s->tail;
    u32 count = 0;

    if (curr != s->head) {
        do {
            if (s->queue[curr].unk00 == target) {
                count++;
            }
            curr = (curr + 1) % 10;
        } while (curr != s->head);
    }
    return count;
}
