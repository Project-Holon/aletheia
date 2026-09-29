/*
 * function: func_02173464
 * address:  0x02173464
 * packet:   pkt_ov011_02173464
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02026478  0x02026478  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_0217C11C  0x0217C11C  thumb  ov018
 *   func_02167794  0x02167794  thumb  ov010
 *   func_021676E4  0x021676E4  thumb  ov010
 *   func_021677E4  0x021677E4  thumb  ov010
 *   func_02167848  0x02167848  thumb  ov010
 *   func_02174F54  0x02174F54  thumb  ov011
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Head {
    u32 f0;
    u32 w[4];
} Head;

typedef struct Entry {
    Head h;
    u16 f14;
    u16 a : 3;
    u16 b : 6;
    u16 f18;
    u8 pad1a;
    u8 pad1b : 7;
    u8 hi : 1;
} Entry;

typedef struct Obj {
    u8 pad0[8];
    int f8;
    u8 padc[0x80];
    Entry ents[3];
    u8 pad[0x8fb - 0x8c - 3 * 0x1c];
    u8 mask;
} Obj;

extern int func_02026478(int);
extern int func_02012B58(int);
extern int func_02012B70(int);
extern void func_02188C9C(int);
extern int func_0217C11C(void);
extern void func_02167794(int);
extern void func_021676E4(int);
extern int func_021677E4(int, int);
extern void func_02167848(int, int, Head *);
extern void func_02174F54(Obj *, int, Entry *, int);

void func_02173464(u8 *a0, Obj *p, int a2)
{
    int h;
    int me;
    int i;
    Head tmp;

    if (p == 0) {
        return;
    }
    h = func_02026478(*(int *)(a0 + 4));
    me = func_02012B58(h);
    if (func_02012B70(h) == 0) {
        func_02188C9C(a2);
        if (func_0217C11C() == 1) {
            func_021676E4(p->f8);
        } else {
            func_02167794(p->f8);
        }
    } else {
        func_021676E4(p->f8);
    }
    for (i = 0; i < 3; i++) {
        if (i != me && func_021677E4(p->f8, i) == 1) {
            p->ents[i].h.f0 = p->ents[i].hi;
            tmp = p->ents[i].h;
            tmp.f0 = 1;
            func_02167848(p->f8, i, &tmp);
        }
    }
    for (i = 0; i < 3; i++) {
        if (i != me && (p->mask & (1 << i))) {
            int hi = p->ents[i].hi;
            func_02174F54(p, i, &p->ents[i], 0);
            p->ents[i].hi = hi;
        }
    }
}
