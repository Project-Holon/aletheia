/*
 * function: INFOWIN_UpdateClock
 * address:  0x020252A8
 * packet:   pkt_020251FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GF_STANDARD_SetField00  0x0203F4CC  arm
 *   gSysState      0x0214693C  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Cfg {
    u32 a;
    u32 b;
    u32 c;
};

struct Sys {
    u32 field_0;
    u16 field_4;
    u16 field_6;
    u32 field_8;
    u32 field_C;
    u32 field_10;
    u32 field_14;
    u32 field_18;
    u8  field_1C;
    u8  field_1D;
    u8  field_1E;
    u8  field_1F;
};

extern struct Sys *gSysState;

struct RtcTime;
extern void GF_STANDARD_SetField00(struct RtcTime *time);

void INFOWIN_UpdateClock(void)
{
    struct Cfg cfg;
    u32 v;

    GF_STANDARD_SetField00((struct RtcTime *)(&cfg));
    v = cfg.c & 1;

    if (cfg.a != gSysState->field_1D) {
        gSysState->field_1D = cfg.a;
        if (gSysState->field_1D >= 0xc) {
            gSysState->field_18 = 1;
        } else {
            gSysState->field_18 = 0;
        }
        gSysState->field_4 |= 1;
    }

    if (cfg.b != gSysState->field_1C) {
        gSysState->field_1C = cfg.b;
        gSysState->field_4 |= 1;
    }

    if (v != gSysState->field_14) {
        gSysState->field_14 = v;
        gSysState->field_4 |= 1;
    }
}
