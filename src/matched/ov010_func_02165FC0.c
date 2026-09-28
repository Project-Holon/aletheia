/*
 * function: func_02165FC0
 * address:  0x02165FC0
 * packet:   pkt_ov010_02165FC0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Second byte of the two-byte table row for a record type.
 *
 * symbols:
 *   d_02171CE8  0x02171CE8  data  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;

typedef struct Row {
    u8 a;
    u8 b;
} Row;

extern const Row d_02171CE8[];

u8 func_02165FC0(u16 type)
{
    return d_02171CE8[type].b;
}
