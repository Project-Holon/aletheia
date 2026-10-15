/*
 * function: FIELD_ENCOUNT_RollSlotMon
 * address:  0x021A9B00
 * packet:   pkt_ov021_021A9B00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 *
 * symbols:
 *   func_02005728  0x02005728  thumb
 *   POKE_TOOL_GetPersonalParam  0x02019C90  thumb
 *   FIELD_ENCOUNT_RandPercent  0x021A9DC8  thumb
 *   _u32_div_f  0x0209C2B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Slot14 { u16 f00; u8 pad02[2]; u8 f04; u8 f05; u8 pad06[0xE]; };
struct Spec { u16 id : 11; u16 lvl : 5; u8 lo; u8 hi; };

extern void MI_CpuFill8(void *dest, u8 value, u32 size);
extern u32 FIELD_ENCOUNT_RandPercent(void);
extern u32 POKE_TOOL_GetPersonalParam(u16 a, u16 b, u32 k);
extern u32 func_02005728(u32 range);

void FIELD_ENCOUNT_RollSlotMon(struct Spec *spec, struct Slot14 *s)
{
    s16 range = spec->hi - spec->lo;
    u8 cap;
    int lvl;
    u16 id;

    MI_CpuFill8(s, 0, 0x14);
    if (range < 0)
        range = 0;
    s->f04 = spec->lo + FIELD_ENCOUNT_RandPercent() % (u32)(range + 1);
    id = spec->id;
    s->f00 = id;
    cap = POKE_TOOL_GetPersonalParam(id, 0, 0x20);
    lvl = spec->lvl;
    if (lvl == 0x1F)
        s->f05 = func_02005728(cap);
    else if (lvl >= cap)
        s->f05 = 0;
    else
        s->f05 = lvl;
}
