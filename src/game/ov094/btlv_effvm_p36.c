/*
 * file:     btlv_effvm_p36.c
 * unit:     yes
 * function: func_021FAD2C, func_021FADC0, func_021FAE48, func_021FAECC, func_021FAF44, func_021FAFBC, func_021FB034, func_021FB09C
 * address:  0x021FAD2C
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
 *   func_021FFA18  0x021FFA18  thumb  ov094
 *   func_0207C768  0x0207C768  arm
 *   func_021FFB04  0x021FFB04  thumb  ov094
 *   func_021FF5B0  0x021FF5B0  thumb  ov094
 *   func_021FF730  0x021FF730  thumb  ov094
 *   func_021FF924  0x021FF924  thumb  ov094
 *   func_021FFBBC  0x021FFBBC  thumb  ov094
 *   func_021FF870  0x021FF870  thumb  ov094
 *   func_021FF304  0x021FF304  thumb  ov094
 */
struct Cursor;
typedef struct {
    char pad[0x23C];
    int f23c;
} State;

typedef struct {
    int f0;
    int item;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    char pad[0x14];
} Req_021FAD2C;

typedef unsigned int   u32;

typedef struct {
    int f0;
    int item;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
} Req_021FADC0;

extern u32 func_0201134C(struct Cursor *p);
extern int func_021FCA04(State *s, int id, int *out);
extern int func_021F8694(void);
extern void func_021FFA18(void *w, Req_021FAD2C *r);
extern u32 func_0207C768(u32 a, u32 b);
extern void func_021FFB04(void *w, Req_021FADC0 *r);
extern void func_021FF5B0(void *w, int a, int b, int *c, int d, int e, int f);
extern void func_021FF730(void *w, int a, int b, int *c, int d, int e, int f);
extern void func_021FF924(char *w, int key, int kind, int value, int a, int b, int c);
extern void func_021FFBBC(char *w, int key, int kind, int value, int a, int b, int c);
extern void func_021FF870(void *w, int a, int b, int c, int d);
extern void func_021FF304(void *w, int a, int b);
int func_021FAD2C(void *a, State *s);
int func_021FADC0(void *a, State *s);
int func_021FAE48(void *a, State *s);
int func_021FAECC(void *a, State *s);
int func_021FAF44(void *a, State *s);
int func_021FAFBC(void *a, State *s);
int func_021FB034(void *a, State *s);
int func_021FB09C(void *a, State *s);


int func_021FAD2C(void *a, State *s)
{
    Req_021FAD2C q;
    int buf[8];
    int n;
    int i;

    n = func_021FCA04(s, (int)func_0201134C(a), buf);
    q.f8 = (int)func_0201134C(a);
    q.fc = (int)func_0201134C(a);
    q.f10 = (int)func_0201134C(a);
    q.f14 = (int)func_0201134C(a);
    q.f18 = (int)func_0201134C(a) >> 12;
    q.f1c = (int)func_0201134C(a) >> 12;
    q.f20 = (int)func_0201134C(a) >> 12;
    q.f24 = (int)func_0201134C(a);
    if (n != 0 && q.f20 != 0) {
        for (i = 0; i < n; i++) {
            q.item = buf[i];
            func_021FFA18((void *)func_021F8694(), &q);
        }
    }
    return s->f23c;
}


int func_021FADC0(void *a, State *s)
{
    Req_021FADC0 q;
    int buf[8];
    int n;
    int p;
    int r;
    int t;
    int u;
    int v;
    int i;

    n = func_021FCA04(s, func_0201134C(a), buf);
    p = func_0201134C(a);
    r = func_0201134C(a);
    t = func_0201134C(a);
    u = func_0201134C(a);
    v = func_0201134C(a);
    q.f18 = r;
    q.f24 = v;
    q.f14 = p;
    q.f20 = u;
    q.f1c = func_0207C768(t - r, v << 12);
    if (n != 0) {
        for (i = 0; i < n; i++) {
            q.item = buf[i];
            func_021FFB04((void *)func_021F8694(), &q);
        }
    }
    return s->f23c;
}


int func_021FAE48(void *a, State *s)
{
    int t[3];
    int buf[8];
    int n;
    int x;
    int r;
    int u;
    int v;
    int i;

    n = func_021FCA04(s, func_0201134C(a), buf);
    x = func_0201134C(a);
    t[0] = func_0201134C(a);
    t[1] = func_0201134C(a);
    t[2] = 0x1000;
    r = func_0201134C(a);
    u = func_0201134C(a);
    v = func_0201134C(a);
    if (n != 0) {
        for (i = 0; i < n; i++)
            func_021FF5B0((void *)func_021F8694(), buf[i], x, t, r, u, v);
    }
    return s->f23c;
}


int func_021FAECC(void *a, State *s)
{
    int buf[8];
    int t[3];
    int n;
    int x;
    int r;
    int u;
    int v;
    int i;

    n = func_021FCA04(s, func_0201134C(a), buf);
    x = func_0201134C(a);
    i = 0;
    t[0] = 0;
    t[1] = 0;
    t[2] = func_0201134C(a);
    r = func_0201134C(a);
    u = func_0201134C(a);
    v = func_0201134C(a);
    if (n != 0) {
        for (; i < n; i++)
            func_021FF730((void *)func_021F8694(), buf[i], x, t, r, u, v);
    }
    return s->f23c;
}


int func_021FAF44(void *a, State *s)
{
    int buf[8];
    int n;
    int p;
    int q;
    int r;
    int t;
    int u;
    int i;

    n = func_021FCA04(s, func_0201134C(a), buf);
    p = func_0201134C(a);
    q = func_0201134C(a);
    r = func_0201134C(a);
    t = func_0201134C(a);
    u = func_0201134C(a);
    if (n != 0) {
        for (i = 0; i < n; i++)
            func_021FF924((char *)func_021F8694(), buf[i], p, q, r, t, u);
    }
    return s->f23c;
}


int func_021FAFBC(void *a, State *s)
{
    int buf[8];
    int n;
    int p;
    int q;
    int r;
    int t;
    int u;
    int i;

    n = func_021FCA04(s, func_0201134C(a), buf);
    p = func_0201134C(a);
    q = func_0201134C(a);
    r = func_0201134C(a);
    t = func_0201134C(a);
    u = func_0201134C(a);
    if (n != 0) {
        for (i = 0; i < n; i++)
            func_021FFBBC((char *)func_021F8694(), buf[i], p, q, r, t, u);
    }
    return s->f23c;
}


int func_021FB034(void *a, State *s)
{
    int buf[8];
    int n;
    int x;
    int y;
    int z;
    int i;

    n = func_021FCA04(s, func_0201134C(a), buf);
    x = func_0201134C(a);
    y = func_0201134C(a);
    z = func_0201134C(a);
    if (n != 0) {
        if (z == 0)
            z = 1;
        for (i = 0; i < n; i++)
            func_021FF870((void *)func_021F8694(), buf[i], x, y, z);
    }
    return s->f23c;
}


int func_021FB09C(void *a, State *s)
{
    int buf[8];
    int n;
    int v;
    int i;

    n = func_021FCA04(s, func_0201134C(a), buf);
    v = func_0201134C(a);
    if (n != 0) {
        for (i = 0; i < n; i++)
            func_021FF304((void *)func_021F8694(), buf[i], v);
    }
    return s->f23c;
}
