/*
 * function: PMi_TryLockForReset
 * address:  0x02731718
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02087988 0x02087988 arm
 *   func_0208799C 0x0208799C arm
 *   data_02732FA8 0x02732FA8 data
 */

typedef unsigned int u32;

extern u32 func_02087988(void);
extern void func_0208799C(u32 state);
extern u32 data_02732FA8;

int PMi_TryLockForReset(void)
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
