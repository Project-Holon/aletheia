/*
 * function: func_0202B454
 * address:  0x0202B454
 * packet:   pkt_0202B454
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

void func_0202B454(char *p)
{
    int i;
    *(unsigned short *)(p + 0x1c) = 0xffff;
    for (i = 0; i < 4; i++) {
        *(unsigned short *)(p + i * 2 + 0x20) = 0;
        *(unsigned short *)(p + i * 2 + 0x28) = 0x100;
        *(unsigned short *)(p + i * 2 + 0x30) = 0;
    }
}
