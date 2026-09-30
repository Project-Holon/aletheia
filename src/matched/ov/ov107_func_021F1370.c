/*
 * unit: yes
 * function: func_021F1370,func_021F13AC
 * address: 0x021F1370
 * packet: pkt_ov107_021F1370
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203996C 0x0203996C arm
 *   func_0203D1B4 0x0203D1B4 arm
 *   func_0203D3F8 0x0203D3F8 arm
 */
typedef unsigned short u16;
extern void *func_0203996C(int);
extern int func_0203D1B4(void *);
extern int func_0203D3F8(void *,int,int,int,void *,int,int,int);
int func_021F1370(void *unused,void *p)
{
    void *obj;
    obj=func_0203996C(255);
    if(func_0203D1B4(obj)<2) return 0;
    return func_0203D3F8(obj,1,0x401,8,p,1,0,1);
}
void func_021F13AC(int a,int b,int c,char *p)
{
    *(u16 *)(p+0x18)=(*(u16 *)(p+0x18)&~1)|1;
}
