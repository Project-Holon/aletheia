/*
 * function: func_021BCF9C
 * address:  0x021BCF9C
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BA828  0x021BA828  thumb  ov099
 *
 * Runs the setup for selector 0x61 and stamps it 0x1CC bytes in.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void func_021BA828(void *p);

int func_021BCF9C(char *p, int v)
{
    func_021BA828(p);
    *(u32 *)(p + 0x1CC) = 0x61;
    return v;
}
