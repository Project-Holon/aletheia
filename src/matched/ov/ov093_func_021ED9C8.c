/*
 * function: func_021ED9C8
 * address:  0x021ED9C8
 * packet:   pkt_ov093_021ED9C8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F80E4  0x021F80E4  thumb  ov094
 */
typedef unsigned char u8;
struct E { int a0; u8 *owner; u8 k8; u8 v9; u8 fa; u8 fb; };
typedef unsigned int   u32;
extern void func_021F80E4(u32 a);
void func_021ED9C8(struct E *e)
{
    if (e->fb != 0) {
        if (e->fa != 0) {
            func_021F80E4(e->v9);
            e->fa = 0;
        }
        e->a0 = 0;
        e->fb = 0;
    }
}
