/*
 * function: func_021B8870
 * address:  0x021B8870
 * packet:   pkt_ov021_021B8870
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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

void *func_021B8870(Table *t, u16 i)
{
    if (t->n8 > i) {
        return t->p20[i];
    }
    if (i == 0xFFFF) {
        return 0;
    }
    return t->p20[0];
}
