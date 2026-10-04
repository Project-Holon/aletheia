/*
 * function: func_021FA444
 * address: 0x021FA444
 * packet: pkt_ov186_021FA444
 * region: ov186
 * status: EXACT
 * symbols:
 *   func_021FAEE4 0x021FAEE4 thumb
 *   func_021FAD18 0x021FAD18 thumb
 *   func_021FAD74 0x021FAD74 thumb
 *   func_021FD73C 0x021FD73C thumb
 *   func_021FA500 0x021FA500 thumb
 */
typedef unsigned char  u8;
extern void func_021FAEE4(char *p, int *out);
extern void func_021FAD18(char *ctx, int mode, const int *target);
extern int func_021FAD74(char *ctx);
extern void func_021FD73C(int *p, int v);
extern void func_021FA500(void *p, int *state, u8 *ctx);
void func_021FA444(void *p, int *state, unsigned char *ctx)
{
    int i, ready;
    int values[2];
    switch (*state) {
    case 0:
        for (i = 0; i < ctx[0x39]; i++) {
            if (*(int *)(ctx + 0x2c) != i) {
                func_021FAEE4(*(char **)(ctx + 0x40) + *(int *)(ctx + 0x2c) * 0x44, values);
                func_021FAD18(*(char **)(ctx + 0x40) + i * 0x44, 0, values);
            }
        }
        *state = 1;
        break;
    case 1:
        ready = 1;
        for (i = 0; i < ctx[0x39]; i++)
            ready &= func_021FAD74(*(char **)(ctx + 0x40) + i * 0x44);
        if (ready) *state = 2;
        break;
    case 2:
        if (*(int *)(ctx + 0x1c) == 4) {
            func_021FD73C(p, (int)func_021FA500);
            return;
        } else {
            func_021FD73C(p, (int)func_021FA500);
        }
        break;
    }
}
