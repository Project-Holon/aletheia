/*
 * function: sub_0200F698
 * address:  0x0200F698
 * packet:   pkt_0200F17C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     wave 16: promoted.  0x02156B70 is the unlabelled ov009 leaf matched
 *           in src/matched/func_02156B70.c (ov009/pkt_02156B70); it attests as
 *           `matched, overlay` under the ov009 hint.
 *
 * symbols:
 *   func_0203D29C  0x0203D29C  arm
 *   func_02156B70  0x02156B70  thumb  ov009
 *   func_02005F24  0x02005F24  thumb
 *
 * Forwards its two arguments to func_02005F24 unless both func_0203D29C()
 * and func_02156B70() report nonzero; func_0203D29C is always called,
 * func_02156B70 only when the first call reports zero (a genuine
 * short-circuit, not an independent second check).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200F698.c \
 *       --func sub_0200F698 --addr 0x0200F698 --cc 1.1p1
 */

typedef unsigned int u32;

extern u32  func_0203D29C(void);
typedef signed short   s16;
extern s16 func_02156B70(void);
extern void func_02005F24(u32 a0, u32 a1);

void sub_0200F698(void *a, void *b)
{
    if (func_0203D29C() == 0 || func_02156B70() == 0) {
        func_02005F24((u32)a, (u32)b);
    }
}
