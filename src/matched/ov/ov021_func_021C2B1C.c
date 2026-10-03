/*
 * function: func_021C2B1C
 * address:  0x021C2B1C
 * packet:   pkt_ov021_021C2B1C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 */

void *func_020124E4(int a);
typedef signed int     s32;
typedef unsigned int   u32;
struct Ctx;
void *func_0201210C(const struct Ctx *p);
void func_0204E720(u32 a, s32 b, s32 c, s32 d);
int func_0204E804(void);

int func_021C2B1C(int a, int *b)
{
    func_0201210C(func_020124E4(a));
    switch (*b) {
    case 0:
        func_0204E720(4, 0, 0x10, -1);
        (*b)++;
        break;
    case 1:
        if (func_0204E804() == 0)
            return 1;
        break;
    }
    return 0;
}
