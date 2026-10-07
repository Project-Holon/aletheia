/*
 * file:     unit_0217F0FC.c
 * unit:     yes
 * function: func_0217F0FC, func_0217F108, func_0217F114, func_0217F120, func_0217F124
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
extern void func_02086004(void *mutex);
extern void func_02086028(void *mutex);
extern void func_02086078(void *mutex);
extern long long func_020964F4(unsigned int a0);
void func_0217F0FC(void *mutex);
void func_0217F108(void *mutex);
void func_0217F114(void *mutex);
void func_0217F120(void *p);
long long func_0217F124(unsigned int a0);


void func_0217F0FC(void *mutex)
{
    func_02086004(mutex);
}


/*
 * Tail-call wrapper: the image spells it `ldr ip, [pc]; bx ip; .word
 * target`, which this compiler emits for a tail call to a callee whose
 * address has to come from a pool.
 */
void func_0217F108(void *mutex)
{
    func_02086028(mutex);
}


void func_0217F114(void *mutex)
{
    func_02086078(mutex);
}

/*
 * Empty stub; nothing but a return.
 */
void func_0217F120(void *p)
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
long long func_0217F124(unsigned int a0)
{
    return func_020964F4(a0);
}
