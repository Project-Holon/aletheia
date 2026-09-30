/*
 * function: func_021D6DF4
 * address: 0x021D6DF4
 * packet: pkt_ov121_021D6DF4
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_021DA8B0 0x021DA8B0 thumb ov121
 *   func_021D80C0 0x021D80C0 thumb ov121
 */
extern void func_0204E720(int, int, int, int);
extern int func_0204E804(void);
extern void func_02005E30(int);
extern void func_021DA8B0(void *, void *);
extern void func_021D80C0(void);
void func_021D6DF4(void *a, int *state)
{
    switch (*state) {
    case 0: func_0204E720(12, 0, 16, 0); func_02005E30(8); *state = 1; break;
    case 1: if (!func_0204E804()) *state = 2; break;
    case 2: func_021DA8B0(a, func_021D80C0); break;
    }
}
