/*
 * file:     btl_server_p10.c
 * unit:     yes
 * function: func_021BD148, func_021BD170, func_021BD1B0, func_021BD1D0, func_021BD1E0, func_021BD200
 * address:  0x021BD148
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BCA08 0x021BCA08 thumb ov093
 *   func_021BCB98 0x021BCB98 thumb ov093
 *   func_021BCAAC  0x021BCAAC  thumb  ov093
 *   func_021BCC50 0x021BCC50 thumb ov093
 *   func_021BD264  0x021BD264  thumb  ov093
 *   func_021BD274  0x021BD274  thumb  ov093
 *   func_021BD284  0x021BD284  thumb  ov093
 *   func_021BD294  0x021BD294  thumb  ov093
 *   func_021BD2A4  0x021BD2A4  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef union {
    struct { u32 type:4, select:3, move:16, arg:8, rest:1; } full;
    struct { u32 type:4, select:3, move:3, rest:22; } small;
} Action;

typedef struct {
    u8 *a;      /* 0x0 */
    Action b;   /* 0x4 */
    u32 c;      /* 0x8 */
    u8 d;       /* 0xc */
    u8 done;    /* 0xd */
    u8 f;       /* 0xe */
    u8 pad;     /* 0xf */
} Entry;

typedef struct {
    u8 *f0;                         /* 0x000 */
    void *f4;                       /* 0x004 */
    void *f8;                       /* 0x008 */
    void *fC;                       /* 0x00c */
    u32 f10;                        /* 0x010 */
    u32 f14;                        /* 0x014 */
    u8 pad18[0x4b8 - 0x18];
    u8 w4b8[0x782 - 0x4b8];         /* 0x4b8 */
    u8 n;                           /* 0x782 */
    u8 pad783;
    u8 f784;                        /* 0x784 */
    u8 pad785;
    u8 f786;                        /* 0x786 */
    u8 pad787[3];
    union {
        u8 raw;
        struct { u8 b0:1, b1:1, b2:1, rest:5; } bits;
    } f78a;                         /* 0x78a */
    u8 f78b[0x7c1 - 0x78b];         /* 0x78b */
    u8 flags[0x7e0 - 0x7c1];        /* 0x7c1 */
    Entry e[6];                     /* 0x7e0 */
    Entry t;                        /* 0x840 */
    u8 pad850[0x1ab8 - 0x850];
    u8 w1ab8[0x1d74 - 0x1ab8];      /* 0x1ab8 */
    u32 lock;                       /* 0x1d74 */
    u8 pad1d78[0x1f78 - 0x1d78];
    int f1f78;                      /* 0x1f78 */
    u8 pad1f7c[0x1fe8 - 0x1f7c];
    u8 f1fe8;                       /* 0x1fe8 */
} Server;

struct Unk021BD1E0 {
    u16 f0;
    u8 f2;
    u8 f3;
    u8 f4;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
};

struct Unk021BD200 {
    u16 f0;
    u8 f2;
    u8 f3;
    u8 f4;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
};


extern Entry *func_021BCA08(Server *p, u8 x);
extern Entry *func_021BCAAC(Server *p, u8 x, u32 i);
extern int func_021BCB98(Server *p, Entry *cur, int start);
extern void func_021BCC50(Server *p, Entry *cur);
extern u8 func_021D5440(u8 *p);
extern int func_021BD264(int t);
extern u8 func_021BD274(u8 *p, u8 x);
extern int func_021BD284(int t);
extern u8 *func_021BD294(int t, int k);
extern u8 func_021BD2A4(u8 *p, u8 x);
int func_021BD148(Server *p, u8 x);
int func_021BD170(Server *p, u8 x);
int func_021BD1B0(Server *p, u8 x);
void func_021BD1D0(Server *p, u8 n);
void func_021BD1E0(struct Unk021BD1E0 *p);
void func_021BD200(struct Unk021BD1E0 *p, Server *q, u8 *a, int t);

int func_021BD148(Server *p, u8 x)
{
    Entry *e = func_021BCA08(p, x);
    if (e && e->done == 0) {
        if (func_021BCB98(p, e, 0) >= 0) return 1;
    }
    return 0;
}

int func_021BD170(Server *p, u8 x)
{
    int i = 0;
    int r;
    Entry *e = func_021BCAAC(p, x, 0);
    r = 0;
    while (e) {
        i = func_021BCB98(p, e, i);
        if (i < 0) break;
        i++;
        e = func_021BCAAC(p, x, (u8)i);
        r = 1;
    }
    return r;
}

int func_021BD1B0(Server *p, u8 x)
{
    Entry *e = func_021BCA08(p, x);
    if (e && e->done == 0) {
        func_021BCC50(p, e);
        return 1;
    }
    return 0;
}

/* 021BD1D0  guard on a callee's pointer result, then set a byte */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; bl func_021BCA08; cmp r0, #0; beq loc_021BD1DE; movs r1, #1; strb r1, [r0, #0xd]; pop {r3, pc}.
 */
void func_021BD1D0(Server *p, u8 n)
{
    Entry *e = func_021BCA08(p, n);
    if (e != 0)
        e->done = 1;
}

void func_021BD1E0(struct Unk021BD1E0 *p)
{
    p->f0 = 0;
    p->f2 = 6;
    p->f3 = 6;
    p->f4 = 0;
    p->b0 = 0;
    p->b1 = 0;
}

void func_021BD200(struct Unk021BD1E0 *p, Server *q, u8 *a, int t)
{
    int r = func_021BD264(t);
    p->f2 = func_021BD274(q->w1ab8, func_021D5440(a));
    p->f3 = 6;
    p->b0 = 0;
    p->b1 = 0;
    if (r == 1 && func_021BD284(t)) {
        p->f3 = func_021BD2A4(q->w1ab8, func_021D5440(func_021BD294(t, 0)));
    }
}
