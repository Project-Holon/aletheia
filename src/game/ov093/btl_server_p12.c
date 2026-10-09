/*
 * file:     btl_server_p12.c
 * unit:     yes
 * function: func_021BD4E4, func_021BD518, func_021BD554, func_021BD584, func_021BD60C, func_021BD6B8, func_021BD708, func_021BD850
 * address:  0x021BD4E4
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
 *   func_021B9AEC 0x021B9AEC thumb ov093
 *   func_021B9C00 0x021B9C00 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   func_021D74F8 0x021D74F8 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021D75A8 0x021D75A8 thumb ov093
 *   func_021D70F0 0x021D70F0 thumb ov093
 *   func_021D7540 0x021D7540 thumb ov093
 *   func_021B8DDC  0x021B8DDC  thumb  ov093
 *   func_021B8FF4  0x021B8FF4  thumb  ov093
 *   func_021BA1B4  0x021BA1B4  thumb  ov093
 *   func_021CD64C  0x021CD64C  thumb  ov093
 *   func_021B86E4  0x021B86E4  thumb  ov093
 *   func_021B9920  0x021B9920  thumb  ov093
 *   func_021D58A8  0x021D58A8  thumb  ov093
 *   func_021D78AC  0x021D78AC  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021B902C 0x021B902C thumb ov093
 *   func_021BD8AC 0x021BD8AC thumb ov093
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_021B86C0 0x021B86C0 thumb ov093
 *   func_021D8244 0x021D8244 thumb ov093
 *   func_021BD89C  0x021BD89C  thumb  ov093
 */

struct S2;
struct B;
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

extern char *func_021B9AEC(char *p, int i);
extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern int func_021D5B68(void *);
extern u32 func_021CC8D8(void *, int);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern void func_021D74F8(int);
extern u8 func_021D5440(u8 *p);
extern void func_021D75A8(int, unsigned int);
extern void func_021D70F0(void *a, int id);
extern void func_021D7540(int);
extern u8 func_021B8DDC(u32 x);
extern u8 func_021B8FF4(u8 *p);
extern void func_021BA1B4(char **p, int i);
extern void func_021CD64C(void *w, u8 id, ...);
extern int func_021B86E4(unsigned int **p);
extern u8 *func_021B9920(void *p, u32 i, u8 j);
extern int func_021D58A8(u8 *p, int k);
extern u32 func_021D78AC(u32 range);
extern void func_021D75EC(int key, u32 val);
extern void func_021D7630(int key, u32 val);
extern int func_021D775C(int key);
extern int func_021B902C(int, int);
extern int func_021BD8AC(Server *, u8 *);
extern void *func_021B86B8(void ***);
extern u8 func_021B86C0(u8 **p);
extern void func_021D8244(struct B *p, int n);
extern void func_021BD89C(Server *p, u8 *a);
void func_021BD4E4(Server *p, int i, u8 a, u8 b);
void func_021BD518(Server *p, u8 *m);
void func_021BD554(Server *p, u8 *m);
int func_021BD584(Server *p, u8 *a);
int func_021BD60C(Server *p, u8 *a, u8 flag);
int func_021BD6B8(Server *p, u8 *a);
int func_021BD708(Server *p, u8 *a, int r, int z);
int func_021BD850(Server *p, u8 *a);




void func_021BD4E4(Server *p, int i, u8 a, u8 b)
{
    u8 *arr;
    u8 *first;
    u8 *second;
    arr = (u8 *)func_021B9AEC((char *)p->f8, i);
    first = func_021B9C00((struct S2 *)arr, a);
    second = func_021B9C00((struct S2 *)arr, b);
    func_021BD518(p, first);
    func_021BD518(p, second);
}




/*
 * return evidence: func_021CC8D8's matched Lock is one full 32-bit word;
 *   021CC8DA loads it, 021CC900 returns that unchanged word in r0.
 *   This caller saves r0 in r4 and passes it unchanged in r1 to restore.
 *   Scalar u32 return follows matched neighbours 021BD708/021BDA00;
 *   union aggregate spelling gave a spurious 8-byte stack frame (run 1).
 */
void func_021BD518(Server *p, u8 *m)
{
    u32 old;
    if (func_021D5B68(m) == 0) {
        old = func_021CC8D8(&p->lock, 2697);
        func_021BD554(p, m);
        func_021CC95C(&p->lock, old, 2699);
    }
}




void func_021BD554(Server *p, u8 *m)
{
    func_021D74F8(2712);
    func_021D75A8(2, func_021D5440(m));
    func_021D70F0(p, 164);
    func_021D7540(2715);
}





int func_021BD584(Server *p, u8 *a)
{
    int k = func_021B8DDC(func_021D5440(a));
    int m = func_021B8FF4((u8 *)p->f4);
    int s = func_021BD60C(p, a, 0);
    if (s) return 1;
    if (k == m) {
        func_021BA1B4((char **)p->f4, 0x4e);
        func_021CD64C(p->fC, 0x5a, 0x49, 0xffff0000);
    } else {
        func_021CD64C(p->fC, 0x5b, 0x36b, func_021D5440(a), 0xffff0000);
    }
    if (k == m) {
        p->f786++;
        if (p->f786 > 0x1e) p->f786 = 0x1e;
    }
    return s;
}





int func_021BD60C(Server *p, u8 *a, u8 flag)
{
    int ret = 0;
    int k;
    u8 *q;
    u16 lo;
    u16 hi;
    int d;
    u32 t;
    if (func_021B86E4((unsigned int **)p->f4) == 0) {
        k = func_021B8DDC(func_021D5440(a));
        if (k == func_021B8FF4((u8 *)p->f4)) {
            ret = func_021BD6B8(p, a);
            if (ret) flag = 1;
        } else {
            flag = 1;
        }
    } else {
        flag = 1;
        ret = 1;
    }
    if (flag == 0) {
        q = func_021B9920(p->f8, 1, 0);
        if (q) {
            lo = func_021D58A8(a, 0xc);
            hi = func_021D58A8(q, 0xc);
            if (lo <= hi) {
                d = (((int)lo << 12) / (int)hi << 7) >> 12;
                t = d + p->f786 * 30;
                if (func_021D78AC(0x100) >= t) return 0;
            }
        }
    }
    return func_021BD708(p, a, ret, 0);
}





int func_021BD6B8(Server *p, u8 *a)
{
    int r;
    if (func_021D5B68(a) == 0) {
        func_021D74F8(2849);
        func_021D75EC(2, func_021D5440(a));
        func_021D7630(0x51, 0);
        func_021D70F0(p, 0xb);
        r = func_021D775C(0x51);
        func_021D7540(2854);
        return r;
    }
    return 0;
}



int func_021BD708(Server *p, u8 *a, int r, int z)
{
    int k = func_021B8DDC(func_021D5440(a));
    u8 f;
    if (func_021B86E4((unsigned int **)p->f4) == 0) {
        f = (u8)(func_021B902C(k, func_021B8FF4((u8 *)p->f4)) == 0 ? 1 : 0);
        if (r == 0 && func_021D5B68(a) == 0) {
            u32 l;
            l = func_021CC8D8(&p->lock, 2888);
            r = func_021BD850(p, a);
            func_021CC95C(&p->lock, l, 2890);
            if (r) return 0;
        }
        if (p->f78a.bits.b2 == 0) {
            if (z == 0) {
                u32 l;
                l = func_021CC8D8(&p->lock, 2904);
                r = func_021BD8AC(p, a);
                func_021CC95C(&p->lock, l, 2906);
            } else {
                r = 0;
            }
            if (r == 0) {
                if (f != 0) {
                    if (func_021B86B8((void ***)p->f4) == 0)
                        func_021CD64C(p->fC, 0x5c, 0x4b, 0x56a, func_021D5440(a), 0xffff0000);
                } else {
                    func_021CD64C(p->fC, 0x5c, 0x48, 0x56a, 0xffff0000);
                }
            }
            p->f78a.raw |= 4;
        }
    } else {
        if (func_021B86C0((u8 **)p->f4) != 0 && p->f78a.bits.b2 == 0) {
            func_021CD64C(p->fC, 0x5a, 0xc6, 0xffff0000);
            p->f78a.raw |= 4;
        }
    }
    func_021D8244((struct B *)(p->w4b8), k);
    return 1;
}


int func_021BD850(Server *p, u8 *a)
{
    int r;
    func_021D74F8(2957);
    func_021D75EC(2, func_021D5440(a));
    func_021D7630(0x41, 0);
    func_021BD89C(p, a);
    func_021D70F0(p, 0xc);
    r = func_021D775C(0x41);
    func_021D7540(2963);
    return r;
}
