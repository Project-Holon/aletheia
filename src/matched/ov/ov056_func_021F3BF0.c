/*
 * function: func_021F3BF0
 * address:  0x021F3BF0
 * packet:   pkt_ov056_021F3BF0
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_0204784C  0x0204784C  arm
 *   func_020477A4  0x020477A4  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct G3dOwner;
struct G3dRec;
extern void *func_02047400(void *a0, u32 n, void *a2);
extern struct G3dRec *func_02047564(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *func_0204767C(u32 a0, u32 *a1, int a2);
typedef signed int     s32;
struct AnmCtl;
extern u32 func_0204784C(struct AnmCtl *c, u32 idx, s32 *frame);
extern void func_020477A4(u32 h, u16 i);

void func_021F3BF0(u32 *p)
{
    int i;
    int v;

    i = 0;
    p[4] = (u32)func_02047400((void *)p[0], 0, (void *)p[0]);
    p[5] = (u32)func_02047564((struct G3dOwner *)p[4], (const struct G3dOwner *)p[1], 0);
    p[6] = (u32)func_02047564((struct G3dOwner *)p[4], (const struct G3dOwner *)p[2], 0);
    p[7] = (u32)func_0204767C(p[4], &p[5], 2);
    v = 0;
    for (; i < 2; i++) {
        func_0204784C((struct AnmCtl *)p[7], (u16)i, &v);
        func_020477A4(p[7], i);
    }
}
