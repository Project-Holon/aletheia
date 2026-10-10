/*
 * function: func_021733C8
 * address: 0x021733C8
 * packet: pkt_ov012_021733C8
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov012/union_comm.c and filed here.
 */

typedef unsigned char u8;
typedef unsigned int  u32;
typedef struct { u8 pad[0x288a]; u8 f : 1; } W;
int func_021733C8(u32 a, u32 b, W *p);

int func_021733C8(u32 a, u32 b, W *p)
{
    if (p->f == 1) {
        if (a == 0x14 || b == 0x14)
            return 0;
        if (a == b)
            return 1;
        return 0;
    }
    if (b >= 0x14 && b <= 0x1b)
        return 1;
    return 0;
}
