/*
 * function: func_021E54EC
 * address:  0x021E54EC
 * packet:   pkt_ov093_021E54EC
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
 *   BTLV_CORE_MakeSlotKind1Empty  0x021E89C0  thumb  ov093
 *   func_021B9A50  0x021B9A50  thumb  ov093
 *   func_021E556C  0x021E556C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef struct Word { u32 v; } Word;

extern Word BTLV_CORE_MakeSlotKind1Empty(void);
extern unsigned char func_021B9A50(unsigned int x);
extern void func_021E556C(int a, int b, int c, int d, int e, int f, Word g, int h);

void func_021E54EC(int a, int b, int c, int d)
{
    Word t = BTLV_CORE_MakeSlotKind1Empty();
    int e = func_021B9A50(c);
    func_021E556C(a, b, c, d, e, 8, t, 0x9c);
}
