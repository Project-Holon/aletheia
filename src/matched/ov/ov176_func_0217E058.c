/*
 * function: func_0217E058
 * address:  0x0217E058
 * packet:   pkt_0217E058
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203CD98  0x0203CD98  arm
 *   func_0203A5E4  0x0203A5E4  arm
 *   func_020307B0  0x020307B0  arm
 */

extern int func_0203CD98(void);
typedef unsigned int   u32;
extern void func_0203A5E4(u32 key);
extern void func_020307B0(void *p);

void func_0217E058(int *p)
{
    if (func_0203CD98())
        func_0203A5E4(0x1f00);
    func_020307B0(p);
}
