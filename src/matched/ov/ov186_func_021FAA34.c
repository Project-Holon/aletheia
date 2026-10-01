/*
 * function: func_021FAA34
 * address: 0x021FAA34
 * packet: pkt_ov186_021FAA34
 * region: ov186
 * status: EXACT
 * symbols:
 *   func_021FD73C 0x021FD73C thumb
 *   func_021FA284 0x021FA284 thumb
 */
extern void func_021FD73C(void *, void *);
extern void func_021FA284(void);
void func_021FAA34(void *p, int *state, int *ctx)
{
    if (*state == 0) {
        if (ctx[8]) {
            switch (ctx[7]) {
            case 0: case 1: case 2: break;
            case 3: ctx[6] = 2; break;
            case 4: ctx[6] = 1; break;
            }
        }
        func_021FD73C(p, func_021FA284);
    }
}
