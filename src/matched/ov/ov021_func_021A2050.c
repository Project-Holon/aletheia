/*
 * function: WEATHER_TASK_RequestEnd
 * address:  0x021A2050
 * packet:   pkt_ov021_021A2050
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WEATHER_TASK_GetStagePhase  0x021A273C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct O {
    u32 pad0[9];
    u8  lo : 4;
    u8  hi : 4;
    u8  f25;
    u8  f26;
} O;

extern u8 WEATHER_TASK_GetStagePhase(u8 *p);

void WEATHER_TASK_RequestEnd(O *p, u32 a, u32 b)
{
    u32 r;
    u32 s;

    r = WEATHER_TASK_GetStagePhase((u8 *)p);
    s = p->f26;
    if (s == 0) {
        return;
    }
    if (r - 4 <= 1) {
        return;
    }
    p->hi = (u8)a;
    p->lo = (u8)b;
    if (s <= 5) {
        p->f26 = 0xb;
        return;
    }
    if (p->hi != 0) {
        p->f26 = 9;
        return;
    }
    p->f26 = 0xb;
}
