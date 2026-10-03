/*
 * function: func_021D20BC
 * address:  0x021D20BC
 * packet:   pkt_ov093_021D20BC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B8DC0  0x021B8DC0  thumb  ov093
 *   func_021EA354  0x021EA354  thumb  ov093
 *   func_021F7EB4  0x021F7EB4  thumb  ov094
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 unk00;
    u32 unk04;
    u8 unk08[0x4C];
    void *win;            /* 0x54 */
} Seq;

extern u32 func_021B8DC0(u32 a, u32 b, u8 c);
extern void func_021EA354(void *ctx, int a, int b);
extern int func_021F7EB4(void);

int func_021D20BC(Seq *s, int *state, u32 *a)
{
    u32 t;

    switch (*state) {
    case 0:
        t = func_021B8DC0(s->unk00, s->unk04, a[0]);
        func_021EA354(s->win, t, a[1] != 0);
        *state = *state + 1;
        break;
    case 1:
        if (func_021F7EB4() == 0) {
            return 1;
        }
        return 0;
    }
    return 0;
}
