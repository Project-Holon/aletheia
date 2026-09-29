/*
 * function: func_02165B5C
 * address:  0x02165B5C
 * packet:   pkt_ov010_02165B5C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Range check of a packed record: returns 1 (invalid) on the first field
 * out of range, else the verdict of the per-kind checker picked from
 * the table at 0x02171CA8 by func_02165FB4(kind).
 *
 * symbols:
 *   func_02165FB4  0x02165FB4  thumb  ov010
 *   d_02171CA8     0x02171CA8  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Rec {
    u8 f00[3];
    u8 f03 : 7;         /* 0x03 */
    u8 f03_7 : 1;
    u32 f04_0 : 17;     /* 0x04 */
    u32 f04_17 : 10;
    u32 f04_27 : 5;
    u32 f08_0 : 17;     /* 0x08 */
    u32 f08_17 : 5;
    u32 f08_22 : 10;
    u32 f0C_0 : 9;      /* 0x0C */
    u32 f0C_9 : 3;
    u32 f0C_12 : 4;
    u32 f0C_16 : 10;
    u32 f0C_26 : 6;
    u8 pad10[0x30 - 0x10];
    u16 f30;            /* 0x30 kind */
    u8 pad32[0x48 - 0x32];
    u16 f48_0 : 8;      /* 0x48 */
    u16 f48_8 : 8;
} Rec;

typedef int (*RecCheck)(Rec *r);

extern u8 func_02165FB4(u16 kind);
extern const RecCheck d_02171CA8[];

int func_02165B5C(Rec *r)
{
    if (r->f30 == 0 || r->f30 >= 0x33)
        return 1;
    if (r->f48_0 >= 6)
        return 1;
    if (r->f0C_9 >= 6)
        return 1;
    if (r->f0C_16 > 999 || r->f0C_26 > 59)
        return 1;
    if (r->f03 > 0x2D && r->f03 != 0x30)
        return 1;
    if (r->f04_17 >= 427 || r->f08_22 >= 427)
        return 1;
    if (r->f04_0 > 99999 || r->f08_0 > 99999)
        return 1;
    if (d_02171CA8[func_02165FB4(r->f30)](r) != 0)
        return 1;
    return 0;
}
