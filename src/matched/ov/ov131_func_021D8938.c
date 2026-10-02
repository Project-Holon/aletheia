/*
 * function: func_021D8938
 * address: 0x021D8938
 * packet: pkt_ov131_021D8938
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note (2026-10-02): the func_021D9440 call is inside the loop (its arg is i), so &d/&g is recomputed
 *   per group; hi/lo are enum locals so (0x19<<22)+(2<<16) is not folded.
 * symbols:
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021D9440 0x021D9440 thumb ov131
 *   func_02043754 0x02043754 arm
 *   func_021DBAD0 0x021DBAD0 thumb ov131
 *   func_021DBCA4 0x021DBCA4 thumb ov131
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Desc {u16 x,y,z;u8 kind,flag;};
enum E {E_0};
struct Grid {void *f0;u16 f4;s16 f6;u32 f8;u32 f12;u8 f16;u8 f17;u16 f18;u32 f20;};
extern void *func_0204B294(u32,u32,u32,u32,void *,u32,u16);
extern void func_0204B3DC(void *,int);
extern s16 func_021D9440(u8 *,u32);
extern void *func_02043754(u32,int,int,int,int);
extern void *func_021DBAD0(void *,struct Grid *);
extern void func_021DBCA4(void *,int);
void func_021D8938(u8 *a,u8 *p)
{
    struct Desc d;
    struct Grid g;
    enum E hi,lo;
    u32 base;
    u8 i;
    d.x=0;d.y=0;d.kind=10;d.flag=0;d.z=0;
    *(void **)(p+0x54)=func_0204B294(*(u32 *)(a+0x174),*(u32 *)(a+0xf8),*(u32 *)(a+0xc4),*(u32 *)(a+0x12c),&d,0,*(u16 *)a);
    func_0204B3DC(*(void **)(p+0x54),0);
    g.f4=8;
    g.f8=*(u32 *)(a+0xb8);
    g.f12=0;
    g.f16=0;
    hi=0x19;
    lo=2;
    g.f17=lo;
    g.f18=0;
    g.f20=0;
    base=(hi<<22)+(lo<<16);
    for(i=0;i<10;i++){
        u8 *e;
        g.f6=func_021D9440(p,i);
        e=p+i*0x14;
        g.f0=*(void **)(e+0x7c)=func_02043754(base-(i+1)*0x660,0x11,3,0x20,*(u16 *)a);
        *(void **)(e+0x80)=func_021DBAD0(*(void **)(p+0x6c),&g);
        func_021DBCA4(*(void **)(e+0x80),0);
    }
}
