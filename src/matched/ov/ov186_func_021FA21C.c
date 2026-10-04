/*
 * unit: yes
 * function: func_021FA21C,func_021FA274
 * address: 0x021FA21C
 * packet: pkt_ov186_021FA21C
 * region: ov186
 * status: EXACT
 * symbols:
 *   func_021FAFC0 0x021FAFC0 thumb
 *   func_021FD73C 0x021FD73C thumb
 *   func_021FA284 0x021FA284 thumb
 */
extern void func_021FAFC0(char *p, unsigned value);
extern void func_021FD73C(int *p, int v);
extern void func_021FA284(void *p, int *state, unsigned char *ctx);
void func_021FA21C(unsigned char *ctx, int mode)
{
    int i, selected;
    for (i = 0; i < ctx[0x3b]; i++) {
        switch (mode) {
        case 0: selected = (i == ctx[0x3b] - 1); break;
        case 1: selected = (i >= ctx[0x3b] - 2); break;
        }
        if (selected)
            func_021FAFC0(*(char **)(ctx + 0x3c) + i * 0x44, 0);
        else
            func_021FAFC0(*(char **)(ctx + 0x3c) + i * 0x44, 1);
    }
}
void func_021FA274(void *p)
{
    func_021FD73C(p, (int)func_021FA284);
}
