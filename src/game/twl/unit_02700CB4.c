/*
 * file:     unit_02700CB4.c
 * function: func_02700CB4
 * address:  0x02700CB4
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_02701FD8  0x02701FD8  arm twl a2
 *   data_02732FC8  0x02732FC8  data twl a2
 *   func_02700C18  0x02700C18  arm twl a2
 *   func_02702028  0x02702028  arm twl a2
 */

typedef unsigned int u32;

extern u32 data_02701FD8;
extern u32 data_02732FC8[];
extern u32 func_02700C18(u32, u32*, u32);
extern void func_02702028(void);

u32 func_02700CB4(u32 a0) {
    u32 ret = func_02700C18(a0, &data_02701FD8, 0);
    data_02732FC8[2] = ret;
    if (ret == 0) {
        func_02702028();
    }
    return data_02732FC8[2];
}
