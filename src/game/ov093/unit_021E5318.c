/*
 * file:     unit_021E5318.c
 * function: func_021E5318, func_021E5350
 * address:  0x021E5318
 * packet:   pkt_ov093_021E5318
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The callee's word result is a one-word struct (see
 * docs/idioms/a-one-word-struct-result-passed-by-value-costs-a-second-frame-word.md).
 *
 * symbols:
 *   d_021F25CC     0x021F25CC  data   ov093  a4
 *   BTLV_CORE_MakeSlotKind2Index  0x021E8940  thumb  ov093
 *   func_021B9A40  0x021B9A40  thumb  ov093
 *   func_021E556C  0x021E556C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef struct Word { u32 v; } Word;

extern Word BTLV_CORE_MakeSlotKind2Index(int k);
extern unsigned char func_021B9A40(unsigned int x);
extern void func_021E556C(int a, int b, int c, int d, int e, int f, Word g, int h);

void func_021E5318(int a, int b, int c, int d)
{
    Word t = BTLV_CORE_MakeSlotKind2Index(5);
    int e = func_021B9A40(c);
    func_021E556C(a, b, c, d, e, 1, t, 0x80);
}


extern int d_021F25CC[];
int *func_021E5350(int *p);

int *func_021E5350(int *p)
{
    *p = 1;
    return d_021F25CC;
}
