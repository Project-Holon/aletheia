/*
 * file:     unit_021E3B64_p03.c
 * unit:     yes
 * function: func_021E3FC0, func_021E4080
 * address:  0x021E3FC0
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
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   func_021D6314  0x021D6314  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021E8A78  0x021E8A78  thumb  ov093
 *   func_021E8A58  0x021E8A58  thumb  ov093
 *   func_021D7D18  0x021D7D18  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   d_021F27BC     0x021F27BC  data   a4
 *   data_021F27B4 0x021F27B4 data a4
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 */
#include "../../matched/include/Obj03704.h"
#include "../../matched/include/Obj02790.h"

typedef unsigned char u8;

typedef unsigned int u32;

typedef struct Word { unsigned int v; } Word;

extern int func_021D775C(int);
extern void *func_021C7CF4(int *p, int i);
extern Word func_021D62A8(void *q);
extern u32 func_021D6314(u8 *p, int i);
extern void *func_021C88A4(char *p, int a, int b);
extern int func_021E8A78(int s);
extern Word func_021E8A58(void);
extern int func_021D7D18(int k);
extern void func_021C88C8(void *a, void *p);
extern int func_021D76BC(int key, u32 val);
extern int func_021D59B4(u8 *p, int k);
extern void func_021C8838(void *, int, int);
void func_021E3FC0(int u, void *a, int c);
int *func_021E4074(int *p);
void func_021E4080(void *a, void *b, int c);
u32 *func_021E4148(u32 *p);
extern int d_021F27BC[];
extern u32 data_021F27B4[];


/*
 * Frame: 0x1c bytes of locals needs the two func_021D62A8 calls and
 * func_021E8A58 declared as returning a one-word struct (Word); see
 * docs/idioms/an-unused-frame-word-is-a-callee-returning-a-one-word-struct.md.
 * Word on func_021D6314 or func_021D7D18 as well gives a larger frame.
 */
void func_021E3FC0(int u, void *a, int c)
{
    void *q;
    int r;
    u8 k;
    int s;
    u8 *p;

    if (c == func_021D775C(3)) {
        q = func_021C7CF4(a, c);
        r = func_021D62A8(q).v;
        if (r != 0) {
            k = func_021D775C(6);
            if (func_021D62A8(func_021C7CF4(a, k)).v == 0) {
                s = func_021D6314(q, r);
                p = func_021C88A4(a, 0xc, c);
                ((struct Obj03704 *)p)->f4 = r;
                if (r == 5 && func_021E8A78(s) != 0)
                    *(Word *)(p + 8) = func_021E8A58();
                else
                    ((struct Obj03704 *)p)->f8 = func_021D7D18(r);
                p[0xf] = k;
                p[0xc] = 1;
                func_021C88C8(a, p);
                p = func_021C88A4(a, 0xb, c);
                ((struct Obj03704 *)p)->f4 = r;
                p[0x14] = 1;
                p[8] = c;
                ((struct Obj03704 *)p)->f0 |= 0x1000000;
                func_021C88C8(a, p);
                func_021D76BC(0x51, 0);
            }
        }
    }
}


int *func_021E4074(int *p)
{
    *p = 1;
    return d_021F27BC;
}

/*
 * follower: 021E4148 store-and-return stub included after two padding bytes.
 */
void func_021E4080(void *a, void *b, int c)
{
    u8 k;
    void *m;
    void *n;
    u32 x;
    u32 y;
    u32 avg;
    u8 *p;
    if (c != func_021D775C(3)) return;
    k = func_021D775C(6);
    m = func_021C7CF4(b, c);
    n = func_021C7CF4(b, k);
    x = func_021D59B4(m, 13);
    y = func_021D59B4(n, 13);
    avg = (x + y) / 2;
    p = func_021C88A4(b, 8, c);
    p[4] = 2;
    p[7] = c;
    ((struct Obj02790 *)p)->f10 = avg - x;
    p[8] = k;
    ((struct Obj02790 *)p)->f14 = avg - y;
    p[6] = 1;
    func_021C88C8(b, p);
    p = func_021C88A4(b, 4, c);
    func_021C8838(p + 4, 1, 113);
    func_021C88C8(b, p);
    p = func_021C88A4(b, 33, c);
    p[4] = c;
    ((struct Obj02790 *)p)->f8 = 1;
    func_021C88C8(b, p);
    p = func_021C88A4(b, 33, c);
    p[4] = k;
    ((struct Obj02790 *)p)->f8 = 1;
    func_021C88C8(b, p);
}

u32 *func_021E4148(u32 *p)
{
    *p = 1;
    return data_021F27B4;
}
