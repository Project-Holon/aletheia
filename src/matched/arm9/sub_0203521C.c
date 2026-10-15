/*
 * function: UI_GetPointerValue
 * address:  0x0203521C
 * packet:   pkt_02035080
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * A trivial pointer-dereference getter: "ldr r0,[r0]; bx lr", eight bytes,
 * no relocations. No lr push, so disasm.py never labels it.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/UI_GetPointerValue.c \
 *       --func UI_GetPointerValue --addr 0x0203521C --cc 1.1p1 --arm
 */

typedef unsigned int u32;

u32 UI_GetPointerValue(u32 *p)
{
    return *p;
}
