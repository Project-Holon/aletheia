/*
 * function: func_021737CC
 * address:  0x021737CC
 * packet:   pkt_ov011_021737CC
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02026478  0x02026478  thumb
 *   func_02174EAC  0x02174EAC  thumb  ov011
 *   func_02012B58  0x02012B58  thumb
 *   func_0203D378  0x0203D378  arm
 */

typedef unsigned char u8;

typedef struct {
    int f0;
    int f4;
    u8 pad08[0x8fa];
    u8 n;
    u8 pad03[0x3c];
    u8 flag : 1;
} D;

typedef struct {
    u8 pad[0x4b];
    u8 lo : 6;
    u8 hit : 1;
} C;

extern int func_02026478(int a);
extern void func_02174EAC(D *d, int a, C *c);
extern int func_02012B58(int a);
extern int func_0203D378(void);

void func_021737CC(int a, int b, C *c, D *d)
{
    int h;

    h = func_02026478(d->f4);
    if (a < d->n) {
        func_02174EAC(d, a, c);
        if (a != func_02012B58(h) && func_0203D378() == 0 && a == 0 && c->hit == 1)
            d->flag = 1;
    }
}
