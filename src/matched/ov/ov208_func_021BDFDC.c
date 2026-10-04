/*
 * function: func_021BDFDC
 * address: 0x021BDFDC
 * packet: pkt_ov208_021BDFDC
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_0203633C 0x0203633C arm
 *   func_021BD388 0x021BD388 thumb
 *   func_021BD3F8 0x021BD3F8 thumb
 *   func_021BDB08 0x021BDB08 thumb
 *   func_021BDB54 0x021BDB54 thumb
 *   func_021BE32C 0x021BE32C thumb
 *   func_021BE378 0x021BE378 thumb
 *   func_021BD368 0x021BD368 thumb
 *   func_021BE170 0x021BE170 thumb
 *   func_021BE1BC 0x021BE1BC thumb
 * tail: two zero alignment bytes after the function (listing extent is 2 bytes longer).
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Ov208Slot { int *p; int q; };
struct Ov208Menu {
    char pad0[0x18];
    int mode;
    int f1c;
    char pad20[0x10];
    void *f30;
    char pad34[0x38];
    struct Ov208Slot tab[9];
};
extern u32 func_020362DC(void);
extern u32 func_0203633C(void);
extern int func_021BD388(void *a, int b);
extern void func_021BD3F8(void *a, int b);
extern u32 func_021BDB08(struct Ov208Menu *m);
extern u32 func_021BDB54(struct Ov208Menu *m);
extern u32 func_021BE32C(u32 v);
extern u32 func_021BE378(u32 v);
extern void func_021BD368(int a, int b, int c);
extern void func_021BE170(struct Ov208Menu *m);
extern void func_021BE1BC(struct Ov208Menu *m);
void func_021BDFDC(struct Ov208Menu *m)
{
    u32 sel = 9;
    u32 trg = func_020362DC();
    u32 held = func_0203633C();
    u32 a;
    u32 b;
    u32 c;
    volatile u32 d; /* volatile on purpose: image spills it to the stack and re-reads it */
    u8 i;
    if (held & 0x20) {
        switch (m->mode) {
        case 0:
            if (func_021BD388(m->f30, *m->tab[3].p))
                sel = 3;
            else
                sel = 4;
            break;
        case 1:
            sel = 6;
            break;
        case 2:
            sel = 5;
            break;
        case 3:
            sel = 4;
            break;
        }
    } else if (held & 0x10) {
        switch (m->mode) {
        case 0:
            sel = 5;
            break;
        case 1:
            sel = 4;
            break;
        case 2:
            if (func_021BD388(m->f30, *m->tab[3].p))
                sel = 3;
            else
                sel = 6;
            break;
        case 3:
            sel = 6;
            break;
        }
    }
    if (sel != 9)
        func_021BD3F8(m->f30, *m->tab[sel].p);
    if ((trg & 0xc0) == 0) {
        if (held & 0x40)
            func_021BD3F8(m->f30, *m->tab[8].p);
        else if (held & 0x80)
            func_021BD3F8(m->f30, *m->tab[7].p);
    }
    a = func_021BDB08(m);
    b = func_021BDB54(m);
    if (a != 0) {
        c = func_021BE32C(a);
        d = func_021BE378(a);
        if (c != 9 && d != 4) {
            for (i = 3; i <= 6; i++)
                func_021BD368((int)m->f30, *m->tab[i].p, i != c);
            m->f1c = d;
            func_021BE170(m);
        }
    }
    if (b != 0) {
        switch (b) {
        case 15:
        case 16:
        case 17:
        case 18:
            func_021BE1BC(m);
            break;
        }
    }
}
