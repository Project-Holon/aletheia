/*
 * function: func_021BFAE8
 * address: 0x021BFAE8
 * packet: pkt_ov204_021BFAE8
 * region: ov204
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */

void func_021BFAE8(char *p, unsigned int v)
{
    *(unsigned int *)(p + 28) = v;
    *(unsigned int *)(p + 32) = 0;
    switch (v)
    {
    case 0:
        *(unsigned int *)(p + 40) = 60;
        *(unsigned int *)(p + 28) = 1;
        break;
    case 1: *(unsigned int *)(p + 40) = 70; break;
    case 2: *(unsigned int *)(p + 40) = 50; break;
    case 3: *(unsigned int *)(p + 40) = 50; break;
    case 4: *(unsigned int *)(p + 40) = 70; break;
    }
}
