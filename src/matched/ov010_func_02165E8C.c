/*
 * function: func_02165E8C
 * address:  0x02165E8C
 * packet:   pkt_ov010_02165E8C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns the f34.h payload of a type-0x24 record, else 1.
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
    union {
        u8 b;
        u16 h;
        u32 w;
    } f34;              /* 0x34 */
    u16 f36;            /* 0x36 */
    u16 f38;            /* 0x38 */
} Rec;

 func_02165E8C(Rec *r)
{
    if (r->type == 0x24)
        return r->f34.h;
    return 1;
}
