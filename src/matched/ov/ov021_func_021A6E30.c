/*
 * function: FIELDMAP_CTRL_HYBRID_Create
 * address:  0x021A6E30
 * packet:   pkt_ov021_021A6E30
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Creates the 12-byte model holder for a field-map object, loads its
 * model, and places it through FIELDMAP_CTRL_HYBRID_SetMode in the mode the object's
 * record asks for (0: at pos; else attached to the record's anchor).
 *
 * symbols:
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   FIELDMAP_SetCtrlWork  0x02188CAC  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   GAME_DATA_GetPlayerMoveForm  0x02012AC0  thumb
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_DRAW_GetBlactAnime  0x0219F058  thumb  ov021
 *   FIELD_PLAYER_CreateGrid  0x021A35E0  thumb  ov021
 *   FIELD_PLAYER_CreateNogrid  0x021A3664  thumb  ov021
 *   FIELD_PLAYER_SetDirDisp  0x021A305C  thumb  ov021
 *   GAME_DATA_GetPlayerRailLocation  0x02012AB8  thumb
 *   FIELDMAP_CTRL_HYBRID_SetMode  0x021A7258  thumb  ov021
 *   FLDMMDL_GetPosPtr  0x0216D888  thumb  ov010
 *   FIELDMAP_SetTargetPos  0x02188D40  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   gFieldMapCtrlHybridFileName     0x021DDF64  data  a1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct VecFx32 { s32 x; s32 y; s32 z; } VecFx32;

typedef struct Holder {
    int mode;
    void *f04;
    void *f08;
} Holder;

extern char gFieldMapCtrlHybridFileName;

extern void *FIELDMAP_GetGameSystem(void *o);
struct Ctx;
struct Rec44;
struct SaveBlock;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetMyPlayerWork(struct SaveBlock *p);
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void FIELDMAP_SetCtrlWork(u8 *p, u32 v);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern u8 GAME_DATA_GetPlayerMoveForm(const struct Rec44 *p);
extern void *FIELD_PLAYER_GetMmdl(u8 *p);
extern void FLDMMDL_DRAW_GetBlactAnime(u32 a, u16 *o1, u16 *o2);
extern void FIELD_PLAYER_CreateGrid(u32 *p, u32 heap);
extern void FIELD_PLAYER_CreateNogrid(u32 *p, u32 heap);
extern void FIELD_PLAYER_SetDirDisp(char *p, u32 b);
struct H4;
extern struct H4 *GAME_DATA_GetPlayerRailLocation(struct Rec44 *p);
extern void FIELDMAP_CTRL_HYBRID_SetMode(void *o, Holder *h, int mode, VecFx32 *pos, u16 e, u16 f, u16 g);
extern void *FLDMMDL_GetPosPtr(void *m);
extern void FIELDMAP_SetTargetPos(u8 *p, u32 v);
extern void FIELD_PLAYER_GetPos(unsigned char *p, struct VecFx32 *out);

void FIELDMAP_CTRL_HYBRID_Create(void *o, VecFx32 *pos, u16 e)
{
    void *r;
    u16 heap;
    Holder *h;
    int mode;
    void *m;
    VecFx32 *anchor;
    u16 anim[2];

    r = GAME_DATA_GetMyPlayerWork(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(o)));
    heap = FIELDMAP_GetHeapId(o);
    h = func_02030734(heap, sizeof(Holder), 1, &gFieldMapCtrlHybridFileName, 0xbd);
    FIELDMAP_SetCtrlWork(o, (u32)h);
    h->f04 = FIELDMAP_GetFieldPlayer(o);
    mode = GAME_DATA_GetPlayerMoveForm(r);
    h->mode = 2;
    m = FIELD_PLAYER_GetMmdl(h->f04);
    FLDMMDL_DRAW_GetBlactAnime((u32)m, &anim[0], &anim[1]);
    if (mode == 0) {
        FIELD_PLAYER_CreateGrid(h->f04, heap);
        FIELD_PLAYER_CreateNogrid(h->f04, heap);
        FIELD_PLAYER_SetDirDisp(h->f04, e);
        FIELDMAP_CTRL_HYBRID_SetMode(o, h, mode, pos, e, anim[0], anim[1]);
    } else {
        anchor = (VecFx32 *)GAME_DATA_GetPlayerRailLocation(r);
        FIELD_PLAYER_CreateNogrid(h->f04, heap);
        FIELD_PLAYER_CreateGrid(h->f04, heap);
        FIELD_PLAYER_SetDirDisp(h->f04, e);
        FIELDMAP_CTRL_HYBRID_SetMode(o, h, mode, anchor, e, anim[0], anim[1]);
    }
    FIELDMAP_SetTargetPos(o, (u32)FLDMMDL_GetPosPtr(m));
    FIELD_PLAYER_GetPos(h->f04, pos);
}
