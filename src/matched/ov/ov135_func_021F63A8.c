/*
 * function: func_021F63A8
 * address: 0x021F63A8
 * packet: pkt_ov135_021F63A8
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F4D14 0x021F4D14 thumb ov135
 *   func_021F4CE4 0x021F4CE4 thumb ov135
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_02034714 0x02034714 arm
 *   d_02203B68 0x02203B68 data a4
 */
typedef unsigned char u8;
extern unsigned func_021F4D14(void *p);
extern void func_021F4CE4(void *p);
typedef unsigned int   u32;
extern void func_021F4EC0(u8 *p, u32 a, u32 b);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern const char d_02203B68[];
int func_021F63A8(u8 *p)
{
    unsigned result = func_021F4D14(p);
    func_02034714(d_02203B68, 0, d_02203B68);
    if (result == 1) {
        func_021F4CE4(p);
        *(unsigned *)(p + 0x28) = 2;
        func_021F4EC0(p, 0, 0);
    } else if (result == 2) {
        func_021F4CE4(p);
        *(unsigned *)(p + 0x28) = 0;
    }
    return 2;
}
