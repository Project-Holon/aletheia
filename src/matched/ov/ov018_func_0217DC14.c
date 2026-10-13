/*
 * function: INTRUDE_SUBDISP_CreateMyPlayerActor
 * address:  0x0217DC14
 * packet:   pkt_ov018_0217DC14
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   GAME_DATA_GetExitMode  0x02012B58  thumb
 *   CLACT_CreateActor  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_0204B92C  0x0204B92C  arm
 *   d_021836D4  0x021836D4  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct { u16 a, b, c, d; } Rect;

typedef unsigned int   u32;
struct BigObj;
struct Ctx;
struct Obj;
struct Sub0200852CObj;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u8 GAME_DATA_GetExitMode(const struct BigObj *p);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, u16, u16);
extern void func_0204B3DC(struct Obj *, unsigned int);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_0204B92C(struct Obj *p, unsigned int v);
extern const Rect d_021836D4;

void INTRUDE_SUBDISP_CreateMyPlayerActor(int *p, void *a1)
{
    Rect r;
    int h;

    r = d_021836D4;
    h = (int)GAMESYSTEM_GetGameData((const struct Ctx *)p[0]);
    if (func_02008550((const struct Sub0200852CObj *)GAME_DATA_GetMyStatus((void *)h)) == 1) {
        r.c = 3;
    }
    p[0x98 / 4] = (int)CLACT_CreateActor((void *)p[0x54 / 4], p[1], p[2], p[4], &r, 0, 0x70);
    func_0204B6F4((struct Obj *)p[0x98 / 4], (u8)(GAME_DATA_GetExitMode((const struct BigObj *)h) + 1), 1);
    func_0204B3DC((struct Obj *)p[0x98 / 4], 0);
    func_0204B92C((struct Obj *)p[0x98 / 4], 1);
}
