/*
 * function: SCRCMD_SODATEYA_RunPartyMenuEvent
 * address:  0x0215D1E4
 * packet:   pkt_ov010_0215D1E4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   FIELD_STATUS_CreateSubProcListEvent  0x02014910  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct { u32 pad[15]; u32 f3c; } O8;
typedef struct { u8 pad[15]; u8 fF; } OC;
typedef struct {
    void *f0;
    void *f4;
    O8 *f8;
    OC *fC;
    u16 *f10;
} Ctx;

extern void *EVENT_FIELDMAP_CONTROL_StartFadeOut(void *, void *, int, int);
extern void *EVENT_FIELDMAP_CONTROL_StartFadeIn(void *, void *, int, int, int, int, int);
struct Evt;
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern int FIELD_STATUS_CreateFieldCloseEvent(int a0, int a1);
extern void *FIELD_STATUS_CreateSubProcListEvent(char *a0, int a1, int a2, int a3);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *);
extern u32 func_020307B0(void *p);

int SCRCMD_SODATEYA_RunPartyMenuEvent(void *a, u32 *st, Ctx *c)
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
        c->f8->f3c = c->fC->fF;
        *st = 2;
        break;
    case 2:
        GAME_EVENT_CallEvent(a, FIELD_STATUS_CreateSubProcListEvent(p0, (int)c->f4, (int)c->f8, (int)c->fC));
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
        *c->f10 = c->f8->f3c;
        func_020307B0(c->f8);
        func_020307B0(c->fC);
        return 1;
    }
    return 0;
}
