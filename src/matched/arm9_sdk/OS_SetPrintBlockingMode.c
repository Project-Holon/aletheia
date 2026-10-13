/*
 * function: OS_SetPrintBlockingMode
 * address:  0x020271DC
 * packet:   pkt_020271DC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202708C 0x0202708C thumb
 *   func_02027230 0x02027230 thumb
 *   func_020271F8 0x020271F8 thumb
 */

typedef unsigned short u16;
extern int func_0202708C(u16 v);
extern void func_02027230(u16 value);
extern void func_020271F8(u16 value);

void OS_SetPrintBlockingMode(u16 v)
{
    if (func_0202708C(v)) {
        func_02027230(v);
    } else {
        func_020271F8(v);
    }
}
