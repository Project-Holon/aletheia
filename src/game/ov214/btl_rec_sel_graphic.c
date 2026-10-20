/*
 * file:     btl_rec_sel_graphic.c
 * unit:     yes
 * function: BTL_REC_SEL_GRAPHIC_Create, BTL_REC_SEL_GRAPHIC_Delete, BTL_REC_SEL_GRAPHIC_Draw, BTL_REC_SEL_GRAPHIC_Draw3d, BTL_REC_SEL_GRAPHIC_DrawEnd, BTL_REC_SEL_GRAPHIC_GetCamera, BTL_REC_SEL_GRAPHIC_VBlank, BTL_REC_SEL_GRAPHIC_InitBg, BTL_REC_SEL_GRAPHIC_DeleteBg, BTL_REC_SEL_GRAPHIC_Noop, BTL_REC_SEL_GRAPHIC_TickDisplay, BTL_REC_SEL_GRAPHIC_InitClact, BTL_REC_SEL_GRAPHIC_DeleteClact, BTL_REC_SEL_GRAPHIC_DrawClact, BTL_REC_SEL_GRAPHIC_VBlankClact, BTL_REC_SEL_GRAPHIC_GetClactBank, BTL_REC_SEL_GRAPHIC_InitG3d, BTL_REC_SEL_GRAPHIC_DeleteG3d, BTL_REC_SEL_GRAPHIC_DrawG3d, BTL_REC_SEL_GRAPHIC_DrawG3dEnd
 * address:  0x021BB178
 * region:   ov214
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * trailing: code ends at 021BB474; subsequent words are data.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   GF_FONT_InitTextColor 0x0201DD60 thumb
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   site 0x021BB668 data ov214
 *   config 0x021BB588 data ov214
 *   config2 0x021BB53C data ov214
 *   TCB_DeleteTask 0x02030EAC arm
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   GFL_HEAP_Free 0x020307B0 arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   records 0x021BB5B8 data a4
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
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
 *   BTL_REC_SEL_InitG3dDisplay 0x021BB0D4 thumb ov214
 *   dims 0x020A1EB8 data
 *   vec1 0x021BB524 data a4
 *   vec2 0x021BB518 data ov214
 *   vec3 0x021BB530 data ov214
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   G3D_SYSTEM_Exit 0x02046788 arm
 *   G3D_SYSTEM_ApplyLookAt  0x020479D8  arm  arm9
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 *   G3D_CAMERA_Reset  0x02048AD0  arm  arm9
 *   G3D_SYSTEM_DrawStart         0x02047964  arm
 */

struct Node;
struct Cfg;
struct Bank;
struct Light;
#include "../types.h"

struct VecFx32;
#include "../arm9/clact.h"
#include "../arm9/bg_sys_types.h"

struct BtlRecSelGraphicRecord { u32 id; u8 template_data[32]; u32 type; u32 enabled; };

struct BtlRecSelGraphicVec3 { u32 x,y,z; };

struct BtlRecSelGraphic {
    u8 bgData[4];
    struct Bank *clactUnit;
    u32 *g3dCamera;
    u32 vblankHandle;
};

/* offset-0 view of the clact slot: the clact helpers receive work + 4 */
struct BtlRecSelClact {
    struct Bank *bank;
};

extern void *GFL_HEAP_Alloc(u32,u32,int,const char *,u16);
extern void MI_CpuFill8(void *,u32,u32);
extern void BG_SYS_ClearGraphicsMemory(u32);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BG_SYS_SetLcdSwap(u32);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void GF_FONT_InitTextColor(void);
struct TcbTask;
extern struct TcbTask *GFL_USE_AddMainTask(void (*)(void *),void *,u32);
struct TcbTask;
extern void TCB_DeleteTask(struct TcbTask *task);
extern void GF_FONT_SetDefaultTextColor(void);
extern u32 GFL_HEAP_Free(void *p);
extern void BG_SYS_Create(u32);
extern void BMP_WIN_Init(u32);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_FreeSlot(u8);
extern void BG_SYS_SetPlaneVisible(u8,u8);
extern void BG_SYS_FreeLayerBuf(u32 i);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void BG_SYS_Update(void);
struct DispVramCfg;
struct SysInit;
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern void BTL_REC_SEL_InitG3dDisplay(void);
extern void G3D_SYSTEM_Init(u32,u32,u32,u32,u16,u32,void (*)(void));
extern struct G3dCamera *G3D_CAMERA_Create(u32,u32,u32,u32,u32,u32,u32,u32,struct VecFx32 *,struct VecFx32 *,struct VecFx32 *,u32);
extern u32 G3D_CAMERA_Delete(void *ptr);
extern void G3D_SYSTEM_Exit(int);
extern void G3D_SYSTEM_DrawStart(void);
struct G3dCamera;
extern void G3D_CAMERA_Reset(struct G3dCamera *camera);
extern void G3D_SYSTEM_ApplyLookAt(void);
extern void G3D_SYSTEM_DrawEnd(void);
char *BTL_REC_SEL_GRAPHIC_Create(u32 a,u32 heap);
void BTL_REC_SEL_GRAPHIC_Delete(char *p);
void BTL_REC_SEL_GRAPHIC_Draw(u8 *p);
void BTL_REC_SEL_GRAPHIC_Draw3d(u8 *p);
void BTL_REC_SEL_GRAPHIC_DrawEnd(char *p);
u32 BTL_REC_SEL_GRAPHIC_GetCamera(u8 *p);
void BTL_REC_SEL_GRAPHIC_VBlank(void *unused,u8 *p);
void BTL_REC_SEL_GRAPHIC_InitBg(void *p,u32 heap);
void BTL_REC_SEL_GRAPHIC_DeleteBg(void *p);
void BTL_REC_SEL_GRAPHIC_Noop(void *p);
void BTL_REC_SEL_GRAPHIC_TickDisplay(void *p);
void BTL_REC_SEL_GRAPHIC_InitClact(unsigned char *p, int a, int b);
void BTL_REC_SEL_GRAPHIC_DeleteClact(void *p);
void BTL_REC_SEL_GRAPHIC_DrawClact(void *p);
void BTL_REC_SEL_GRAPHIC_VBlankClact(void *p);
u32 BTL_REC_SEL_GRAPHIC_GetClactBank(u32 *p);
void BTL_REC_SEL_GRAPHIC_InitG3d(u32 **out,u32 heap);
void BTL_REC_SEL_GRAPHIC_DeleteG3d(int *p);
void BTL_REC_SEL_GRAPHIC_DrawG3d(unsigned int *p);
void BTL_REC_SEL_GRAPHIC_DrawG3dEnd(void *work);
extern const char site[];
extern const u32 config[];
extern const u32 config2[];
extern const struct BtlRecSelGraphicRecord records[];
extern const char dims[];
extern struct BtlRecSelGraphicVec3 vec1,vec2,vec3;

/*
 * volatile: MMIO accesses 021BB19E..021BB1B2
 */
char *BTL_REC_SEL_GRAPHIC_Create(u32 a,u32 heap)
{
    char *p=GFL_HEAP_Alloc(heap,16,0,site,458);
    MI_CpuFill8(p,0,16);
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile u32 *)0x04000000 &= 0xFFFF1FFF;
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)config);
    BG_SYS_SetLcdSwap(a);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    GF_FONT_InitTextColor();
    BTL_REC_SEL_GRAPHIC_InitBg(p,heap);
    BTL_REC_SEL_GRAPHIC_InitClact((unsigned char *)p+4,(sptr)config,heap);
    BTL_REC_SEL_GRAPHIC_InitG3d((u32 **)(p+8),heap);
    ((struct BtlRecSelGraphic *)p)->vblankHandle=(uptr)GFL_USE_AddMainTask((void (*)(void *))BTL_REC_SEL_GRAPHIC_VBlank,p,(unsigned int)0);
    return p;
}

void BTL_REC_SEL_GRAPHIC_Delete(char *p)
{
    TCB_DeleteTask((struct TcbTask *)((struct BtlRecSelGraphic *)p)->vblankHandle);
    BTL_REC_SEL_GRAPHIC_DeleteG3d((int *)(p+8));
    BTL_REC_SEL_GRAPHIC_DeleteClact(p+4);
    BTL_REC_SEL_GRAPHIC_DeleteBg(p);
    GF_FONT_SetDefaultTextColor();
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile u32 *)0x04000000 &= 0xFFFF1FFF;
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
    MI_CpuFill8(p,0,16);
    GFL_HEAP_Free(p);
}

void BTL_REC_SEL_GRAPHIC_Draw(u8 *p) { BTL_REC_SEL_GRAPHIC_DrawClact(p+4);BTL_REC_SEL_GRAPHIC_Noop(p); }

void BTL_REC_SEL_GRAPHIC_Draw3d(u8 *p) { BTL_REC_SEL_GRAPHIC_DrawG3d((u32 *)(p+8)); }

void BTL_REC_SEL_GRAPHIC_DrawEnd(char *p) { BTL_REC_SEL_GRAPHIC_DrawG3dEnd(p+8); }

u32 BTL_REC_SEL_GRAPHIC_GetCamera(u8 *p) { return BTL_REC_SEL_GRAPHIC_GetClactBank((u32 *)(p+4)); }

void BTL_REC_SEL_GRAPHIC_VBlank(void *unused,u8 *p) { BTL_REC_SEL_GRAPHIC_TickDisplay(p);BTL_REC_SEL_GRAPHIC_VBlankClact(p+4); }

/*
 * Caller explicitly narrows both BG identifiers and record fields to u8.
 * Heap externs widened: caller passes full r1 without a narrowing instruction.
 */
void BTL_REC_SEL_GRAPHIC_InitBg(void *p,u32 heap)
{
    u32 i;
    MI_CpuFill8(p,0,4);
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    BG_SYS_SetGraphicsMode((struct DispConfig *)config2);
    for(i=0;i<3;i++) {
        const struct BtlRecSelGraphicRecord *r=&records[i];
        u32 id=r->id;
        BG_SYS_InitBgLayer((u8)id,(const struct BgTemplate *)r->template_data,(u8)r->type);
        BG_SYS_FreeSlot(id);
        BG_SYS_SetPlaneVisible(id,r->enabled);
    }
}

void BTL_REC_SEL_GRAPHIC_DeleteBg(void *p) { u32 i;for(i=0;i<3;i++)BG_SYS_FreeLayerBuf((u8)records[i].id);BMP_WIN_Exit();BG_SYS_Delete();MI_CpuFill8(p,0,4); }

void BTL_REC_SEL_GRAPHIC_Noop(void *p) { }

void BTL_REC_SEL_GRAPHIC_TickDisplay(void *p) { BG_SYS_Update(); }

void BTL_REC_SEL_GRAPHIC_InitClact(unsigned char *p, int a, int b)
{
    MI_CpuFill8(p, 0, 4);
    CLACT_InitSystem((struct ClactSysInit *)0x021BB54C, (struct DispVramCfg *)a, b);
    ((struct BtlRecSelClact *)p)->bank = (struct Bank *)CLACT_CreateUnit(0x80, 0, b);
    CLACT_SetUnitDefaultRenderer((struct Unit *)(((struct BtlRecSelClact *)p)->bank));
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}

void BTL_REC_SEL_GRAPHIC_DeleteClact(void *p) { CLACT_DeleteUnit((struct Unit *)(((struct BtlRecSelClact *)p)->bank));CLACT_ExitSystem();MI_CpuFill8(p,0,4); }

void BTL_REC_SEL_GRAPHIC_DrawClact(void *p) { CLACT_DrawSystem(); }

void BTL_REC_SEL_GRAPHIC_VBlankClact(void *p) { CLACT_VBlankSystem(); }

/*
 * follower: 021BB3D8 word getter, within handed extent.
 */
u32 BTL_REC_SEL_GRAPHIC_GetClactBank(u32 *p) { return *p; }

void BTL_REC_SEL_GRAPHIC_InitG3d(u32 **out,u32 heap)
{
    G3D_SYSTEM_Init(0,1,0,1,0,heap,BTL_REC_SEL_InitG3dDisplay);
    *out=(u32 *)G3D_CAMERA_Create(0,*(s16 *)(dims+12),*(s16 *)(dims+14),0x1555,0,4096,0x400000,0,(struct VecFx32 *)(&vec1),(struct VecFx32 *)(&vec2),(struct VecFx32 *)(&vec3),heap);
}

void BTL_REC_SEL_GRAPHIC_DeleteG3d(int *p)
{
    G3D_SYSTEM_Exit(G3D_CAMERA_Delete((void *)(*p)));
}

void BTL_REC_SEL_GRAPHIC_DrawG3d(unsigned int *p)
{
    G3D_SYSTEM_DrawStart();
    G3D_CAMERA_Reset((struct G3dCamera *)(*p));
    G3D_SYSTEM_ApplyLookAt();
}

void BTL_REC_SEL_GRAPHIC_DrawG3dEnd(void *work) { G3D_SYSTEM_DrawEnd(); }
