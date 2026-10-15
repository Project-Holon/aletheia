/*
 * function: DWCi_Ndi_lockGlobal
 * address:  0x021C78E0
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 *
 * Tail call of OS_LockMutex on the 0x021D3C38 block.
 *
 * symbols:
 *   OS_LockMutex  0x02086028  arm  arm9
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void OS_LockMutex(void *);

void DWCi_Ndi_lockGlobal(void)
{
    OS_LockMutex((void *)0x021D3C38);
}
