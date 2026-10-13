/*
 * file:     unit_0689C104.c
 * function: func_0689C104
 * address:  0x0689C104
 * packet:   pkt_ov095_0689C104
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C8838  0x021C8838  thumb
 *   func_021C8860  0x021C8860  thumb
 *   func_021C88A4  0x021C88A4  thumb
 *   func_021C88C8  0x021C88C8  thumb
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb
 */

typedef unsigned char u8;

typedef struct Rec {
    int f00;
    u8 f04[1];
} Rec;

extern int BTL_POKEPARAM_GetPokeId(void *);
extern Rec *func_021C88A4(void *, int, int);
extern void func_021C8838(void *, int, int);
extern void func_021C8860(void *, int);
extern void func_021C88C8(void *, Rec *);

void func_0689C104(void *a, void *b, u8 c)
{
    int k;
    Rec *r;

    k = BTL_POKEPARAM_GetPokeId(b);
    r = func_021C88A4(a, 4, k);
    func_021C8838(r->f04, 2, 0x35c);
    func_021C8860(r->f04, k);
    func_021C8860(r->f04, c);
    func_021C88C8(a, r);
}
