/*
 * function: FIELD_ENCOUNT_CreateWildMons
 * address:  0x021A9508
 * packet:   pkt_ov021_021A9508
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   FIELD_ENCOUNT_IsRepelled  0x021A996C  thumb
 *   FIELD_ENCOUNT_SelectMon  0x021A9C58  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Slot14 { u8 pad00[4]; u8 f04; u8 pad05[0xF]; };

struct Spec;
struct Unit;
extern void FIELD_ENCOUNT_SelectMon(struct Unit *u, struct Spec *specs, struct Slot14 *s);
extern int FIELD_ENCOUNT_IsRepelled(struct Unit *u, u8 n);

int FIELD_ENCOUNT_CreateWildMons(u8 *u, void *arg, struct Slot14 *slots)
{
    int n = 0;
    int i;

    for (i = 0; i < u[0x15]; i++) {
        struct Slot14 *s = &slots[n];
        FIELD_ENCOUNT_SelectMon((struct Unit *)u, arg, s);
        if (FIELD_ENCOUNT_IsRepelled((struct Unit *)u, s->f04) == 0)
            n++;
    }
    return n;
}
