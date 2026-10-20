/*
 * file:     zenkoku_zukan_award_graphic.c
 * unit:     yes
 * function: ZENKOKU_ZUKAN_AWARD_GRAPHIC_Create, ZENKOKU_ZUKAN_AWARD_GRAPHIC_Delete, ZENKOKU_ZUKAN_AWARD_GRAPHIC_Update, ZENKOKU_ZUKAN_AWARD_GRAPHIC_GetActor, ZENKOKU_ZUKAN_AWARD_GRAPHIC_Task, ZENKOKU_ZUKAN_AWARD_GRAPHIC_SetupBg, ZENKOKU_ZUKAN_AWARD_GRAPHIC_CleanupBg, ZENKOKU_ZUKAN_AWARD_GRAPHIC_Noop, ZENKOKU_ZUKAN_AWARD_GRAPHIC_DrawObjects, ZENKOKU_ZUKAN_AWARD_GRAPHIC_SetupClact, ZENKOKU_ZUKAN_AWARD_GRAPHIC_DeleteClact, ZENKOKU_ZUKAN_AWARD_GRAPHIC_Draw, ZENKOKU_ZUKAN_AWARD_GRAPHIC_VBlank, ZENKOKU_ZUKAN_AWARD_GRAPHIC_GetValue, ZENKOKU_ZUKAN_AWARD_GRAPHIC_SetupCamera, ZENKOKU_ZUKAN_AWARD_GRAPHIC_DeleteCamera
 * address:  0x021B9F10
 * region:   ov222
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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
 *   d_021BA390 0x021BA390 data a1
 *   d_021BA2CC 0x021BA2CC data a4
 *   TCB_DeleteTask 0x02030EAC arm
 *   ZENKOKU_ZUKAN_AWARD_GRAPHIC_DeleteCamera 0x021BA1C8 thumb ov222
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   GFL_HEAP_Free 0x020307B0 arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   config 0x021BA280 data a4
 *   records 0x021BA2FC data a4
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   BG_SYS_Update 0x020419E4 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   ZENKOKU_ZUKAN_AWARD_Callback 0x021B9E6C thumb ov222
 *   dims 0x020A1EB8 data
 *   vec1 0x021BA268 data a4
 *   vec2 0x021BA25C data a4
 *   vec3 0x021BA274 data ov222
 */
struct DispVram;
struct Node;
struct BgTemplate;
struct DispConfig;
struct Bank;
struct Cfg;
#include "../types.h"

struct ZenkokuZukanAwardGraphicBgRow { u32 id; u8 cfg[32]; u32 type; u32 enable; };

struct ClactCtx {
    struct Bank *unit;     /* +0x00 CLACT unit from CLACT_CreateUnit */
};

struct ZenkokuZukanAwardGraphic {
    u32 bgState;           /* +0x00 zeroed by SetupBg and CleanupBg, never read */
    struct ClactCtx clact; /* +0x04 CLACT context */
    u32 *camera;           /* +0x08 G3D camera from SetupCamera */
    void *proc;            /* +0x0C task proc from GFL_USE_AddMainTask */
};

struct Vec3 { u32 x,y,z; };

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void*,int,u32);
extern void BG_SYS_ClearGraphicsMemory(u32);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BG_SYS_SetLcdSwap(u32);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void GF_FONT_InitTextColor(void);
extern void* GFL_USE_AddMainTask(u32,u32,u32);
struct TcbTask;
extern void TCB_DeleteTask(struct TcbTask *task);
extern void ZENKOKU_ZUKAN_AWARD_GRAPHIC_DeleteCamera(u32 *);
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
extern void CLACT_InitSystem(struct SysInit *cfg, struct DispVramCfg *res_cfg, u32 heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, unsigned int heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void CLACT_DrawSystem(void);
extern void CLACT_VBlankSystem(void);
extern void ZENKOKU_ZUKAN_AWARD_Callback(void);
extern void G3D_SYSTEM_Init(u32,u32,u32,u32,u16,u32,void (*)(void));
extern u32 *G3D_CAMERA_Create(u32,u32,u32,u32,u32,u32,u32,u32,struct Vec3 *,struct Vec3 *,struct Vec3 *,u32);
extern u32 G3D_CAMERA_Delete(void *ptr);
extern void G3D_SYSTEM_Exit(u32 x);
void* ZENKOKU_ZUKAN_AWARD_GRAPHIC_Create(u32 swap,u32 heap);
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_Delete(char *p);
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_Update(char *p);
u32 ZENKOKU_ZUKAN_AWARD_GRAPHIC_GetActor(char *p);
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_Task(void *unused, char *p);
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_SetupBg(void *p,u32 heap);
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_CleanupBg(void *p);
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_Noop(void *p);
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_DrawObjects(void *p);
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_SetupClact(unsigned char *p, int a, int b);
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_DeleteClact(char *p);
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_Draw(void *p);
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_VBlank(void *p);
u32 ZENKOKU_ZUKAN_AWARD_GRAPHIC_GetValue(const u32 *p);
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_SetupCamera(u32 **out,u32 heap);
extern char d_021BA390[];
extern u32 d_021BA2CC[];
extern u32 config[];
extern const struct ZenkokuZukanAwardGraphicBgRow records[];
extern const char dims[];
extern struct Vec3 vec1,vec2,vec3;

void* ZENKOKU_ZUKAN_AWARD_GRAPHIC_Create(u32 swap,u32 heap)
{
 char*p;
 u32*g;
 p=GFL_HEAP_Alloc(heap,16,0,d_021BA390,0x1cc);
 MI_CpuFill8(p,0,16);
 *(volatile u16*)0x04000050=0;
 *(volatile u16*)0x04001050=0;
 *(volatile u32*)0x04000000 &= ~0xe000u;
 *(volatile u32*)0x04001000 &= ~0xe000u;
 BG_SYS_ClearGraphicsMemory(0);
 g=d_021BA2CC;
 BG_SYS_SetVramBanks((const struct DispVram *)g);
 BG_SYS_SetLcdSwap(swap);
 BG_SYS_ResetSubDisplay();
 BG_SYS_ClearMainPlanes();
 BG_SYS_ClearSubPlanes();
 GF_FONT_InitTextColor();
 ZENKOKU_ZUKAN_AWARD_GRAPHIC_SetupBg(p,heap);
 ZENKOKU_ZUKAN_AWARD_GRAPHIC_SetupClact((unsigned char*)p+4,(int)g,heap);
 ZENKOKU_ZUKAN_AWARD_GRAPHIC_SetupCamera((u32**)(p+8),heap);
 *(void* *)&((struct ZenkokuZukanAwardGraphic *)p)->proc=GFL_USE_AddMainTask((u32)ZENKOKU_ZUKAN_AWARD_GRAPHIC_Task,(u32)p,0);
 return p;
}

/*
 * volatile: BLDCNT stores 021B9FDE/021B9FE4; DISPCNT accesses 021B9FE6..021B9FF4
 * 1DD68 ignores incoming arguments and tails with fixed 1,2,0.
 */
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_Delete(char *p)
{
    TCB_DeleteTask(((struct ZenkokuZukanAwardGraphic *)p)->proc);
    ZENKOKU_ZUKAN_AWARD_GRAPHIC_DeleteCamera((u32 *)(p+8));
    ZENKOKU_ZUKAN_AWARD_GRAPHIC_DeleteClact(p+4);
    ZENKOKU_ZUKAN_AWARD_GRAPHIC_CleanupBg(p);
    GF_FONT_SetDefaultTextColor();
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile u32 *)0x04000000 &= 0xFFFF1FFF;
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
    MI_CpuFill8(p,0,16);
    GFL_HEAP_Free(p);
}

void ZENKOKU_ZUKAN_AWARD_GRAPHIC_Update(char *p)
{
    ZENKOKU_ZUKAN_AWARD_GRAPHIC_Draw(p + 4);
    ZENKOKU_ZUKAN_AWARD_GRAPHIC_Noop(p);
}

u32 ZENKOKU_ZUKAN_AWARD_GRAPHIC_GetActor(char *p) { return ZENKOKU_ZUKAN_AWARD_GRAPHIC_GetValue((const u32 *)(p+4)); }

void ZENKOKU_ZUKAN_AWARD_GRAPHIC_Task(void *unused, char *p)
{
    ZENKOKU_ZUKAN_AWARD_GRAPHIC_DrawObjects(p);
    ZENKOKU_ZUKAN_AWARD_GRAPHIC_VBlank(p + 4);
}

void ZENKOKU_ZUKAN_AWARD_GRAPHIC_SetupBg(void *p,u32 heap)
{
    u32 i;
    MI_CpuFill8(p,0,4);
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    BG_SYS_SetGraphicsMode((struct DispConfig *)config);
    for(i=0;i<2;i++) {
        const struct ZenkokuZukanAwardGraphicBgRow *r=&records[i];
        u32 id=r->id;
        BG_SYS_InitBgLayer((u8)id,(const struct BgTemplate *)r->cfg,(u8)r->type);
        BG_SYS_FreeSlot(id);
        BG_SYS_SetPlaneVisible(id,r->enable);
    }
}

void ZENKOKU_ZUKAN_AWARD_GRAPHIC_CleanupBg(void *p) { u32 i;for(i=0;i<2;i++)BG_SYS_FreeLayerBuf((u8)records[i].id);BMP_WIN_Exit();BG_SYS_Delete();MI_CpuFill8(p,0,4); }

void ZENKOKU_ZUKAN_AWARD_GRAPHIC_Noop(void *p) { }

void ZENKOKU_ZUKAN_AWARD_GRAPHIC_DrawObjects(void *p) { BG_SYS_Update(); }

void ZENKOKU_ZUKAN_AWARD_GRAPHIC_SetupClact(unsigned char *p, int a, int b)
{
    MI_CpuFill8(p, 0, 4);
    CLACT_InitSystem((struct SysInit *)0x021BA290, (struct DispVramCfg *)a, b);
    ((struct ClactCtx *)p)->unit = CLACT_CreateUnit(0x80, 0, b);
    CLACT_SetUnitDefaultRenderer(((struct ClactCtx *)p)->unit);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}

/*
 * Addresses are Black-image addresses.
 */
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_DeleteClact(char *p)
{
    CLACT_DeleteUnit(((struct ClactCtx *)p)->unit);
    CLACT_ExitSystem();
    MI_CpuFill8(p, 0, 4);
}

void ZENKOKU_ZUKAN_AWARD_GRAPHIC_Draw(void *p) { CLACT_DrawSystem(); }

void ZENKOKU_ZUKAN_AWARD_GRAPHIC_VBlank(void *p) { CLACT_VBlankSystem(); }

u32 ZENKOKU_ZUKAN_AWARD_GRAPHIC_GetValue(const u32 *p) { return *p; }

void ZENKOKU_ZUKAN_AWARD_GRAPHIC_SetupCamera(u32 **out,u32 heap)
{
    G3D_SYSTEM_Init(0,1,0,1,0,heap,ZENKOKU_ZUKAN_AWARD_Callback);
    *out=G3D_CAMERA_Create(0,*(s16 *)(dims+12),*(s16 *)(dims+14),0x1555,0,4096,0x400000,0,&vec1,&vec2,&vec3,heap);
}

void ZENKOKU_ZUKAN_AWARD_GRAPHIC_DeleteCamera(u32 *p)
{
    G3D_SYSTEM_Exit(G3D_CAMERA_Delete((void *)(*p)));
}
