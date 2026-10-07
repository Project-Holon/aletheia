/*
 * file:     btlv_effvm_p90.c
 * unit:     yes
 * function: func_0220270C, func_02202DC4
 * address:  0x0220270C
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
 *   func_022056B4  0x022056B4  thumb  ov094
 *   func_022043C0  0x022043C0  thumb  ov094
 *   func_02204960  0x02204960  thumb  ov094
 *   func_0202173C  0x0202173C  thumb
 *   func_02030734  0x02030734  arm
 *   func_021F8A78  0x021F8A78  thumb  ov094
 *   func_02205E30  0x02205E30  thumb  ov094
 *   func_02205AB8  0x02205AB8  thumb  ov094
 *   func_02030DA8  0x02030DA8  arm
 *   func_0220684C  0x0220684C  thumb  ov094
 *   func_02021848  0x02021848  thumb
 *   func_0204B248  0x0204B248  arm
 *   func_0204B22C  0x0204B22C  arm
 *   func_022067E8  0x022067E8  thumb  ov094
 *   func_021F8A40  0x021F8A40  thumb  ov094
 *   func_0220680C  0x0220680C  thumb  ov094
 *   func_021F8914  0x021F8914  thumb  ov094
 *   func_022057CC  0x022057CC  thumb  ov094
 *   func_02205B90  0x02205B90  thumb  ov094
 *   func_02206A7C  0x02206A7C  thumb  ov094
 *   func_02206728  0x02206728  thumb  ov094
 *   func_02205B80  0x02205B80  thumb  ov094
 *   func_02205D58  0x02205D58  thumb  ov094
 *   func_02204CC0  0x02204CC0  thumb  ov094
 *   func_021F8AC0  0x021F8AC0  thumb  ov094
 *   func_021F7998  0x021F7998  thumb  ov094
 *   func_022050F0  0x022050F0  thumb  ov094
 *   func_02205340  0x02205340  thumb  ov094
 *   func_022053DC  0x022053DC  thumb  ov094
 *   func_0220558C  0x0220558C  thumb  ov094
 *   func_0201DD78  0x0201DD78  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_02045808  0x02045808  arm
 *   func_02045374  0x02045374  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02045334  0x02045334  arm
 *   func_022043AC  0x022043AC  thumb  ov094
 *   func_02203BC0  0x02203BC0  thumb  ov094
 *   func_02203C2C  0x02203C2C  thumb  ov094
 *   func_02203978  0x02203978  thumb  ov094
 *   func_022035C0  0x022035C0  thumb  ov094
 *   func_02203B08  0x02203B08  thumb  ov094
 *   func_022036C4  0x022036C4  thumb  ov094
 *   func_02203880  0x02203880  thumb  ov094
 *   func_02203A78  0x02203A78  thumb  ov094
 *   func_02203D40  0x02203D40  thumb  ov094
 *   func_02203E30  0x02203E30  thumb  ov094
 *   func_022041E0  0x022041E0  thumb  ov094
 *   func_02203FDC  0x02203FDC  thumb  ov094
 *   func_022040FC  0x022040FC  thumb  ov094
 *   d_0220AEB0     0x0220AEB0  data
 *   func_02021ED8  0x02021ED8  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_021F8168  0x021F8168  thumb  ov094
 *   func_02035C08  0x02035C08  arm
 *   func_02206B58  0x02206B58  thumb  ov094
 *   func_02206B30  0x02206B30  thumb  ov094
 *   func_0220648C  0x0220648C  thumb  ov094
 *   func_02206578  0x02206578  thumb  ov094
 *   func_02206140  0x02206140  thumb  ov094
 *   func_0203630C  0x0203630C  arm
 *   func_02206BAC  0x02206BAC  thumb  ov094
 *   func_02206908  0x02206908  thumb  ov094
 *   d_0689E090     0x0689E090  data   ov095
 *   d_0689E0B0     0x0689E0B0  data   ov095
 *   d_0689E560     0x0689E560  data   ov095
 *   d_0689E704     0x0689E704  data   ov095
 */
#define S_INT(o) (*(int *)(s + (o)))
#define S_PTR(o) (*(void **)(s + (o)))
#define F68_(s) (*(F68 *)((s) + 0x68))
#define F6C_(s) (*(F6C *)((s) + 0x6c))
#define HEAP(s) ((u16)((*(u16 *)((s) + 0x240) & 0x7fff) | 0x8000))
struct Bank;
struct Cfg;
struct Ctx;
struct Info;
struct Main;
struct MsgBank;
struct Out;
struct Slots;
struct U16Vec;
struct Work;
struct Descriptor;
typedef unsigned char u8;

typedef signed short s16;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct F68 {
    u32 b0 : 1;
    u32 b1 : 3;
    u32 b4 : 1;
    u32 b5 : 4;
    u32 b9 : 4;
    u32 b13 : 1;
    u32 b14 : 1;
    u32 mode : 2;
    u32 b17 : 2;
    u32 b19 : 2;
    u32 b21 : 2;
    u32 b23 : 4;
    u32 b27 : 5;
} F68;

typedef struct F6C {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 x : 8;
    u32 rest : 22;
} F6C;

typedef struct T12 {
    int v[3];
} T12;

typedef struct Task {
    char *s;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    void *f1c;
    int f20;
} Task;

typedef struct Arg1 {
    T12 a[6];
    T12 b[6];
    int f90;
    int f94;
    u8 pad98[0xbc - 0x98];
    int fbc;
    u8 padc0[5];
    u8 bc5;
} Arg1;

typedef struct Arg2 {
    u16 h[4];
    int f8;
    int fc;
    int f10;
    int f14;
} Arg2;

typedef struct Arg5 {
    int a[3];
    int b[3][4];
} Arg5;

typedef struct S5 {
    u8 pad[0x2a4];
    int a[3];
    int b[3][4];
} S5;

typedef signed char s8;

typedef struct {
    char pad0[0xa];
    s8 id;              /* 0x0a */
    char padb;
} Ent;

typedef struct {
    void *key;          /* 0x00 */
    int f4;
    int *vals;          /* 0x08 */
} Cmd;

typedef struct {
    char pad0[0x50];
    int f50;            /* 0x50 */
    int f54;
    int mode;           /* 0x58 */
    char pad5c[0x64 - 0x5c];
    int f64;            /* 0x64 */
    u32 busy : 1;       /* 0x68 */
    u32 f68_1 : 30;
    u32 lock : 1;
    u32 f6c_0 : 1;      /* 0x6c */
    u32 flag : 1;
    u32 sel : 8;
    u32 f6c_10 : 22;
    int pending;        /* 0x70 */
    char pad74[0x242 - 0x74];
    u8 slot[3][8];      /* 0x242 */
    u8 en[8];           /* 0x25a */
    u8 en2[8];          /* 0x262 */
    char pad26a[0x27c - 0x26a];
    int cur;            /* 0x27c */
    int f280;           /* 0x280 */
} Obj;

extern void func_022056B4(struct Main *m);
extern void func_022043C0(struct Main *m, int a1, int a2, int a3, int a4);
extern void func_02204960(struct Main *m, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
extern int func_0202173C(void *, u16, u16, s16, u8, u8, u16, void *);
extern int func_02021848(void *, u16, u16, s16, u8, u8, u16, void *);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void *func_02030DA8(void *, void (*)(void *, void *), void *, u32);
extern void func_0220684C(char *p, int a, int b);
extern void func_021F8A78(void);
extern void func_02205E30(char *);
extern void func_02205AB8(char *);
extern u32 func_0204B248(struct Bank *bank);
extern void func_0204B22C(struct Bank *bank, u32 mode);
extern void func_022067E8(char *);
extern void func_021F8A40(int);
extern void func_0220680C(char *);
extern int func_021F8914(void);
extern void func_022057CC(struct Main *m, struct Info *q);
extern void func_02205B90(char *, int);
extern int func_02206A7C(char *);
extern void func_02206728(char *s, char *b);
extern void func_02205B80(char *, int);
extern void func_02205D58(char *, int);
extern void func_02204CC0(struct Work *p, const struct Slots *q);
extern void func_021F8AC0(int);
extern void func_021F7998(u32);
extern void func_022050F0(char *s, struct Out *out, const struct Info *p);
extern void func_02205340(struct Main *m, const int *c);
extern void func_022053DC(char *);
extern void func_0220558C(char *s, const int *b);
extern void func_0201DD78(u32, u32, u32);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045374(struct Cfg *cfg);
extern void func_020409B4(u32 index);
extern void func_02045334(struct Descriptor *);
extern void func_022043AC(void *);
extern void func_02203BC0(int a0, struct Ctx *c);
extern void func_02203C2C(void *task, struct Ctx *c);
extern void func_02203978(void *task, struct Ctx *c);
extern void func_022035C0(void *task, struct Ctx *c);
extern void func_02203B08(int a0, struct Ctx *c);
extern void func_022036C4(void *task, struct Ctx *c);
extern void func_02203880(void *task, struct Ctx *c);
extern void func_02203A78(int a0, struct Ctx *c);
extern void func_02203D40(void *, void *);
extern void func_02203E30(void *, void *);
extern void func_022041E0(void *, void *);
extern void func_02203FDC(void *, void *);
extern void func_022040FC(void *, void *);
extern u32 func_02021ED8(const char *ptr);
extern u32 func_020362DC(void);
extern void func_021F8168(void);
extern int func_02035C08(const void *p);
extern void func_02206B58(char *p);
extern void func_02206B30(char *p);
extern int func_0220648C(char *p);
extern int func_02206578(char *s, int a, int b);
extern int func_02206140(Obj *o, Cmd *c, int x, int y, int k, int z);
extern unsigned int func_0203630C(void);
extern void func_02206BAC(char *p);
extern int func_02206908(char *p, char *q, int i);
void func_0220270C(char *s, int mode, void *arg);
int func_02202DC4(Obj *o, Cmd *c, int x);
extern const char d_0220AEB0[];
extern u8 d_0689E090[][15];
extern u8 d_0689E0B0[][15];
extern Ent *d_0689E560[][15];
extern Ent *d_0689E704[][15];


void func_0220270C(char *s, int mode, void *arg)
{
    Task *t;
    void *w;
    int i;
    int j;

    func_022056B4((struct Main *)s);
    F68_(s).b23 = 0;
    F6C_(s).b0 = 1;
    switch (mode) {
    case 0:
        S_INT(0x70) = -1;
        if (S_INT(0x58) == 0) {
            func_022043C0((struct Main *)s, 0x3000, 0x3000, 0, 0x98);
            func_02204960((struct Main *)s, -1, 0, 0, 0, 0, 2, 1);
            func_0202173C(S_PTR(0x64), 2, 3, 1, 12, 12, 0x842, S_PTR(0));
        } else {
            t = func_02030734(HEAP(s), 0x24, 1, d_0220AEB0, 0x549);
            F68_(s).b0 = 1;
            t->s = s;
            if (S_INT(0x23c) == 1)
                func_021F8A78();
            func_02205E30(s);
            func_02205AB8(s);
            if (S_INT(0x58) == 1 || S_INT(0x58) == 4) {
                func_0220684C(s, (int)func_02030DA8(S_PTR(0), (void (*)(void *, void *))func_02203BC0, t, 1), (int)func_022043AC);
            } else {
                t->f20 = S_INT(0x58);
                func_0220684C(s, (int)func_02030DA8(S_PTR(0), (void (*)(void *, void *))func_02203C2C, t, 1), (int)func_022043AC);
            }
            func_02021848(S_PTR(0x64), 2, 3, 1, 0, 12, 0x842, S_PTR(0));
            if (func_0204B248(S_PTR(0x17c)) != 0) {
                F68_(s).b5 = 0;
                F68_(s).b9 = 15;
                F68_(s).b13 = 1;
                func_0204B22C(S_PTR(0x17c), 0);
            }
        }
        break;
    case 1: {
        Arg1 *a = arg;
        Task *t1;
        t1 = func_02030734(HEAP(s), 0x24, 1, d_0220AEB0, 0x570);
        S_INT(0x278) = a->fbc;
        func_022067E8(s);
        func_021F8A40(2);
        if (a->fbc >= 2)
            a->fbc = (a->fbc - 2) / 2;
        F68_(s).b0 = 1;
        F68_(s).b4 = a->f90;
        t1->s = s;
        t1->f8 = a->fbc;
        S_INT(0x27c) = a->fbc;
        if (S_INT(0x58) == 0)
            func_0220680C(s);
        for (i = 0; i < 6; i++) {
            ((T12 *)(s + 0x74))[i] = a->a[i];
            ((T12 *)(s + 0xbc))[i] = a->b[i];
        }
        for (j = 0; j < 4; j++)
            s[0x25a + j] = 1;
        s[0x25b] = func_021F8914();
        func_02205AB8(s);
        func_022057CC((struct Main *)s, (struct Info *)a);
        func_02205B90(s, a->bc5);
        t1->fc = func_02206A7C(s);
        func_02206728(s, (char *)a);
        if (S_INT(0x58) == 2 || S_INT(0x58) == 5) {
            func_02205B80(s, 0);
            func_0220684C(s, (int)func_02030DA8(S_PTR(0), (void (*)(void *, void *))func_02203978, t1, 1), (int)func_022043AC);
        } else {
            func_02205D58(s, 0);
            if (a->f94 != 0)
                func_02205D58(s, 1);
            F68_(s).b14 = a->f94;
            func_0220684C(s, (int)func_02030DA8(S_PTR(0), (void (*)(void *, void *))func_022035C0, t1, 1), (int)func_022043AC);
        }
        break;
    }
    case 2: {
        Arg2 *a = arg;
        Task *t2;
        t2 = func_02030734(HEAP(s), 0x24, 1, d_0220AEB0, 0x5bd);
        func_02204CC0((struct Work *)s, (const struct Slots *)a);
        F68_(s).b0 = 1;
        t2->s = s;
        t2->f8 = a->f10;
        S_INT(0x280) = a->f14;
        t2->fc = func_02206A7C(s);
        for (j = 0; j < 4; j++)
            ((u16 *)(s + 0x26c))[j] = a->h[j];
        if (S_INT(0x23c) == 1 && (S_INT(0x50) == 1 || S_INT(0x50) == 2)) {
            func_021F8AC0(2);
            func_021F7998(0x244);
        }
        if (S_INT(0x58) == 3) {
            func_0220684C(s, (int)func_02030DA8(S_PTR(0), (void (*)(void *, void *))func_02203B08, t2, 1), (int)func_022043AC);
        } else if (S_INT(0x58) == 0) {
            func_02205D58(s, 0);
            if (F68_(s).b14)
                func_02205D58(s, 1);
            func_0220684C(s, (int)func_02030DA8(S_PTR(0), (void (*)(void *, void *))func_022036C4, t2, 1), (int)func_022043AC);
        } else {
            func_02205AB8(s);
            func_0220684C(s, (int)func_02030DA8(S_PTR(0), (void (*)(void *, void *))func_02203880, t2, 1), (int)func_022043AC);
        }
        break;
    }
    case 3:
        t = func_02030734(HEAP(s), 0x24, 1, d_0220AEB0, 0x5ec);
        func_022050F0(s, (struct Out *)t, arg);
        F68_(s).b0 = 1;
        t->s = s;
        t->f8 = ((u8 *)arg)[0x48];
        func_0220684C(s, (int)func_02030DA8(S_PTR(0), (void (*)(void *, void *))func_02203A78, t, 1), (int)func_022043AC);
        break;
    case 4:
        t = func_02030734(HEAP(s), 0x24, 1, d_0220AEB0, 0x5f8);
        func_02205340((struct Main *)s, arg);
        F68_(s).b0 = 1;
        t->s = s;
        F6C_(s).b0 = ((int *)arg)[2];
        func_0220684C(s, (int)func_02030DA8(S_PTR(0), func_02203D40, t, 1), (int)func_022043AC);
        break;
    case 5: {
        Arg5 *a = arg;
        int k;
        t = func_02030734(HEAP(s), 0x24, 1, d_0220AEB0, 0x605);
        if (S_INT(0x58) != 0) {
            F68_(s).b17 = 0;
            F68_(s).b19 = 0;
        }
        for (i = 0; i < 3; i++) {
            ((S5 *)s)->a[i] = a->a[i];
            for (k = 0; k < 4; k++)
                ((S5 *)s)->b[i][k] = a->b[i][k];
        }
        func_022053DC(s);
        F68_(s).b0 = 1;
        t->s = s;
        if (S_INT(0x58) == 0) {
            func_02205D58(s, 0);
            if (F68_(s).b14)
                func_02205D58(s, 1);
            func_0220684C(s, (int)func_02030DA8(S_PTR(0), func_02203E30, t, 1), (int)func_022043AC);
        } else {
            func_0220684C(s, (int)func_02030DA8(S_PTR(0), func_022041E0, t, 1), (int)func_022043AC);
        }
        break;
    }
    case 6: {
        Arg2 *a = arg;
        w = 0;
        for (j = 0; j < 3; j++)
            s[0x25a + j] = 1;
        func_0220558C(s, (const int *)a);
        switch (a->fc) {
        case 0:
            break;
        case 1:
        case 2:
        case 3:
            func_0201DD78(1, 2, 0);
            w = func_02045EC0(S_PTR(0x5c), a->fc + 8);
            break;
        }
        if (S_INT(0x58) == 0) {
            t = func_02030734(HEAP(s), 0x24, 1, d_0220AEB0, 0x65f);
            F68_(s).b0 = 1;
            t->s = s;
            if (a->fc == 0) {
                t->f10 = 0;
                t->f14 = 0x100;
            } else {
                t->f10 = 0x100;
                t->f14 = 0;
            }
            t->f1c = w;
            func_0220684C(s, (int)func_02030DA8(S_PTR(0), func_02203FDC, t, 1), (int)func_022043AC);
        } else {
            if (a->fc == 0)
                func_02204960((struct Main *)s, 4, 0, 0x100, 2, 2, 2, 2);
            else
                func_02204960((struct Main *)s, 4, 0x100, 0, 2, 2, 2, 2);
            if (w != 0) {
                func_0201C7A4((void *)S_INT(0x22c), 0x18, 0x38, w, (void *)S_INT(0x224));
                func_02045808(w);
            }
            func_02045374(S_PTR(0x228));
            func_020409B4(6);
            func_02045334(S_PTR(0x228));
        }
        break;
    }
    case 7:
        t = func_02030734(HEAP(s), 0x24, 1, d_0220AEB0, 0x68c);
        F68_(s).b0 = 1;
        t->s = s;
        func_0220684C(s, (int)func_02030DA8(S_PTR(0), func_022040FC, t, 1), (int)func_022043AC);
        s[0x25a] = 1;
        s[0x25b] = 1;
        break;
    }
    S_INT(0x58) = mode;
}


int func_02202DC4(Obj *o, Cmd *c, int x)
{
    int r;
    int k;
    u32 keys;
    int ret;
    int i;
    int cnt;
    int idx;
    Ent *e;
    int mode;

    if (o->busy || func_02021ED8((const char *)o->f64) != 0 || o->lock)
        return -1;
    ret = o->pending;
    if (ret != -1) {
        o->flag = 0;
        o->pending = -1;
        return ret;
    }
    if (func_020362DC() & 8) {
        if ((u32)(o->mode - 1) <= 2)
            func_021F8168();
    }
    if (o->mode == 6) {
        r = func_02035C08(c->key);
        if (r != -1) {
            if (o->en[r] == 0)
                r = -1;
            else if (r == 2)
                func_02206B58((char *)o);
            else
                func_02206B30((char *)o);
        } else {
            r = func_0220648C((char *)o);
        }
        if (r != -1)
            r = func_02206578((char *)o, r, c->vals[r]);
        return r;
    }

    k = func_02035C08(c->key);
    r = func_02206140(o, c, x, 0, k, o->f280);
    if (r != -1) {
        keys = func_0203630C();
        if (o->en[r] == 0 && (!(keys & 0x200) || o->mode != 2)) {
            if (o->en2[r] != 0 && o->mode == 2)
                func_02206BAC((char *)o);
            r = -1;
        } else if (r < 4 && (keys & 0x200) && o->mode == 2 && o->f280 == 1) {
            r = -1;
        } else if (r < 4 && (keys & 0x200) && o->mode == 2 && o->en2[r] == 0) {
            r = -1;
        } else if (k != -1) {
            if (func_02206908((char *)o, (char *)c, r) == 0 && !o->flag) {
                func_02206B30((char *)o);
                mode = o->mode;
                switch (mode) {
                case 1:
                case 2:
                case 5:
                    o->slot[o->cur][mode] = r;
                    break;
                case 3:
                    idx = 0;
                    if (o->f50 != 2)
                        cnt = d_0689E090[o->cur][o->sel];
                    else
                        cnt = d_0689E0B0[o->cur][o->sel];
                    if (o->f50 != 2)
                        e = d_0689E560[o->cur][o->sel];
                    else
                        e = d_0689E704[o->cur][o->sel];
                    for (i = 0; i < cnt; i++) {
                        if (r == e[i].id) {
                            idx = i;
                            break;
                        }
                    }
                    o->slot[o->cur][mode] = (o->slot[o->cur][2] << 4) | idx;
                    break;
                }
            } else {
                func_02206B58((char *)o);
            }
        }
    }
    if (r != -1)
        r = func_02206578((char *)o, r, c->vals[r]);
    return r;
}
