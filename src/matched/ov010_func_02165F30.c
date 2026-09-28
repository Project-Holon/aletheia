/*
 * function: func_02165F30
 * address:  0x02165F30
 * packet:   pkt_ov010_02165F30
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns the f34 halfword for record types 6..11, else 1.
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

u16 func_02165F30(Rec *r)
{
    switch (r->type) {
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
        return r->f34;
    }
    return 1;
}
