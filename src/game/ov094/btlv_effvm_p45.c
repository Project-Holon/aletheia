/*
 * file:     btlv_effvm_p45.c
 * unit:     yes
 * function: func_021FBFC0, func_021FC134
 * address:  0x021FBFC0
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
 *   func_02030734 0x02030734 arm
 *   func_0201134C 0x0201134C thumb
 *   func_02030DA8 0x02030DA8 arm
 *   func_021F896C 0x021F896C thumb ov094
 *   func_021FE8D8 0x021FE8D8 thumb ov094
 *   func_021FE6A4 0x021FE6A4 thumb ov094
 *   func_021FE750 0x021FE750 thumb ov094
 *   func_021FCA04 0x021FCA04 thumb ov094
 *   func_021FE4D0 0x021FE4D0 thumb ov094
 *   func_021F8694 0x021F8694 thumb ov094
 *   func_021FE410 0x021FE410 thumb ov094
 *   func_02200218 0x02200218 thumb ov094
 *   d_0220AE68 0x0220AE68 data ov094 a1
 */
#include "../../matched/include/Obj00177.h"
#include "../../matched/include/Obj13596.h"

struct Cursor;
typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { unsigned low : 10; unsigned bit10 : 1; unsigned high : 21; } Flags;

extern void *func_02030734(u32, u32, int, const char *, u16);
extern u32 func_0201134C(struct Cursor *p);
extern void *func_02030DA8(void *, void (*)(void *, void *), void *, int);
extern void func_021F896C(void *h, void (*cb)(void *), int arg);
extern void func_021FE8D8(void *, void *);
extern void func_021FE6A4(void *, void *);
extern void func_021FE750(void *);
extern int func_021FCA04(char *, int, int *);
extern int func_021FE4D0(char *);
extern int func_021F8694(void);
extern void func_021FE410(char *, int, int, int);
extern int func_02200218(char *, int, int, int, int, int, int);
int func_021FBFC0(void *a, char *s);
int func_021FC134(void *a, char *s);
extern char d_0220AE68[];

int func_021FBFC0(void *a, char *s)
{
    int buf[8];
    int n;
    int x;
    int y;
    int z;
    int q;
    int r;
    int duration;
    int i;
    int slot;
    int *p;
    n = func_021FCA04(s, func_0201134C(a), buf);
    x = func_0201134C(a);
    y = func_0201134C(a);
    z = func_0201134C(a);
    q = func_0201134C(a);
    r = func_0201134C(a);
    duration = func_0201134C(a);
    if (n != 0) {
        if (duration == 0) {
            for (i = 0; i < n; i++) {
                slot = func_021FE4D0(s);
                *(int *)(s + slot * 4 + 0x26c) = func_02200218((char *)func_021F8694(), buf[i], x, y, z, q, r);
            }
            func_021FE410(s, 0x7f000, 0x6b000, 10);
            if (!((Flags *)s)->bit10) {
                p = func_02030734((u16)((((struct Obj00177 *)s)->f238 & 0x7fff) | 0x8000), 4, 0, d_0220AE68, 0x10f9);
                p[0] = (int)s;
                func_021F896C(func_02030DA8(((struct Obj00177 *)s)->f8, func_021FE8D8, p, 0), 0, 0);
            }
        } else {
            for (i = 0; i < n; i++) {
                p = func_02030734((u16)((((struct Obj00177 *)s)->f238 & 0x7fff) | 0x8000), 0x20, 0, d_0220AE68, 0x1104);
                p[0] = (int)s;
                p[1] = buf[i];
                p[2] = x;
                p[3] = y;
                p[4] = z;
                p[5] = q;
                p[6] = r;
                p[7] = duration;
                ((struct Obj00177 *)s)->f0 |= 0x800;
                func_021F896C(func_02030DA8(((struct Obj00177 *)s)->f8, func_021FE6A4, p, 0), func_021FE750, 1);
            }
        }
    }
    return ((struct Obj00177 *)s)->f23C;
}


/*
 * Script command: stores one argument at 0x25c of the state.
 */
int func_021FC134(void *a, char *s)
{
    ((struct Obj13596 *)s)->f25C = func_0201134C(a);
    return ((struct Obj13596 *)s)->f23C;
}
