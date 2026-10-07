/*
 * file:     zonedata_p05.c
 * unit:     yes
 * function: func_02013D74, func_02013D9C, func_02013DB8, func_02013DD0, func_02013DE0
 * address:  0x02013D74
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02013A94  0x02013A94  thumb
 *   func_02013D9C  0x02013D9C  thumb
 *   sub_02013A94  0x02013A94  thumb
 *   func_02013B10  0x02013B10  thumb
 *   d_0209DFC0     0x0209DFC0  data  a4
 *   d_0209DFEC     0x0209DFEC  data  a4
 */
typedef unsigned int u32;

typedef unsigned short u16;

typedef signed int     s32;

extern u16 func_02013A94(u32 key);
extern u32 func_02013D9C(u32 id);
extern u16 sub_02013A94(u32 key);
u32 func_02013B10(u32 id, const u16 *table, s32 count);
int func_02013D74(u32 key);
u32 sub_02013D9C(u32 id);
u32 sub_02013DB8(u32 id);
int func_02013DD0(int a0);
int func_02013DE0(u16 a0);
extern const int d_0209DFC0[];
extern const int d_0209DFEC[];


/*
 * zonedata.c: true when the zone id is in 0x121..0x13C or func_02013D9C
 * accepts it.  The image shares one `movs r0, #1` exit between the range
 * test and the callee test, which only one disjunction gives
 * (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md).
 */
int func_02013D74(u32 key)
{
    u32 v = func_02013A94(key);

    if ((v >= 0x121 && v <= 0x13c) || func_02013D9C(v) == 1)
        return 1;
    return 0;
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * alias: the id-classification predicate started in unit_02013CC8.c, plus
 * one unlabelled leaf immediately after it, read out of the bytes the same
 * way as the ones in unit_0200E884.c: sub_02013DB8 saves no registers and
 * calls nothing, so disasm.py never gave it a label.  It is the same range
 * check as sub_02013D74 (a documented near miss two functions before this
 * one) but on the RAW id, with no call to sub_02013A94 at all, which is
 * exactly what its lack of a stack frame says.
 *
 * Near miss: 0x02013DD0 to 0x02013DF0 (32 bytes, two more unlabelled leaves)
 * immediately follows and is not in this file.  Both tail call
 * sub_02013B10 (defined in the neighbouring packet) through a pool word
 * over a different fixed table (0x0209DFC0 count 4, 0x0209DFEC count 9),
 * the same shape as sub_02013C70 in unit_02013C10.c, and for the same
 * reason: every other place either pointer or table address appears in the
 * image is itself one of these unlabelled thunks rather than a literal pool
 * or a direct call, so neither has an attestable witness outside its own
 * bytes.  sub_02013DF0 onward resumes in unit_02013DF0.c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02013D9C.c \
 *       --addr 0x02013D9C --thumb
 */
u32 sub_02013D9C(u32 id)
{
    u32 v = sub_02013A94(id);

    return v >= 0x118 && v <= 0x120;
}


u32 sub_02013DB8(u32 id)
{
    return id >= 0x121 && id <= 0x13c;
}


/*
 * Unlabelled Thumb leaf inside func_02013D9C's listing extent: a tail call
 * to func_02013B10 with a fixed table and count. Filed as the witness for
 * the ov021 and ov018 callers.
 */
int func_02013DD0(int a0)
{
    return func_02013B10(a0, (const u16 *)d_0209DFC0, 4);
}


/*
 * Unlabelled Thumb leaf after func_02013DD0: a tail call
 * to func_02013B10 with a fixed table and count. Filed as the witness for
 * the ov020 caller func_021862A8 (wave D4 lane 12).
 */
int func_02013DE0(u16 a0)
{
    return func_02013B10(a0, (const u16 *)d_0209DFEC, 9);
}
