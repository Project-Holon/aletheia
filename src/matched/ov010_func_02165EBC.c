/*
 * function: func_02165EBC
 * address:  0x02165EBC
 * packet:   pkt_ov010_02165EBC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns the f38 payload of a type-0x32 record, else 0.
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

u16 func_02165EBC(Rec *r)
{
    if (r->type == 0x32)
        return r->f38;
    return 0;
}
