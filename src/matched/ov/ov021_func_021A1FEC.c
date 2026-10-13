/*
 * function: WEATHER_TASK_Start
 * address:  0x021A1FEC
 * packet:   pkt_ov021_021A1FEC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WEATHER_TASK_SetSoundUseSoundSys  0x021A2C2C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct O {
    u32 pad0[8];
    u32 f20;
    u8  lo : 4;
    u8  hi : 4;
    u8  f25;
    u8  f26;
    u8  pad27[0x19];
    u8  f40;
} O;

extern void WEATHER_TASK_SetSoundUseSoundSys(u8 *p, u32 v);

void WEATHER_TASK_Start(O *p, u32 v, u8 b, u32 c, u32 d, u32 e, u32 g)
{
    p->f20 = v;
    p->lo = (u8)d;
    p->hi = (u8)c;
    p->f25 = b;
    if (p->f25 == 0) {
        p->f26 = 1;
    } else if (p->f25 == 1) {
        p->f26 = 2;
    }
    WEATHER_TASK_SetSoundUseSoundSys(&p->f40, e);
}
