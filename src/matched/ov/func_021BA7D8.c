/*
 * function: func_021BA7D8
 * address:  0x021BA7D8
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BA7CC  0x021BA7CC  thumb  ov099
 *   func_021BA7D4  0x021BA7D4  thumb  ov099
 *   func_0203A574  0x0203A574  arm
 *
 * Plays the 0x0A00 sound with the two constants and the block.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern u8 *func_021BA7CC(void);
extern int func_021BA7D4(void);
extern void func_0203A574(u32 a, u32 b, u32 c, u32 d);

void func_021BA7D8(void *p)
{
    func_0203A574(0x0A00, (u32)func_021BA7CC(), func_021BA7D4(), (u32)p);
}
