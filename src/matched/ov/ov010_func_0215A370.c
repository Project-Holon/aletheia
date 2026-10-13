/*
 * function: EVENT_POKE_STATUS_MoveSelectEvent
 * address:  0x0215A370
 * packet:   pkt_ov010_0215A370
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Case 2 loads 0x00000083 from the pool: an absolute symbol (overlay id),
 * see docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.
 *
 * symbols:
 *   ov131_id       0x00000083  data
 *   gPokeStatusProcData     0x021DC800  data  ov131
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct { u8 pad[0x11]; u8 f11; u8 f12; } O8;
typedef struct {
    void *f0;
    void *f4;
    O8 *f8;
    u16 *fC;
    u16 *f10;
} Ctx;

extern u8 ov131_id[];
extern u8 gPokeStatusProcData[];

extern void *EVENT_FIELDMAP_CONTROL_StartFadeOut(void *, void *, int, int);
extern void *EVENT_FIELDMAP_CONTROL_StartFadeIn(void *, void *, int, int, int, int, int);
struct Evt;
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
struct IcaAnime;
extern int FIELD_STATUS_CreateFieldCloseEvent(int a0, int a1);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *);
extern void GAMESYSTEM_CallProc(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 func_020307B0(void *p);

int EVENT_POKE_STATUS_MoveSelectEvent(void *a, u32 *st, Ctx *c)
{
    u32 s = *st;
    void *p0 = c->f0;
    switch (s) {
    case 0:
        GAME_EVENT_CallEvent(a, EVENT_FIELDMAP_CONTROL_StartFadeOut(p0, c->f4, 0, 0));
        *st = 1;
        break;
    case 1:
        GAME_EVENT_CallEvent(a, (struct Evt **)FIELD_STATUS_CreateFieldCloseEvent((int)p0, (int)c->f4));
        *st = 2;
        break;
    case 2:
        GAMESYSTEM_CallProc(p0, (u32)ov131_id, gPokeStatusProcData, c->f8);
        *st = 3;
        break;
    case 3:
        GAME_EVENT_CallEvent(a, FIELD_STATUS_CreateFieldOpenEvent(p0));
        *st = 4;
        break;
    case 4:
        GAME_EVENT_CallEvent(a, EVENT_FIELDMAP_CONTROL_StartFadeIn(p0, c->f4, 0, 0, 1, 0, 0));
        *st = 5;
        break;
    case 5:
        if (c->f8->f12 == 0) {
            *c->f10 = c->f8->f11;
            *c->fC = 1;
        } else {
            *c->f10 = 0;
            *c->fC = 0;
        }
        func_020307B0(c->f8);
        return 1;
    }
    return 0;
}
