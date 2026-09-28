/*
 * function: func_02703854
 * address:  0x02703854
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_027026DC  0x027026DC  code twl a2
 *   func_027028E4  0x027028E4  code twl a2
 *   func_02703A34  0x02703A34  code twl a2
 *   func_02703A54  0x02703A54  code twl a2
 *   func_02703A74  0x02703A74  code twl a2
 */

typedef unsigned int u32;

extern u32 func_027026DC(void);
extern u32 func_027028E4(u32, u32, u32);
extern void func_02703A34(u32, u32);
extern void func_02703A54(u32, u32);
extern u32 func_02703A74(u32, u32, u32);

u32 func_02703854(u32 a0, u32 a1) {
    u32 st;
    u32 res;

    func_027026DC();
    st = func_027028E4(2, 3, 4);
    if (st != 0 && st != 2) {
        return st;
    }
    func_02703A34(0xC, a0);
    func_02703A54(a1, 0);
    res = func_02703A74(0xC, 1, a1);
    if (res == 0) {
        return 2;
    }
    return res;
}
