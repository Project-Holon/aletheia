/*
 * function: func_021FAA74
 * address: 0x021FAA74
 * packet: pkt_ov186_021FAA74
 * region: ov186
 * status: EXACT
 * symbols:
 *   func_021FAF24 0x021FAF24 thumb
 *   func_021FD12C 0x021FD12C thumb
 *   func_021FD170 0x021FD170 thumb
 *   func_021FD73C 0x021FD73C thumb
 *   func_021FA284 0x021FA284 thumb
 */
extern int func_021FAF24(char *ctx, int kind);
extern void *func_021FD12C(void *, int, unsigned);
extern void func_021FD170(void *, void *, int);
extern void func_021FD73C(void *, void *);
extern void func_021FA284(void *p, int *state, unsigned char *ctx);
void func_021FAA74(void *p, int *state, unsigned *ctx)
{
    int value;
    switch (*state) {
    case 0:
        value = func_021FAF24((char *)ctx[16] + ctx[11] * 0x44, 6);
        if (ctx[20] == 0)
            ctx[20] = (unsigned)func_021FD12C((void *)ctx[1], ctx[19], *(unsigned short *)ctx);
        func_021FD170((void *)ctx[20], (void *)ctx[1], value);
        *state = 1;
        break;
    case 1: *state = 2; break;
    case 2: func_021FD73C(p, func_021FA284); break;
    }
}
