/*
 * function: func_021F32D8
 * address:  0x021F32D8
 * packet:   pkt_021F32D8
 * region:   ov194
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

int func_021F32D8(char *p, unsigned short *out)
{
    int s = *(int *)(p + 0xe8);
    if ((s == 1 || s == 2 || s == 9) && out != 0)
    {
        *out = *(unsigned short *)(p + 0xfc);
    }
    return *(int *)(p + 0xe8);
}
