/*
 * function: func_02193BE4
 * address:  0x02193BE4
 * packet:   pkt_02193BE4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * 
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_02186770 (0x02186770) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_02193EB4  0x02193EB4  thumb  ov021
 *   func_02193F34  0x02193F34  thumb  ov021
 *   func_02186770  0x02186770  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int func_02186770(u8 *);
struct V;
extern void func_02193EB4(struct V *v);
extern u8 *func_02193F34(void *, u32);

int func_02193BE4(void *a, u32 b)
{
func_02193EB4(a);
return func_02186770((func_02193F34(a, b) + 52));
}

