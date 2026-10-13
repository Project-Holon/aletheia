/*
 * function: ARC_TOOL_DeleteHandle
 * address:  0x02049238
 * packet:   pkt_02049238
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_02078A80 0x02078A80 arm
 */

extern void func_02078A80(void *p);
extern unsigned int func_020307B0(void *p);

void ARC_TOOL_DeleteHandle(void *arc)
{
    func_02078A80(arc);
    func_020307B0(arc);
}
