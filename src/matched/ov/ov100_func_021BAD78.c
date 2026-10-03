/*
 * function: func_021BAD78
 * address: 0x021BAD78
 * packet: pkt_ov100_021BAD78
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_02027858 0x02027858 thumb
 *   func_02041B6C 0x02041B6C arm
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021BB058 0x021BB058 thumb ov100
 */
typedef unsigned char u8;
extern int func_020279E8(int);
extern u8 func_02027A04(const u8 *);
extern void func_02027858(int),func_02041B6C(int);
extern void func_021B95B8(u8 *,unsigned);
extern void func_021BB058(int a);
void func_021BAD78(unsigned a)
{
 if(func_020279E8(*(int *)(a+0xcc0))!=0) {
  func_02027A04(*(const u8 **)(a+0xcc0));
  func_02027858(*(int *)(a+0xcc0));
  *(unsigned *)(a+0xcc0)=0;
  func_02041B6C(6);
  func_021B95B8((u8 *)a,(unsigned)func_021BB058);
 }
}
