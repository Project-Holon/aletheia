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
typedef unsigned int   u32;
extern u32 func_0201AA50(void *p);
int func_021B9AB4(unsigned a)
{
 int x; int y;
 x=func_0201AA50((void *)(*(int *)(*(unsigned *)(a+0x244)+8)));
 y=func_0201AA50((void *)(*(int *)(*(unsigned *)(a+0x244)+12)));
 if(x>y) return y;
 return x;
}
