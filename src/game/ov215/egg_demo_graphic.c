/*
 * file:     egg_demo_graphic.c
 * unit:     yes
 * function: EGG_DEMO_GRAPHIC_Create, EGG_DEMO_GRAPHIC_Delete, EGG_DEMO_GRAPHIC_Draw, EGG_DEMO_GRAPHIC_Draw3d, EGG_DEMO_GRAPHIC_DrawEnd, EGG_DEMO_GRAPHIC_GetClactBank2, EGG_DEMO_GRAPHIC_VBlank, EGG_DEMO_GRAPHIC_InitBg, EGG_DEMO_GRAPHIC_DeleteBg, EGG_DEMO_GRAPHIC_Noop, EGG_DEMO_GRAPHIC_TickDisplay, EGG_DEMO_GRAPHIC_InitClact, EGG_DEMO_GRAPHIC_DeleteClact, EGG_DEMO_GRAPHIC_DrawClact, EGG_DEMO_GRAPHIC_VBlankClact, EGG_DEMO_GRAPHIC_GetClactBank, EGG_DEMO_GRAPHIC_InitG3d, EGG_DEMO_GRAPHIC_DeleteG3d, EGG_DEMO_GRAPHIC_DrawG3d, EGG_DEMO_GRAPHIC_DrawG3dEnd
 * address:  0x021F63CC
 * region:   ov215
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from egg_demo_view.c by tools/splitfile.py.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BMP_SetDisplaySwap 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   GF_FONT_InitTextColor 0x0201DD60 thumb
 *   func_020056A0 0x020056A0 thumb
 *   d_021F73E0 0x021F73E0 data a4
 *   d_021F71C4 0x021F71C4 data a4
 *   func_02030EAC 0x02030EAC arm
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   func_020307B0 0x020307B0 arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_021F7178 0x021F7178 data a4
 *   d_021F71F4 0x021F71F4 data a4
 *   func_020403F4 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   BG_SYS_Update 0x020419E4 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   EGG_DEMO_MENU_InitGraphics 0x021F6328 thumb ov215
 *   d_020A1EB8 0x020A1EB8 data a2
 *   d_021F7160 0x021F7160 data a4
 *   d_021F7154 0x021F7154 data a4
 *   d_021F716C 0x021F716C data a4
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   G3D_SYSTEM_Exit 0x02046788 arm
 *   func_02047964 0x02047964 arm
 *   func_02048AD0 0x02048AD0 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 */
#include "../../matched/include/Obj25749.h"
#include "../../matched/include/Obj25750.h"
#include "../../matched/include/Obj14709.h"
#include "../../matched/include/Obj25751.h"
#include "../../matched/include/Obj25752.h"
#include "../../matched/include/Obj25755.h"
#include "egg_demo_graphic_shared_types.h"

struct DispVram;

struct DispConfig;

struct Cfg;

struct Bank;

struct Light;

struct BgTemplate { unsigned words[8]; };

struct BgConfig { unsigned layer; struct BgTemplate template; unsigned type,enable; };

struct Vec3 { unsigned x,y,z; };

extern void *func_02030734(unsigned,unsigned,int,const char *,u16);

extern void MI_CpuFill8(void *,int,int);

extern void BG_SYS_ClearGraphicsMemory(u32 keep);

extern void BG_SYS_SetVramBanks(const struct DispVram *c);

extern void BMP_SetDisplaySwap(unsigned);

extern void BG_SYS_ResetSubDisplay(void);

extern void BG_SYS_ClearMainPlanes(void);

extern void BG_SYS_ClearSubPlanes(void);

extern void GF_FONT_InitTextColor(void);

extern void *func_020056A0(void (*)(int,char *),char *,unsigned);

extern void func_02030EAC(struct Node *n);

extern void GF_FONT_SetDefaultTextColor(void);

extern u32 func_020307B0(void *p);

extern void BG_SYS_Create(unsigned);

extern void BMP_WIN_Init(unsigned);

extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);

extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);

extern void BG_SYS_FreeSlot(u8);

extern void func_02040588(u8,u8);

extern void func_020403F4(u32 i);

extern void BMP_WIN_Exit(void);

extern void BG_SYS_Delete(void);

extern void BG_SYS_Update(void);

extern void CLACT_InitSystem(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);

extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);

extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);

extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);

extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);

extern u32 CLACT_DeleteUnit(struct Bank *bank);

extern void CLACT_ExitSystem(void);

extern void CLACT_DrawSystem(void);

extern void CLACT_VBlankSystem(void);

extern void EGG_DEMO_MENU_InitGraphics(void);

extern void G3D_SYSTEM_Init(unsigned,unsigned,unsigned,unsigned,u16,unsigned,void (*)(void));

extern void *G3D_CAMERA_Create(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,const struct Vec3 *,const struct Vec3 *,const struct Vec3 *,u16);

extern u32 G3D_CAMERA_Delete(void *ptr);

extern void G3D_SYSTEM_Exit(int);

extern void func_02047964(void);

extern void func_02048AD0(struct Light *);

extern void G3D_SYSTEM_ApplyLookAt(void);

extern void G3D_SYSTEM_DrawEnd(void);

char *EGG_DEMO_GRAPHIC_Create(unsigned mode,u16 heap);

void EGG_DEMO_GRAPHIC_Delete(char *p);

void EGG_DEMO_GRAPHIC_Draw(char *a);

void EGG_DEMO_GRAPHIC_Draw3d(char *p);

void EGG_DEMO_GRAPHIC_DrawEnd(char *p);

int EGG_DEMO_GRAPHIC_GetClactBank2(char *p);

void EGG_DEMO_GRAPHIC_VBlank(int a, char *b);

void EGG_DEMO_GRAPHIC_InitBg(void *out,unsigned heap);

void EGG_DEMO_GRAPHIC_DeleteBg(void *p);

void EGG_DEMO_GRAPHIC_Noop(void *a0);

void EGG_DEMO_GRAPHIC_TickDisplay(void *a0);

void EGG_DEMO_GRAPHIC_InitClact(unsigned char *p, int a, u32 b);

void EGG_DEMO_GRAPHIC_DeleteClact(char *p);

void EGG_DEMO_GRAPHIC_DrawClact(void *a0);

void EGG_DEMO_GRAPHIC_VBlankClact(void *a0);

int EGG_DEMO_GRAPHIC_GetClactBank(void *p);

void EGG_DEMO_GRAPHIC_InitG3d(void **out,u16 heap);

void EGG_DEMO_GRAPHIC_DeleteG3d(int *p);

void EGG_DEMO_GRAPHIC_DrawG3d(void *p);

void EGG_DEMO_GRAPHIC_DrawG3dEnd(void *p);

extern const char d_021F73E0[];

extern const unsigned d_021F71C4[];

extern const unsigned d_021F7178[];

extern const struct BgConfig d_021F71F4[];

extern const s16 d_020A1EB8[];

extern const struct Vec3 d_021F7160,d_021F7154,d_021F716C;

/*
 * volatile: hardware 021F63F2,63F4,63F8,6400,6402,6406.
 */
char *EGG_DEMO_GRAPHIC_Create(unsigned mode,u16 heap)
{
    char *p;
    p=func_02030734(heap,16,0,d_021F73E0,466);
    MI_CpuFill8(p,0,16);
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &=0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &=0xFFFF1FFF;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021F71C4);
    BMP_SetDisplaySwap(mode);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    GF_FONT_InitTextColor();
    EGG_DEMO_GRAPHIC_InitBg(p,heap);
    EGG_DEMO_GRAPHIC_InitClact((unsigned char *)(p+4),(int)d_021F71C4,heap);
    EGG_DEMO_GRAPHIC_InitG3d((void **)(p+8),heap);
    ((struct Obj25749 *)p)->fC=func_020056A0(EGG_DEMO_GRAPHIC_VBlank,p,0);
    return p;
}

void EGG_DEMO_GRAPHIC_Delete(char *p)
{
    func_02030EAC(((struct Obj25750 *)p)->fC);
    EGG_DEMO_GRAPHIC_DeleteG3d((int *)(p+8));
    EGG_DEMO_GRAPHIC_DeleteClact(p+4);
    EGG_DEMO_GRAPHIC_DeleteBg(p);
    GF_FONT_SetDefaultTextColor();
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= 0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &= 0xFFFF1FFF;
    MI_CpuFill8(p,0,16);
    func_020307B0(p);
}

void EGG_DEMO_GRAPHIC_Draw(char *a)
{
    EGG_DEMO_GRAPHIC_DrawClact(a + 4);
    EGG_DEMO_GRAPHIC_Noop(a);
}

void EGG_DEMO_GRAPHIC_Draw3d(char *p){EGG_DEMO_GRAPHIC_DrawG3d(p+8);}

void EGG_DEMO_GRAPHIC_DrawEnd(char *p){EGG_DEMO_GRAPHIC_DrawG3dEnd(p+8);}

int EGG_DEMO_GRAPHIC_GetClactBank2(char *p){return EGG_DEMO_GRAPHIC_GetClactBank(p+4);}

void EGG_DEMO_GRAPHIC_VBlank(int a, char *b)
{
    EGG_DEMO_GRAPHIC_TickDisplay(b);
    EGG_DEMO_GRAPHIC_VBlankClact(b + 4);
}

void EGG_DEMO_GRAPHIC_InitBg(void *out,unsigned heap)
{
    unsigned i;
    MI_CpuFill8(out,0,4);
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    BG_SYS_SetGraphicsMode((struct DispConfig *)d_021F7178);
    for(i=0;i<6;i++) {
        BG_SYS_InitBgLayer((u8)d_021F71F4[i].layer,&d_021F71F4[i].template,(u8)d_021F71F4[i].type);
        BG_SYS_FreeSlot(d_021F71F4[i].layer);
        func_02040588(d_021F71F4[i].layer,d_021F71F4[i].enable);
    }
}

/*
 * evidence: the caller truncates the 020403F4 argument with lsl/lsr #24,
 * so its extern is u8 although the callee's own source uses a word.
 * lever: a named unsigned byte-address base keeps the table in r4 and
 * index in r5; the inline address swaps them, and word indexing adds lsl #2.
 */
void EGG_DEMO_GRAPHIC_DeleteBg(void *p){unsigned base=(unsigned)d_021F71F4;unsigned i;for(i=0;i<6;i++)func_020403F4((unsigned char)(*(const unsigned *)(base+i*44)));BMP_WIN_Exit();BG_SYS_Delete();MI_CpuFill8(p,0,4);}

/*
 * extent: two-byte alignment padding follows the body.
 */
void EGG_DEMO_GRAPHIC_Noop(void *a0){}

void EGG_DEMO_GRAPHIC_TickDisplay(void *a0){BG_SYS_Update();}

void EGG_DEMO_GRAPHIC_InitClact(unsigned char *p, int a, u32 b)
{
    MI_CpuFill8(p, 0, 4);
    CLACT_InitSystem((const struct Cfg *)0x021F7188, a, b);
    ((struct Obj14709 *)p)->f0 = CLACT_CreateUnit(0x80, 0, b);
    CLACT_SetUnitDefaultRenderer(((struct Obj14709 *)p)->f0);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}

void EGG_DEMO_GRAPHIC_DeleteClact(char *p){CLACT_DeleteUnit(*(struct Bank * *)&((struct Obj25751 *)p)->f0);CLACT_ExitSystem();MI_CpuFill8(p,0,4);}

void EGG_DEMO_GRAPHIC_DrawClact(void *a0){CLACT_DrawSystem();}

/*
 * extent: includes cleared tiny follower EGG_DEMO_GRAPHIC_GetClactBank; no further code included.
 */
void EGG_DEMO_GRAPHIC_VBlankClact(void *a0){CLACT_VBlankSystem();}

int EGG_DEMO_GRAPHIC_GetClactBank(void *p){return ((struct Obj25752 *)p)->f0;}

/*
 * evidence: 46440 heap extern widened; original stores full r1 at sp+4.
 */
void EGG_DEMO_GRAPHIC_InitG3d(void **out,u16 heap)
{
    G3D_SYSTEM_Init(0,2,0,1,0,heap,EGG_DEMO_MENU_InitGraphics);
    *out=G3D_CAMERA_Create(0,d_020A1EB8[6],d_020A1EB8[7],0x1555,0,4096,4194304,0,&d_021F7160,&d_021F7154,&d_021F716C,heap);
}

void EGG_DEMO_GRAPHIC_DeleteG3d(int *p)
{
    G3D_SYSTEM_Exit(G3D_CAMERA_Delete((void *)(*p)));
}

/*
 * extent: includes cleared tiny follower EGG_DEMO_GRAPHIC_DrawG3dEnd; no further code included.
 */
void EGG_DEMO_GRAPHIC_DrawG3d(void *p){func_02047964();func_02048AD0(*(struct Light * *)&((struct Obj25755 *)p)->f0);G3D_SYSTEM_ApplyLookAt();}

void EGG_DEMO_GRAPHIC_DrawG3dEnd(void *p){G3D_SYSTEM_DrawEnd();}
