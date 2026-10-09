/*
 * file:     btl_server_p13.c
 * unit:     yes
 * function: func_021BD8AC, func_021BD8F0
 * address:  0x021BD8AC
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
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D75A8  0x021D75A8  thumb  ov093
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 *   func_021B9AEC 0x021B9AEC thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021B9D10 0x021B9D10 thumb ov093
 *   func_021B9C10 0x021B9C10 thumb ov093
 *   func_021B9BF0 0x021B9BF0 thumb ov093
 *   func_021B8750 0x021B8750 thumb ov093
 *   func_021D8484 0x021D8484 thumb ov093
 *   func_021DCF5C 0x021DCF5C thumb ov093
 *   func_021D63EC 0x021D63EC thumb ov093
 *   func_021D6580 0x021D6580 thumb ov093
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021B99B8 0x021B99B8 thumb ov093
 *   func_021B8BEC 0x021B8BEC thumb ov093
 *   func_021BD9C4 0x021BD9C4 thumb ov093
 */

struct Arr;
struct S2;
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

extern void func_021D74F8(int line);
extern u8 func_021D5440(u8 *p);
extern void func_021D75A8(int key, u32 val);
extern void func_021D7630(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern int func_021D775C(int key);
extern void func_021D7540(int line);
extern char *func_021B9AEC(char *p, int i);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021B9D10(char *a, struct Arr *arr, int k);
extern void func_021B9C10(u32 *p, int a, int b);
extern u32 func_021B9BF0(struct S2 *p, u32 i);
extern void func_021B8750(char *p, unsigned char k, void *m);
extern void *func_021D8484(void *a);
extern void *func_021DCF5C(void *p);
extern void func_021D63EC(u8 *p, u16 n);
extern void func_021D6580(void *);
extern u32 func_021B8588(void **p);
extern int func_021B99B8(void *pp, unsigned int b);
extern u8 func_021B8BEC(u8 *, u32, u8);
extern void func_021BD9C4(void *, int, u8, void *);
int func_021BD8AC(Server *p, u8 *a);
void func_021BD8F0(Server *p, u8 i, u8 a, u8 b);


int func_021BD8AC(Server *p, u8 *a)
{
    int r;
    func_021D74F8(2979);
    func_021D75A8(2, func_021D5440(a));
    func_021D7630(0x51, 0);
    func_021D70F0(p, 0xd);
    r = func_021D775C(0x51);
    func_021D7540(2984);
    return r;
}

void func_021BD8F0(Server *p, u8 i, u8 a, u8 b)
{
    char *arr;
    u8 *m;
    u8 id;
    u8 *flags;
    arr = func_021B9AEC((char *)p->f8, i);
    func_021CD4B0(p->fC, 42, i);
    func_021B9D10((char *)p->f4, (struct Arr *)arr, i);
    if (a != b) func_021B9C10((u32 *)arr, a, b);
    m = (u8 *)func_021B9BF0((struct S2 *)arr, a);
    id = func_021D5440(m);
    func_021B8750(p->f4, i, m);
    func_021D8484(m);
    func_021DCF5C(m);
    func_021D63EC(m, p->f10);
    func_021D6580(m);
    flags = p->flags;
    flags[id] = 1;
    if (func_021B8588(p->f4) == 3) {
        if ((u32)func_021B99B8(p->f4, (int)i) <= a) flags[id] = 0;
    }
    func_021CD4B0(p->fC, 18, i, a, b, (u16)p->f10);
    func_021BD9C4(p->w1ab8, func_021B8BEC((u8 *)p->f4, i, a), id, p->f8);
}
