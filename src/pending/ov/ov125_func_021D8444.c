/*
 * function: func_021D8444
 * address: 0x021D8444
 * packet: pkt_ov125_021D8444
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: DIFF
 *
 * 2026-10-04 (wave D2 lane 14): DIFF, 23 bytes, structure right. Sav and Big are the two struct
 * copies (301 bytes by byte loop, 312 bytes by ldm/stm; Big must be a u32 array). Residue: in the
 * 301-byte copy the original puts the global destination in r5 and the stack source in r3; this
 * build swaps them (r3 destination, r5 source), which shifts the next block. The a/b stack order
 * is fixed by declaring b first. Tried: pointer locals for src/dst in both orders, typed extern
 * destination, struct-typed buf. The 312-byte copy source/destination go through d_021D9E40
 * directly (the original reloads the pool word into lr).
 *
 * symbols:
 *   func_02167FA8 0x02167FA8 arm ov009
 *   func_02168040 0x02168040 arm ov009
 *   func_02059E38 0x02059E38 arm
 *   func_021D7CAC 0x021D7CAC arm ov125
 *   func_021D7CC0 0x021D7CC0 arm ov125
 *   func_021D8438 0x021D8438 arm ov125
 *   d_021D9E40 0x021D9E40 data a4
 *   d_021D8D30 0x021D8D30 data a4
 */

/*
 * 2026-10-05 (wave D4 lane07): DIFF, unchanged 23 bytes. Re-read: the 301-byte copy uses r5 (the register that holds the constant 1 for func_021D8438(1)) for the destination d_021D9E46 and r3 for the stack source; the build swaps them, and the trailing byte schedules ldr lr first. No new form found beyond the earlier list; next idea: write the Big copy and the Sav copy through one struct type whose field order puts Sav first, or derive the 1 for func_021D8438 from a local.
 */
/*
 * 2026-10-05 (wave D5 lane09): DIFF, 23 bytes (21 with the g + 6 form). Tried: destination written as
 *   `*(Sav *)(g + 6)` (pool word folds to r4 + 6: no; but the trailing ldrb then schedules before the
 *   Big copy as in the original), memcpy through the house string.h (real call, no), the copy in a
 *   static inline cp(Sav *d, const Sav *s) helper (identical). Finding: the source pointer gets r5 in
 *   every form, whichever operand is computed first; the original gives r5 to the destination.
 */
/*
 * 2026-10-05 (wave D6 lane02): DIFF, 18 bytes (was 23). New form: d_021D9E40 is one struct Data
 *   (312 bytes: u32, u16, Sav at +6, 5 tail bytes) and the copies are "d_021D9E40.sav = ..." and
 *   "*(Data *)(ptr + 8) = d_021D9E40". The pool word 021D9E46 is now &d_021D9E40.sav (no extra
 *   symbol) and the trailing byte of the 301-byte copy now schedules before the Big copy, as in the
 *   original. Residue: only the r3/r5 swap (original dst r5, src r3) and the "mov r5,#0x13" that
 *   follows from it. Tried with no effect: Buf struct local with a Sav member at 0x45, the copy in
 *   an inline cp(src, dst) helper, pointer locals for dst/src in both declaration orders, the
 *   r == 3 path as "break" with the copies after the loop (worse). All callees checked: no hidden
 *   arguments (021D7CAC/021D7CC0/021D8438 are thunks that load their own r0).
 */
/*
 * 2026-10-05 (wave D7 lane15): DIFF, 18 bytes, unchanged. Residue: the 301-byte byte-copy loop has the
 *   destination (&d_021D9E40.sav) in r3 and the stack source in r5; the original has dst r5, src r3, then
 *   `mov r5,#0x13` after the trailing strb. Checked callees again: 02168040 and 02167FA8 take no hidden
 *   arguments, 021D8438 is a veneer to 0x02085A38. No value merges at a join in the r == 3 block. Tried:
 *   the r chain as a switch on the call result (332 bytes, worse), `int one = 1` for the 021D8438 argument
 *   (same 18), static inline accessors for the source (SavOf(buf)) and for the destination (DstOf()), both
 *   same 18. Open: what makes mwcc colour the struct-copy source before the destination.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 b[301]; } Sav;
typedef struct { u32 w0; u16 h4; Sav sav; u8 tail[5]; } Data;
extern int func_02167FA8(const char *, void *);
extern int func_02168040(void);
extern int func_02059E38(int *, int *);
extern void func_021D7CAC(void);
extern void func_021D7CC0(void);
extern void func_021D8438(int);
extern Data d_021D9E40;
extern const char d_021D8D30[];

int func_021D8444(void)
{
    char *g = (char *)&d_021D9E40;
    u8 buf[0x174];
    int b, a;
    int r;

    if (*(int *)(g + 0x138) == 1)
        return 1;
    if (func_02167FA8(d_021D8D30, buf) == 0) {
        *(int *)(g + 0x250) = 0xE;
        return 0;
    }
    for (;;) {
        r = func_02168040();
        if (r == 3) {
            d_021D9E40.sav = *(Sav *)(buf + 0x45);
            *(Data *)(*(char **)((char *)&d_021D9E40 + 0x258) + 8) = d_021D9E40;
            *(int *)(g + 0x138) = 1;
            return 1;
        }
        if (r == 4) {
            func_02059E38(&a, &b);
            *(int *)(g + 0x250) = 0xE;
            return 0;
        }
        if (r == 5) {
            *(int *)(g + 0x250) = 0xE;
            return 0;
        }
        func_021D7CAC();
        if (*(int *)(g + 0x268) == 1) {
            *(int *)(g + 0x250) = 0xD;
            func_021D7CC0();
            return 0;
        }
        func_021D7CC0();
        func_021D8438(1);
    }
}
