/*
 * function: func_021C4044
 * address: 0x021C4044
 * packet: pkt_ov127_021C4044
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021C4564 0x021C4564 thumb ov127
 *   func_021C45AC 0x021C45AC thumb ov127
 *   func_021C435C 0x021C435C thumb ov127
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_021C4564(u8 *p, u32 a, u32 b, u32 heap);
extern void func_021C45AC(u8 *p, u32 heap);
extern void func_021C435C(u8 *, int, int, int, int, int);
void func_021C4044(u8 *p,int a,int b,int c,int d)
{
    int i;
    func_021C4564(p,a,c,d);
    func_021C45AC(p,d);
    for(i=0;i<16;i++)func_021C435C(p,i,a,b,d,1);
}
