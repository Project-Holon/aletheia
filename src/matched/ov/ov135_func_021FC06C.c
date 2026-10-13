/*
 * function: func_021FC06C
 * address: 0x021FC06C
 * packet: pkt_ov135_021FC06C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 recoup: WIPE_SYS_Start declared with an int return (first-check lever). With void the
 *   literal 1 stayed in r4 for the stack store, r1, r2 and the return (4 B differ); with int the
 *   constants are rematerialised as in the original. The other callees stay void as in their matched files.
 * symbols:
 *   func_0200ADB4 0x0200ADB4 thumb
 *   POKE_TOOL_Dummy 0x020185F0 thumb
 *   func_020084F4 0x020084F4 thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   func_021FC528 0x021FC528 thumb ov135
 *   func_021FC1C0 0x021FC1C0 thumb ov135
 *   func_021FFFE8 0x021FFFE8 thumb ov135
 *   func_021FC2C0 0x021FC2C0 thumb ov135
 *   func_021FC3E0 0x021FC3E0 thumb ov135
 *   func_021FC360 0x021FC360 thumb ov135
 *   func_021FC8CC 0x021FC8CC thumb ov135
 *   func_021FCA8C 0x021FCA8C thumb ov135
 *   func_021F886C 0x021F886C thumb ov135
 *   func_021F8290 0x021F8290 thumb ov135
 *   func_021FCB54 0x021FCB54 thumb ov135
 */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
extern void *func_0200ADB4(void *);
extern void *POKE_TOOL_Dummy(void *);
extern void *func_020084F4(void *);
extern int WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
extern void func_021FC528(char *);
extern void func_021FC1C0(void);
extern void func_021FFFE8(u8 *,u32,u32);
extern void func_021FC2C0(void *);
extern void func_021FC3E0(void *);
extern void func_021FC360(char *);
extern void func_021FC8CC(void *,void *,void *,void **,void *,void *,void *);
extern void func_021FCA8C(void *,void *,void *,void *,void *,void *);
extern int func_021F886C(int,int,int);
extern void func_021F8290(void *,void *,int,u8 *,u32,int,int,void *);
extern void func_021FCB54(void *);
int func_021FC06C(u8 *p)
{
    void *mon;
    int index;
    mon=func_0200ADB4(*(void **)(*(u8 **)p));
    func_021FC528((char *)p);
    func_021FC1C0();
    func_021FFFE8(p,0,0);
    func_021FC2C0(p);
    func_021FC3E0(p);
    func_021FC360((char *)p);
    func_021FC8CC(*(void **)(p+0xB6C),*(void **)(p+0xB70),*(void **)(p+0xB68),(void **)(p+0xD90),POKE_TOOL_Dummy(mon),p+0x1D0,p+0xFA0);
    func_021FCA8C(*(void **)(p+0xB6C),p+0xDAC,func_020084F4(*(void **)(*(u8 **)p+0x1C)),mon,p+0xDC0,p+0xFA0);
    index=func_021F886C(*(s8 *)(p+0x1D7),*(s8 *)(p+0x1D8),0);
    func_021F8290(*(void **)(p+0xB6C),*(void **)(p+0xB70),*(int *)(p+0xB68),p+0xDB4,*(s16 *)(p+0x1D4),*(s8 *)(p+0x1D6),index,p+0xFA0);
    func_021FCB54(mon);
    WIPE_SYS_Start((void *)3,1,1,0,6,1,0x48);
    *(u32 *)(p+0x28)=0;
    *(u32 *)(p+0x12E4)=0;
    return 1;
}
