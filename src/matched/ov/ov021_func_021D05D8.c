/*
 * function: func_021D05D8
 * address:  0x021D05D8
 * packet:   pkt_ov021_021D05D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DB968     0x021DB968  data  ov021  a4
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Arg021D05D8 {
    u32 h;
    void *a;
} Arg021D05D8;

typedef struct Vec021D05D8 {
    int x, y, z;
} Vec021D05D8;

extern u32 func_021ABEA0(void *a, u32 b);
struct Actor;
struct VecFx32;
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern void func_021ABFA8(void *a, void *b, void *c, u32 d, void *e, u32 f);
extern char d_021DB968[];

void func_021D05D8(void *a, void *b)
{
    Arg021D05D8 arg;
    Vec021D05D8 v;

    arg.h = func_021ABEA0(b, 0x10);
    arg.a = a;
    func_0216D88C(a, (struct VecFx32 *)&v);
    func_021ABFA8(b, d_021DB968, &v, 0, &arg, 0);
}
