/*
 * function: func_021BD814
 * address:  0x021BD814
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203D7B0  0x0203D7B0  arm
 *   func_0203D7BC  0x0203D7BC  arm
 *
 * Two arm9 calls with a 0 argument, then two field stores; returns the second
 * argument.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void func_0203D7B0(int a);
extern void func_0203D7BC(int a);

typedef struct {
    char pad[0x1CC];
    u32 f1CC;
    char pad2[0x10];
    u32 f1E0;
} S;

int func_021BD814(S *s, int b)
{
    func_0203D7B0(0);
    func_0203D7BC(0);
    s->f1E0 = 0;
    s->f1CC = 0x91;

    return b;
}
