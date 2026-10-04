/*
 * function: func_021B7574
 * address:  0x021B7574
 * packet:   pkt_ov021_021B7574
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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
 * Addresses are Black-image addresses.
 */

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

extern Obj *func_021B7400(u32 a, u32 *b, int c);
extern void func_021B74CC(Obj *o);
extern u32 func_02188C54(u32 a);
extern u32 func_02192788(u32 a);
extern int func_0219077C(u32 a);
extern u32 func_021907C0(u32 a);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_021928C0(u32 a, u32 b, u32 c);
extern void func_02045334(u32 a);
extern u32 func_020362DC(void);
extern void func_020061E4(u32 a);
extern void func_021927B0(u32 a);
extern void func_021B7494(Obj *o);
extern void func_020307B0(void *p);

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
        w->f4 = func_021B7400(w->f0, w->f8 + w->f10, n);
        func_021B74CC(w->f4);
        w->f4->f10 = func_02192788(func_02188C54(w->f0));
        (*st)++;
        break;
    case 1:
        if (func_0219077C(w->f4->fC) == 1) {
            (*st)++;
        }
        break;
    case 2:
        h = func_021907C0(w->f4->fC);
        func_021928C0(w->f4->f10, (u32)func_02045770((struct Descriptor *)h), 15);
        func_02045334(h);
        if (func_020362DC() & 1) {
            func_020061E4(0x547);
            (*st)++;
        }
        break;
    case 3:
        func_021927B0(w->f4->f10);
        func_021B7494(w->f4);
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
