/*
 * function: func_02017B4C
 * address:  0x02017B4C
 * packet:   pkt_02017A20
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * poke_tool.c: the "reset this record to a fresh hatched state" writer.  It
 * takes the block lock, reads the species (id 5) and the form (id 0x6F, for
 * its side effect only -- the result is discarded, which is why the call is a
 * statement), clears the egg flag (id 0x4C), stores 0x78 into id 9, renders
 * the species name into the shared 0x20 halfword buffer at 0x021462F0 and
 * writes it back as the nickname (id 0x74), then hands the record and the
 * three caller arguments to func_0202F1B4 before releasing the lock.
 *
 * WHAT WAS WRONG IN THE EARLIER NOTE, AND WHAT CLOSED IT
 * -----------------------------------------------------
 * docs/notes/func_02017B4C.diff.c.txt records this function as a 104-byte
 * DIFF at 120 bytes against 124, and that source is four bytes short with the
 * whole body misaligned.  The note's skeleton is correct; only two
 * declarations are wrong, and they are the whole difference.
 *
 * The note declares the two accessor externs as returning narrow types --
 * `u8 func_02017DBC(...)` and `u16 func_02017E88(...)` -- and assigns their
 * results to same-width locals.  With the callee declared narrow the compiler
 * believes the value is already truncated, emits no shift pair, and then has
 * nothing cheap to keep the value in, so it spills BOTH to the frame
 * (`str r0, [sp, #4]` / `str r0, [sp, #8]`) and burns the two argument
 * registers r6 and r7 on a1 and a2 instead.
 *
 * The original does the opposite: it truncates at the ASSIGNMENT
 * (`lsls r0, r0, #0x18` / `lsrs r7, r0, #0x18` for the u8 and
 * `lsls r0, r0, #0x10` / `lsrs r6, r0, #0x10` for the u16) and keeps both
 * narrowed values live in r7 and r6, which frees the frame slots for a1 and
 * a2 (`str r1, [sp, #4]` / `str r2, [sp, #8]`).  That shape only compiles
 * when the CALLEE is declared to return a full word and the LOCAL is declared
 * narrow, so the cast is the source's own and not the callee's.  Declaring
 * both externs u32 and both locals u8/u16 is the entire fix; nothing else in
 * the note's body changed.
 *
 * This is the same adjudication rule docs/families/poke_tool.h states: a
 * truncation emitted at the call constrains the callee's parameter width,
 * while a truncation emitted at the assignment constrains the local's.  Here
 * it is the assignment, so the accessors stay u32 -- which also agrees with
 * every other matched file in the family (unit_02017E64.c, unit_0201854C.c,
 * unit_02018430.c all declare func_02017E88 returning u32).
 *
 * The third argument of func_02017E64 is a plain u32 and not a pointer: the
 * note spells it `void *` and passes `(void *)0x78`, which compiles the same
 * here but is a claim the bytes do not support, since id 9 is a byte field.
 *
 * Nothing here is version specific: 5, 9, 0x4C, 0x6F and 0x74 are field
 * selectors and 0x20 is a halfword count.  g_020A7370 and g_021462F0 are
 * globals, so their addresses are build properties.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02017B4C.c \
 *       --func func_02017B4C --addr 0x02017B4C --cc 1.1p1 --thumb
 *
 * symbols:
 *   func_02017DBC  0x02017DBC  thumb
 *   func_02017E88  0x02017E88  thumb
 *   func_02017E64  0x02017E64  thumb
 *   func_02045F5C  0x02045F5C  arm
 *   func_0202F1B4  0x0202F1B4  thumb
 *   func_02017DE4  0x02017DE4  thumb
 *   g_020A7370     0x020A7370  data
 *   g_021462F0     0x021462F0  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32  func_02017DBC(void *a0);
extern u32  func_02017E88(void *a0, u32 a1, u32 a2);
extern void func_02017E64(void *a0, u32 a1, u32 a2);
extern void func_02045F5C(void *a0, u32 a1, void *a2, u32 a3);
extern void func_0202F1B4(void *a0, u32 a1, u32 a2, u32 a3, u32 a4);
extern u32  func_02017DE4(void *a0, u32 a1);

extern void *g_020A7370;
extern u8    g_021462F0[];

u32 func_02017B4C(void *a0, u32 a1, u32 a2, u32 a3)
{
    u8  v = (u8)func_02017DBC(a0);
    u16 w = (u16)func_02017E88(a0, 5, 0);

    func_02017E88(a0, 0x6f, 0);
    func_02017E64(a0, 0x4c, 0);
    func_02017E64(a0, 9, 0x78);
    func_02045F5C(g_020A7370, w, g_021462F0, 0x20);
    func_02017E64(a0, 0x74, (u32)g_021462F0);
    func_0202F1B4(a0, 2, a1, a2, a3);
    return func_02017DE4(a0, v);
}
