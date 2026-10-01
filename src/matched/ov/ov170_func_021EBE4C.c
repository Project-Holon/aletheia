/*
 * function: func_021EBE4C
 * address: 0x021EBE4C
 * packet: pkt_ov170_021EBE4C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 */
extern void func_0204A8D4(int);
extern void func_0204ADA4(int);
extern void func_0204AFD8(int);
void func_021EBE4C(char *p)
{
    unsigned i;
    for (i = 0; i < 0x45; i++)
        if (*(int *)(p + i * 4 + 0x9FF4) != -1)
            func_0204A8D4(*(int *)(p + i * 4 + 0x9FF4));
    for (i = 0; i < 0xB; i++)
        if (*(int *)(p + i * 4 + 0xA108) != -1)
            func_0204ADA4(*(int *)(p + i * 4 + 0xA108));
    for (i = 0; i < 0xC; i++)
        if (*(int *)(p + i * 4 + 0xA134) != -1)
            func_0204AFD8(*(int *)(p + i * 4 + 0xA134));
}
