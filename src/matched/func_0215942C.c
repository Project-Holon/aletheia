/*
 * function: func_0215942C
 * address:  0x0215942C
 * packet:   pkt_0215942C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * One arm9 getter read twice, folded with '+', written back
 * through the arm9 setter.
 *
 * symbols:
 *   func_02011398   0x02011398  thumb
 *   func_0201137C   0x0201137C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02011398(void *);
extern void func_0201137C(void *, int);

int func_0215942C(void *a0)
{
    int v = func_02011398(a0);
    int w = func_02011398(a0);

    func_0201137C(a0, w + v);

    return 0;
}
