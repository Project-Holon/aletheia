/*
 * function: func_021BCD70
 * address:  0x021BCD70
 * packet:   pkt_ov021_021BCD70
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BCB9C  0x021BCB9C  thumb  ov021
 */

typedef unsigned short u16;

typedef struct {
    char pad[0x42];
    u16 h42;
} Obj;

extern void func_021BCB9C(void *p, int keep);

void func_021BCD70(Obj *p)
{
    if (p->h42 > 10) {
        func_021BCB9C(p, 4);
    }
}
