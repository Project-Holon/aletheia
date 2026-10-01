/*
 * function: func_0217D244
 * address: 0x0217D244
 * packet: pkt_ov176_0217D244
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding follow.
 * symbols:
 *   func_021E5548 0x021E5548 thumb ov177
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200BAC8 0x0200BAC8 thumb
 *   func_021E7E3C 0x021E7E3C thumb ov177
 */
extern int func_021E5548(int);
extern int func_02012EBC(int);
extern int func_0200BAC8(int);
extern int func_021E7E3C(int,int,int,int,int,int,unsigned short);
void func_0217D244(char *p)
{
    int a;
    if (*(int *)(p + 0x18) == 0) {
        a = func_021E5548(*(int *)(p + 0x1B4));
        *(int *)(p + 0x18) = func_021E7E3C(func_0200BAC8(func_02012EBC(*(int *)(p + 0x1B8))), a,
            *(int *)(p + 0x1B0), *(int *)(p + 0x28), *(int *)(p + 0x1AC), *(int *)(p + 0x24), *(unsigned short *)(p + 0x1C8));
    }
}
