/*
 * function: func_021EE364
 * address:  0x021EE364
 * packet:   pkt_ov170_021EE364
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020260F0 0x020260F0 thumb
 *   func_021EE3CC 0x021EE3CC thumb
 *   func_02025CD0 0x02025CD0 thumb
 *   func_02025D1C 0x02025D1C thumb
 *   func_021EE408 0x021EE408 thumb
 *   func_021ED55C 0x021ED55C thumb
 *   d_021F02F0 0x021F02F0 data
 */

typedef struct { unsigned a; unsigned b; } Pair;
typedef unsigned int   u32;
struct Sound;
struct Struct_02025D1C;
extern u32 func_020260F0(struct Sound *obj);
extern void func_021EE3CC(char **p);
extern void *func_02025CD0(unsigned a0, unsigned a1, void *a2, int a3, unsigned char a4, unsigned short heapId);
extern void func_02025D1C(struct Struct_02025D1C *obj);
extern void func_021EE408(char **p, int v);
extern void func_021ED55C(char **p, int flag);
extern const Pair d_021F02F0[];

void func_021EE364(char **p, int idx, int v)
{
    int r = func_020260F0(*(void **)(p[11] + 0x70));
    func_021EE3CC(p);
    *(void **)(p[11] + 0x70) = func_02025CD0(d_021F02F0[idx].a, d_021F02F0[idx].b, p, r, v, 0x4C);
    func_02025D1C(*(void **)(p[11] + 0x70));
    func_021EE408(p, v);
    func_021ED55C(p, r);
    *(int *)(p[11] + 0xA168) = v;
}
