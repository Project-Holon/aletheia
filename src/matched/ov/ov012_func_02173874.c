/*
 * function: func_02173874
 * address:  0x02173874
 * packet:   pkt_ov012_02173874
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * func_021A2E44(q, v) takes a second argument (it stores r1 at +0xc); its 1
 * is CSE'd with the stored 1, which is what puts that constant in r1 and
 * fixes the prologue schedule. Bitfield at +0xc8 needs lsls/lsrs #0x1f.
 *
 * symbols:
 *   func_021A2E44  0x021A2E44  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02013CC8  0x02013CC8  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0217B440  0x0217B440  thumb  ov019
 *   func_021676E4  0x021676E4  thumb  ov010
 */
#include "../include/Obj07338.h"
#include "../include/Obj19237.h"
#include "../include/Obj19238.h"

typedef unsigned char u8;

typedef struct { u8 pad[0xc8]; u8 f : 1; } S;

extern void func_021A2E44(void *q, int v);
typedef unsigned short u16;
typedef unsigned int   u32;
struct Work;
extern u16 func_02188C9C(u8 *p);
extern u32 func_02013CC8(u32 id);
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern void func_0217B440(void *p, int r, void *q);
extern void func_021676E4(struct Work *w);

void func_02173874(int a, u8 *p, void *q)
{
    S *r4;

    r4 = *(S * *)&((struct Obj07338 *)p)->f355C;
    p[0x282A] = 1;
    if (p[0x3563] == 1) {
        func_021A2E44(q, 1);
    }
    if (func_02013CC8(func_02188C9C(q)) == 1) {
        func_0217B440(p, (int)func_020120F4((const struct Ctx *)(((struct Obj19238 *)(*(u8 * *)&((struct Obj07338 *)p)->f0))->fC)), q);
    }
    if (r4 != 0 && r4->f == 1) {
        func_021676E4(((struct Obj19237 *)r4)->f0);
    }
}
