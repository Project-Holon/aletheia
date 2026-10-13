/*
 * function: GIMMICK46_HopEventProc
 * address:  0x021F3EFC
 * packet:   pkt_ov046_021F3EFC
 * region:   ov046
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The ov046 token is dropped from sGimmick46HopHeights (contested hint).
 *
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FIELD_PLAYER_SetPos  0x021A3044  thumb  ov021
 *   sGimmick46HopHeights  0x021F4130  data  a4
 */

typedef unsigned int u32;
typedef unsigned char u8;
struct Big;
struct Ctx;
struct Obj;
extern void *GAME_EVENT_GetGameSystem(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FIELDMAP_GetExpObj(int *);
extern int *FIELDMAP_GetCommonWork(char *, int);
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *p, struct VecFx32 *out);
extern void FIELD_PLAYER_SetPos(u8 *p, void *v);
extern int sGimmick46HopHeights[];

int GIMMICK46_HopEventProc(u32 a, int *b)
{
    void *x;
    int *w;
    int r = 1;
    void *c;
    int v[3];

    x = GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem((void *)a));
    FIELDMAP_GetExpObj(x);
    w = FIELDMAP_GetCommonWork(x, 1) + 3;
    GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData((void *)FIELDMAP_GetGameSystem(x))), 10);
    switch (*b) {
    case 0:
        GFL_USE_PlaySeDefaultVolume(0x55e);
        (*b)++;
        break;
    case 1:
        c = FIELDMAP_GetFieldPlayer((void *)x);
        FIELD_PLAYER_GetPos(c, (struct VecFx32 *)v);
        v[0] = v[0] + w[1];
        v[1] = w[2] + (sGimmick46HopHeights[((u8 *)w)[3]] << 12);
        FIELD_PLAYER_SetPos(c, v);
        ((u8 *)w)[3] = ((u8 *)w)[3] + 1;
        if (((u8 *)w)[3] >= 8) {
            GFL_USE_PlaySeDefaultVolume(0x6d3);
            return r;
        }
        break;
    }
    return 0;
}
