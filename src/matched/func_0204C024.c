/*
 * function: func_0204C024
 * address:  0x0204C024
 * packet:   pkt_0204BE84
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A74     0x02146A74  data
 *   func_02063378  0x02063378  arm
 *
 * Tail call through the singleton pointer: the pool word for the global is
 * loaded, its value passed as the first argument, and the callee reached with
 * the compiler's usual `ldr ip, [pc, #4]` / `bx ip` plus a second pool word.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern u8 *g_02146A74;
extern void func_02063378(u32 a0, u32 a1);

void func_0204C024(u32 v)
{
    func_02063378((u32)g_02146A74, v);
}
