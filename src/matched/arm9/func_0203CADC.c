/*
 * function: func_0203CADC
 * address:  0x0203CADC
 * packet:   pkt_0203CADC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Unlabelled ARM assert thunk: tail call func_02034714(g_020A7BA8, 0x8D8, g_020A7C7C), the fall-through failure path after func_0203CA98.
 *
 * symbols:
 *   g_020A7BA8     0x020A7BA8  data
 *   g_020A7C7C     0x020A7C7C  data
 *   func_02034714  0x02034714  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u8  g_020A7BA8[];
extern u8  g_020A7C7C[];
extern void func_02034714(const char *expr, u32 line, const char *file);

void func_0203CADC(void)
{
    func_02034714((const char *)((u32)g_020A7BA8), 0x8D8, (const char *)((u32)g_020A7C7C));
}
