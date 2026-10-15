/*
 * function: BSUBWAY_SCR_CreateWork
 * address:  0x021C9934
 * packet:   pkt_ov021_021C9934
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_02030734  0x02030734  arm
 *   d_021DE58C     0x021DE58C  data  ov021
 *   func_02008550  0x02008550  thumb
 *   func_020071CC  0x020071CC  thumb
 *   GDS_PROFILE_SetFieldRecFlag1  0x0200D868  thumb
 *   GAME_DATA_SetCurrentEvent  0x02012EE4  thumb
 *   BSUBWAY_SCR_GetMemberNum  0x021CA270  thumb  ov021
 *   GDS_PROFILE_ClearFieldRec  0x0200D85C  thumb
 *   GDS_PROFILE_ClearFieldRecCount03  0x0200DA14  thumb
 *   GDS_PROFILE_GetScoreRecCountC  0x0200DB44  thumb
 *   GDS_PROFILE_GetScoreRecCountA  0x0200DAC4  thumb
 *   BSUBWAY_SCR_SetWinCount  0x021CA238  thumb  ov021
 *   GDS_PROFILE_SetFieldRecField  0x0200D914  thumb
 *   GDS_PROFILE_GetFieldRecField  0x0200D884  thumb
 *   BSUBWAY_SCR_LoadPartyCopy  0x021CA1E4  thumb  ov021
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   BSUBWAY_SCR_CreatePartnerMons  0x021CBF38  thumb  ov021
 *   GDS_PROFILE_GetFieldRecCount03  0x0200DA54  thumb
 *   GDS_PROFILE_GetScoreRecCountCDec  0x0200DB80  thumb
 *   BSUBWAY_SCR_SetWinCountFromRound  0x021CA258  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 magic;
    u32 heap;
    u8 f8;
    u8 kind;
    u8 fa;
    u8 fb;
    u16 lo : 5;
    u16 sel : 3;
    u16 hi : 8;
    u8 pad0e[0x1e - 0x0e];
    u8 f1e[4];
    u8 pad22[0x32 - 0x22];
    u16 f32[14];
    u8 pad4e[0x6c - 0x4e];
    void *sys;
    void *f70;
    void *f74;
    void *f78;
    u8 pad7c[0x2c8 - 0x7c];
    u8 big[3][0x120];
    u8 small[22][0x14];
} Obj;

extern const char d_021DE58C[];

struct Big;
struct Blk1AC;
struct Blk3C;
struct Ctx;
struct Sub020071CCCtrl;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct Sub0200852CObj;
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern void GDS_PROFILE_SetFieldRecFlag1(struct Blk3C *p, u32 v);
extern char *GAME_DATA_SetCurrentEvent(char *base, int v);
extern int BSUBWAY_SCR_GetMemberNum(u16 kind);
extern void GDS_PROFILE_ClearFieldRec(struct Blk3C *p);
extern void GDS_PROFILE_ClearFieldRecCount03(struct Blk3C *p);
extern u32 GDS_PROFILE_GetScoreRecCountC(struct Blk1AC *p, u32 i);
extern u16 GDS_PROFILE_GetScoreRecCountA(struct Blk1AC *p, u32 i);
extern void BSUBWAY_SCR_SetWinCount(u8 *p, u16 v);
extern void GDS_PROFILE_SetFieldRecField(struct Blk3C *p, u32 id, const void *src);
extern u32 GDS_PROFILE_GetFieldRecField(struct Blk3C *p, u32 id, void *out);
extern void BSUBWAY_SCR_LoadPartyCopy(u8 *p);
extern u8 *GAME_DATA_GetMyPlayerWork(void *p);
extern void BSUBWAY_SCR_CreatePartnerMons(Obj *p, void *a, u16 b, u32 c, void *d, u16 e);
extern u16 GDS_PROFILE_GetFieldRecCount03(struct Blk3C *p);
extern u16 GDS_PROFILE_GetScoreRecCountCDec(struct Blk1AC *p, u32 i);
extern void BSUBWAY_SCR_SetWinCountFromRound(Obj *p, u16 a, u16 b);

Obj *BSUBWAY_SCR_CreateWork(void *arg, int mode, u8 kind)
{
    void *sys;
    void *save;
    void *res;
    Obj *p;
    int i;
    u32 base;
    u32 k;
    u16 v;
    u8 t;

    sys = GAMESYSTEM_GetGameData(arg);
    save = GAME_DATA_GetMyStatus(sys);
    res = GAME_DATA_GetSaveControl(sys);
    p = func_02030734(4, 0x7EC, 1, d_021DE58C, 0x5f);
    p->heap = 4;
    p->magic = 0x12345678;
    p->sys = sys;
    p->fa = func_02008550(save);
    p->f70 = func_020071CC(res, 0x39);
    p->f74 = func_020071CC(res, 0x3a);
    p->f78 = func_020071CC(res, 0x3b);
    GDS_PROFILE_SetFieldRecFlag1(p->f70, 0);
    GAME_DATA_SetCurrentEvent(sys, (int)p);
    if (mode == 0) {
        p->kind = kind;
        p->f8 = BSUBWAY_SCR_GetMemberNum(p->kind);
        for (i = 0; i < 4; i++)
            p->f1e[i] = 0xff;
        for (i = 0; i < 14; i++)
            p->f32[i] = 0xffff;
        GDS_PROFILE_ClearFieldRec(p->f70);
        GDS_PROFILE_ClearFieldRecCount03(p->f70);
        if (GDS_PROFILE_GetScoreRecCountC(p->f74, p->kind) == 1)
            BSUBWAY_SCR_SetWinCount((u8 *)p, GDS_PROFILE_GetScoreRecCountA(p->f74, p->kind));
        t = p->kind;
        GDS_PROFILE_SetFieldRecField(p->f70, 0, &t);
    } else {
        p->kind = GDS_PROFILE_GetFieldRecField(p->f70, 0, 0);
        p->f8 = BSUBWAY_SCR_GetMemberNum(p->kind);
        if (GDS_PROFILE_GetFieldRecField(p->f70, 10, 0) != 0)
            BSUBWAY_SCR_LoadPartyCopy((u8 *)p);
        GDS_PROFILE_GetFieldRecField(p->f70, 5, p->f1e);
        GDS_PROFILE_GetFieldRecField(p->f70, 8, p->f32);
        if (p->kind == 2 || p->kind == 7) {
            p->sel = (u8)GDS_PROFILE_GetFieldRecField(p->f70, 9, 0);
            GDS_PROFILE_GetFieldRecField(p->f70, 6, p->small[p->sel]);
            base = 0x12f;
            if (func_02008550((const struct Sub0200852CObj *)(GAME_DATA_GetMyPlayerWork(sys) + 0x20)) != 0)
                base -= 3;
            i = p->sel;
            BSUBWAY_SCR_CreatePartnerMons(p, p->big[i], base + i, GDS_PROFILE_GetFieldRecField(p->f70, 7, 0), p->small[i], p->heap);
        }
        k = p->kind;
        if (GDS_PROFILE_GetScoreRecCountC(p->f74, k) == 1) {
            v = GDS_PROFILE_GetFieldRecCount03(p->f70);
            BSUBWAY_SCR_SetWinCountFromRound(p, GDS_PROFILE_GetScoreRecCountCDec(p->f74, k), v);
        }
    }
    return p;
}
