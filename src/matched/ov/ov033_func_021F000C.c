/*
 * function: DOWSING_Create
 * address:  0x021F000C
 * packet:   pkt_ov033_021F000C
 * region:   ov033
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   DOWSING_InitBgsAndActorUnit 0x021F06AC thumb ov033
 *   DOWSING_LoadBackground 0x021F0760 thumb ov033
 *   DOWSING_CreateParts 0x021F07F4 thumb ov033
 *   DOWSING_CreateCloseButton 0x021F0924 thumb ov033
 *   ARC_UTIL_LoadMemberWithSize 0x0204A298 arm
 *   func_020056A0 0x020056A0 thumb
 *   DOWSING_TaskTransferPalettes 0x021F0674 thumb ov033
 *   DOWSING_InitFade 0x021F0B74 thumb ov033
 *   DOWSING_UpdateDisplay 0x021F05A4 thumb ov033
 *   FIELDMAP_GetGameSystem 0x02188C80 thumb ov021
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetEventWork 0x0201296C thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   func_0200BE48 0x0200BE48 thumb
 *   DOWSING_CreateSearch 0x021EFEC0 thumb ov033
 *   func_0207D63C 0x0207D63C arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   sDowsingFileName 0x021F0E60 data ov033 a1
 */
#include "../include/Obj00618.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void DOWSING_InitBgsAndActorUnit(char *p);
extern void DOWSING_LoadBackground(char *p);
extern void DOWSING_CreateParts(void *);
extern void DOWSING_CreateCloseButton(void *);
struct Big;
struct BigObj;
struct Ctx;
extern int ARC_UTIL_LoadMemberWithSize(int a0, int a1, int a2, int a3, u32 *out);
extern void *func_020056A0(void *fn, void *ctx, u32 a);
extern void DOWSING_TaskTransferPalettes(int a, unsigned char *p);
extern void DOWSING_InitFade(char *p);
extern void DOWSING_UpdateDisplay(char *p, int flag);
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern u16 *func_0200BE48(void *sys);
extern void *DOWSING_CreateSearch(u32, u32, u32);
extern void func_0207D63C(u32 reg, int plane1, int plane2, int ev1, int ev2);
extern void GFL_NET_RestartWithDefaultTimeout(u32, u32);
extern const char sDowsingFileName[];

void *DOWSING_Create(u32 heap, u32 heap2, u32 a, u32 b)
{
    char *p;
    u32 size;
    u32 s;
    u32 v;

    p = func_02030734(heap, 0xD4, 1, sDowsingFileName, 0x272);
    ((struct Obj00618 *)p)->f0 = heap;
    ((struct Obj00618 *)p)->f2 = heap2;
    ((struct Obj00618 *)p)->f4 = a;
    ((struct Obj00618 *)p)->f8 = b;
    DOWSING_InitBgsAndActorUnit(p);
    DOWSING_LoadBackground(p);
    DOWSING_CreateParts(p);
    DOWSING_CreateCloseButton(p);
    ((struct Obj00618 *)p)->f60 = (void *)ARC_UTIL_LoadMemberWithSize(0xC3, 0xD, 0, ((struct Obj00618 *)p)->f0, &size);
    ((struct Obj00618 *)p)->fA8 = func_020056A0(DOWSING_TaskTransferPalettes, p, 1);
    ((struct Obj00618 *)p)->fAC = 0;
    ((struct Obj00618 *)p)->fB0 = 1;
    DOWSING_InitFade(p);
    ((struct Obj00618 *)p)->f64 = 10;
    ((struct Obj00618 *)p)->f68 = 9;
    ((struct Obj00618 *)p)->f6C = 10;
    ((struct Obj00618 *)p)->f70 = 0;
    ((struct Obj00618 *)p)->f7C = 0;
    ((struct Obj00618 *)p)->f88 = 0;
    ((struct Obj00618 *)p)->f8C = 0;
    ((struct Obj00618 *)p)->f90 = 0;
    ((struct Obj00618 *)p)->f94 = 0;
    ((struct Obj00618 *)p)->f9C = 0;
    ((struct Obj00618 *)p)->fA4 = 0;
    DOWSING_UpdateDisplay(p, 1);
    ((struct Obj00618 *)p)->fC8 = 1;
    ((struct Obj00618 *)p)->fCC = 1;
    s = (u32)GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem((void *)(((struct Obj00618 *)p)->f8)));
    v = GAME_DATA_GetEventWork((const struct BigObj *)s);
    ((struct Obj00618 *)p)->fD0 = DOWSING_CreateSearch(((struct Obj00618 *)p)->f0, v, (u32)func_0200BE48(GAME_DATA_GetSaveControl((struct Big *)s)));
    func_0207D63C(0x04001050, 0x10, 0x18, 1, 7);
    GFL_NET_RestartWithDefaultTimeout(0, ((struct Obj00618 *)p)->f0);
    return p;
}
