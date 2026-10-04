/*
 * function: func_0217B4C4
 * address:  0x0217B4C4
 * packet:   pkt_ov019_0217B4C4
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0217AE38  0x0217AE38  thumb  ov019
 *   func_0217AED4  0x0217AED4  thumb  ov019
 *   func_0217AFB0  0x0217AFB0  thumb  ov019
 *   func_0217F060  0x0217F060  thumb  ov019
 *   func_0217F858  0x0217F858  thumb  ov019
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D5A0  0x0216D5A0  thumb  ov010
 *   func_0216E0E8  0x0216E0E8  thumb  ov010
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Rec {
    u8 pad0[6];
    u8 b6;
    u8 f7_lo : 1;
    u8 valid : 1;
    u8 f7_hi : 6;
} Rec;

typedef struct Entry {
    u8   pad0[6];
    u8   n : 3;
    u8   f6_hi : 5;
    u8   f7_lo : 5;
    u8   kind : 3;
    u8   pad8[3];
    u8   bB;
    u8   padC[0x28 - 0xC];
    Rec  recs[8];
    u8   pad68[4];
    u16  h6C;
} Entry;

typedef struct Msg {
    Entry *e;
    u8     b4;
    u8     b5;
    u8     idx;
} Msg;

extern int func_0217AE38(char *p, char v);
extern u16 func_0217AED4(u8 *a, u8 *b);
extern void *func_0217AFB0(u8 *w, Entry *e, Msg *m);
extern int  func_0217F060(u8 v);
extern int func_0217F858(int a);
extern int func_0216D3CC(int a0);
extern void func_0216D410(void *a0, u16 a1);
extern u16 func_0216D5A0(void *p);
extern int func_0216E0E8(int a0, int a1);

int func_0217B4C4(u8 *w, Msg *m)
{
    Entry *e;
    u8 *s;
    int t;
    int v;
    void *r;

    s = w + 0x2830;
    e = m->e;
    if (e->h6C == 0) {
        func_0217AE38((char *)m, 2);
        return 1;
    }
    if (!e->recs[m->idx].valid || m->b4 != e->recs[m->idx].b6) {
        func_0217AE38((char *)m, 2);
        return 1;
    }
    t = func_0217F858(e->bB);
    if (*(u16 *)(s + 0x58) == func_0217AED4((u8 *)m->e, (u8 *)m)) {
        func_0217AE38((char *)m, 3);
        return 1;
    }
    v = s[2];
    if (v != 0 && (v == t || (t == 0 && v == e->kind)) && m->idx == 0
        && func_0217F060(e->bB) > e->n) {
        r = func_0217AFB0(w, m->e, m);
        if (func_0216D3CC((int)r) == 1) {
            func_0216D410(r, 0x31);
        }
    } else if (m->idx == 0 && e->n > 1) {
        r = func_0217AFB0(w, m->e, m);
        if (func_0216D5A0(r) == 2) {
            func_0216E0E8((int)r, 0xF);
        }
    } else if (m->idx == 0 && e->n <= 1) {
        r = func_0217AFB0(w, m->e, m);
        if (func_0216D5A0(r) == 0xF) {
            func_0216E0E8((int)r, 2);
        }
    }
    return 0;
}
