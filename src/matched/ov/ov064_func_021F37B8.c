/*
 * function: func_021F37B8
 * address:  0x021F37B8
 * packet:   pkt_ov064_021F37B8
 * region:   ov064
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_021F384C  0x021F384C  thumb  ov064
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct {
    int a;
    int b;
    int c;
} V3;

struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern int func_02188D2C(int *p);
struct Obj00020;
extern void *func_02188CB4(struct Obj00020 *p);
struct VecFx32;
extern void func_021A3038(unsigned char *a, struct VecFx32 *v);
typedef unsigned int   u32;
struct Desc;
extern int func_021BE480(char *p, unsigned i, int j);
extern void func_021BE4B4(char *p, int i, int j, int v);
extern void *func_021BE674(char *base, int i, unsigned int j, int k);
extern void func_021BE6B0(u8 *p, int v);
extern void func_021BE700(int a, int b, int c, u16 d, int e);
extern void func_021BE6CC(int a, int b, int c, u16 d, int e);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int func_021F384C(void *task, int *st);

void *func_021F37B8(int a)
{
    int i;
    void *sys;
    int s;
    V3 v;

    sys = func_0201210C((void *)a);
    s = func_02188D2C(sys);
    func_021A3038(func_02188CB4((void *)sys), (struct VecFx32 *)&v);
    *(V3 *)func_021BE480((char *)s, 0, 0) = v;
    func_021BE4B4((char *)s, 0, 0, 0);
    for (i = 0; i < 4; i++) {
        func_021BE6B0(func_021BE674((char *)s, 0, (int)0, (u16)i), 0);
        func_021BE700(s, 0, 0, i, 1);
        func_021BE6CC(s, 0, 0, i, 0);
    }
    return func_020122C0((void *)a, 0, (void *)func_021F384C, 0);
}
