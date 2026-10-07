/*
 * file:     delivery_beacon_p01.c
 * unit:     yes
 * function: func_021576C4, func_021576CC
 * address:  0x021576C4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021576B8  0x021576B8  thumb  ov010
 */
void func_021576B8(char *p, int v);
void func_021576C4(char *p, int v, int line);
void func_021576CC(void);


/*
 * Unblocked by matching func_021576B8 (ov010, EXACT). The ABS32 site +0004 now
 * attests as `matched`.
 * The listing extent is now 8 bytes, so the verdict is plain EXACT.
 *
 * `line`: every caller loads r2 with a constant, but the callee never
 * reads it, so the thunk takes it and drops it.
 */
void func_021576C4(char *p, int v, int line)
{
    func_021576B8(p, v);
}

/*
 * Unlabelled empty callback (bx lr) hidden in a .word run; witness for the
 * function pointer taken in func_021578A0.
 */
void func_021576CC(void)
{
}
