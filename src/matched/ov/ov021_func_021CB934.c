/*
 * function: func_021CB934
 * address:  0x021CB934
 * packet:   pkt_ov021_021CB934
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Task step: fades out, runs the ov021 sub-screen on the +0xc argument, stores whether it was cancelled at *w[1].
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A684  0x0215A684  thumb  ov010
 *   func_0215A690  0x0215A690  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C54  0x02188C54  thumb
 *   func_02190BE4  0x02190BE4  thumb
 *   func_02190C78  0x02190C78  thumb
 *   func_021909BC  0x021909BC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    void *owner;
    u16 *result;
    u32 screen;
    u32 arg;
} Work;

extern void *func_0215A5F4(void *p);
struct Ctx;
extern void func_0215A684(int *p, unsigned short v);
extern int func_0215A690(void *a);
extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_02188C54(u8 *p);
struct Handle;
extern u32 *func_02190BE4(u16 *a, u32 b);
extern int func_02190C78(struct Handle *h);
extern int func_021909BC(void *a);

int func_021CB934(void *task, int *state, Work *w)
{
    func_0215A5F4(w->owner);
    switch (*state) {
    case 0:
        func_0215A684(w->owner, 8);
        (*state)++;
    case 1:
        if (func_0215A690(w->owner) == 1) {
            w->screen = (u32)func_02190BE4((u16 *)func_02188C54(func_0201210C(func_0215A5DC(w->owner))), w->arg);
            (*state)++;
        }
        break;
    case 2:
        switch (func_02190C78((struct Handle *)w->screen)) {
        case 0:
            *w->result = 0;
            (*state)++;
            break;
        case 2:
            break;
        default:
            *w->result = 1;
            (*state)++;
            break;
        }
        break;
    case 3:
        func_021909BC((void *)w->screen);
        return 1;
    }
    return 0;
}
