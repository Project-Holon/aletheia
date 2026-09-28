/*
 * function: func_0200E06C
 * address:  0x0200E06C
 * packet:   pkt_0200E024
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

extern void func_0203F37C(void *p, int off, int v);
void func_0200E06C(char *p)
{
    func_0203F37C(p, 0x84c,
        *(unsigned short *)(p + 0x84c) + (*(unsigned short *)(p + 0x84e) << 16));
    *(unsigned short *)(p + 0x84e) = 0;
}
