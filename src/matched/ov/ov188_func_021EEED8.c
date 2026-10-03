/*
 * function: func_021EEED8
 * address:  0x021EEED8
 * packet:   pkt_021EEED8
 * region:   ov188
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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


typedef unsigned int u32;

extern void func_02082BCC(int, int, int);
extern int func_0201AA14(int);
extern int func_0201AA18(int);
extern void *func_0201AB28(void *p, u32 idx);
extern void func_021EE920(int, char *);

void func_021EEED8(int a, char *p)
{
    int i;
    func_02082BCC((int)p, 0, 0x2A4);
    if (func_0201AA18(a) == 0)
        return;
    *(unsigned short *)p = func_0201AA14(a);
    *(unsigned short *)(p + 2) = func_0201AA18(a);
    for (i = 0; i < *(unsigned short *)(p + 2); i++)
        func_021EE920((int)func_0201AB28((void *)a, i), p + 4 + i * 0x70);
}
