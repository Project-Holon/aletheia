/*
 * function: FLD_FACEUP_Create
 * address:  0x021F5260
 * packet:   pkt_ov082_021F5260
 * region:   ov082
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Lever: declaring w before obj gives w r4 and obj r5.
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   func_02030734  0x02030734  arm
 *   FIELDMAP_GetFaceUpWorkPtr  0x02189A60  thumb  ov021
 *   FLD_FACEUP_InitAnim  0x021F58C0  thumb  ov082
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200873C  0x0200873C  thumb
 *   CONFIG_GetTextSpeed  0x02008374  thumb
 *   func_020122C0  0x020122C0  thumb
 *   FIELDMAP_GetTcblSys  0x02188D30  thumb  ov021
 *   func_02030DA8  0x02030DA8  arm
 *   func_020056A0  0x020056A0  thumb
 *   FLD_FACEUP_OpenEventMain  0x021F5338  thumb  ov082
 *   FLD_FACEUP_UpdateTaskMain  0x021F5748  thumb  ov082
 *   FLD_FACEUP_VBlankUpload  0x021F57D8  thumb  ov082
 *   gFldFaceupFileName     0x021F5920  data  a1
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02424.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern const char gFldFaceupFileName[];

typedef unsigned short u16;
struct Big;
struct Ctx;
struct Desc;
struct Sub02008700Obj;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u8 **FIELDMAP_GetFaceUpWorkPtr(void *p);
extern void FLD_FACEUP_InitAnim(char *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern unsigned int CONFIG_GetTextSpeed(int a0);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern u32 FIELDMAP_GetTcblSys(u8 *p);
extern void *func_02030DA8(void *a0, void *callback, void *ctx, int a3);
extern void *func_020056A0(void *callback, void *ctx, int a2);
extern int FLD_FACEUP_OpenEventMain(void *task, int *st);
extern void FLD_FACEUP_UpdateTaskMain(int a0, char *p);
extern void FLD_FACEUP_VBlankUpload(int a0, char *p);

void *FLD_FACEUP_Create(int a0, int a1, int a2, void *a3, int a4)
{
    u8 *w;
    void *obj;
    u32 mode;
    void *task;

    obj = GAMESYSTEM_GetFieldMap(a3);
    w = func_02030734(0x50, 0x78, 1, gFldFaceupFileName, 0xa2);
    if (*FIELDMAP_GetFaceUpWorkPtr(obj) != 0)
        return 0;
    *FIELDMAP_GetFaceUpWorkPtr(obj) = w;
    ((struct Obj02424 *)w)->fC = a0;
    ((struct Obj02424 *)w)->f10 = a4;
    ((struct Obj02424 *)w)->f70 = a2;
    FLD_FACEUP_InitAnim((char *)(w + 0x28));
    FLD_FACEUP_InitAnim((char *)(w + 0x4c));
    mode = CONFIG_GetTextSpeed((int)func_0200873C(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(a3))));
    if (mode == 0)
        w[0x55] = 3;
    else if (mode == 1)
        w[0x55] = 2;
    else
        w[0x55] = 1;
    w[0x31] = 2;
    task = func_020122C0(a3, 0, (void *)FLD_FACEUP_OpenEventMain, 0);
    ((struct Obj02424 *)w)->f14 = func_02030DA8((void *)FIELDMAP_GetTcblSys(obj), (void *)FLD_FACEUP_UpdateTaskMain, w, 0);
    ((struct Obj02424 *)w)->f18 = func_020056A0((void *)FLD_FACEUP_VBlankUpload, w, 1);
    ((struct Obj02424 *)w)->f1C = 0;
    ((struct Obj02424 *)w)->f74 = 1;
    return task;
}
