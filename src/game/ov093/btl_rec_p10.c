/*
 * file:     btl_rec_p10.c
 * unit:     yes
 * function: func_021EED90, func_021EEE24
 * address:  0x021EED90
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
 *   func_021B9F70  0x021B9F70  thumb  ov093
 *   func_021B86B8  0x021B86B8  thumb  ov093
 *   func_021BA004  0x021BA004  thumb  ov093
 *   func_021B9FAC  0x021B9FAC  thumb  ov093
 *   func_021BA064  0x021BA064  thumb  ov093
 *   func_021BA080  0x021BA080  thumb  ov093
 *   func_0202A3CC  0x0202A3CC  thumb
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F134  0x0201F134  thumb
 *   d_021F6398     0x021F6398  data  ov093  a4
 *   func_021EEE80  0x021EEE80  thumb  ov093
 *   d_021F63C8     0x021F63C8  data  a4
 */
#include "../../matched/include/G_ov093_021F6398.h"

#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))
#define va_arg(ap, t) (*(t *)((ap += 4) - 4))
struct WordSet;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

typedef char *va_list;

extern int func_021B9F70(u8 *p, int i);
extern void *func_021B86B8(void ***p);
extern u16 func_021BA004(char *p, int i);
extern u32 func_021B9FAC(u8 *p, int i, u32 *out);
extern int func_021BA064(char *p, int i);
extern int func_021BA080(void *battle);
extern u8 func_0202A3CC(u32 cls);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F134(struct WordSet *p, u32 i, u32 v);
extern void func_021EEE80(u32 a, u16 k, u32 *p);
void func_021EED90(void *win, u8 slot, u8 k);
void func_021EEE24(u32 a, u16 k, u32 n, ...);
extern struct G_ov093_021F6398 d_021F6398;
extern s32 d_021F63C8[];


void func_021EED90(void *win, u8 slot, u8 k)
{
    u32 t;
    int v;

    if (k != 4) {
        if (func_021B9F70((*(void * *)&d_021F6398), k) != 0) {
            if ((int)func_021B86B8((*(void * *)&d_021F6398)) == 1) {
                v = func_021BA004((*(void * *)&d_021F6398), k);
                if (v != 0)
                    func_0201F134(win, slot, v);
            } else {
                v = func_021B9FAC((*(void * *)&d_021F6398), k, &t);
                func_0201EE0C(win, slot, (void *)v, func_0202A3CC(t), 1, 2);
            }
        } else {
            func_0201F02C(win, slot, (void *)func_021BA064((*(void * *)&d_021F6398), k));
        }
    } else {
        func_0201F02C(win, slot, (void *)func_021BA080((*(void * *)&d_021F6398)));
    }
}


/*
 * Variadic: copies n words into an eight-word table at d_021F6398 + 0x30
 * (zero-filling the rest), then hands the table (named separately at its
 * own address d_021F63C8) to func_021EEE80.
 */
void func_021EEE24(u32 a, u16 k, u32 n, ...)
{
    va_list ap;
    u32 i;

    va_start(ap, n);
    for (i = 0; i < n; i++) {
        d_021F6398.a[i] = va_arg(ap, s32);
    }
    for (; i < 8; i++) {
        d_021F6398.a[i] = 0;
    }
    func_021EEE80(a, k, (u32 *)d_021F63C8);
}
