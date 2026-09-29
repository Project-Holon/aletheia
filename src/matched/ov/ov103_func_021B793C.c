/*
 * function: func_021B793C
 * address:  0x021B793C
 * packet:   pkt_ov103_021B793C
 * region:   ov103
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B7C5C  0x021B7C5C  thumb  ov103
 *
 * evidence: func_021B7C5C is ov103's own code ("lsls r1, #2; adds r0, r1;
 * ldr r0, [r0, #0x10]; bx lr" after pool_021B7C58), inside ov103's window, so
 * only ov103 can be resident there when this pool word is used.  Its start is
 * seeded in layout/function_starts.txt from this pointer word, the only
 * reference; it attests as sole-ref/code from ov103's own listing.  The old
 * hint ov016 named a different overlay's function mapped over the address.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void func_021B7C5C(void *);
void func_021B793C(u8 *p) { func_021B7C5C(p + 0xcc); }
