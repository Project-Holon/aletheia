/*
 * file:     field_wfbc_p02.c
 * unit:     yes
 * function: func_02193920, func_02193924, func_021939C0, func_02193ABC, func_02193AFC
 * address:  0x02193920
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
 *   func_02194038  0x02194038  thumb  ov021
 *   func_021C939C  0x021C939C  thumb  ov021
 *   func_021C93E4  0x021C93E4  thumb  ov021
 *   func_021C9450  0x021C9450  thumb  ov021
 *   func_021C93D0  0x021C93D0  thumb  ov021
 *   func_020493D4  0x020493D4  arm
 *   func_02049250  0x02049250  arm
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02194044  0x02194044  thumb  ov021
 *   func_0216245C  0x0216245C  thumb  ov010
 *   d_021D3F60     0x021D3F60  data  a4
 *   d_021DDA60     0x021DDA60  data  a4
 *   func_0204A380  0x0204A380  arm
 *   func_021938F4  0x021938F4  thumb  ov021
 *   func_0218E17C  0x0218E17C  thumb  ov021
 */
#include "../../matched/include/Obj17939.h"
#include "../../matched/include/Obj07440.h"
#include "../../matched/include/Obj19614.h"
#include "../../matched/include/Obj17940.h"

struct ArcFile;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { u8 lo:4; u8 hi:4; u8 b; u16 c; } Cell;

typedef struct { u16 a; u16 b; u32 c; } Ent;

extern Cell func_02194038(void *a, int b, int c);
extern u32 *func_021C939C(u32 a, u32 heap);
extern void func_021C93E4(u32 a, u8 *q, u32 x, u32 y, u32 z, u32 w, u32 n, u32 cnt);
extern u32 func_021C9450(u32 a, u32 b, u32 c, u32 d, int e, int f);
extern void func_021C93D0(void **q);
extern u32 func_020493D4(struct ArcFile *arc, u32 member);
extern Ent *func_02049250(int h, int a, u16 heap);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern int func_02194044(u8 *p, u16 a, u16 b);
extern void func_0216245C(u8 *o, u16 idx);
extern void *func_0204A380(void *a0, u32 a1, u32 a2, u32 a3);
extern int func_021938F4(unsigned char *p);
extern void func_0218E17C(u32 *p, u32 v);
u8 func_02193920(u8 *p);
int func_02193924(u8 *a, void *q, int c, int d, int e, int f, int g, u16 h);
void func_021939C0(u8 *o, void *dst, int skip, u32 heap);
void func_02193ABC(char *p, int a, int b);
void func_02193AFC(u8 *p, u32 v);
extern int d_021D3F60[];
extern int d_021DDA60;


/*
 * Loads the byte at +0x1 of the object.
 */
u8 func_02193920(u8 *p)
{
    return ((struct Obj17939 *)p)->f1;
}


/*
 * The cell comes back from func_02194038 as a 4-byte struct in r0; the high
 * nibble is read before the low one.
 * Addresses are Black-image addresses.
 */
int func_02193924(u8 *a, void *q, int c, int d, int e, int f, int g, u16 h)
{
    Cell cell = func_02194038(a + 0x18, f, g);
    u32 *t;
    int x, y;
    int lo, hi;

    if (cell.b != 0xFF) {
        x = (f * 8) & 0x1F;
        y = (g * 8) & 0x1F;
        t = func_021C939C(cell.c, (u16)((h & 0x7FFF) | 0x8000));
        hi = cell.hi;
        lo = cell.lo;
        func_021C93E4((u32)t, q, lo * 8, hi * 8, x, y, 8, 8);
        if (lo == 0 && hi == 0) {
            e = func_021C9450((u32)t, c, d, e, x, y);
        }
        func_021C93D0((void **)t);
    }
    return e;
}


/*
 * Addresses are Black-image addresses.
 */
void func_021939C0(u8 *o, void *dst, int skip, u32 heap)
{
    u32 n;
    Ent *e;
    u32 *seen;
    u32 cnt;
    u32 i;
    u32 j;
    Ent *cur;

    if (skip != 0)
        return;
    n = func_020493D4((struct ArcFile *)(((struct Obj07440 *)o)->f10), d_021D3F60[*o]);
    heap = (heap & 0x7FFF) | 0x8000;
    e = func_02049250(((struct Obj07440 *)o)->f10, d_021D3F60[*o], (u16)heap);
    n >>= 3;
    seen = func_02030734((u16)heap, n * 4, 1, (const char *)&d_021DDA60, 0x208);
    cnt = 0;
    for (i = 0; i < n; i++) {
        cur = &e[i];
        if (func_02194044(o + 0x18, e[i].a, cur->b)) {
            seen[cnt] = cur->c;
            cnt++;
        } else {
            for (j = 0; j < cnt; j++) {
                if (seen[j] == e[i].c)
                    break;
            }
            if (j >= cnt) {
                for (j = i + 1; j < n; j++) {
                    if (cur->c == e[j].c)
                        break;
                }
                if (j >= n)
                    func_0216245C(dst, (u16)cur->c);
            }
        }
    }
    func_020307B0(seen);
    func_020307B0(e);
}


void func_02193ABC(char *p, int a, int b)
{
    u16 *h;

    h = func_0204A380((void *)(((struct Obj19614 *)p)->f10), 0x24, 0, (u16)((b & 0x7fff) | 0x8000));
    func_0218E17C((u32 *)a, h[func_021938F4((unsigned char *)p)]);
    func_020307B0(h);
}


/*
 * Stores the 32-bit word into byte +0x140 of the object.
 */
void func_02193AFC(u8 *p, u32 v)
{
    ((struct Obj17940 *)p)->f140 = v;
}
