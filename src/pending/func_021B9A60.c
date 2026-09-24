/*
 * function: func_021B9A60
 * address:  0x021B9A60
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 *
 * symbols:
 *   func_021C49A4  0x021C49A4  thumb  ov127
 *   func_021C4A8C  0x021C4A8C  thumb  ov127
 * Two ov127 calls, the second on the first one's answer.
 *
 * NOT EXACT.  MATCH: 16 bytes, the call sequence and the first relocation are
 * right; the second target 0x021C4A8C has no witness.  It is not a `func_` label
 * in any overlay listing, yet nine overlays overlap the address (ov016, ov021,
 * ov093, ov111, ov114, ov127, ov136, ov172, ov208), so a region hint cannot name
 * one either.  It turns EXACT as soon as 0x021C4A8C is labelled or matched.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_021B9A60.c --func func_021B9A60 --addr 0x021B9A60 \n    --region ov099 --thumb --cc dsi/1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void *func_021C49A4(void *a, int b);
extern void func_021C4A8C(void *a);

void func_021B9A60(char *p)
{
    func_021C4A8C(func_021C49A4(*(void **)p, 6));
}
