/*
 * function: func_02731718
 * address:  0x02731718
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   func_02087988  0x02087988  code twl a2
 *   func_0208799C  0x0208799C  code twl a2
 *   data_02732FA8  0x02732FA8  data twl a4
 */

typedef unsigned int u32;

extern u32 func_02087988(void);
extern void func_0208799C(u32 state);
extern u32 data_02732FA8;

int func_02731718(void)
{
    u32 state = func_02087988();
    if (data_02732FA8 != 0) {
        func_0208799C(state);
        return 0;
    }
    data_02732FA8 = 1;
    func_0208799C(state);
    return 1;
}
