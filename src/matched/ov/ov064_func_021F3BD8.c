/*
 * function: func_021F3BD8
 * address:  0x021F3BD8
 * packet:   pkt_ov064_021F3BD8
 * region:   ov064
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6BC  0x021BE6BC  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;

struct Ctx;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern int func_02188D2C(int *p);
extern void *func_021BE674(char *base, int i, unsigned int j, int k);
extern int func_021BE6BC(int *p);

int func_021F3BD8(void *task)
{
    int s;

    s = func_02188D2C(func_0201210C(func_020124E4(task)));
    if (func_021BE6BC(func_021BE674((char *)s, 0, 1, 0)) != 0) {
        return 1;
    }
    return 0;
}
