/*
 * function: func_021C587C
 * address: 0x021C587C
 * packet: pkt_ov136_021C587C
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202C9B4 0x0202C9B4 thumb
 *   func_0202CA3C 0x0202CA3C thumb
 *   func_0202CAE4 0x0202CAE4 thumb
 *   func_0202CF84 0x0202CF84 thumb
 *   func_02082D44 0x02082D44 arm
 *   func_0202CB4C 0x0202CB4C thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed char s8;
extern void *func_0202C9B4(u32,u32,u32);
extern void func_0202CA3C(void *,u32,u32,u32,u32);
extern void func_0202CAE4(void *,int,int,int,int);
extern void *func_0202CF84(void *,u32);
extern void func_02082D44(void *,void *,u32);
extern void func_0202CB4C(void *,u32,s8,s8);
void func_021C587C(u8 *p)
{
    u32 i;
    void *first;
    **(void ***)(p+8) = func_0202C9B4(2,11,102);
    for(i=0;i<10;i++) func_0202CA3C(**(void ***)(p+8),i,2,14,4);
    func_0202CA3C(**(void ***)(p+8),10,1,14,4);
    func_0202CAE4(**(void ***)(p+8),0,155,40,1);
    first = func_0202CF84(**(void ***)(p+8),0);
    for(i=1;i<=10;i++) func_02082D44(first,func_0202CF84(**(void ***)(p+8),i),112);
    for(i=0;i<10;i++) func_0202CB4C(**(void ***)(p+8),i,(i%2)*16+1,(i/2)*4);
}
