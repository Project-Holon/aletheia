/*
 * function: ov208_func_021BDC48
 * address:  0x021BDC48
 * packet:   pkt_ov208_021BDC48
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BD35C  0x021BD35C  thumb
 *   func_021BD358  0x021BD358  thumb
 */

typedef unsigned int u32;

struct Ov208Scene {
    u32 pad0[2];
    u32 f8;
    u32 pad0c[9];
    void *mgr;
    u32 f34;
};

extern int func_021BD35C(char *p);
extern void func_021BD358(char *p, int v);

void ov208_func_021BDC48(struct Ov208Scene *p, u32 on)
{
    p->f34 = on;
    if (on != 0) {
        if (func_021BD35C(p->mgr) == 0 && p->f8 == 2)
            func_021BD358(p->mgr, 1);
    } else {
        if (func_021BD35C(p->mgr) != 0)
            func_021BD358(p->mgr, 0);
    }
}
