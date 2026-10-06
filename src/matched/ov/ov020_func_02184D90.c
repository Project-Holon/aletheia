/*
 * function: func_02184D90
 * address:  0x02184D90
 * packet:   pkt_ov020_02184D90
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocator with callback (0x9c-byte work area), then the 0x18-byte record
 * at +0x10 initialised by func_020141A8 from three u16 fields of q.
 * What closed it: `const Q *q`. Without const the q field loads are kept
 * below the outgoing stack-argument stores and `adds r1,r7` is scheduled
 * first; const lets them hoist (docs/notes/pkt_ov020_02184D38.c.txt has
 * the earlier near miss). The u16 stack parameter s fixes the frame.
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020142A4  0x020142A4  thumb
 *   func_020141A8  0x020141A8  thumb
 *   func_02184CEC  0x02184CEC  thumb  ov020
 *   func_02184388  0x02184388  thumb  ov020
 */
#include "../include/Obj00248.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;

typedef struct { u16 f0; u16 f2; s16 f4; u16 f6; } Q;

struct Desc;
struct Obj;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
void func_02184CEC(void **o, void *p);
u32 func_020142A4(u32 idx);
int func_02184388(int a, int *state, u8 *p);
struct t;
void func_020141A8(struct t *p, int b, int d, u16 g, u16 i, s16 h);

void *func_02184D90(void *p, int unused, int a, const Q *q, u16 s, int t)
{
    void *r0v = func_020122C0(p, 0, func_02184388, 0x9c);
    char *r4 = func_020124E8(r0v);

    func_02184CEC((void **)r4, p);
    s = func_020142A4(s);
    func_020141A8((struct t *)(r4 + 0x10), a, (s16)s, q->f0, q->f6, q->f4);
    ((struct Obj00248 *)r4)->f2C = 0;
    ((struct Obj00248 *)r4)->f40 = t;
    return r0v;
}
