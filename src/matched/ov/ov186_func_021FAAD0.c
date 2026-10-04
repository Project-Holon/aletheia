/*
 * function: func_021FAAD0
 * address: 0x021FAAD0
 * packet: pkt_ov186_021FAAD0
 * region: ov186
 * status: EXACT
 * symbols:
 *   func_021FAF24 0x021FAF24 thumb
 *   func_021FAD18 0x021FAD18 thumb
 *   func_021FAD74 0x021FAD74 thumb
 *   func_021FD73C 0x021FD73C thumb
 *   func_021FA274 0x021FA274 thumb
 */
extern int func_021FAF24(char *ctx, int kind);
extern void func_021FAD18(char *ctx, int mode, const int *target);
extern int func_021FAD74(char *ctx);
extern void func_021FD73C(int *p, int v);
extern void func_021FA274(void *p);
void func_021FAAD0(void *p, int *state, unsigned char *ctx)
{
    int i, ready;
    int values[2];
    switch (*state) {
    case 0:
        for (i = 0; i < ctx[0x39]; i++) {
            values[0] = func_021FAF24(*(char **)(ctx + 0x40) + i * 0x44, 8);
            values[1] = func_021FAF24(*(char **)(ctx + 0x40) + i * 0x44, 9);
            func_021FAD18(*(char **)(ctx + 0x40) + i * 0x44, 4, values);
        }
        *state = 1;
        break;
    case 1:
        ready = 1;
        for (i = 0; i < ctx[0x39]; i++)
            ready &= func_021FAD74(*(char **)(ctx + 0x40) + i * 0x44);
        if (ready) *state = 2;
        break;
    case 2: func_021FD73C(p, (int)func_021FA274); break;
    }
}
