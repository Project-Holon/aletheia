/*
 * function: func_021F5C20
 * address: 0x021F5C20
 * packet: pkt_ov215_021F5C20
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02040588 0x02040588 arm
 *   func_021F63CC 0x021F63CC thumb ov215
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_020056A0 0x020056A0 thumb
 *   func_021F5C08 0x021F5C08 thumb ov215
 *   func_021F5D4C 0x021F5D4C thumb ov215
 *   func_021F5DAC 0x021F5DAC thumb ov215
 *   func_021F6060 0x021F6060 thumb ov215
 *   func_021F6280 0x021F6280 thumb ov215
 *   func_0204047C 0x0204047C arm
 *   func_0207D63C 0x0207D63C arm
 *   func_02040EBC 0x02040EBC arm
 *   func_021F6720 0x021F6720 thumb ov215
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Context; struct GfFont;
extern void func_02040588(u32,u32);
extern char *func_021F63CC(u32,u16);
extern struct GfFont *func_0201D7EC(int,int,int,int,u32);
extern u32 func_0201C440(void *);
extern void *func_020056A0(u32,u32,u32);
extern void func_021F5C08(int,char *);
extern void func_021F5D4C(int,char *);
extern void func_021F5DAC(int,struct Context *);
extern void func_021F6060(int,char *);
extern void func_021F6280(int,u8 *);
extern void func_0204047C(int,u16);
extern void func_0207D63C(u32 *,u32,u32,int,int);
extern void func_02040EBC(u32,u32);
extern char *func_021F6720(u32,void *);
void func_021F5C20(int a,char *p)
{
    u8 i;
    for (i=0;i<=7;i++) func_02040588(i,0);
    *(void **)(p+4)=func_021F63CC(1,*(u16 *)p);
    *(void **)(p+8)=func_0201D7EC(23,0,0,0,*(u16 *)p);
    *(u32 *)(p+12)=func_0201C440((void *)(u32)*(u16 *)p);
    *(void **)(p+0x28)=func_020056A0((u32)func_021F5C08,(u32)p,1);
    func_021F5D4C(a,p);
    func_021F5DAC(a,(struct Context *)p);
    func_021F6060(a,p);
    func_021F6280(a,(u8 *)p);
    func_0204047C(0,2);
    func_0204047C(2,1);
    func_0204047C(1,0);
    func_0204047C(4,0);
    func_02040588(0,1);
    func_02040588(2,1);
    func_02040588(4,1);
    func_0207D63C((u32 *)0x04000050,1,47,0,0);
    func_02040EBC(0,0x4210);
    func_02040EBC(4,0);
    *(char **)(p+0x80)=func_021F6720(*(u16 *)p,*(void **)((u32)a+4));
}
