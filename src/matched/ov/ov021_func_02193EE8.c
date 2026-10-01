/*
 * function: func_02193EE8
 * address:  0x02193EE8
 * packet:   pkt_ov021_02193EE8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021938FC  0x021938FC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct E50 {
    u16 f00;
    u8  pad02[0x32];
    u8  f34[0x1C];
} E50;

typedef struct E18 {
    u8 b[0x18];
} E18;

typedef struct Tbl {
    u8  hdr[8];
    E18 e[10];
} Tbl;

typedef struct V {
    u8   f00;
    u8   f01;
    u8   pad02[2];
    E50 *f04;
    Tbl *f08;
} V;

extern void func_021938FC(V *v);

void func_02193EE8(V *v)
{
    if (v->f01 == 0 && v->f08 != 0)
        func_021938FC(v);
}
