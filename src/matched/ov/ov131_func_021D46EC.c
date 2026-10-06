/*
 * function: func_021D46EC
 * address: 0x021D46EC
 * packet: pkt_ov131_021D46EC
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interface: complete original 020160C0 bytes 41 64 70 47 store r1 at
 *   r0+0x44 and return. Caller supplies object and full word 0x10000.
 *   02046440 owner's s16 heap is u16 here: original ldrh zero-extends its
 *   outgoing stack word. Lower 16-bit callee conversion remains unchanged.
 *   Config c initializes all 28 bytes before h[0] and consumer reads.
 * lever: game hardware writes use vendor visible-plane and enum display
 *   selection inlines; raw compound assignments change constant sharing.
 * witness: 020160C0 filed as src/matched/arm9/func_020160C0.c.
 * volatile: hardware DISPCNT/BLDCNT/POWCNT1/DISP3DCNT registers
 * symbols:
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_0202223C 0x0202223C thumb
 *   func_02022224 0x02022224 thumb
 *   func_020433E0 0x020433E0 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_021D4940 0x021D4940 thumb ov131
 *   func_02040588 0x02040588 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_02046440 0x02046440 arm
 *   func_02048A24 0x02048A24 arm
 *   func_02048AD0 0x02048AD0 arm
 *   func_0207DCF8 0x0207DCF8 arm
 *   func_02046BE0 0x02046BE0 arm
 *   func_0204044C 0x0204044C arm
 *   func_02014B08 0x02014B08 thumb
 *   func_02016020 0x02016020 thumb
 *   func_020160C0 0x020160C0 thumb
 *   g_C0E4 0x021DC0E4 data ov131
 *   g_BFF4 0x021DBFF4 data ov131
 *   g_C004 0x021DC004 data ov131
 *   g_1448 0x020A1448 data
 *   g_BFC0 0x021DBFC0 data ov131
 *   g_BFE4 0x021DBFE4 data ov131
 */
#include "../include/Obj01739.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct DispVram;
struct DispConfig;
struct BgConfig {u32 w[8];};
struct Cfg {u32 w[4];u16 h[6];};
struct Vec3 {u32 x,y,z;};
extern const struct DispVram g_C0E4;
extern struct DispConfig g_BFF4;
extern struct BgConfig g_C004[7];
extern struct Cfg g_1448;
extern struct Vec3 g_BFC0[3];
extern u16 g_BFE4[8];
extern void func_020434CC(void),func_02043588(void);
extern void func_0202223C(u32,u32);
extern u32 func_02022224(void *);
extern void func_020433E0(const struct DispVram *);
extern void func_0203F8F4(u16),func_02045088(u16);
extern void func_0203FC28(struct DispConfig *);
extern void func_021D4940(struct BgConfig *,u32,u32);
extern void func_02040588(u32,u32);
extern void func_0207D63C(u32 *,u32,u32,u32,u32);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
struct Bank;
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_020434DC(u32,u32),func_02043598(u32,u32);
extern void func_02046440(u32,u32,u32,u32,u16,u16,void (*)(void));
extern u32 *func_02048A24(u32,u32,u32,u32,u32,u32,u32,u32,struct Vec3 *,struct Vec3 *,struct Vec3 *,u16);
struct Light;
extern void func_02048AD0(struct Light *l);
extern void func_0207DCF8(const void *);
extern void func_02046BE0(u32,u32),func_0204044C(u32);
extern void *func_02014B08(u32,void *);
extern void func_02016020(void *,u32);
extern void func_020160C0(char *p, unsigned int v);
typedef enum {GX_DISP_SELECT_SUB_MAIN=0, GX_DISP_SELECT_MAIN_SUB=1} GXDispSelect;
static inline void GX_SetVisiblePlane(int plane)
{ *(volatile u32 *)0x04000000=(u32)((*(volatile u32 *)0x04000000 & ~0x1f00) | (plane<<8)); }
static inline void GXS_SetVisiblePlane(int plane)
{ *(volatile u32 *)0x04001000=(u32)((*(volatile u32 *)0x04001000 & ~0x1f00) | (plane<<8)); }
static inline void GX_SetDispSelect(GXDispSelect sel)
{ *(volatile u16 *)0x04000304=(u16)((*(volatile u16 *)0x04000304 & ~0x8000) | (sel<<15)); }
void func_021D46EC(char *p)
{
    struct Cfg c;
    func_020434CC();func_02043588();
    GX_SetVisiblePlane(0);GXS_SetVisiblePlane(0);
    func_0202223C(0,0);func_0202223C(1,0);
    func_02022224(0);func_02022224((void *)1);
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);
    func_020433E0(&g_C0E4);
    func_0203F8F4(((struct Obj01739 *)p)->f0);func_02045088(((struct Obj01739 *)p)->f0);
    func_0203FC28(&g_BFF4);
    func_021D4940(&g_C004[6],1,0);func_021D4940(&g_C004[4],2,0);func_021D4940(&g_C004[0],3,0);
    func_02040588(0,1);
    func_021D4940(&g_C004[1],4,0);func_021D4940(&g_C004[2],5,0);func_021D4940(&g_C004[3],6,0);func_021D4940(&g_C004[5],7,0);
    func_0207D63C((u32 *)0x04000050,4,30,13,16);
    func_0207D63C((u32 *)0x04001050,4,8,13,16);
    c=g_1448;c.h[0]=110;
    func_0204A48C(&c,(u32)(&g_C0E4),((struct Obj01739 *)p)->f0);
    ((struct Obj01739 *)p)->f174=func_0204B100(96,0,((struct Obj01739 *)p)->f0);
    func_0204B270(((struct Obj01739 *)p)->f174);
    func_020434DC(16,1);func_02043598(16,1);
    func_02046440(0,2,0,1,0,((struct Obj01739 *)p)->f0,0);
    *(u32 * *)&((struct Obj01739 *)p)->f70=func_02048A24(2,0xc0000,0,0,0x100000,0x80000,0x200000,0,&g_BFC0[0],&g_BFC0[2],&g_BFC0[1],((struct Obj01739 *)p)->f0);
    func_02048AD0(((struct Obj01739 *)p)->f70);
    func_0207DCF8(g_BFE4);
    *(volatile u16 *)0x04000060 &= ~0x3020;
    func_02046BE0(0,0);func_0204044C(0);
    ((struct Obj01739 *)p)->f78=func_02014B08(2,(void *)((struct Obj01739 *)p)->f0);
    func_02016020(((struct Obj01739 *)p)->f78,0);
    func_020160C0(((struct Obj01739 *)p)->f78,0x10000);
}
