/*
 * function: func_021C85CC
 * address:  0x021C85CC
 * packet:   pkt_ov021_021C85CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_020124E4  0x020124E4  thumb
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
extern void *func_020124E4(void *task);
extern void *func_0201210C(void *p);
extern void func_0204E720(u32 a, u32 b, u32 c, u32 d);
extern int func_0204E804(void);
int func_021C85CC(void *task, int *state)
{
    func_0201210C(func_020124E4(task));
    switch (*state) {
    case 0:
        func_0204E720(3, 0x10, 0, 0);
        (*state)++;
        break;
    case 1:
        if (func_0204E804() == 0)
            return 1;
        break;
    }
    return 0;
}
