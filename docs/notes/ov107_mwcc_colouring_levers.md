# Two mwccarm levers that closed ov107 MBi_ParentCallback (2004 bytes, EXACT)

Row: `ov107/pkt_ov107_021F46C8` (`src/matched/ov_sdk/ov107_func_021F46C8.c`). It went
1178 differing concrete bytes -> 4 -> 0 using the two levers below plus declaration
order. Neither is ov107-specific.

## 1. A `volatile` pointer cast restores a load the front end CSE'd

The image reads `g_021F6F90.p_parm` twice, adjacent (`ldr r0,[r4,#0xc]` /
`ldr r3,[r4,#0xc]`), once for a ternary and once for a call's argument list. Plain C
gives one load (and a 2000-byte function); the object is 2004. Spelling the *first*
read `*(char *volatile *)(d_021F6F90 + 0xC)` forces the second load back, with no
other byte moving:

    f = (*(u16 *)(*(char *volatile *)(d_021F6F90 + 0xC) + 0x52C) != 0) ? 0 : f;
    {
        char *parm = *(char **)(d_021F6F90 + 0xC);   /* stays a plain read */
        ...

Rule of thumb: when a row is exactly 4 bytes (one `ldr`) short and the diff shows a
pair of loads of the same global where yours has one, put the volatile cast on the
first read only. Putting it on the second (V2) and on both (V3) were inert; putting
the volatile on the *pointer variable* (`char *volatile p = ...`) costs 24 bytes.

## 2. Declaration order of the small scalars is the scratch-register order

mwccarm hands `r1, r2, r3` to the case-scoped locals in *declaration* order. For the
case-0x0F loop the image wants `work=r3, n=r2, i=r1`, which is exactly

    u32 i;
    u32 n;
    char *work;

Any other order rotates the triple (`char *work; u32 n; u32 i;` gives work=r1,n=r2,i=r3;
`u32 n; u32 i; char *work;` gives work=r3,n=r1,i=r2) while every other byte of the
function stays identical. This is a cheap first knob on any "cyclic rotation of
scratch registers" residue -- cheaper than loop restructurings, which were inert here
(6 spellings of the 15-iteration loop changed nothing). Do NOT push it into a note
before trying it: it costs nothing and it is often the whole difference between a
one-register rotation and EXACT.

Also on this row: the loop counters are `u32`, not `int` -- the object has `blo`/`bhs`
where signed counters emit `blt`/`bge`.

## 3. `break;` at the end of an inner switch shares the outer epilogue

The `case 0x80:` inner `switch (*(u16 *)((char *)arg + 4))` ends in `break;`, not
`return;`. With `return;` the four "empty" jump-table slots (cases 0x14, 0x15, 0x17
and the out-of-range fall-through) target the epilogue at +0x07A0 that `case 0x16:
OS_Terminate();` leaves behind; with `break;` they target the function's final
epilogue at +0x07BC, which the outer `default:` also returns through. Same 4 bytes
either way, same behaviour -- only the jump-table words differ. When a switch residue
is "N identical-epilogue jump-table words point 0x1c too early", try swapping the
trailing `return;` for `break;` (or the reverse) before anything else.
