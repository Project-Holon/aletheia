/*
 * function: func_021BBEF4
 * address:  0x021BBEF4
 * packet:   pkt_ov021_021BBEF4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned short u16;

typedef struct Head {
    int h0;
    int h4;
} Head;

typedef struct Obj {
    Head *head;
    int pad4;
    u16 h8;
} Obj;

typedef unsigned int   u32;
struct BbActSys;
extern void func_02050468(struct BbActSys *o, u16 first, u32 count);

void func_021BBEF4(int a0, Obj *p)
{
    int h = p->head->h4;
    u16 i = p->h8;

    if (i != 0xFFFF) {
        func_02050468((struct BbActSys *)h, i, 1);
    }
}
