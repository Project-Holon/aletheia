/*
 * function: func_021E552C
 * address:  0x021E552C
 * packet:   pkt_ov093_021E552C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_CORE_MakeSlotKind2Index  0x021E8940  thumb  ov093
 *   func_021B9A40  0x021B9A40  thumb  ov093
 *   func_021E556C  0x021E556C  thumb  ov093
 *   func_021E3C5C  0x021E3C5C  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct { u32 v; } Word;

extern Word BTLV_CORE_MakeSlotKind2Index(int v);
extern unsigned char func_021B9A40(unsigned int x);
extern void func_021E556C(int a, int b, int c, int d, u8 e, int f, Word g, u16 h);
extern void func_021E3C5C(void *a, int b, int c);

void func_021E552C(int a, int b, int c, int d)
{
    Word t;

    t = BTLV_CORE_MakeSlotKind2Index(1);
    func_021E556C(a, b, c, d, func_021B9A40(c), 9, t, 0xa0);
    func_021E3C5C((void *)b, c, 1);
}
