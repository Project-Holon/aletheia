/*
 * function: func_021DCE14
 * address: 0x021DCE14
 * packet: pkt_ov170_021DCE14
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045B38 0x02045B38 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201C450 0x0201C450 thumb
 *   func_020457B0 0x020457B0 arm
 */
extern void *func_02045B38(unsigned,unsigned,unsigned,unsigned);
extern void *func_0201D7EC(unsigned,unsigned,unsigned,unsigned,unsigned);
extern void *func_0201EC64(unsigned);
extern void *func_0201C450(unsigned short,unsigned);
extern void *func_020457B0(unsigned,unsigned);
#define PTR(p,n) (*(void **)(*(char **)((p)+0x2c)+(n)))
void func_021DCE14(char *p)
{
    PTR(p,0x80) = func_02045B38(0,2,9,0x4c);
    PTR(p,0x78) = func_0201D7EC(0x17,0,1,0,0x4c);
    PTR(p,0x7c) = func_0201D7EC(0x17,3,0,0,0x4c);
    PTR(p,0x84) = func_0201EC64(0x4c);
    PTR(p,0x8c) = func_0201C450(0x800,0x4c);
    PTR(p,0x88) = func_020457B0(0x400,0x4c);
}
