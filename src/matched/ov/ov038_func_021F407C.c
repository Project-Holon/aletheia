/*
 * function: GIMMICK38_EventBumpClosedDoor
 * address:  0x021F407C
 * packet:   pkt_ov038_021F407C
 * region:   ov038
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     `k++` on the u8 local keeps the increment of the stored zero
 *           (adds; lsls; lsrs); `k = k + 1` folds it to `movs #1` and swaps
 *           a1/sys between r5 and r6.
 *
 * symbols:
 *   func_020124E4 0x020124E4 thumb
 *   GAMESYSTEM_GetFieldMap 0x0201210C thumb
 *   FIELDMAP_GetExpObj 0x02188D2C thumb ov021
 *   FIELDMAP_GetCommonWork 0x021897BC thumb
 *   FIELDMAP_GetFieldPlayer 0x02188CB4 thumb ov021
 *   FLD_EXP_OBJ_GetAnime 0x021BE674 thumb ov021
 *   FLD_EXP_OBJ_SetModelHidden 0x021BE4B4 thumb ov021
 *   FLD_EXP_OBJ_GetModelStatus 0x021BE480 thumb ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled 0x021BE700 thumb ov021
 *   FLD_EXP_OBJ_SetAnimePaused 0x021BE6B0 thumb ov021
 *   FLD_EXP_OBJ_SetAnimeFrame 0x021BE6CC thumb ov021
 *   FLD_EXP_OBJ_IsAnimeStopped 0x021BE6BC thumb ov021
 *   func_020061E4 0x020061E4 thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int x, y, z;
} Vec;

struct Ctx;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FIELDMAP_GetExpObj(int *p);
extern u8 *FIELDMAP_GetCommonWork(void *p, int idx);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern void FLD_EXP_OBJ_SetModelHidden(char *p, int i, int j, int v);
extern Vec *FLD_EXP_OBJ_GetModelStatus(char *p, int i, int j);
extern void FLD_EXP_OBJ_SetAnimeEnabled(void *p, int i, int j, int k, int flag);
extern void FLD_EXP_OBJ_SetAnimePaused(unsigned char *p, int v);
extern void FLD_EXP_OBJ_SetAnimeFrame(int a, int b, int c, int d, int e);
extern int FLD_EXP_OBJ_IsAnimeStopped(int *p);
extern void func_020061E4(u32 a);

int GIMMICK38_EventBumpClosedDoor(int a0, int *a1)
{
    void *sys;
    char *h;
    u8 *s;
    u8 c;
    u8 k;
    void *o;
    Vec *v;

    sys = GAMESYSTEM_GetFieldMap(func_020124E4((void *)a0));
    h = (char *)FIELDMAP_GetExpObj(sys);
    s = FIELDMAP_GetCommonWork(sys, 1);
    FIELDMAP_GetFieldPlayer(sys);
    k = 0;
    c = s[3] + 0x12;
    if (s[6] == 1) {
        k++;
    }
    o = FLD_EXP_OBJ_GetAnime(h, 0, 0x21, k);
    switch (*a1) {
    case 0:
        FLD_EXP_OBJ_SetModelHidden(h, 0, c, 1);
        FLD_EXP_OBJ_SetModelHidden(h, 0, 0x21, 0);
        v = FLD_EXP_OBJ_GetModelStatus(h, 0, c);
        *FLD_EXP_OBJ_GetModelStatus(h, 0, 0x21) = *v;
        FLD_EXP_OBJ_SetAnimeEnabled(h, 0, 0x21, k, 1);
        FLD_EXP_OBJ_SetAnimePaused(o, 0);
        FLD_EXP_OBJ_SetAnimeFrame((int)h, 0, 0x21, k, 0);
        func_020061E4(0x6C5);
        *a1 = *a1 + 1;
        break;
    case 1:
        if (FLD_EXP_OBJ_IsAnimeStopped(o)) {
            FLD_EXP_OBJ_SetAnimeEnabled(h, 0, 0x21, k, 0);
            FLD_EXP_OBJ_SetModelHidden(h, 0, 0x21, 1);
            FLD_EXP_OBJ_SetModelHidden(h, 0, c, 0);
            return 1;
        }
        break;
    }
    return 0;
}
