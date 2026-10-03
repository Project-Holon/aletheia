/*
 * function: func_021D1F10
 * address:  0x021D1F10
 * packet:   pkt_ov093_021D1F10
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CD9E0  0x021CD9E0  thumb  ov093
 *   func_021EA694  0x021EA694  thumb  ov093
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
extern void func_021EA694(void *win, u16 a, void *b);
extern int func_021EA710(u32 *p);

int func_021D1F10(Seq *s, int *state, u32 *a)
{
    switch (*state) {
    case 0:
        if (func_021CD9E0(s)) {
            return 1;
        }
        func_021EA694(s->win, a[0], a + 1);
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
