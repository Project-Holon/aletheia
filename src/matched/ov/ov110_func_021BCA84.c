/*
 * function: func_021BCA84
 * address: 0x021BCA84
 * packet: pkt_ov110_021BCA84
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes zero alignment padding after return.
 * symbols:
 *   func_021BD348 0x021BD348 thumb ov110
 *   func_0204B98C 0x0204B98C arm
 */
typedef unsigned char u8;
extern void func_02028178(void *);
extern unsigned func_0204B98C(void *);
extern void func_021BD348(u8 *);
void func_021BCA84(u8 *p)
{
    int i;
    for (i=0;i<3;i++) if (*(void **)(p+0x64+i*4)) func_02028178(*(void **)(p+0x64+i*4));
    switch (*(unsigned *)(p+0x2c)) {
    case 0: break;
    case 1: *(unsigned *)(p+0x2c)=2;
    case 2: if (!func_0204B98C(*(void **)(p+0x28))) *(unsigned *)(p+0x2c)=3; break;
    case 3: *(unsigned *)(p+0x2c)=0; break;
    }
    func_021BD348(p);
}
