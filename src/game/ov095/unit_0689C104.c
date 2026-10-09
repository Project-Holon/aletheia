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
 *   func_0689C144   0x0689C144  thumb  ov095
 *   func_0689C154   0x0689C154  thumb  ov095
 *   func_0689C164   0x0689C164  thumb  ov095
 *   func_0689C174   0x0689C174  thumb  ov095
 *   func_0689C184   0x0689C184  thumb  ov095
 *   func_0689C194   0x0689C194  thumb  ov095
 */

typedef unsigned char u8;

typedef struct Rec {
    int f00;
    u8 f04[1];
} Rec;

extern int func_0689C144(void *);
extern Rec *func_0689C154(void *, int, int);
extern void func_0689C164(void *, int, int);
extern void func_0689C174(void *, int);
extern void func_0689C184(void *, int);
extern void func_0689C194(void *, Rec *);

void func_0689C104(void *a, void *b, u8 c)
{
    int k;
    Rec *r;

    k = func_0689C144(b);
    r = func_0689C154(a, 4, k);
    func_0689C164(r->f04, 2, 0x35c);
    func_0689C174(r->f04, k);
    func_0689C184(r->f04, c);
    func_0689C194(a, r);
}
