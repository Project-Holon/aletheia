/*
 * function: ISS_SYS_ChangeZone
 * address:  0x0202B544
 * packet:   pkt_0202B500
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *           --suggest-split offers nothing (single function, both
 *           unresolved sites' only witness is inside this range).
 *
 * Parked: four of the six call sites resolve (0x0202B7B8, 0x0202B7C8,
 * 0x0202B7D4, 0x0202B7E0 are manifest entries).  The two that stay unresolved
 * are 0x0202B7BC and 0x0202B7EC, whose own single callees are the four-byte
 * Thumb linker veneers at 0x0202AB5C and 0x0202B90C - artifact class, no C
 * spelling produces them, so neither thunk can ever earn a manifest entry and
 * no cut of this file frees the site.  Every concrete byte reproduces.
 *
 * symbols:
 *   ISS_SYS_OnZoneChangeCity  0x0202B7BC  thumb
 *   ISS_SYS_OnZoneChangeDungeon  0x0202B7C8  thumb
 *   ISS_SYS_OnZoneChangeZone  0x0202B7D4  thumb
 *   ISS_SYS_OnZoneChangeSwitch  0x0202B7E0  thumb
 *   ISS_SYS_OnZoneChange3ds  0x0202B7EC  thumb
 */

typedef signed char    s8;
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_0202B7B8(void);
struct Obj;
extern void ISS_SYS_OnZoneChangeCity(struct Obj *o, u32 a1);
extern void ISS_SYS_OnZoneChangeDungeon(u8 *p, u16 v);
extern void ISS_SYS_OnZoneChangeZone(u8 *p, u32 key);
extern void ISS_SYS_OnZoneChangeSwitch(u8 *p, u32 b);
extern void ISS_SYS_OnZoneChange3ds(u8 *p, u32 b);

void ISS_SYS_ChangeZone(u32 a, u16 b)
{
    func_0202B7B8();
    ISS_SYS_OnZoneChangeCity((struct Obj *)a, b);
    ISS_SYS_OnZoneChangeDungeon((u8 *)a, b);
    ISS_SYS_OnZoneChangeZone((u8 *)a, b);
    ISS_SYS_OnZoneChangeSwitch((u8 *)a, b);
    ISS_SYS_OnZoneChange3ds((u8 *)a, b);
}
