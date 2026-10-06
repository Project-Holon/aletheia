/*
 * function: func_021BF624
 * address: 0x021BF624
 * packet: pkt_ov204_021BF624
 * region: ov204
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Enum zero preserves the clear before the indexed base add.
 * symbols:
 *   defaultPos 0x021C08F0 data ov204
 *   func_021BF7F0 0x021BF7F0 thumb ov204
 *   func_02015CAC 0x02015CAC thumb
 */
#include "../include/Obj25390.h"

struct Vec { int v[3]; };
extern const struct Vec defaultPos;
typedef unsigned int   u32;
struct Obj;
struct Rec;
struct Sub150;
extern struct Rec *func_020159C8(struct Obj *obj, u32 a1, u32 a2, u32 a3, const struct Sub150 *src);
extern void func_02015CAC(void *p, u32 *src);
typedef unsigned char  u8;
extern void func_021BF7F0(u8 *p);
extern void func_02015F2C(void *, void *, void (*)(void *, void *), int);

void func_021BF624(char *p, unsigned int a, unsigned int b, unsigned int c, void *d, unsigned char i)
{
    struct Vec pos = defaultPos;
    char *base = p + 8;
    unsigned int off = i * 12;
    enum { Zero } zero;
    *(void **)(base + off) = func_020159C8(((struct Obj25390 *)p)->f4, a, b, c, d);
    func_02015CAC(*(void **)(base + off), (u32 *)(&pos));
    zero = Zero;
    *(unsigned int *)(p + off + 12) = zero;
    *(unsigned int *)(p + off + 16) = 1;
    func_02015F2C(*(void **)(base + off), base + off, (void (*)(void *, void *))func_021BF7F0, 0);
}
