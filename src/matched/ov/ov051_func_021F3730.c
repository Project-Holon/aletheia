/*
 * function: FIELD_GIMMICK_D06_Init
 * address:  0x021F3730
 * packet:   pkt_ov051_021F3730
 * region:   ov051
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     the flag test reads p[0] as unsigned char (ldrb); a plain char
 *           test gives ldrsb with a zero register hoisted above the branch.
 *
 * symbols:
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   FIELD_GIMMICK_D06_GetGimmickId  0x021F3D94  thumb  ov051
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 *   func_02030734  0x02030734  arm
 *   FIELD_EFFECT_LoadResources  0x021ABE30  thumb  ov021
 *   GIMMICK49_Exit  0x021F36EC  thumb  ov051
 *   FIELD_GIMMICK_D06_GetStonePositions  0x021F36E0  thumb  ov051
 *   FIELD_GIMMICK_D06_AddStone  0x021F3B44  thumb  ov051
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb
 *   FLDMMDL_SysSearchUseMmdl  0x0216DD1C  thumb
 *   FLDMMDL_GetObjId  0x0216D588  thumb
 *   FIELD_GIMMICK_D06_AttachStone  0x021F3B88  thumb  ov051
 *   FIELD_GIMMICK_D06_GetPanelCount  0x021F3724  thumb  ov051
 *   FIELD_GIMMICK_D06_GetPanelPositions  0x021F3718  thumb  ov051
 *   FIELD_GIMMICK_D06_AddPanelPulse  0x021F3CCC  thumb  ov051
 *   gGimmickD06SourceFile     0x021F40A0  data  ov051  a4
 */
#include "../include/Obj09844.h"

extern unsigned short FIELDMAP_GetHeapId(unsigned char *p);
typedef unsigned char  u8;
struct Big;
struct Ctx;
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
extern unsigned int FIELDMAP_GetEffect(u8 *p);
extern unsigned short FIELDMAP_GetZoneId(u8 *p);
extern int FIELD_GIMMICK_D06_GetGimmickId(int a);
typedef signed int     s32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, unsigned int b);
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void FIELD_EFFECT_LoadResources(int, int *, int);
extern int GIMMICK49_Exit(int a);
extern int FIELD_GIMMICK_D06_GetStonePositions(int a);
extern void FIELD_GIMMICK_D06_AddStone(int *a, int *out, int x, int y);
extern void *FIELDMAP_GetMmdlSys(unsigned char *p);
extern int FLDMMDL_SysSearchUseMmdl(void *it, int *cur, int *v);
extern int FLDMMDL_GetObjId(int a);
extern void FIELD_GIMMICK_D06_AttachStone(int *a, u32 *out, int c);
extern int FIELD_GIMMICK_D06_GetPanelCount(int a);
extern int FIELD_GIMMICK_D06_GetPanelPositions(int a);
extern void FIELD_GIMMICK_D06_AddPanelPulse(int *a, unsigned *b, int x, int y, int z);
extern char gGimmickD06SourceFile[];

void FIELD_GIMMICK_D06_Init(unsigned char *a)
{
    int n;
    int v;
    int cur;
    int r4;
    unsigned h;
    int sp8;
    int r5;
    char *p;
    int *q;
    unsigned int i;
    unsigned int cnt;
    int *e;
    void *it;

    r4 = FIELDMAP_GetHeapId(a);
    h = (unsigned int)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem((void *)a)));
    sp8 = FIELDMAP_GetEffect((u8 *)a);
    r5 = FIELDMAP_GetZoneId((u8 *)a);
    p = (char *)GIMMICK_WORK_GetSaveArea((struct Rec94 *)h, FIELD_GIMMICK_D06_GetGimmickId(r5));
    q = func_02030734(r4, 0xa4, 1, gGimmickD06SourceFile, 0xca);
    *(int * *)&((struct Obj09844 *)p)->f4 = q;
    q[1] = (int)p;
    q[2] = (int)a;
    q[0] = r5;
    n = 0xb;
    FIELD_EFFECT_LoadResources(sp8, &n, 1);
    if (((struct Obj09844 *)p)->f0 == 0) {
        cnt = GIMMICK49_Exit(q[0]);
        e = (int *)FIELD_GIMMICK_D06_GetStonePositions(q[0]);
        i = 0;
        if (i < cnt)
            for (; i < cnt; i++) {
                FIELD_GIMMICK_D06_AddStone(q, q + 3 + i * 2, e[0], e[2]);
                e += 3;
            }
    } else {
        i = 0;
        v = 0;
        it = FIELDMAP_GetMmdlSys((void *)a);
        while (FLDMMDL_SysSearchUseMmdl(it, &cur, &v)) {
            if (FLDMMDL_GetObjId(cur) == 0xfd) {
                FIELD_GIMMICK_D06_AttachStone(q, (u32 *)(q + 3 + i * 2), cur);
                i++;
                if (i >= 12)
                    break;
            }
        }
    }
    cnt = FIELD_GIMMICK_D06_GetPanelCount(q[0]);
    e = (int *)FIELD_GIMMICK_D06_GetPanelPositions(q[0]);
    i = 0;
    if (i < cnt)
        for (; i < cnt; i++) {
            FIELD_GIMMICK_D06_AddPanelPulse(q, (unsigned int *)(q + 0x1b + i), e[0], e[1], e[2]);
            e += 3;
        }
    *p = 1;
}
