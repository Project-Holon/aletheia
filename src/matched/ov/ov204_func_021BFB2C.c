/*
 * function: func_021BFB2C
 * address: 0x021BFB2C
 * packet: pkt_ov204_021BFB2C
 * region: ov204
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BFBC8 0x021BFBC8 thumb ov204
 */

extern void func_021BFBC8(char *, unsigned int);

int func_021BFB2C(char *p)
{
    switch (*(unsigned int *)(p + 28))
    {
    case 0: break;
    case 1:
        --*(unsigned int *)(p + 40);
        func_021BFBC8(p, *(unsigned int *)(p + 40));
        if (*(unsigned int *)(p + 40) == 50) return 1;
        break;
    case 2:
        ++*(unsigned int *)(p + 40);
        func_021BFBC8(p, *(unsigned int *)(p + 40));
        if (*(unsigned int *)(p + 40) == 70) return 1;
        break;
    case 3:
        --*(unsigned int *)(p + 40);
        func_021BFBC8(p, *(unsigned int *)(p + 40));
        if (*(unsigned int *)(p + 40) == 0) return 1;
        break;
    case 4:
        ++*(unsigned int *)(p + 40);
        func_021BFBC8(p, *(unsigned int *)(p + 40));
        if (*(unsigned int *)(p + 40) == 120) return 1;
        break;
    }
    return 0;
}
