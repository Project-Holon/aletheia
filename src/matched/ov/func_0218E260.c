/*
 * function: func_0218E260
 * address:  0x0218E260
 * packet:   pkt_0218E260
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_020493D4  0x020493D4  arm
 *   func_0204944C  0x0204944C  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09175.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct ArcFile;
extern u32 func_020493D4(struct ArcFile *arc, u32 member);
struct ArcFile;
extern void func_0204944C(struct ArcFile *, u32, u32, u32, void *);

void func_0218E260(void *a, void *b)
{
func_020493D4((struct ArcFile *)(((struct Obj09175 *)((u8 *)(a)))->f4), 0);
func_0204944C((struct ArcFile *)((struct Obj09175 *)((u8 *)(a)))->f4, 0, (44 * ((struct Obj09175 *)((u8 *)(a)))->f10), 44, b);
}

