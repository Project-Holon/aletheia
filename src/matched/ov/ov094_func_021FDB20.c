/*
 * function: func_021FDB20
 * address:  0x021FDB20
 * packet:   pkt_ov094_021F9AB8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F8694  0x021F8694  thumb  ov094
 *   func_021FF16C  0x021FF16C  thumb  ov094
 *   func_021FF1B0  0x021FF1B0  thumb  ov094
 */
typedef struct {
    char pad[0x244];
    int f244;
} State;

extern void *func_021F8694(void);
extern void func_021FF16C(void *w);
extern void func_021FF1B0(void *w);

void func_021FDB20(State *s)
{
    if (s->f244 == 1)
        func_021FF1B0(func_021F8694());
    else
        func_021FF16C(func_021F8694());
}
