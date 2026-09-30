/*
 * function: func_021E1A44
 * address: 0x021E1A44
 * packet: pkt_ov119_021E1A44
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045B38 0x02045B38 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02045770 0x02045770 arm
 *   func_02045C04 0x02045C04 arm
 */
typedef signed short s16;
typedef unsigned short u16;
extern int func_02045B38(int,int,int,int);
extern int func_02018598(int);
extern void func_02045CAC(int,int,int);
extern void *func_02045770(int);
extern void func_0201C7A4(void *,s16,s16,void *,void *);
extern void func_02045C04(int);
void func_021E1A44(int a,int b,int x,int y,char *p)
{
    int s;
    s=func_02045B38(0,2,24,*(u16 *)(p+0x5f4));
    func_02045CAC(s,func_02018598(a),*(int *)(p+0x730));
    func_0201C7A4(func_02045770(b),x,y,*(void **)(p+0x730),*(void **)(p+0x728));
    func_02045C04(s);
}
