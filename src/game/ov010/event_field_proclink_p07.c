/*
 * file:     event_field_proclink_p07.c
 * unit:     yes
 * function: func_0215F2B8, func_0215F2DC, func_0215F2F0, func_0215F318, func_0215F33C, func_0215F3A4, func_0215F424, func_0215F4F4
 * address:  0x0215F2B8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0201214C  0x0201214C  thumb
 *   func_02012158 0x02012158 thumb
 *   func_0215A5F4 0x0215A5F4 thumb ov010
 *   func_0204A1BC 0x0204A1BC arm
 *   func_02159114 0x02159114 thumb ov010
 *   func_0215911C  0x0215911C  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012844  0x02012844  thumb
 *   func_0215F608  0x0215F608  thumb  ov010
 *   func_0215A480  0x0215A480  thumb  ov010
 *   func_02162788  0x02162788  thumb  ov010
 *   func_0215A490  0x0215A490  thumb  ov010
 *   func_02162774  0x02162774  thumb  ov010
 *   func_02158F54 0x02158F54 thumb ov010
 *   func_020120F4 0x020120F4 thumb
 *   func_0201296C 0x0201296C thumb
 *   func_0215A500 0x0215A500 thumb ov010
 */
struct Ctx;
struct BigObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Entry_0215F424 {
    u32 f00;
    u16 f04;
    u16 f06;
} Entry_0215F424;

typedef struct Entry_0215F4F4 { u32 a; u16 b,c; } Entry_0215F4F4;

extern void *func_0215A5DC(void *a0);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u32 func_0201214C(const struct Ctx *p);
extern void func_02012158(char *p, unsigned int v);
extern void *func_0215A5F4(void *p);
extern int func_0204A1BC(int,int,int,int);
extern void *func_02159114(void *p, u32 v);
extern u32 func_0215911C(void *p);
extern u32 func_020307B0(void *p);
extern unsigned int func_02159B10(void *a0, void *a1);
extern void *func_0215A5E4(void *a0);
extern u32 func_02012844(const struct BigObj *p);
extern int func_0215F608();
extern u16 func_0215A480(unsigned a);
extern void func_02162788(char *p, unsigned i, u16 v);
extern u16 func_0215A490(unsigned a);
extern void func_02162774(char *p, unsigned i, u16 v);
extern void *func_02158F54(void *);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_0201296C(const struct BigObj *p);
extern void func_0215A500(char *a, unsigned b);
int func_0215F2B8(int a0, int a1);
int func_0215F2DC(void *a, void *b);
int func_0215F2F0(void *a, void *b);
int func_0215F318(void *a0, int a1);
int func_0215F33C(int a, int b);
int func_0215F3A4(int a, int b);
int func_0215F424(int a0, int a1);
int func_0215F4F4(void *a,void *b);


int func_0215F2B8(int a0, int a1)
{    int t5;
    int t6;
    u16 *q;
    void *v0;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = func_0215A5DC((void *)a0);
loc_0215F2C4:
a0 = t5 + 0;
a1 = t6 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215F2CE:
    a0 = func_0201214C(v0);
loc_0215F2D6:
*q = a0;
a0 = 0;
    return a0;}

int func_0215F2DC(void *a, void *b) { func_02012158(func_0215A5DC(b), 0); return 0; }

int func_0215F2F0(void *a, void *b) { void *p = func_0215A5F4(b); func_02159114(p,func_0204A1BC(0xd1,0,0,0x8004)); return 0; }


int func_0215F318(void *a0, int a1)
{    void *v0;

a0 = (void *)(a1 + 0);
    v0 = func_0215A5F4((void *)a0);
loc_0215F320:
    a0 = (void *)func_0215911C(v0);
loc_0215F326:
    if (a0 == 0) goto loc_0215F336;
loc_0215F32A:
    a0 = (void *)func_020307B0(a0);
loc_0215F32E:
a1 = 0;
    a0 = (void *)func_02159114(v0, a1);
loc_0215F336:
a0 = 0;
    return (int)a0;}


int func_0215F33C(int a, int b)
{
    void *x = func_0215A5F4((void *)b);
    int y = func_02159B10((void *)a, (void *)b);
    int z = func_02159B10((void *)a, (void *)b);
    int w = func_02159B10((void *)a, (void *)b);
    u8 *base;
    int h;
    int r;
    r = func_02012844(func_0215A5E4((void *)b));
    base = (u8 *)func_0215911C(x);
    h = *(u16 *)(base + (u16)func_0215F608(base, y, w) * 8 + 6);
    func_02162788((char *)r, z, func_0215A480(h));
    return 0;
}


int func_0215F3A4(int a, int b)
{
    void *x = func_0215A5F4((void *)b);
    int y0 = func_02159B10((void *)a, (void *)b);
    int y1 = func_02159B10((void *)a, (void *)b);
    int y2 = func_02159B10((void *)a, (void *)b);
    int y3 = func_02159B10((void *)a, (void *)b);
    u8 *base;
    u8 *e;
    u16 h;
    int r;
    r = func_02012844(func_0215A5E4((void *)b));
    base = (u8 *)func_0215911C(x);
    e = base + 6;
    h = func_0215F608(base, y0, y3);
    func_02162788((char *)r, y1, func_0215A480(*(u16 *)(e + h * 8)));
    func_02162788((char *)r, y2, func_0215A490(*(u16 *)(e + h * 8)));
    return 0;
}


int func_0215F424(int a0, int a1)
{
    void *w = func_0215A5F4((void *)a1);
    int s0 = func_02159B10((void *)a0, (void *)a1);
    int s1 = func_02159B10((void *)a0, (void *)a1);
    int s2 = func_02159B10((void *)a0, (void *)a1);
    int i0 = func_02159B10((void *)a0, (void *)a1);
    int i1 = func_02159B10((void *)a0, (void *)a1);
    int i2 = func_02159B10((void *)a0, (void *)a1);
    int obj = func_02012844(func_0215A5E4((void *)a1));
    Entry_0215F424 *t = (Entry_0215F424 *)func_0215911C(w);
    func_02162774((char *)obj, s0, t[i0].f04);
    func_02162774((char *)obj, s1, t[i1].f04);
    func_02162774((char *)obj, s2, t[i2].f04);
    func_02162788((char *)obj, s0, func_0215A480(t[i0].f06));
    func_02162788((char *)obj, s1, func_0215A480(t[i1].f06));
    func_02162788((char *)obj, s2, func_0215A480(t[i2].f06));
    return 0;
}

int func_0215F4F4(void *a,void *b) { void *p; void *s; int i; Entry_0215F4F4 *t; p=func_0215A5F4(b); s=(void *)func_0201296C(func_020120F4(func_02158F54(p))); t=(Entry_0215F4F4 *)func_0215911C(p); for(i=0;i<0x6b;i++) func_0215A500(s,t[i].c); return 0; }
