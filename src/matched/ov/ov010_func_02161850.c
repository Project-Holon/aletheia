/*
 * function: func_02161850
 * address:  0x02161850
 * packet:   pkt_ov010_02161850
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_02161938  0x02161938  thumb  ov010
 *   func_02197D3C  0x02197D3C  thumb  ov021
 *   func_02161964  0x02161964  thumb  ov010
 *   func_02161984  0x02161984  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Obj {
    u8 pad00[4];
    void *f04;          /* 0x04 */
    u8 pad08[4];
    u16 f0c;            /* 0x0C */
    u8 pad0e[2];
    void *f10;          /* 0x10 */
} Obj;

extern void *func_02188C7C(void *p);
extern void *func_02161938(void *a, u32 b);
extern void *func_02197D3C(void *a, void *b);
extern void func_02161964(Obj *o, void *v);
extern int func_02161984(Obj *o);

int func_02161850(void *a0, int *state, Obj *o)
{
    void *t;

    t = func_02188C7C(o->f04);
    switch (*state) {
    case 0:
        t = func_02161938(t, o->f0c);
        if (t == 0)
            return 1;
        func_02161964(o, func_02197D3C(t, o->f10));
        *state = *state + 1;
        break;
    case 1:
        if (func_02161984(o) == 0)
            return 1;
        break;
    }
    return 0;
}
