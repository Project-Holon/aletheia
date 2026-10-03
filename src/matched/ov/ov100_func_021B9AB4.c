/*
 * function: func_021B9AB4
 * address: 0x021B9AB4
 * packet: pkt_ov100_021B9AB4
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201AA50 0x0201AA50 thumb
 */
extern int func_0201AA50(int);
int func_021B9AB4(unsigned a)
{
 int x; int y;
 x=func_0201AA50(*(int *)(*(unsigned *)(a+0x244)+8));
 y=func_0201AA50(*(int *)(*(unsigned *)(a+0x244)+12));
 if(x>y) return y;
 return x;
}
