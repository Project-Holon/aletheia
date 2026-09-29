/*
 * function: func_021D1E6C
 * address:  0x021D1E6C
 * packet:   pkt_ov093_021D1E6C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CD9E0  0x021CD9E0  thumb  ov093
 *   func_021EA678  0x021EA678  thumb  ov093
 *   func_021EA710  0x021EA710  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 unk00[0x54];
    void *win;            /* 0x54 */
} Seq;

extern u32 func_021CD9E0(void *s);
extern void func_021EA678(void *win, u16 a, void *b);
extern int func_021EA710(void *win);

int func_021D1E6C(Seq *s, int *state, u32 *a)
{
    switch (*state) {
    case 0:
        if (func_021CD9E0(s)) {
            return 1;
        }
        func_021EA678(s->win, a[0], a + 1);
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA710(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}
