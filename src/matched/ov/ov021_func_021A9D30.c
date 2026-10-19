/*
 * function: FIELD_ENCOUNT_CreatePersonality
 * address:  0x021A9D30
 * packet:   pkt_ov021_021A9D30
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   POKE_TOOL_CreatePersonalRnd  0x020186C8  thumb
 *   POKE_PERSONAL_GetParam  0x0201AE1C  thumb
 *   POKE_PERSONAL_IsFixedGender  0x0201AF6C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Unit {
    u8 pad00[0x1C];
    u8 f1C;
    u8 pad1D[3];
    u32 f20;
    u8 pad24[4];
    u32 b0 : 11;
    u32 b11 : 1;
};
struct Slot14 { u16 f00; u8 pad02[3]; u8 f05; u8 f06; u8 pad07[9]; u8 f10; };

struct Personal;
extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);
extern u32 POKE_PERSONAL_IsFixedGender(u32 v);
extern u32 POKE_TOOL_CreatePersonalRnd(u32 a0, int a1, int a2, int a3, int a4, int a5);

u32 FIELD_ENCOUNT_CreatePersonality(struct Unit *u, void *src, struct Slot14 *s)
{
    u32 gender = 2;
    u32 r;
    u32 x;

    if (POKE_PERSONAL_IsFixedGender((u8)POKE_PERSONAL_GetParam(src, 0x14)) != 1) {
        if (u->b11) {
            if (u->f1C == 0)
                gender = 1;
            else if (u->f1C == 1)
                gender = 0;
        }
        if (s->f10 == 1)
            gender = 0;
        else if (s->f10 == 2)
            gender = 1;
    }
    r = POKE_TOOL_CreatePersonalRnd(u->f20, s->f00, s->f05, gender, 2, s->f06 == 2 ? 0 : 2);
    if (s->f06 != 2) {
        x = (u16)r ^ ((u->f20 >> 16) ^ (u16)u->f20);
        if (x & 1)
            r |= 0x80000000;
        else
            r &= 0x7FFFFFFF;
    }
    return r;
}
