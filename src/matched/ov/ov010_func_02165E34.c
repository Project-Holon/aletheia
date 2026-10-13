/*
 * function: GAME_BEACON_ACCESSOR_GetActionMonsNo
 * address:  0x02165E34
 * packet:   pkt_ov010_02165E34
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns the f32 halfword for the record types that carry one, else 0x1F8.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;

typedef struct Rec {
    u8 pad00[0x30];
    u16 type;           /* 0x30 */
    u16 f32;            /* 0x32 */
    u16 f34;            /* 0x34 */
    u16 f36;            /* 0x36 */
    u16 f38;            /* 0x38 */
} Rec;

u16 GAME_BEACON_ACCESSOR_GetActionMonsNo(Rec *r)
{
    switch (r->type) {
    case 2:
    case 3:
    case 4:
    case 5:
    case 14:
    case 15:
    case 17:
    case 38:
        return r->f32;
    }
    return 0x1F8;
}
