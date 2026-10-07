/*
 * file:     btlv_effvm_p37.c
 * unit:     yes
 * function: func_021FB0E8, func_021FB168
 * address:  0x021FB0E8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_021FCA04  0x021FCA04  thumb  ov094
 *   func_021F8694  0x021F8694  thumb  ov094
 *   func_021FFDB4  0x021FFDB4  thumb  ov094
 *   func_021FF374  0x021FF374  thumb  ov094
 *   func_02200654  0x02200654  thumb  ov094
 */
struct Cursor;
typedef unsigned char u8;

typedef struct {
    char pad[0x23C];
    int f23c;
} State;

typedef unsigned int   u32;

extern u32 func_0201134C(struct Cursor *p);
extern int func_021FCA04(State *s, int id, int *out);
extern int func_021F8694(void);
extern void func_021FFDB4(void *w, int a, u8 b, u8 c, u8 d, int e);
extern void func_021FF374(void *w, int a, int b);
extern void func_02200654(void *w);
int func_021FB0E8(void *a, State *s);
int func_021FB168(void *a, State *s);


int func_021FB0E8(void *a, State *s)
{
    int buf[8];
    int n;
    int p;
    int q;
    int r;
    int t;
    int i;

    n = func_021FCA04(s, func_0201134C(a), buf);
    p = func_0201134C(a);
    q = func_0201134C(a);
    r = func_0201134C(a);
    t = func_0201134C(a);
    if (n != 0) {
        for (i = 0; i < n; i++)
            func_021FFDB4((void *)func_021F8694(), buf[i], p, q, r, t);
    }
    return s->f23c;
}


int func_021FB168(void *a, State *s)
{
    int buf[8];
    int n;
    int v;
    int i;

    n = func_021FCA04(s, func_0201134C(a), buf);
    v = func_0201134C(a);
    if (v == 5) {
        func_02200654((void *)func_021F8694());
    } else if (n != 0) {
        for (i = 0; i < n; i++)
            func_021FF374((void *)func_021F8694(), buf[i], v);
    }
    return s->f23c;
}
