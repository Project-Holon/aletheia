/*
 * function: GAME_BEACON_ACCESSOR_IsDistributionItemNoInvalid
 * address:  0x02166218
 * packet:   pkt_ov010_02166218
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Record field validator: returns 1 when the field is out of range.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;

typedef struct Rec {
    u8 pad00[0xC];
    u32 pad0c : 16;
    u32 a : 10;
    u32 b : 6;
    u8 pad10[0x32 - 0x10];
    u16 f32;            /* 0x32 */
    u16 f34;            /* 0x34 */
    u16 f36;            /* 0x36 */
    u16 f38;            /* 0x38 */
} Rec;

typedef struct RecW {
    u8 pad00[0x34];
    u32 f34;            /* 0x34 */
} RecW;

typedef struct RecB {
    u8 pad00[0x34];
    u8 f34;             /* 0x34 */
} RecB;

int GAME_BEACON_ACCESSOR_IsDistributionItemNoInvalid(Rec *r)
{
    if (r->f36 == 0 || r->f36 > 0x272)
        return 1;
    return 0;
}
