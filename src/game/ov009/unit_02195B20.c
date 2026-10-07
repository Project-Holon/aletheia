/*
 * file:     unit_02195B20.c
 * unit:     yes
 * function: func_02195B20, func_02195B2C, func_02195B38
 * address:  0x02195B20
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
 *   func_02198020  0x02198020  arm
 */
extern void func_02198020(int *p, int v);
extern int func_0219569C(void *connection, void *callbacks);
extern void func_021956F8(void);
void func_02195B20(int *p, int v);
int func_02195B2C(void *connection, void *callbacks);
void func_02195B38(void);


/*
 * Tail-call wrapper: the image spells it `ldr ip, [pc]; bx ip; .word
 * target`, which this compiler emits for a tail call to a callee whose
 * address has to come from a pool.
 *
 * Unblocked by matching the 8-byte ARM leaf at 0x02198020 in ov009 (its
 * listing emits it as a .word run, unlabelled); the ABS32 site now resolves
 * via `matched`.  Packet renamed from pkt_02155168 so this promotion does
 * not rewrite that packet's shard.
 */
void func_02195B20(int *p, int v)
{
    func_02198020(p, v);
}


/*
 * Tail-call wrapper: the image spells it `ldr ip, [pc]; bx ip; .word
 * target`, which this compiler emits for a tail call to a callee whose
 * address has to come from a pool.
 */
int func_02195B2C(void *connection, void *callbacks)
{
    return func_0219569C(connection, callbacks);
}


void func_02195B38(void)
{
    func_021956F8();
}
