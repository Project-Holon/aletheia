/*
 * function: GAME_BEACON_ACCESSOR_GetDistributionItemNo
 * address:  0x02165EAC
 * packet:   pkt_ov010_02165EAC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Returns the f36 payload of a type-0x1A record, else 0x11.
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

u16 GAME_BEACON_ACCESSOR_GetDistributionItemNo(Rec *r)
{
    if (r->type == 0x1A)
        return r->f36;
    return 0x11;
}
