/*
 * function: func_021C6E18
 * address: 0x021C6E18
 * packet: pkt_ov136_021C6E18
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov136/mb_seq.c and filed here.
 *
 * symbols:
 *   func_021C7178 0x021C7178 thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;
int func_021C6E18(u8 *p);
int func_021C7178(u8 *p, u32 v);

int func_021C6E18(u8 *p)
{
    *(u32 *)(p + 0x28) = 0x1b;
    return func_021C7178(p, 1);
}
