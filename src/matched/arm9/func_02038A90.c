/*
 * function: func_02038A90
 * address:  0x02038A90
 * packet:   pkt_02038A90
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   str_020A7A24   0x020A7A24  data
 *   str_020A7A50   0x020A7A50  data
 *   func_02034714  0x02034714  arm
 *   func_0203D6BC  0x0203D6BC  arm
 *   func_0203D680  0x0203D680  arm
 *   func_0203D798  0x0203D798  arm
 *   func_02037224  0x02037224  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern const u8 str_020A7A24[];
extern const u8 str_020A7A50[];
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u32 func_0203D6BC(void);
extern u32 func_0203D680(void);
extern void *func_0203D798(void);
extern void func_02037224(u32 a, u32 b);

int func_02038A90(u32 a)
{
    func_0203D6BC();
    func_0203D680();
    func_0203D798();
    if (a != 0) {
        func_02037224(4, 0x5d4);
    } else {
        func_02034714((const char *)str_020A7A24, 0x5d8, (const char *)str_020A7A50);
    }
    return 1;
}
