/*
 * function: ISS_CITY_SYS_Stop
 * address: 0x0202AB54
 * packet: pkt_arm9_0202AB54
 * region: arm9
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/arm9/iss_city_sys.c and filed here.
 *
 * symbols:
 *   ISS_CITY_SYS_Disable 0x0202AC4C thumb
 */

struct Rec44;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;

/* One 0x28-byte record, filled from archive 0x84. */
struct CityBand {
    u16 id;
    u16 pad02;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u8 a[6];
    u8 b[6];
    u8 c[6];
    u8 d[6];
};

struct CitySys {
    struct Rec44 *owner;
    u32 enabled;
    u32 mode;
    u32 vol;
    u32 level;
    struct CityBand **bands;
    u8 count;
    u8 cur;
};

void ISS_CITY_SYS_Stop(u8 *p);
int ISS_CITY_SYS_Disable(struct CitySys *s);

void ISS_CITY_SYS_Stop(u8 *p)
{
    ISS_CITY_SYS_Disable((struct CitySys *)p);
}
