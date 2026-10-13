/*
 * function: FIELD_ENCOUNT_StartScriptedWild
 * address:  0x021AA0A0
 * packet:   pkt_ov021_021AA0A0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb
 *   FIELDMAP_GetWeather  0x02188C6C  thumb
 *   WEATHER_GetWeatherId  0x021A1BF4  thumb
 *   FIELD_ENCOUNT_SetupParam  0x021A9350  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *   BTL_SETUP_Create  0x02013090  thumb
 *   FIELD_ENCOUNT_SetupWildBattle  0x021AA490  thumb
 *   BTL_SETUP_SetStatusFlag  0x02013144  thumb
 *   EVENT_BATTLE_CreateScriptedBattle  0x0216E7C8  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 h0;
    u16 h2;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 b7;
    u8 pad8[8];
    u8 b10;
    u8 pad11[0x17];
} Opts;

typedef struct {
    u8 b[0x2c];
} Buf;

typedef struct {
    int f0;
    int f4;
    int f8;
} S;

struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern u32 FIELDMAP_GetWeather(u8 *p);
extern u16 WEATHER_GetWeatherId(u8 *p);
struct Ctx;
struct Sel;
struct Slot14;
struct Unit;
extern void FIELD_ENCOUNT_SetupParam(struct Sel *s, void *a, int b, int c, u16 d);
extern void MI_CpuFill8(void *p, int v, int n);
extern void *BTL_SETUP_Create(u32 heap);
extern void FIELD_ENCOUNT_SetupWildBattle(struct Ctx *ctx, struct Unit *u, void *a2, u16 heap, struct Slot14 *slots);
extern void BTL_SETUP_SetStatusFlag(char *p, int v);
extern void EVENT_BATTLE_CreateScriptedBattle(int a, int b, int h, int c, int d);

void FIELD_ENCOUNT_StartScriptedWild(S *s, u16 a, u8 b, u32 flags)
{
    Opts opts;
    Buf buf;
    int h;
    Opts *o;

    FIELDMAP_GetFieldPlayer((struct Obj00020 *)s->f0);
    FIELD_ENCOUNT_SetupParam((struct Sel *)(&buf), (void *)s->f8, 0xff, 0, WEATHER_GetWeatherId((u8 *)FIELDMAP_GetWeather((u8 *)s->f0)));
    o = &opts;
    MI_CpuFill8(o, 0, 0x28);
    opts.h0 = a;
    o->b4 = b;
    if (flags & 4) {
        o->h2 = 0xffff;
    }
    if (flags & 2) {
        o->b6 = 1;
    } else if (flags & 0x10) {
        o->b6 = 2;
    } else {
        o->b6 = 0;
    }
    if (flags & 8) {
        o->b7 = 1;
    }
    if (flags & 0x20) {
        o->b10 = 1;
    } else if (flags & 0x40) {
        o->b10 = 2;
    }
    h = (int)BTL_SETUP_Create(4);
    FIELD_ENCOUNT_SetupWildBattle((struct Ctx *)s, (struct Unit *)(&buf), (void *)h, 4, (struct Slot14 *)(&opts));
    if (flags & 1) {
        BTL_SETUP_SetStatusFlag((char *)h, 4);
    } else if (flags & 0x80) {
        BTL_SETUP_SetStatusFlag((char *)h, 0x80);
    }
    if (flags & 0x100) {
        BTL_SETUP_SetStatusFlag((char *)h, 0x200);
    }
    EVENT_BATTLE_CreateScriptedBattle(s->f4, s->f0, h, 1, 0);
}
