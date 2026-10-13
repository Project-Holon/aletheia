/*
 * function: FIELD_ENCOUNT_CreateZoneWildMons
 * address:  0x021A954C
 * packet:   pkt_ov021_021A954C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   FIELD_ENCOUNT_CreateWildMons  0x021A9508  thumb
 *   FIELD_ENCOUNT_LoadSlots  0x021A9A5C  thumb
 *   MIi_CpuClear32  0x02082A7C  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Spec { u16 id : 11; u16 lvl : 5; u8 lo; u8 hi; };

extern void MIi_CpuClear32(u32 data, void *destp, u32 size);
struct Slot14;
struct Unit;
extern u8 FIELD_ENCOUNT_LoadSlots(u8 *a0, struct Unit *u, u16 id, struct Spec *spec);
extern int FIELD_ENCOUNT_CreateWildMons(u8 *u, void *arg, struct Slot14 *slots);

int FIELD_ENCOUNT_CreateZoneWildMons(void *a0, void *u, u16 id, void *slots)
{
    struct Spec specs[12];

    MIi_CpuClear32(0, specs, sizeof(specs));
    FIELD_ENCOUNT_LoadSlots(a0, u, id, specs);
    return FIELD_ENCOUNT_CreateWildMons(u, specs, slots);
}
