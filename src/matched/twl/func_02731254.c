/*
 * function: MIi_UnlockWramManagerRI
 * address:  0x02731254
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_RestoreInterrupts 0x0208799C arm
 *   MI_UnlockWramManager 0x02731210 arm twl
 */
typedef unsigned int u32;

extern void OS_RestoreInterrupts(u32);
extern void MI_UnlockWramManager(u32 id);

void MIi_UnlockWramManagerRI(u32 id, u32 irq)
{
    MI_UnlockWramManager(id);
    OS_RestoreInterrupts(irq);
}
