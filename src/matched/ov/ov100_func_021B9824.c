/*
 * function: func_021B9824
 * address: 0x021B9824
 * packet: pkt_ov100_021B9824
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: alignment then separately filed follower func_021B9848.
 * symbols:
 *   func_02080D24 0x02080D24 arm
 */
extern unsigned func_02080D24(void);
void func_021B9824(int a,int b)
{
 *(unsigned *)(a+0x2e8) |= 1 << b;
 if(func_02080D24()>=2) *(int *)(a+0x2ec)=1;
}
