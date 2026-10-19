/*
 * function: WORLDTRADE_SEARCH_ScrollBgs
 * address:  0x021FF50C
 * packet:   pkt_021FF50C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_ChangeScrollImmediate  0x02040618  arm
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0xD3C];
    int scroll;
} Work;

extern void BG_SYS_ChangeScrollImmediate(u32 layer, u32 a, u32 b);

void WORLDTRADE_SEARCH_ScrollBgs(Work *p)
{
    BG_SYS_ChangeScrollImmediate(0, 3, p->scroll);
    BG_SYS_ChangeScrollImmediate(1, 3, p->scroll);
    BG_SYS_ChangeScrollImmediate(2, 3, p->scroll);
    BG_SYS_ChangeScrollImmediate(3, 3, p->scroll);
    BG_SYS_ChangeScrollImmediate(4, 3, -p->scroll);
    BG_SYS_ChangeScrollImmediate(5, 3, -p->scroll);
    BG_SYS_ChangeScrollImmediate(6, 3, -p->scroll);
    BG_SYS_ChangeScrollImmediate(7, 3, -p->scroll);
}
