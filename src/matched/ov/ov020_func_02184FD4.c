/*
 * function: EVENT_MAPCHANGE_CreateZoneStartWarpEvent
 * address:  0x02184FD4
 * packet:   pkt_ov020_02184FD4
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * blocker: byte-correct; the bl to 0x02014184 has no witness (unlabelled ARM9
 * Thumb leaf, sole caller in range). Evidence class: label / sole-ref/code.
 * Leaf 0x02014184 (arm9, Thumb, EXACT with match.py one, the integrator's to file):
 *   typedef short s16;
 *   typedef struct { int f0; s16 h4, h6, h8, ha; int fc, f10, f14, f18; } Obj;
 *   void ZONEDATA_SetDirectLocation(Obj *o, s16 a, s16 b, int c, int d, int e)
 *   { o->f0 = 1; o->h4 = a; o->h6 = -1; o->h8 = b; o->ha = 0; o->fc = 0;
 *     o->f10 = c; o->f14 = d; o->f18 = e; }
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   ZONEDATA_SetDirectLocation  0x02014184  thumb
 *   ZONEDATA_SetZoneStartLocation  0x02014204  thumb
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetPlayerPosition  0x02012AA0  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   GAME_DATA_GetPlayerDirectionType  0x02012AE4  thumb
 *   GAME_DATA_SetSpecialLocation  0x0201289C  thumb
 *   EVENT_MAPCHANGE_FadeDetachEvent  0x02184AB4  thumb  ov020
 *   EVENT_MAPCHANGE_InitWork  0x02184CEC  thumb  ov020
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short s16;

typedef struct { int w[7]; } V28;

struct BigObj;
struct Desc;
struct Obj;
struct Rec1C;
struct Rec44;
struct SaveBlock;
struct Vec12;
struct t;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
void ZONEDATA_SetDirectLocation(void *d, int a, int b, int c, int e, int f);
void ZONEDATA_SetZoneStartLocation(struct t *p, int id);
void *GAME_DATA_GetMyPlayerWork(struct SaveBlock *p);
struct Vec12 *GAME_DATA_GetPlayerPosition(struct Rec44 *p);
u16 GAME_DATA_GetPlayerZoneId(const struct Rec44 *p);
u32 GAME_DATA_GetPlayerDirectionType(const struct Rec44 *p);
void GAME_DATA_SetSpecialLocation(struct BigObj *p, const struct Rec1C *src);
int EVENT_MAPCHANGE_FadeDetachEvent(int ctx, int *state, u8 *p);
void EVENT_MAPCHANGE_InitWork(void **o, void *p);

void *EVENT_MAPCHANGE_CreateZoneStartWarpEvent(void *p, u16 id)
{
    V28 v;
    void *r0v = func_020122C0(p, 0, EVENT_MAPCHANGE_FadeDetachEvent, 0x9c);
    char *r5 = func_020124E8(r0v);
    int r6, r7;
    int *r4;

    EVENT_MAPCHANGE_InitWork((void **)r5, p);
    ZONEDATA_SetZoneStartLocation((struct t *)(r5 + 0x10), id);
    *(int *)(r5 + 0x2c) = 0;
    *(u16 *)(r5 + 0x18) = 1;
    r6 = (int)GAME_DATA_GetMyPlayerWork(*(void **)(r5 + 4));
    r4 = (int *)GAME_DATA_GetPlayerPosition((struct Rec44 *)r6);
    r7 = GAME_DATA_GetPlayerZoneId((const struct Rec44 *)r6);
    ZONEDATA_SetDirectLocation(&v, r7, (s16)GAME_DATA_GetPlayerDirectionType((const struct Rec44 *)r6), r4[0], r4[1], r4[2]);
    GAME_DATA_SetSpecialLocation(*(void **)(r5 + 4), (const struct Rec1C *)(&v));
    return r0v;
}
