/*
 * function: func_021F5488
 * address:  0x021F5488
 * packet:   pkt_ov073_021F5488
 * region:   ov073
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 */
typedef unsigned int u32;

typedef signed int     s32;
struct Ctx;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);

int func_021F5488(void *task, int *st)
{
    func_0201210C(func_020124E4(task));
    switch (*st) {
    case 0:
        func_0204E720(3, 0, 0x10, 3);
        *st = *st + 1;
        break;
    case 1:
        if (func_0204E804() == 0) {
            return 1;
        }
        break;
    }
    return 0;
}
