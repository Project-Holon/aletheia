/*
 * function: func_021EEED8
 * address:  0x021EEED8
 * packet:   pkt_021EEED8
 * region:   ov188
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02082BCC   0x02082BCC  arm
 *   func_0201AA14   0x0201AA14  thumb
 *   func_0201AA18   0x0201AA18  thumb
 *   func_0201AB28   0x0201AB28  thumb
 *   func_021EE920   0x021EE920  thumb
 *
 * Clear a 0x2A4-byte record, copy the pair of counts out of a and release
 *   each of the 0x70-byte subrecords through 0x21EE920.
 */
#include "../include/Obj10803.h"


typedef unsigned int u32;

extern void func_02082BCC(int, int, int);
struct Mon;
extern u32 func_0201AA14(void *p);
extern u32 func_0201AA18(void *);
extern void *func_0201AB28(void *p, u32 idx);
extern void func_021EE920(struct Mon *p, char *q);

void func_021EEED8(int a, char *p)
{
    int i;
    func_02082BCC((int)p, 0, 0x2A4);
    if (func_0201AA18((void *)a) == 0)
        return;
    ((struct Obj10803 *)p)->f0 = func_0201AA14((void *)a);
    ((struct Obj10803 *)p)->f2 = func_0201AA18((void *)a);
    for (i = 0; i < ((struct Obj10803 *)p)->f2; i++)
        func_021EE920((struct Mon *)((int)func_0201AB28((void *)a, i)), p + 4 + i * 0x70);
}
