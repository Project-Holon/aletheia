/*
 * function: func_02186480
 * address: 0x02186480
 * packet: pkt_ov023_02186480
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02186694 0x02186694 thumb ov023
 */
extern void func_02186694(char *);
void func_02186480(char *p)
{
    if (*(int *)(p + 0x9e70) != 0) {
        if (*(int *)(p + 0x178) != 0)
            func_02186694(p);
        *(int *)(p + 0x9e70) = 0;
    }
}
