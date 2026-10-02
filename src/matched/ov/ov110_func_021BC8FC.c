/*
 * function: func_021BC8FC
 * address: 0x021BC8FC
 * packet: pkt_ov110_021BC8FC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: difference of stored fixed-point fields prevents shift factoring.
 * symbols:
 *   func_0207D658 0x0207D658 arm
 *   func_021BC964 0x021BC964 thumb ov110
 *   func_021B9BA4 0x021B9BA4 thumb ov110
 */
typedef unsigned char u8;
extern void func_0207D658(int,int,int);
extern void func_021BC964(void *, u8 *);
extern void *func_021B9BA4(void (*)(void *,u8 *),u8 *,int);
void func_021BC8FC(u8 *p,int a,int start,int end,int n)
{
    func_0207D658(0x4000050,a,start);
    *(int *)p=a;
    *(int *)(p+0x14)=n;
    *(int *)(p+8)=start<<12;
    *(int *)(p+0xc)=end<<12;
    *(int *)(p+0x10)=(*(int *)(p+0xc)-*(int *)(p+8))/n;
    *(int *)(p+0x18)=0;
    *(void **)(p+0x1c)=func_021B9BA4(func_021BC964,p,0);
}
