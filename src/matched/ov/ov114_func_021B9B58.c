/*
 * function: NHTTPi_LockMutexThunk
 * address:  0x021B9B58
 * packet:   pkt_ov114_021B9B58
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_LockMutex  0x02086028  arm
 *
 * ARM linker veneer / far tail call: ldr ip,[pc,#0]; bx ip; .word
 * 0x02086028, printed as a .word run by disasm.py at 0x021B9B58 in ov114.
 * Blocker target of NHTTPi_lockReqList (pkt_021B9500).
 */

extern void OS_LockMutex(void);

void NHTTPi_LockMutexThunk(void)
{
    OS_LockMutex();
}
