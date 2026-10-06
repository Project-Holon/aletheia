/*
 * function: func_0218932C
 * address:  0x0218932C
 * packet:   pkt_ov021_0218932C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AA0  0x02012AA0  thumb
 *   func_020141E0  0x020141E0  thumb
 *   func_020141F0  0x020141F0  thumb
 */
#include "../include/Obj19496.h"

typedef struct Vec { int x, y, z; } Vec;

struct Ctx;
struct SaveBlock;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_020127A4(struct SaveBlock *p);
struct Rec020141E0;
struct Rec020141F0;
struct Rec44;
struct Vec020141E0;
struct Vec020141F0;
struct Vec12;
extern struct Vec12 *func_02012AA0(struct Rec44 *p);
extern void func_020141E0(const struct Rec020141E0 *p, struct Vec020141E0 *out);
extern void func_020141F0(struct Rec020141F0 *p, const struct Vec020141F0 *v);

int func_0218932C(char *p)
{
    Vec v;
    char *q;
    Vec *pos;

    q = p + 0xd4;
    pos = (Vec *)func_02012AA0(func_020127A4(func_020120F4(((struct Obj19496 *)p)->f4)));
    func_020141E0((const struct Rec020141E0 *)q, (struct Vec020141E0 *)(&v));
    if (pos->x != v.x || pos->z != v.z) {
        func_020141F0((struct Rec020141F0 *)q, (const struct Vec020141F0 *)pos);
        return 1;
    }
    return 0;
}
