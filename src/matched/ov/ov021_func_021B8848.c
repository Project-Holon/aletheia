/*
 * function: func_021B8848
 * address:  0x021B8848
 * packet:   pkt_ov021_021B8848
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021D9A30     0x021D9A30  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 b[0x24];
} Elem;

typedef struct {
    u16 h0;
    u16 h2;
    u16 n4;
    u16 n6;
    u16 n8;
    u16 na;
    u16 nc;
    u16 he;
    u8 pad10[8];
    Elem *p18;
    Elem *p1c;
    void **p20;
    void **p24;
    void **p28;
} Table;

extern Elem d_021D9A30;

Elem *func_021B8848(Table *t, u16 i)
{
    if (t->n6 > i) {
        return &t->p1c[i];
    }
    if (i == 0xFFFF) {
        return 0;
    }
    return &d_021D9A30;
}
