/*
 * function: FIELDMAP_SeqInitSystem
 * address:  0x021880C8
 * packet:   pkt_ov021_021880C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sVramBankSetup     0x021D3688  data
 *   sClactSetup     0x021D3604  data
 *   sFieldMapSourceName     0x021DD9C0  data
 *   abs_id_19      0x00000013  data
 *   abs_id_18      0x00000012  data
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   FIELDMAP_InitBgSystem  0x02188D5C  thumb
 *   CLACT_InitSystem  0x0204A48C  arm
 *   func_020434DC  0x020434DC  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   BMP_WIN_Init  0x02045088  arm
 *   GF_FONT_ResetTextColor  0x0201DD60  thumb
 *   G3D_SYSTEM_Init  0x02046440  arm
 *   FIELDMAP_SetupG3d  0x02188E50  thumb
 *   FIELDMAP_CreateG3dResources  0x02188EE4  thumb
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   FIELD_G3D_MAPPER_Create  0x0218C9E8  thumb
 *   func_020056A0  0x020056A0  thumb
 *   FIELDMAP_VBlankTask  0x02189108  thumb
 *   func_02030CB0  0x02030CB0  arm
 *   func_02030734  0x02030734  arm
 *   func_02030CBC  0x02030CBC  arm
 *   FIELD_TASK_MANAGER_Create  0x021C6D10  thumb
 *   FLD_VREQ_Create  0x021D317C  thumb
 *   func_02013CC8  0x02013CC8  thumb
 *   func_02013CE0  0x02013CE0  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_02035660  0x02035660  arm
 */
#include "../include/Obj01489.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 sVramBankSetup[];
extern u8 sClactSetup[];
extern char sFieldMapSourceName[];
extern u8 abs_id_19[];
extern u8 abs_id_18[];

struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void FIELDMAP_InitBgSystem(u16 *p);
struct BigObj;
struct Cfg;
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern void func_020434DC(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
struct Ctx;
extern void BMP_WIN_Init(u16 heapId);
extern void GF_FONT_ResetTextColor(void);
extern void G3D_SYSTEM_Init(u32 texMode, u32 texSize, u32 plttMode, u32 plttSize,
                          u32 fifoSize, u32 heap, void (*setup)(void));
extern void FIELDMAP_SetupG3d(void);
extern void FIELDMAP_CreateG3dResources(u8 *p);
extern u8 GAME_DATA_GetSeason(const struct BigObj *p);
extern char *FIELD_G3D_MAPPER_Create(int heap, int b);
extern void *func_020056A0(void (*cb)(int, u8 *), void *arg, int pri);
extern void FIELDMAP_VBlankTask(int unused, u8 *p);
extern u32 func_02030CB0(u32 idx);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern u8 *FIELD_TASK_MANAGER_Create(int n, int heap);
extern void *FLD_VREQ_Create(u32 heap);
extern u32 func_02013CC8(u32 id);
extern u32 func_02013CE0(u32 id);
extern int func_02034AC4(int id);
extern void func_02035660(u32 a);

int FIELDMAP_SeqInitSystem(int unused, u8 *p)
{
    u16 heap = ((struct Obj01489 *)p)->f0;

    BG_SYS_SetVramBanks((const struct DispVram *)sVramBankSetup);
    FIELDMAP_InitBgSystem((u16 *)p);
    CLACT_InitSystem((const struct Cfg *)sClactSetup, (u32)sVramBankSetup, 0x89);
    func_020434DC(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
    BMP_WIN_Init(heap);
    GF_FONT_ResetTextColor();
    G3D_SYSTEM_Init(0, 3, 0, 1, 0x1000, ((struct Obj01489 *)p)->f0, FIELDMAP_SetupG3d);
    FIELDMAP_CreateG3dResources(p);
    *(char * *)&((struct Obj01489 *)p)->f48 = FIELD_G3D_MAPPER_Create(((struct Obj01489 *)p)->f0, GAME_DATA_GetSeason((const struct BigObj *)(((struct Obj01489 *)p)->f8)));
    ((struct Obj01489 *)p)->fAC = func_020056A0(FIELDMAP_VBlankTask, p, 0);
    ((struct Obj01489 *)p)->f114 = func_02030734(heap, func_02030CB0(0x20), 0, sFieldMapSourceName, 0x26B);
    ((struct Obj01489 *)p)->f110 = func_02030CBC(0x20, ((struct Obj01489 *)p)->f114);
    *(u8 * *)&((struct Obj01489 *)p)->f134 = FIELD_TASK_MANAGER_Create(0xA, ((struct Obj01489 *)p)->f0);
    ((struct Obj01489 *)p)->f14C = FLD_VREQ_Create(((struct Obj01489 *)p)->f0);
    func_02034AC4((func_02013CC8(((struct Obj01489 *)p)->fD0) == 1 || func_02013CE0(((struct Obj01489 *)p)->fD0) == 1) ? (int)abs_id_19 : (int)abs_id_18);
    func_02035660(0x1E);
    return 1;
}
