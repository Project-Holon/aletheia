/*
 * function: STA_ACTING_InitDisplay
 * address: 0x021F899C
 * packet: pkt_ov132_021F899C
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 020434CC in unit_0204349C.c missing function: entry;
 *   one MATCH (020434B4 unwitnessed), enclosing 0204349C TU EXACT:
 *   extern unsigned d_02146A48[];
 *   void BG_SYS_ClearMainBgPlanes(void) { d_02146A48[1]&=16; }
 *   void BG_SYS_ClearMainObjPlane(void) { d_02146A48[1]&=15; }
 *   void BG_SYS_ClearMainPlanes(void) { BG_SYS_ClearMainBgPlanes(); BG_SYS_ClearMainObjPlane(); }
 * blocker: ARM9 02043588 in unit_02043570.c missing function: entry;
 *   one EXACT, fixed compiler/flags ARM:
 *   extern void BG_SYS_ClearSubBgPlanes(void),BG_SYS_ClearSubObjPlane(void);
 *   void BG_SYS_ClearSubPlanes(void) { BG_SYS_ClearSubBgPlanes(); BG_SYS_ClearSubObjPlane(); }
 * blocker: ARM9 data 020A1448 has no witness; little-endian word at 021F8BC8
 *   is 48 14 0A 02 and reaches 0204A48C as r0. ARM9 data ownership prevents filing.
 * note: 02046440 heap extern is u16 because original caller loads it with ldrh;
 *   its own s16 declaration inserted ldrsh. Second 0204A48C arg is d_021FDBA0.
 * volatile: GX display 021F89AE/021F89B8/021F8B40, power 021F89DC,
 *   3D control 021F8AB4/021F8ABC/021F8ACA, window 021F8B50/021F8B64.
 * symbols:
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   func_02040588 0x02040588 arm
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   BG_SYS_SetLowBit 0x0204044C arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   func_0207DCF8 0x0207DCF8 arm
 *   BILLBOARD_Create 0x0204EBD4 arm
 *   BILLBOARD_SetField10 0x0204ED70 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   func_0207D63C 0x0207D63C arm
 *   WIPE_SetBrightnessFadeOut 0x0202223C thumb
 *   WIPE_ResetWndMask 0x02022224 thumb
 *   STA_ACTING_SetupBg 0x021F8DA0 thumb ov132
 *   d_021FDBA0 0x021FDBA0 data a4
 *   d_021FDAA0 0x021FDAA0 data a4
 *   d_021FDB40 0x021FDB40 data a4
 *   d_021FDB60 0x021FDB60 data a4
 *   d_021FDB80 0x021FDB80 data a4
 *   d_021FDAC0 0x021FDAC0 data a4
 *   d_021FDAE0 0x021FDAE0 data a4
 *   d_021FDB00 0x021FDB00 data a4
 *   d_021FDB20 0x021FDB20 data a4
 *   d_021FDAB0 0x021FDAB0 data a4
 *   gClActorInitParam 0x020A1448 data a4
 *   d_021FDA7C 0x021FDA7C data a4
 *   d_021FDBF8 0x021FDBF8 data a4
 *   d_021FDBD4 0x021FDBD4 data a4
 */
typedef unsigned u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int BOOL;
typedef struct { u32 w[3]; } Vec3;
typedef struct { Vec3 a,b,c; } Vectors;
typedef struct { u32 w[7]; } Blob28;
extern const Vectors d_021FDA7C;
extern const Blob28 d_021FDBF8;
extern const Vec3 d_021FDBD4;
extern const u32 d_021FDBA0[];
extern const u32 d_021FDAA0[];
extern const u32 d_021FDB40[];
extern const u32 d_021FDB60[];
extern const u32 d_021FDB80[];
extern const u32 d_021FDAC0[];
extern const u32 d_021FDAE0[];
extern const u32 d_021FDB00[];
extern const u32 d_021FDB20[];
extern const u32 d_021FDAB0[];
extern const u32 gClActorInitParam[];
extern void BG_SYS_ClearMainPlanes(void),BG_SYS_ClearSubPlanes(void);
extern void WIPE_SetBrightnessFadeOut(u32,u32);
extern u32 WIPE_ResetWndMask(void *);
struct BgTemplate;
struct Blk3;
struct Cfg;
struct DispConfig;
struct DispVram;
struct Light;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BG_SYS_Create(u16);
extern void BMP_WIN_Init(u16);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void STA_ACTING_SetupBg(const struct BgTemplate *p, u32 id, u32 type);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void G3D_SYSTEM_Init(u32,u32,u32,u32,u16,u16,void (*)(void));
extern void BG_SYS_SetLowBit(u32),G3D_SYSTEM_SetSwapBuffersMode(u32,u32);
extern void *G3D_CAMERA_Create(u32,u32,u32,u32,u32,u32,u32,u32,const Vec3 *,const Vec3 *,const Vec3 *,u16);
extern void G3D_CAMERA_Reset(struct Light *l);
extern void func_0207DCF8(const void *);
extern void *BILLBOARD_Create(u8 *src, void *heap);
extern void BILLBOARD_SetField10(u8 *dst, struct Blk3 *src);
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern void BG_SYS_SetMainPlaneVisible(u32,u32),BG_SYS_SetSubPlaneVisible(u32,u32),func_0207D63C(void *,int,int,int,int);
typedef enum { MAIN_SUB=0,SUB_MAIN=1 } GXDispSelect;
static inline void GX_SetVisiblePlane(int plane) { *(volatile u32 *)0x04000000=(*(volatile u32 *)0x04000000&~0x1F00u)|((u32)plane<<8); }
static inline void GXS_SetVisiblePlane(int plane) { *(volatile u32 *)0x04001000=(*(volatile u32 *)0x04001000&~0x1F00u)|((u32)plane<<8); }
static inline void GX_SetDispSelect(GXDispSelect sel) { *(volatile u16 *)0x04000304=(u16)((*(volatile u16 *)0x04000304&~0x8000u)|(sel<<15)); }
static inline void G3X_EdgeMarking(BOOL enable) { if(enable) *(volatile u16 *)0x04000060=(u16)((*(volatile u16 *)0x04000060&~0x3000u)|0x20); else *(volatile u16 *)0x04000060&=(u16)~0x3020; }
static inline void G3X_AntiAlias(BOOL enable) { if(enable) *(volatile u16 *)0x04000060=(u16)((*(volatile u16 *)0x04000060&~0x3000u)|0x10); else *(volatile u16 *)0x04000060&=(u16)~0x3010; }
static inline void G3X_AlphaBlend(BOOL enable) { if(enable) *(volatile u16 *)0x04000060=(u16)((*(volatile u16 *)0x04000060&~0x3000u)|8); else *(volatile u16 *)0x04000060&=(u16)~0x3008; }
static inline void GX_SetVisibleWnd(int window) { *(volatile u32 *)0x04000000=(*(volatile u32 *)0x04000000&~0xE000u)|((u32)window<<13); }
static inline void G2_SetWndOBJInsidePlane(int wnd,BOOL effect) { u32 tmp; tmp=(*(volatile u16 *)0x0400004A&~0x3F00u)|((u32)wnd<<8); if(effect) tmp|=0x2000; *(volatile u16 *)0x0400004A=(u16)tmp; }
static inline void G2_SetWndOutsidePlane(int wnd,BOOL effect) { u32 tmp; tmp=(*(volatile u16 *)0x0400004A&~0x3Fu)|(u32)wnd; if(effect) tmp|=0x20; *(volatile u16 *)0x0400004A=(u16)tmp; }
void STA_ACTING_InitDisplay(u8 *p)
{
    Blob28 big;
    Vec3 small;
    void *light,*board;
    BG_SYS_ClearMainPlanes(); BG_SYS_ClearSubPlanes();
    GX_SetVisiblePlane(0); GXS_SetVisiblePlane(0);
    WIPE_SetBrightnessFadeOut(0,0); WIPE_SetBrightnessFadeOut(1,0);
    WIPE_ResetWndMask(0); WIPE_ResetWndMask((void *)1);
    GX_SetDispSelect(SUB_MAIN);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021FDBA0);
    BG_SYS_Create(*(u16 *)p); BMP_WIN_Init(*(u16 *)p);
    BG_SYS_SetGraphicsMode((struct DispConfig *)d_021FDAA0);
    STA_ACTING_SetupBg((const struct BgTemplate *)d_021FDB40,1,0);
    STA_ACTING_SetupBg((const struct BgTemplate *)d_021FDB60,2,0);
    STA_ACTING_SetupBg((const struct BgTemplate *)d_021FDB80,3,0);
    STA_ACTING_SetupBg((const struct BgTemplate *)d_021FDAC0,5,0);
    STA_ACTING_SetupBg((const struct BgTemplate *)d_021FDAE0,6,0);
    STA_ACTING_SetupBg((const struct BgTemplate *)d_021FDB00,4,0);
    STA_ACTING_SetupBg((const struct BgTemplate *)d_021FDB20,7,0);
    func_02040588(0,1);
    G3D_SYSTEM_Init(0,2,0,4,0,*(u16 *)p,0);
    BG_SYS_SetLowBit(3);
    G3D_SYSTEM_SetSwapBuffersMode(0,1);
    light=G3D_CAMERA_Create(2,0xC000,0,0,0x10000,0x1000,0x3E8000,0,&d_021FDA7C.c,&d_021FDA7C.a,&d_021FDA7C.b,*(u16 *)p);
    *(void **)(p+0xA8)=light;
    G3D_CAMERA_Reset(light);
    func_0207DCF8(d_021FDAB0);
    G3X_EdgeMarking(0); G3X_AntiAlias(1); G3X_AlphaBlend(1);
    G3D_SYSTEM_SetSwapBuffersMode(0,0);
    big=d_021FDBF8;
    small=d_021FDBD4;
    board=BILLBOARD_Create((u8 *)(&big),(void *)(u32)*(u16 *)p);
    *(void **)(p+0xAC)=board;
    BILLBOARD_SetField10(board,(struct Blk3 *)(&small));
    CLACT_InitSystem((const struct Cfg *)gClActorInitParam,(u32)d_021FDBA0,*(u16 *)p);
    BG_SYS_SetMainPlaneVisible(16,1); BG_SYS_SetSubPlaneVisible(16,1);
    func_0207D63C((void *)0x04000050,8,1,0,10);
    GX_SetVisibleWnd(4);
    G2_SetWndOBJInsidePlane(23,1);
    G2_SetWndOutsidePlane(31,1);
}
