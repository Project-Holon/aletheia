/*
 * function: func_0215946C
 * address:  0x0215946C
 * packet:   pkt_0215946C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * One arm9 getter read twice, folded with '*', written back
 * through the arm9 setter.
 *
 * symbols:
 *   func_02011398   0x02011398  thumb
 *   func_0201137C   0x0201137C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ring;
extern u32 func_02011398(struct Ring *r);
extern void func_0201137C(struct Ring *r, u32 v);

int func_0215946C(void *a0)
{
    int v = func_02011398(a0);
    int w = func_02011398(a0);

    func_0201137C(a0, w * v);

    return 0;
}
