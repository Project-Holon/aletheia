/*
 * function: func_021FA6A8
 * address: 0x021FA6A8
 * packet: pkt_ov186_021FA6A8
 * region: ov186
 * status: EXACT
 * symbols:
 *   func_021FAD18 0x021FAD18 thumb
 *   func_021FAD74 0x021FAD74 thumb
 *   func_021FD73C 0x021FD73C thumb
 *   func_021FAA34 0x021FAA34 thumb
 *   func_021FA7FC 0x021FA7FC thumb
 */
extern void func_021FAD18(char *ctx, int mode, const int *target);
extern int func_021FAD74(char *ctx);
extern void func_021FD73C(int *p, int v);
extern void func_021FAA34(void *p, int *state, int *ctx);
extern void func_021FA7FC(void *p, int *state, unsigned char *ctx);
void func_021FA6A8(void *p, int *state, unsigned char *ctx)
{
    int i, ready;
    switch (*state) {
    case 0:
        for (i = 0; i < ctx[0x39]; i++)
            func_021FAD18(*(char **)(ctx + 0x40) + i * 0x44, 1, 0);
        *state = 1;
        break;
    case 1:
        ready = 1;
        for (i = 0; i < ctx[0x39]; i++)
            ready &= func_021FAD74(*(char **)(ctx + 0x40) + i * 0x44);
        if (ready) *state = 2;
        break;
    case 2:
        switch (*(unsigned *)(ctx + 0x1c)) {
        case 0: case 1: func_021FD73C(p, (int)func_021FAA34); break;
        case 4: func_021FD73C(p, (int)func_021FA7FC); break;
        default: func_021FD73C(p, (int)func_021FAA34); break;
        }
        break;
    }
}
