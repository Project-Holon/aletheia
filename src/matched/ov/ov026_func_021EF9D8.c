/*
 * function: WEATHER_LIGHTNING_Update
 * address:  0x021EF9D8
 * packet:   pkt_ov026_021EF9D8
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * State 6 re-reads `cur` into a local after the entry's decrement
 * (`p->ent[p->cur].d--; i = p->cur; if (p->ent[i].d <= 0) { if (p->count >
 * i + 1)`): spelled with `p->cur` throughout, every form tried (either
 * compare order, `p->cur++`, a temporary for cur + 1) colours count and
 * cur + 1 into r0/r1 swapped, 7 bytes out; the permuter was flat on it.
 * State 4 indexes the entry directly (`p->ent[i].e`); an `Ent *e` cursor
 * gives 100+ bytes out.
 *
 * symbols:
 *   func_020056EC  0x020056EC  thumb
 *   _s32_div_f     0x0209C0A4  arm
 *   WEATHER_TASK_FlashLight  0x021A2130  thumb  ov021
 *   WEATHER_TASK_SetLightColor  0x021A2154  thumb  ov021
 *   WEATHER_TASK_PlaySeDirect  0x021A25DC  thumb  ov021
 *   WEATHER_TASK_IsLightFlashing  0x021A213C  thumb  ov021
 *   WEATHER_LIGHTNING_PickShortFlashes  0x021EFBA4  thumb  ov026
 *   WEATHER_LIGHTNING_PickSingleFlash  0x021EFBFC  thumb  ov026
 *   WEATHER_LIGHTNING_PickLongSequence  0x021EFC3C  thumb  ov026
 *   WEATHER_LIGHTNING_GetFlashColor  0x021EFCD4  thumb  ov026
 *   gWeatherLightningPatternChance     0x021EFCF9  data  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    s16 d;
    s16 e;
    u16 f;
} Ent;

typedef struct {
    u8 state;
    u8 mode;
    u16 x2;
    u16 count;
    u16 cur;
    Ent ent[4];
    int timer;
    s16 t3c;
    s16 t3e;
} Obj;

extern u32 func_020056EC(u32 v);
extern void WEATHER_TASK_FlashLight(u8 *p, u32 b, u32 c, u32 d);
extern void WEATHER_TASK_SetLightColor(u8 *p, u32 b, u32 c);
extern void WEATHER_TASK_PlaySeDirect(u8 *p, int a);
extern int WEATHER_TASK_IsLightFlashing(u8 *p);
extern void WEATHER_LIGHTNING_PickShortFlashes(u16 *p);
extern void WEATHER_LIGHTNING_PickSingleFlash(u16 *p);
extern void WEATHER_LIGHTNING_PickLongSequence(Obj *p);
extern u16 WEATHER_LIGHTNING_GetFlashColor(Obj *p);
extern u8 gWeatherLightningPatternChance[];

void WEATHER_LIGHTNING_Update(Obj *p, int b)
{
    u32 r;
    int i;

    switch (p->state) {
    case 0:
        if (--p->timer < 0) {
            p->state = 1;
        }
        break;
    case 1:
        r = func_020056EC(100);
        for (i = 0; i < 3; i++) {
            if (gWeatherLightningPatternChance[i] >= r) {
                break;
            }
        }
        if (p->mode == 0) {
            WEATHER_LIGHTNING_PickShortFlashes((u16 *)p);
        } else {
            switch (i) {
            case 0:
                if (p->mode == 1) {
                    WEATHER_LIGHTNING_PickShortFlashes((u16 *)p);
                } else {
                    WEATHER_LIGHTNING_PickSingleFlash((u16 *)p);
                }
                break;
            case 1:
                WEATHER_LIGHTNING_PickSingleFlash((u16 *)p);
                break;
            case 2:
                WEATHER_LIGHTNING_PickLongSequence(p);
                break;
            }
        }
        p->cur = 0;
        p->state = 2;
        break;
    case 2:
        if (p->mode != 2) {
            p->state = 4;
            break;
        }
        WEATHER_TASK_SetLightColor((u8 *)b, 0x3129, 4);
        p->timer = 10;
        p->state = 3;
        break;
    case 3:
        if (--p->timer <= 0) {
            p->state = 4;
        }
        break;
    case 4:
        if (p->mode != 0) {
            WEATHER_TASK_FlashLight((u8 *)b, WEATHER_LIGHTNING_GetFlashColor(p), p->ent[p->cur].a, p->ent[p->cur].b);
        }
        if (p->x2 == 2) {
            p->timer = p->ent[p->cur].a / 2 + func_020056EC(p->ent[p->cur].b);
        }
        i = p->cur;
        p->t3c = p->ent[i].e;
        p->t3e = p->ent[i].f;
        if (p->mode == 2) {
            if (i + 1 == p->count) {
                p->ent[i].d = p->ent[i].d / 3;
            }
        } else if (p->mode == 0) {
            p->ent[i].d = p->ent[i].d * 2;
        }
        p->state = 5;
        break;
    case 5:
        if (p->t3c > 0) {
            p->t3c--;
            if (p->t3c == 0) {
                WEATHER_TASK_PlaySeDirect((u8 *)b, p->t3e);
            }
        }
        if (WEATHER_TASK_IsLightFlashing((u8 *)b) == 0) {
            p->state = 6;
        }
        break;
    case 6:
        if (p->t3c > 0) {
            p->t3c--;
            if (p->t3c == 0) {
                WEATHER_TASK_PlaySeDirect((u8 *)b, p->t3e);
            }
        }
        p->ent[p->cur].d--;
        i = p->cur;
        if (p->ent[i].d <= 0) {
            if (p->count > i + 1) {
                p->cur = i + 1;
                p->state = 4;
            } else {
                p->state = 1;
            }
        }
        break;
    }
}
