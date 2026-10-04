/*
 * function: func_021BC97C
 * address:  0x021BC97C
 * packet:   pkt_021BC97C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)

 * Passes the byte at +4 and the two halfwords of the word at +0 on, then re-inits the object.
 */


typedef unsigned int   u32;
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_020307B0(void *p);

void func_021BC97C(char *p)
{
    unsigned int w;

    w = *(unsigned int *)p;
    func_0203FB44(*(unsigned char *)(p + 4), (unsigned short)w, (unsigned short)(w >> 16));
    func_020307B0((void *)((int)p));
}

