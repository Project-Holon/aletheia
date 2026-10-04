/*
 * function: func_021A926C
 * address:  0x021A926C
 * packet:   pkt_ov021_021A926C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020452E8  0x020452E8  arm
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204A8D4  0x0204A8D4  arm
 */

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
} S;

struct Descriptor;
struct Obj;
extern void func_020452E8(struct Descriptor *d);
extern void func_0204B3B4(struct Obj *p);
typedef unsigned int   u32;
extern void func_0204AFD8(u32 i);
extern void func_0204A8D4(u32 i);

void func_021A926C(int a, S *s)
{
    if (s->f0 == 1) {
        func_020452E8((struct Descriptor *)s->f4);
        if (s->f18 != 0) {
            func_0204B3B4((struct Obj *)s->f18);
            func_0204AFD8(s->f10);
            func_0204A8D4(s->fc);
        }
    }
}
