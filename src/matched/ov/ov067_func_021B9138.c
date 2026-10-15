/*
 * function: FRAME_LIST_ClearBgRows
 * address:  0x021B9138
 * packet:   pkt_ov067_021B9138
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BG_SYS_SetTileEntry  0x02041300  arm
 *   func_02041B6C  0x02041B6C  arm
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    u8 f4;
    u8 f5;
};

extern void BG_SYS_SetTileEntry(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern void func_02041B6C(u32 bit);

void FRAME_LIST_ClearBgRows(struct S *p, u32 a1, s8 a2)
{
    u32 j;

    for (j = 0; j < p->f5; j++) {
        if (a2 < 0)
            a2 += 0x20;
        else if (a2 >= 0x20)
            a2 -= 0x20;
        BG_SYS_SetTileEntry(a1, 0, p->f2, (u8)a2, p->f4, 1, 0);
        a2++;
    }
    func_02041B6C(a1);
}
