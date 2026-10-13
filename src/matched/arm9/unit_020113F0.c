/*
 * unit:     yes
 * function: TIMEZONE_GetTimeZoneOfHour, TIMEZONE_GetZoneLightLevel
 * address:  0x020113F0
 * packet:   pkt_020113F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   _TimeZoneTable  0x0209DF24  data  a1
 *   _TimeZoneLightTable  0x0209DF10  data  a1
 *
 * vm.c, 0x020113F0..0x02011410: two byte lookups in constant 2D tables,
 * rows of 0x18 and 5 bytes.  Plain subscripts `tbl[row][col]` give the
 * image's `base + row * stride` then `ldrb [col, base]`; the old pending
 * park (byte-offset arithmetic, docs/notes/pkt_020113F0.c.txt) was capped on
 * the two single-pool rodata tables, which sole-ref/self now carries.
 */

typedef unsigned char u8;

extern const u8 _TimeZoneTable[][0x18];
extern const u8 _TimeZoneLightTable[][5];

int TIMEZONE_GetTimeZoneOfHour(int row, int col)
{
    return _TimeZoneTable[row][col];
}

u8 TIMEZONE_GetZoneLightLevel(int row, int col)
{
    return _TimeZoneLightTable[row][col];
}
