/*
 * function: func_021F5338
 * address:  0x021F5338
 * packet:   pkt_ov082_021F5338
 * region:   ov082
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02189A60  0x02189A60  thumb  ov021
 *   func_021F53B4  0x021F53B4  thumb  ov082
 *   func_021F5708  0x021F5708  thumb  ov082
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef short s16;

typedef signed int     s32;
typedef unsigned int   u32;
struct Ctx;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern u8 *func_02189A60(u8 *p);
extern void func_021F53B4(u8 *w, int p);
extern int func_021F5708(u8 *w);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);

int func_021F5338(void *task, int *st)
{
    void *p;
    u8 *w;

    p = func_0201210C(func_020124E4(task));
    w = *(u8 **)func_02189A60(p);
    switch (*st) {
    case 0:
        func_0204E720(1, 0, 0x10, 0);
        (*st)++;
        break;
    case 1:
        if (func_0204E804() == 0) {
            func_021F53B4(w, (int)p);
            func_0204E720(1, 0x10, 0, 0);
            (*st)++;
        }
        break;
    case 2:
        if (func_0204E804() == 0) {
            *(s16 *)(w + 0x24) = 0;
            (*st)++;
        }
        break;
    case 3:
        if (func_021F5708(w) != 0)
            return 1;
        break;
    }
    return 0;
}
