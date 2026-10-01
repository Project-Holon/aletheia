/*
 * function: func_0217D1C8
 * address: 0x0217D1C8
 * packet: pkt_ov176_0217D1C8
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding follow.
 * symbols:
 *   func_021E5548 0x021E5548 thumb ov177
 *   func_0200B078 0x0200B078 thumb
 *   func_021E7520 0x021E7520 thumb ov177
 */
extern int func_021E5548(int);
extern int func_0200B078(int,int);
extern int func_021E7520(int,int,int,int,int,int,int,int,int,int,unsigned short);
void func_0217D1C8(char *p, int value)
{
    int a;
    int b;
    if (*(int *)(p + 0x14) == 0) {
        a = func_021E5548(*(int *)(p + 0x1B4));
        b = func_0200B078(*(int *)(p + 0x38), 11);
        *(int *)(p + 0x14) = func_021E7520(value, a, *(int *)(p + 0x1B0), *(int *)(p + 0x1A8),
            *(int *)(p + 0x1AC), *(int *)(p + 0x24), *(int *)(p + 0x2C), 1, 0, b, *(unsigned short *)(p + 0x1C8));
    }
}
