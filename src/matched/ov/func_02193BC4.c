/*
 * function: func_02193BC4
 * address:  0x02193BC4
 * packet:   pkt_02193BC4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_02186764 (0x02186764) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_02193EB4  0x02193EB4  thumb  ov021
 *   func_02193EFC  0x02193EFC  thumb  ov021
 *   func_02186764  0x02186764  thumb
 *   func_02193EE8  0x02193EE8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_02186764(u8 *);
extern void func_02193EB4(void *);
extern void func_02193EE8(void *);
extern u8 *func_02193EFC(void *, u32);

void func_02193BC4(void *a, u32 b)
{
func_02193EB4(a);
func_02186764((func_02193EFC(a, b) + 52));
func_02193EE8(a);
}

