/*
 * file:     pdw_postman_p02.c
 * unit:     yes
 * function: func_021B7574, func_021B7640
 * address:  0x021B7574
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B7400  0x021B7400  thumb  ov021
 *   func_021B74CC  0x021B74CC  thumb  ov021
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02192788  0x02192788  thumb  ov021
 *   func_0219077C  0x0219077C  thumb  ov021
 *   func_021907C0  0x021907C0  thumb  ov021
 *   func_02045770  0x02045770  arm
 *   func_021928C0  0x021928C0  thumb  ov021
 *   func_02045334  0x02045334  arm
 *   func_020362DC  0x020362DC  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_021927B0  0x021927B0  thumb  ov021
 *   func_021B7494  0x021B7494  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_0201292C  0x0201292C  thumb
 *   func_02030734  0x02030734  arm
 *   func_02009310  0x02009310  thumb
 *   func_02009330  0x02009330  thumb
 *   func_02007E3C  0x02007E3C  thumb
 *   d_021DE288     0x021DE288  data   ov021  a1
 */
struct Cur;
struct Fx;
struct G;
struct Descriptor;
struct BigObj;
struct Sub02009210Obj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct Obj {
    u16 f0;
    u16 pad2;
    u32 f4;
    u32 f8;
    u32 fC;
    u32 f10;
} Obj;

typedef struct Work {
    u32 f0;
    Obj *f4;
    u32 *f8;
    u32 fC;
    u16 f10;
} Work;

typedef struct Pair {
    u16 a;
    u16 b;
} Pair;

extern struct Obj *func_021B7400(u32 a, u32 b, int c);
extern void func_021B74CC(Obj *o);
extern u32 func_02188C54(u8 *p);
extern struct G *func_02192788(struct Fx *a);
extern int func_0219077C(u8 *p);
extern u32 func_021907C0(u8 *p);
extern void *func_02045770(struct Descriptor *p);
extern void func_021928C0(struct Cur *c, u32 win, u32 col);
extern void func_02045334(struct Descriptor *d);
extern u32 func_020362DC(void);
extern void func_020061E4(u32 a);
extern void func_021927B0(u8 *p);
extern int func_021B7494(void *a);
extern u32 func_020307B0(void *p);
extern void *func_0201292C(const struct BigObj *p);
extern void *func_02030734(u32 heap, u32 size, int a, const char *file, u16 line);
extern u16 func_02009310(const struct Sub02009210Obj *obj, int i);
extern u8 func_02009330(const struct Sub02009210Obj *obj, int i);
extern int func_02007E3C(void *a, u32 b, u32 c, u32 d);
int func_021B7574(void *task, int *st, Work *w);
Pair *func_021B7640(u32 a, u32 b, u32 c, int *d);
extern u8 d_021DE288[];


/*
 * Addresses are Black-image addresses.
 */
int func_021B7574(void *task, int *st, Work *w)
{
    u16 n;
    u32 h;
    u16 t;

    switch (*st) {
    case 0:
        n = w->fC - w->f10;
        if (n > 7) {
            n = 7;
        }
        w->f4 = func_021B7400(w->f0, (u32)(w->f8 + w->f10), n);
        func_021B74CC(w->f4);
        w->f4->f10 = (u32)func_02192788((struct Fx *)func_02188C54((u8 *)w->f0));
        (*st)++;
        break;
    case 1:
        if (func_0219077C((u8 *)w->f4->fC) == 1) {
            (*st)++;
        }
        break;
    case 2:
        h = func_021907C0((u8 *)w->f4->fC);
        func_021928C0((struct Cur *)w->f4->f10, (u32)func_02045770((struct Descriptor *)h), 15);
        func_02045334((struct Descriptor *)h);
        if (func_020362DC() & 1) {
            func_020061E4(0x547);
            (*st)++;
        }
        break;
    case 3:
        func_021927B0((u8 *)w->f4->f10);
        func_021B7494((void *)w->f4);
        (*st)++;
        break;
    case 4:
        if (w->f10 + 7 >= w->fC) {
            func_020307B0(w->f8);
            return 1;
        }
        w->f10 += 7;
        *st = 0;
        break;
    }
    return 0;
}


Pair *func_021B7640(u32 a, u32 b, u32 c, int *d)
{
    Pair *buf;
    void *h;
    int n;
    int i;
    u16 x;
    u16 y;

    h = func_0201292C((const struct BigObj *)a);
    buf = func_02030734(b, 0x50, 1, (const char *)d_021DE288, 0x14d);
    i = 0;
    n = 0;
    for (; i < 0x14; i++) {
        x = func_02009310((const struct Sub02009210Obj *)c, i);
        y = func_02009330((const struct Sub02009210Obj *)c, i);
        if (x != 0 && func_02007E3C(h, x, y, b) == 1) {
            buf[n].a = x;
            buf[n].b = y;
            n++;
        }
    }
    *d = n;
    return buf;
}
