/*
 * file:     unit_021F5620_p01.c
 * unit:     yes
 * function: func_021F5620, func_021F565C, func_021F5698
 * address:  0x021F5620
 * region:   ov078
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F5BC8 0x021F5BC8 data a4
 *   func_02189A08 0x02189A08 thumb ov021
 *   func_021CF59C 0x021CF59C thumb ov021
 *   func_021F5260 0x021F5260 thumb ov075
 *   func_021F5800 0x021F5800 thumb ov078
 *   d_021F5BBC 0x021F5BBC data a4
 *   func_021F529C 0x021F529C thumb ov075
 *   func_021F5AFC 0x021F5AFC thumb ov078
 *   func_0201210C  0x0201210C  thumb
 *   func_021CF52C  0x021CF52C  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_021F5748  0x021F5748  thumb  ov078
 */
#include "../../matched/include/Obj03670.h"

struct Res021CF;
struct Vec;
struct Ctx;
struct Desc;
typedef struct { int x,y,z; } Vec;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef short s16;

extern int func_02189A08(unsigned char *p);
extern void func_021CF59C(struct Res021CF *r);
extern void *func_021F5260(void *a, struct Vec *src, u32 b, u32 c);
extern void func_021F5800(void);
extern void *func_021F529C(void *a, struct Vec *src, u32 b, u32 c);
extern void *func_021F5AFC(void *a);
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_021CF52C(u32 *p, int size, int heap);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int func_021F5748(void *task, int *st);
void *func_021F5620(void *p, int b);
void *func_021F565C(void *p, int b);
void *func_021F5698(void *a);
extern const Vec d_021F5BC8;
extern const Vec d_021F5BBC;

void *func_021F5620(void *p, int b) {
    Vec v = d_021F5BC8;
    func_021CF59C((void *)func_02189A08((unsigned char *)b));
    return func_021F5260(p, (struct Vec *)(&v), (u32)func_021F5698, (u32)func_021F5800);
}

/*
 * note (2026-10-05, wD4 lane17): still MATCH, only the ov021 callee 021CF59C (12-byte thunk, no label) is unresolved. Nothing to change in the source.
 * note (2026-10-04, wD2 lane07): re-verified MATCH: the only wildcard is the ov021 callee 021CF59C (no label witness). It is a 12-byte ARM-style thunk inside the ov021_func_021CF580 extent (ldr r1,[pc]; ldr r3,[pc]; bx r3 with r1 = 0x4B, target func_021CF564): veneer-like, not C. Needs a label in layout.
 */
void *func_021F565C(void *p, int b) {
    Vec v = d_021F5BBC;
    func_021CF59C((void *)func_02189A08((unsigned char *)b));
    return func_021F529C(p, (struct Vec *)(&v), (u32)func_021F5AFC, (u32)func_021F5800);
}


/*
 * Addresses are Black-image addresses.
 */
void *func_021F5698(void *a)
{
    u8 *w;
    void *h;
    int i;

    w = (u8 *)func_021CF52C((u32 *)func_02189A08((unsigned char *)((int)func_0201210C(a))), 0x19E0, 0x50);
    h = func_020122C0(a, 0, (void (*)(void))func_021F5748, 0);
    ((struct Obj03670 *)w)->f19CA = 7;
    ((struct Obj03670 *)w)->f19C8 = 0;
    ((struct Obj03670 *)w)->f19CC = 8;
    ((struct Obj03670 *)w)->f19D0 = 0x400;
    ((struct Obj03670 *)w)->f19CE = 0;
    ((struct Obj03670 *)w)->f19D8 = 0x32;
    ((struct Obj03670 *)w)->f19DC = 0;
    for (i = 0; i < 0x339; i++) {
        s16 *e = (s16 *)(w + i * 6);

        e[0] = ((i % 33) << 12) / 16;
        e[1] = ((i / 33) << 12) / 16;
        e[2] = 0;
    }
    ((struct Obj03670 *)w)->f19D4 = 0xc;
    return h;
}
