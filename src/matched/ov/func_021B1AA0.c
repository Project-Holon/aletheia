/*
 * function: func_021B1AA0
 * address:  0x021B1AA0
 * packet:   pkt_021B1AA0
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

void func_021B1AA0(char *p, unsigned short v)
{
    *(unsigned short *)(p + 0x68) = v;
    *(int *)(p + 0x64) = 0x00010001;
    *(int *)(p + 0x60) = 0;
    *(int *)(p + 0x5c) = 0;
}
