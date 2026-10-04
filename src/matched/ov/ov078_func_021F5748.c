/*
 * function: func_021F5748
 * address:  0x021F5748
 * packet:   pkt_ov078_021F5748
 * region:   ov078
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02189A08  0x02189A08  thumb  ov021
 *   func_021CF560  0x021CF560  thumb  ov021
 *   func_021F5950  0x021F5950  thumb  ov078
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;

typedef signed int     s32;
struct Ctx;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern int func_02189A08(unsigned char *p);
extern u32 func_021CF560(u32 *p);
extern int func_021F5950(u8 *p);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);

int func_021F5748(void *task, int *st)
{
    u8 *w;

    w = (u8 *)func_021CF560((u32 *)func_02189A08((unsigned char *)((int)func_0201210C(func_020124E4(task)))));
    switch (*st) {
    case 0:
        if (*(int *)(w + 0x19D8) != 0) {
            (*(int *)(w + 0x19D8))--;
        } else if (*(int *)(w + 0x19DC) == 0) {
            func_0204E720(*(int *)(w + 0x19D4), 0, 0x10, 0);
            *(int *)(w + 0x19DC) = 1;
        }
        if (func_021F5950(w) != 0) {
            *(s16 *)(w + 0x19C8) = 6;
            (*st)++;
        }
        break;
    case 1:
        if (*(s16 *)(w + 0x19C8) != 0) {
            (*(s16 *)(w + 0x19C8))--;
        } else if (func_0204E804() == 0) {
            return 1;
        }
        break;
    }
    return 0;
}
