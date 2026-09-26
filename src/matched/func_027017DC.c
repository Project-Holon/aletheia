/*
 * function: func_027017DC
 * address:  0x027017DC
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_02701FD8  0x02701FD8  data twl a2
 *   data_02732FC8  0x02732FC8  data twl a2
 *   func_02701718  0x02701718  code twl a2
 *   func_02702028  0x02702028  code twl a2
 */

typedef unsigned int u32;

extern u32 data_02701FD8;
extern u32 data_02732FC8[];
extern u32 func_02701718(u32, u32, u32*, u32);
extern void func_02702028(void);

u32 func_027017DC(u32 a0, u32 a1) {
    u32 ret = func_02701718(a0, a1, &data_02701FD8, 0);
    data_02732FC8[2] = ret;
    if (ret == 0) {
        func_02702028();
    }
    return data_02732FC8[2];
}
