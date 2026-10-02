/*
 * function: func_021DD90C
 * address: 0x021DD90C
 * packet: pkt_ov119_021DD90C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: DIFF
 * symbols:
 *   d_021E76FC 0x021E76FC data a4
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   func_020452E8 0x020452E8 arm
 *   func_020450F0 0x020450F0 arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_02045770 0x02045770 arm
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { int a,b; } Pair;
extern const Pair d_021E76FC;
extern int func_021D8AA8(void *);
extern void func_020452E8(int);
extern int func_020450F0(u32,u8,u32,u32,u8,u8,u8);
extern void func_0201DD78(u32,u32,u32);
extern void func_02045CAC(int,int,int);
extern void *func_02045770(int);
extern void func_0201C7A4(void *,int,int,int,int);
extern void func_02045334(int);
extern void func_02045374(int);
extern void func_02041B6C(int);
void func_021DD90C(u8 *p,int i,int msg,int force)
{
    Pair t=d_021E76FC;
    int w;
    int *items;
    if(force==0) {
        if((p+i)[0x11e8]==3) return;
        if(p[0x11ea]==0) return;
        if(func_021D8AA8(p)==0) return;
    }
    if(*(int *)(p+i*4+0x5bc)) func_020452E8(*(int *)(p+i*4+0x5bc));
    items=(int *)(p+0x5bc);
    w=func_020450F0(3,((int *)&t)[i],16,12,2,5,0);
    items[i]=w;
    func_0201DD78(5,6,0);
    msg+=0x72;
    func_02045CAC(*(int *)(p+0x720),msg,*(int *)(p+0x730));
    func_0201C7A4(func_02045770(w),0,0,*(int *)(p+0x730),*(int *)(p+0x728));
    func_02045334(w);
    func_02045374(w);
    func_02041B6C(3);
    (p+i)[0x11e8]=3;
}
