/*
 * function: func_021CF844
 * address:  0x021CF844
 * packet:   pkt_ov021_021CF844
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Task body started by func_021CF7DC: a three-state counter walk.
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   func_021CF8E4  0x021CF8E4  thumb  ov021
 *   func_021CF940  0x021CF940  thumb  ov021
 *   func_021CF9AC  0x021CF9AC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Work {
    u32 f00;
    int f04;
    u16 *f08;
    int f0c;
} Work;

struct Ctx;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern int func_021CF8E4(void *a, void *src, int c);
extern int func_021CF940(void *a, void *src, void *b, int *c);
extern int func_021CF9AC(void *a, void *heap, int x, int y);

int func_021CF844(void *a, int *task, Work *w)
{
    int *out;
    int flag = 0;
    void *sys;
    int i;

    sys = GAMESYSTEM_GetGameData(func_020124E4(a));
    switch (*task) {
    case 0:
        func_021CF8E4((void *)w->f00, sys, (int)(&w->f0c));
        (*task)++;
        break;
    case 1: {
        int base = w->f04;
        out = &w->f0c;
        for (i = flag; i < 2; i++) {
            func_021CF940((void *)w->f00, sys, (void *)(base + i), out);
            w->f04++;
            if (w->f04 >= 0x18) {
                (*task)++;
                break;
            }
        }
        break;
    }
    case 2:
        func_021CF9AC((void *)w->f00, sys, flag, (int)(&w->f0c));
        flag = 1;
        break;
    }
    if (w->f0c >= 0x32) {
        flag = 1;
    }
    if (flag) {
        *w->f08 = w->f0c;
        return 1;
    }
    return 0;
}
