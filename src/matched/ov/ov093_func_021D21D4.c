/*
 * function: func_021D21D4
 * address:  0x021D21D4
 * packet:   pkt_ov093_021D21D4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 *   func_021EA384  0x021EA384  thumb  ov093
 *   func_021EA3A0  0x021EA3A0  thumb  ov093
 *   func_021EA678  0x021EA678  thumb  ov093
 *   func_021EA710  0x021EA710  thumb  ov093
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

extern int func_021B8D8C(void *p, void *a, u32 b);
extern void func_021EA384(char *ctx, int a);
extern int func_021EA3A0(u32 *p);
extern void func_021EA678(void *win, u16 a, void *b);
extern int func_021EA710(u32 *p);

int func_021D21D4(Seq *s, int *state, u32 *a)
{
    switch (*state) {
    case 0:
        func_021EA384(s->win, func_021B8D8C((void *)s->unk00, (void *)s->unk04, (u8)a[0]));
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA3A0(s->win)) {
            func_021EA678(s->win, 0x61, a);
            *state = *state + 1;
        }
        break;
    case 2:
        if (func_021EA710(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}
