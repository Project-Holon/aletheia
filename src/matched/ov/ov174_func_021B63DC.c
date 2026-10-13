/*
 * function: func_021B63DC
 * address: 0x021B63DC
 * packet: pkt_ov174_021B63DC
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 020434CC is omitted from unit_0204349C.c's function header.
 *   one --arm, no region: MATCH, 16 bytes, blocker434CC.log; concrete bytes agree,
 *   unresolved 020434B4 is also omitted from that owner unit's function header.
 *   Scratch copy of owner unit also verifies TU EXACT: blocker434unit.log.
 *   extern void BG_SYS_ClearMainBgPlanes(void),BG_SYS_ClearMainObjPlane(void);
 *   void BG_SYS_ClearMainPlanes(void) {BG_SYS_ClearMainBgPlanes();BG_SYS_ClearMainObjPlane();}
 * blocker: ARM9 02043588 is omitted from unit_02043570.c's function header.
 *   one --arm, no region: EXACT, 16 bytes, blocker43588.log.
 *   extern void BG_SYS_ClearSubBgPlanes(void),BG_SYS_ClearSubObjPlane(void);
 *   void BG_SYS_ClearSubPlanes(void) {BG_SYS_ClearSubBgPlanes();BG_SYS_ClearSubObjPlane();}
 * blocker: ARM9 data 020A1448 has no witness outside this caller; extern a4
 *   retained without an overlay token, ROM pool +0128 names 020A1448.
 * volatile: DISPCNT reads/writes 021B63EE..021B63FE; blend writes 021B6420/6424; POWCNT1 read/write 021B6426..642E.
 * symbols:
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   func_0202223C 0x0202223C thumb
 *   WIPE_ResetWndMask 0x02022224 thumb
 *   func_020433E0 0x020433E0 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_021B6538 0x021B6538 thumb ov174
 *   func_02082A7C 0x02082A7C arm
 *   func_0204A48C 0x0204A48C arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_0204B100 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   func_0207D63C 0x0207D63C arm
 *   d_021B7450 0x021B7450 data a4
 *   d_021B7388 0x021B7388 data a4
 *   d_021B73D0 0x021B73D0 data a4
 *   d_021B73B0 0x021B73B0 data a4
 *   d_021B7410 0x021B7410 data a4
 *   d_021B7430 0x021B7430 data a4
 *   d_021B73F0 0x021B73F0 data a4
 *   d_020A1448 0x020A1448 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
typedef struct { u32 w[7]; } Config;
extern void BG_SYS_ClearMainPlanes(void),BG_SYS_ClearSubPlanes(void);
struct Bank;
struct Cfg;
struct DispConfig;
struct DispVram;
extern void func_0202223C(u32 a, u32 color);
extern u32 WIPE_ResetWndMask(void *win);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203F8F4(u16),func_02045088(u16);
extern void func_0203FC28(struct DispConfig *cfg);
struct BgTemplate;
extern void func_021B6538(const struct BgTemplate *p, int i, int type);
extern void func_02082A7C(int,int,u32);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void func_0207D63C(void *,int,int,int,int);
extern const u32 d_021B7450[],d_021B7388[],d_021B73D0[],d_021B73B0[],d_021B7410[],d_021B7430[],d_021B73F0[];
extern const Config d_020A1448;
void func_021B63DC(u8 *p)
{
    Config c;
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    *(volatile u32 *)0x04000000 &= ~0x1F00;
    *(volatile u32 *)0x04001000 &= ~0x1F00;
    func_0202223C(0,0);
    func_0202223C(1,0);
    WIPE_ResetWndMask(0);
    WIPE_ResetWndMask((void *)1);
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile u16 *)0x04000304 |=0x8000;
    func_020433E0((const struct DispVram *)d_021B7450);
    func_0203F8F4(*(u16 *)p);
    func_02045088(*(u16 *)p);
    func_0203FC28((void *)d_021B7388);
    func_021B6538((const struct BgTemplate *)d_021B73D0,0,0);
    func_021B6538((const struct BgTemplate *)d_021B73B0,1,0);
    func_021B6538((const struct BgTemplate *)d_021B7410,2,2);
    func_021B6538((const struct BgTemplate *)d_021B7430,3,2);
    func_021B6538((const struct BgTemplate *)d_021B73F0,7,0);
    func_02082A7C(0,0x06000000,0x40000);
    c=d_020A1448;
    func_0204A48C((const struct Cfg *)(&c),(u32)d_021B7450,*(u16 *)p);
    func_020434DC(16,1);
    func_02043598(16,1);
    *(void **)(p+80)=func_0204B100(16,0,*(u16 *)p);
    CLACT_SetUnitDefaultRenderer(*(void **)(p+80));
    func_0207D63C((void *)0x04000050,1,30,16,4);
}
