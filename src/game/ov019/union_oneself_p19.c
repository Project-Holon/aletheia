/*
 * file:     union_oneself_p19.c
 * unit:     yes
 * function: func_0217FCE4, func_0217FD04, func_0217FD38
 * address:  0x0217FCE4
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0217FCA4 0x0217FCA4 thumb ov019
 *   func_0216DA30 0x0216DA30 thumb ov010
 *   func_0217FCC0 0x0217FCC0 thumb ov019
 *   MTX_Identity33_  0x0207ADC4  arm
 *   func_0217FCC4    0x0217FCC4  thumb  ov019
 *   d_02180758       0x02180758  data   ov019 a4
 */
typedef unsigned int u32;

struct E_0217FCE4 { u32 a,b,c,d; unsigned short h; };

struct E_0217FD04 { u32 a,b,c,d; unsigned short h; };

typedef unsigned char  u8;

typedef unsigned short u16;

struct B60 { u32 w[15]; };

struct E_0217FD38 { u32 a, b, c, d; u16 h; };

extern void func_0217FCA4(u32 *p);
extern int func_0216DA30(u32 a);
extern void func_0217FCC0(struct E_0217FD04 *e);
extern void MTX_Identity33_(void *m);
extern void func_0217FCC4(u32 *p, u32 *b);
void func_0217FCE4(struct E_0217FCE4 *p);
void func_0217FD04(struct E_0217FD04 *p);
void func_0217FD38(struct E_0217FD38 *p);
extern struct B60 d_02180758;

void func_0217FCE4(struct E_0217FCE4 *p) { int i; for(i=0;i<10;i++) { struct E_0217FCE4 *e=&p[i]; if(e->d != 0) func_0217FCA4((u32 *)e); } }

void func_0217FD04(struct E_0217FD04 *p)
{
    int i;
    for (i=0;i<10;i++) {
        struct E_0217FD04 *e=&p[i];
        if (e->d != 0) {
            if (func_0216DA30(e->a) == 1) func_0217FCC0(e);
            else func_0217FCA4((u32 *)e);
        }
    }
}


/*
 * Addresses are Black-image addresses.
 */
void func_0217FD38(struct E_0217FD38 *p)
{
    struct B60 b = d_02180758;
    int i;

    MTX_Identity33_(&b.w[6]);
    for (i = 0; i < 10; i++) {
        struct E_0217FD38 *e = &p[i];
        if (e->d != 0 && func_0216DA30(e->a) == 1) {
            func_0217FCC4((u32 *)e, (u32 *)(&b));
        }
    }
}
