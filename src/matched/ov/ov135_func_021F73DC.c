/*
 * function: func_021F73DC
 * address: 0x021F73DC
 * packet: pkt_ov135_021F73DC
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F798C 0x021F798C thumb ov135
 *   func_021F75C0 0x021F75C0 thumb ov135
 *   func_021FFFE8 0x021FFFE8 thumb ov135
 *   func_021F76D8 0x021F76D8 thumb ov135
 *   func_021F777C 0x021F777C thumb ov135
 *   func_021F7878 0x021F7878 thumb ov135
 *   func_0202208C 0x0202208C thumb
 *   func_021F9254 0x021F9254 thumb ov135
 *   func_021F81C8 0x021F81C8 thumb ov135
 *   func_021F8358 0x021F8358 thumb ov135
 *   func_021F9890 0x021F9890 thumb ov135
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { void *a,*b,*obj,*d,*e,*f,*g,*h,*i; u32 j,k,l; } Init;
extern void func_021F798C(u8 *);
extern void func_021F75C0(void);
extern void func_021FFFE8(u8 *,u32,u32);
extern void func_021F76D8(void *);
extern void func_021F777C(void *);
extern void func_021F7878(u8 *);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern void func_021F9254(u8 *);
extern void func_021F81C8(void *,void *,void *,void *,int,int,int,void *);
extern void func_021F8358(void *,void *,void **,void *,void *,void *);
extern void *func_021F9890(Init *,u32,u32);
int func_021F73DC(u8 *p)
{
    Init init;
    func_021F798C(p);
    func_021F75C0();
    func_021FFFE8(p,0,0);
    func_021F76D8(p);
    func_021F777C(p);
    func_021F7878(p);
    func_0202208C((void *)3,1,1,0,6,1,0x48);
    func_021F9254(p);
    func_021F81C8(*(void **)(p+0xB6C),*(void **)(p+0xB70),*(void **)(p+0xB68),p+0xD90,0,3,-1,p+0xFA0);
    func_021F8358(*(void **)(p+0xB6C),*(void **)(p+0xB68),(void **)(p+0xD9C),*(void **)(p+0xCC),p+0xB4C,p+0xFA0);
    init.a=p+0xD50;
    init.b=p+0xDD4;
    init.obj=*(void **)(p+0xBF8);
    init.d=*(void **)(p+0xD2C);
    init.e=*(void **)(p+0xD30);
    init.f=0;
    init.g=*(void **)(p+0xB6C);
    init.h=*(void **)(p+0xB70);
    init.i=*(void **)(p+0xB7C);
    init.j=*(u32 *)(*(u8 **)p+0x10);
    init.k=*(u32 *)(*(u8 **)(p+0xE00)+0x14);
    init.l=*(u32 *)(*(u8 **)p+0x20);
    *(void **)(p+0xDE4)=func_021F9890(&init,2,0);
    *(u32 *)(p+0x28)=0;
    *(u32 *)(p+0x12E4)=0;
    return 1;
}
