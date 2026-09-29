/*
 * function: func_02175F34
 * address:  0x02175F34
 * packet:   pkt_ov011_02175F34
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * note:     the unlabelled 2-instruction leaf at 0x02175FB4 (ldrb r0,[r0,#0x10]; bx lr) follows.
 *
 * symbols:
 *   func_02026478  0x02026478  thumb
 *   func_021583CC  0x021583CC  thumb  ov010
 *   func_021583EC  0x021583EC  thumb  ov010
 *   func_0200855C  0x0200855C  thumb
 *   func_02008530  0x02008530  thumb
 *   func_021584F4  0x021584F4  thumb  ov010
 *   func_02175EFC  0x02175EFC  thumb  ov011
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 h[8];
    u8  f10;
    u8  f11;
    u8  f12;
    u8  pad13;
    u8  f14[0x14];
} Ent;

typedef struct {
    u16 h[8];
} Half8;

extern int    func_02026478(void *p);
extern Half8 *func_021583CC(int sv, int i);
extern int    func_021583EC(int a, int i);
extern int    func_0200855C(void);
extern int    func_02008530(int a);
extern int    func_021584F4(int a, int b);
extern void   func_02175EFC(void *w, void *p, u8 i);

void func_02175F34(void *w, Ent *tbl, u32 arg, int idx)
{
    int sv;
    Ent *e;
    Half8 *src;
    int t;
    int u;
    u8 flag;

    sv = func_02026478(((void **)w)[1]);
    e = (Ent *)((u8 *)tbl + idx * 0x28);
    if (e->f10 != 1) {
        src = func_021583CC(sv, idx);
        t = func_021583EC(sv, idx);
        u = func_0200855C();
        flag = func_021584F4(u, func_02008530(t)) == 0x15;
        *(Half8 *)e = *src;
        e->f11 = flag;
        e->f12 = arg;
        func_02175EFC(w, e->f14, idx);
        e->f10 = 1;
    }
}
