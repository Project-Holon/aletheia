/*
 * file:     unit_0217F0FC.c
 * unit:     yes
 * function: func_0217F0FC, gsiEnterCriticalSection, gsiLeaveCriticalSection, gsiDeleteCriticalSection, gsiStringToInt64
 * address:  0x0217F0FC
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
 *   func_020964F4  0x020964F4  arm
 */
extern void func_02086004(void *criticalSection);
extern void func_02086028(void *criticalSection);
extern void func_02086078(void *criticalSection);
extern long long func_020964F4(unsigned int string);
void func_0217F0FC(void *criticalSection);
void gsiEnterCriticalSection(void *criticalSection);
void gsiLeaveCriticalSection(void *criticalSection);
void gsiDeleteCriticalSection(void *criticalSection);
long long gsiStringToInt64(unsigned int string);


void func_0217F0FC(void *criticalSection)
{
    func_02086004(criticalSection);
}


/*
 * Tail-call wrapper: the image spells it `ldr ip, [pc]; bx ip; .word
 * target`, which this compiler emits for a tail call to a callee whose
 * address has to come from a pool.
 */
void gsiEnterCriticalSection(void *criticalSection)
{
    func_02086028(criticalSection);
}


void gsiLeaveCriticalSection(void *criticalSection)
{
    func_02086078(criticalSection);
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
    return func_020964F4(string);
}
