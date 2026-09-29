/*
 * function: func_021D2234
 * address:  0x021D2234
 * packet:   pkt_ov093_021D2234
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 *   func_021B8E70  0x021B8E70  thumb  ov093
 *   func_021F81D0  0x021F81D0  thumb  ov094
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 unk00;
    u32 unk04;
} Seq;

extern int func_021B8D8C(void *p, void *a, u32 b);
extern u8 func_021B8E70(u8 *p, u32 k);
extern void func_021F81D0(u32 a, u32 b);

int func_021D2234(Seq *s, int *state, u32 *a)
{
    int t;

    switch (*state) {
    case 0:
        t = func_021B8D8C((void *)s->unk00, (void *)s->unk04, (u8)a[0]);
        func_021F81D0(a[1], func_021B8E70((u8 *)s->unk00, t));
        *state = *state + 1;
        break;
    case 1:
        return 1;
    }
    return 0;
}
