/*
 * function: func_021D215C
 * address:  0x021D215C
 * packet:   pkt_ov093_021D215C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021CD644  0x021CD644  thumb  ov093
 *   func_021EA280  0x021EA280  thumb  ov093
 *   func_021EA2BC  0x021EA2BC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 unk00[0x54];
    void *win;            /* 0x54 */
    u8 unk58[0x134 - 0x58];
    u32 unk134;
} Seq;

extern u32 func_021CD644(u32 a);
extern void func_021EA280(void *win, u32 n, u32 b, u8 *buf, u32 c);
extern int func_021EA2BC(void *win);

int func_021D215C(Seq *s, int *state, u32 *a)
{
    u8 buf[8];
    u8 i;
    u16 n;
    u32 p1;
    u16 p2;

    switch (*state) {
    case 0:
        n = a[0];
        p1 = a[1];
        p2 = a[2];
        for (i = 0; i < n; i++) {
            buf[i] = func_021CD644(s->unk134);
        }
        func_021EA280(s->win, n, p1, buf, p2);
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA2BC(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}
