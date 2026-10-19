/*
 * file:     gsplatformthread.c
 * unit:     yes
 * function: gsiInterlockedIncrement, gsiInterlockedDecrement, gsiInitializeCriticalSection, gsiEnterCriticalSection, gsiLeaveCriticalSection, gsiDeleteCriticalSection, gsiStringToInt64
 * address:  0x0217F0B4
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   OS_DisableInterrupts_IrqAndFiq                  0x020879B4  arm
 *   OS_RestoreInterrupts_IrqAndFiq                  0x020879C8  arm
 *   atoll  0x020964F4  arm
 *   OS_InitMutex  0x02086004  arm  arm9
 *   OS_LockMutex  0x02086028  arm  arm9
 *   OS_UnlockMutex  0x02086078  arm  arm9
 */
extern unsigned long OS_DisableInterrupts_IrqAndFiq(void);
extern unsigned long OS_RestoreInterrupts_IrqAndFiq(unsigned long state);
struct OSMutex;
extern void OS_InitMutex(struct OSMutex *mutex);
extern void OS_LockMutex(struct OSMutex *mutex);
extern void OS_UnlockMutex(struct OSMutex *mutex);
extern long long atoll(unsigned int string);
unsigned int gsiInterlockedIncrement(unsigned int *value);
unsigned int gsiInterlockedDecrement(unsigned int *value);
void gsiInitializeCriticalSection(void *criticalSection);
void gsiEnterCriticalSection(void *criticalSection);
void gsiLeaveCriticalSection(void *criticalSection);
void gsiDeleteCriticalSection(void *criticalSection);
long long gsiStringToInt64(unsigned int string);



/*
 * sdk:      gsiInterlockedIncrement (gsplatformthread)
 */
unsigned int gsiInterlockedIncrement(unsigned int *value)
{
    unsigned long state;
    unsigned int ret;

    state = OS_DisableInterrupts_IrqAndFiq();
    ret = (*value) + 1;
    *value = ret;
    OS_RestoreInterrupts_IrqAndFiq(state);
    return ret;
}



/*
 * sdk:      gsiInterlockedDecrement (gsplatformthread)
 */
unsigned int gsiInterlockedDecrement(unsigned int *value)
{
    unsigned long state;
    unsigned int ret;

    state = OS_DisableInterrupts_IrqAndFiq();
    ret = (*value) - 1;
    *value = ret;
    OS_RestoreInterrupts_IrqAndFiq(state);
    return ret;
}



void gsiInitializeCriticalSection(void *criticalSection)
{
    OS_InitMutex(criticalSection);
}



/*
 * Tail-call wrapper: the image spells it `ldr ip, [pc]; bx ip; .word
 * target`, which this compiler emits for a tail call to a callee whose
 * address has to come from a pool.
 */
void gsiEnterCriticalSection(void *criticalSection)
{
    OS_LockMutex(criticalSection);
}



void gsiLeaveCriticalSection(void *criticalSection)
{
    OS_UnlockMutex(criticalSection);
}


/*
 * Empty stub; nothing but a return.
 */
void gsiDeleteCriticalSection(void *criticalSection)
{
}



/*
 * Tail-call wrapper: the image spells it `ldr ip, [pc]; bx ip; .word
 * target`, which this compiler emits for a tail call to a callee whose
 * address has to come from a pool.
 *
 * Promoted from MATCH by the recursive-unblocker lane: 0x020964F4 now has an
 * EXACT arm9 shard entry (pkt_020964F4) reproducing the defaulting thunk, so
 * the ABS32 site resolves via `matched`.  Verified EXACT.
 */
long long gsiStringToInt64(unsigned int string)
{
    return atoll(string);
}
