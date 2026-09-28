/*
 * function: ov208_func_021C52F0
 * address:  0x021C52F0
 * packet:   pkt_ov208_021C52F0
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The three ARM9 callees 0x0201BC3C, 0x0201BC78 and 0x0201BCEC were
 * unlabelled; seeds_3 labelled them and matched them in
 * src/matched/unit_0201BC3C.c, so every relocation now attests.
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_0201BC3C  0x0201BC3C  thumb
 *   func_0204ACEC  0x0204ACEC  arm
 *   func_0201BC78  0x0201BC78  thumb
 *   func_0201BCEC  0x0201BCEC  thumb
 *   func_0204AF28  0x0204AF28  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ov208Menu {
    u8  pad0[0x128];
    u32 arc;
    u32 res[2];
    u32 j;
    u32 k;
};

extern u32  func_020490F4(u32 id, u32 heap);
extern u32  func_0201BC3C(void);
extern u32  func_0204ACEC(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);
extern u32  func_0201BC78(void);
extern u32  func_0201BCEC(void);
extern u32  func_0204AF28(u32 a0, u32 a1, u32 a2, u32 a3);

void ov208_func_021C52F0(u16 *heap, struct Ov208Menu *p)
{
    p->arc = func_020490F4(7, *heap);
    p->j = func_0204ACEC(p->arc, func_0201BC3C(), 1, 0, *heap);
    p->k = func_0204AF28(p->arc, func_0201BC78(), func_0201BCEC(), *heap);
}
