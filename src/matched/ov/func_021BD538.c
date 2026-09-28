/*
 * function: func_021BD538
 * address:  0x021BD538
 * packet:   pkt_021BD538
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)

 * Releases +8, +4 and +0, passes the pair at +0x10 on and clears the 0x14-byte object.
 */


extern void func_0204AFD8(int);
extern void func_0204A8D4(int);
extern void func_0204ADA4(int);
extern void func_0203FB44(int, unsigned short, unsigned short);
extern void func_02082BCC(int, int, int);

void func_021BD538(char *p)
{
    unsigned int w;

    func_0204AFD8(*(int *)(p + 8));
    func_0204A8D4(*(int *)(p + 4));
    func_0204ADA4(*(int *)p);
    w = *(unsigned int *)(p + 0x10);
    func_0203FB44(*(int *)(p + 0xc), (unsigned short)w, (unsigned short)(w >> 16));
    func_02082BCC((int)p, 0, 0x14);
}

