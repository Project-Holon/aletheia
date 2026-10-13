/*
 * function: PMi_TryLockForReset
 * address:  0x02731718
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_DisableInterrupts 0x02087988 arm
 *   OS_RestoreInterrupts 0x0208799C arm
 *   data_02732FA8 0x02732FA8 data
 */

typedef unsigned int u32;

extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32 state);
extern u32 data_02732FA8;

int PMi_TryLockForReset(void)
{
    u32 state = OS_DisableInterrupts();
    if (data_02732FA8 != 0) {
        OS_RestoreInterrupts(state);
        return 0;
    }
    data_02732FA8 = 1;
    OS_RestoreInterrupts(state);
    return 1;
}
