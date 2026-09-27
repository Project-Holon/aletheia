/*
 * function: func_02700BD0
 * address:  0x02700BD0
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0270212C  0x0270212C  arm twl a2
 *   func_02087A04  0x02087A04  arm twl a2
 *   func_027020F0  0x027020F0  arm twl a2
 *   func_027021E4  0x027021E4  arm twl a2
 *   func_02700DB8  0x02700DB8  arm twl a2
 */

typedef unsigned int u32;
typedef signed int s32;

extern void func_0270212C(void);
extern void func_02087A04(u32);
extern u32 func_027020F0(void);
extern void func_027021E4(void);
extern void func_02700DB8(u32);

void func_02700BD0(void) {
    s32 r5 = 0x001991B0;
    u32 r4 = 4;
    func_0270212C();
    goto entry;
    do {
        func_02087A04(r4);
entry:
        if (r5-- <= 0) break;
    } while (func_027020F0() != 0);

    func_027021E4();
    func_02700DB8(0);
}
