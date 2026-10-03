/*
 * function: func_02017900
 * address:  0x02017900
 * packet:   pkt_0201756C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * poke_tool.c: "change this record's species to a1".  It takes the block
 * lock, reads the current species (id 5) and does nothing at all when it
 * already matches.  Otherwise it touches id 0x6F for its side effect, reads
 * the "nickname is not the default" bit (id 0x75), writes the new species,
 * refreshes the two derived type fields through func_02017C50 and
 * func_02017CC8, and -- only when the nickname was still the default -- also
 * renders the new species' name into the shared buffer at 0x021462F0 and
 * stores it back as id 0x74.  Then it releases the lock.
 *
 * The id 0x75 guard is what makes this correct game behaviour: a record the
 * player has renamed keeps its nickname across a species change, and one that
 * never was renamed follows the species.  func_02019ABC (unit_02019ABC.c) is
 * what sets that bit, and func_02018E34 reads it back as id 0x75.
 *
 * WHAT WAS WRONG IN THE EARLIER NOTE, AND WHAT CLOSED IT
 * -----------------------------------------------------
 * docs/notes/func_02017900.diff.c.txt records this as a DIFF and its skeleton
 * is correct in every structural respect -- the guard, the nested 0x75 test,
 * the call order.  Only the extern declarations are wrong, and in exactly the
 * same way as its sibling src/matched/func_02017B4C.c, which the same note
 * file pairs it with.
 *
 * The note declares the accessors narrow (`u8 func_02017DBC`, `u16
 * func_02017E88`).  With the callee declared narrow the compiler emits no
 * truncation at all and then spills the live values to the frame.  The
 * original truncates at the ASSIGNMENT with a `lsls`/`lsrs` pair and keeps
 * both narrowed values in callee-saved registers.  That shape needs the
 * callee declared returning a full word and the LOCAL declared narrow, so the
 * cast belongs to the source rather than to the callee.  Declaring
 * func_02017DBC and func_02017E88 u32 and keeping `u8 v` / `u16 w` is the
 * entire fix; the body is the note's, unchanged.
 *
 * This is docs/families/poke_tool.h's adjudication rule: a truncation at the
 * call constrains the callee's width, a truncation at the assignment
 * constrains the local's.  Every other matched file in the family
 * (unit_02017E64.c, unit_0201854C.c, unit_02018430.c) already declares
 * func_02017E88 returning u32, so the note's spelling was the outlier.
 *
 * The third argument of func_02017E64 is a plain u32, not a `void *`: ids 5
 * and 0x74 take an integer and a buffer address respectively, and spelling
 * the parameter as a pointer is a claim the bytes do not make.
 *
 * Nothing here is version specific: 5, 0x6F, 0x74 and 0x75 are field
 * selectors and 0x20 is a halfword count.  g_020A7370 and g_021462F0 are
 * globals, so their addresses are build properties and must be re-derived
 * for a White build rather than copied.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02017900.c \
 *       --func func_02017900 --addr 0x02017900 --cc 1.1p1 --thumb
 *
 * symbols:
 *   func_02017DBC  0x02017DBC  thumb
 *   func_02017E88  0x02017E88  thumb
 *   func_02017E64  0x02017E64  thumb
 *   func_02017C50  0x02017C50  thumb
 *   func_02017CC8  0x02017CC8  thumb
 *   func_02045F5C  0x02045F5C  arm
 *   func_02017DE4  0x02017DE4  thumb
 *   g_020A7370     0x020A7370  data
 *   g_021462F0     0x021462F0  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sav;
extern u32 func_02017DBC(struct Sav *p);
extern u32  func_02017E88(void *a0, u32 a1, u32 a2);
extern void func_02017E64(void *a0, u32 a1, u32 a2);
extern void func_02017C50(void *a0, u32 a1, u32 a2);
extern void func_02017CC8(void *a0, u32 a1, u32 a2);
extern void func_02045F5C(void *a0, u32 a1, void *a2, u32 a3);
extern u32 func_02017DE4(struct Sav *p, u32 f);

extern void *g_020A7370;
extern u8    g_021462F0[];

u32 func_02017900(void *a0, u32 a1)
{
    u8  v = (u8)func_02017DBC(a0);
    u16 w = (u16)func_02017E88(a0, 5, 0);

    if (w != a1) {
        u32 x;

        func_02017E88(a0, 0x6f, 0);
        x = func_02017E88(a0, 0x75, 0);
        func_02017E64(a0, 5, a1);
        func_02017C50(a0, a1, w);
        func_02017CC8(a0, a1, w);
        if (x == 0) {
            func_02045F5C(g_020A7370, a1, g_021462F0, 0x20);
            func_02017E64(a0, 0x74, (u32)g_021462F0);
        }
    }
    return func_02017DE4(a0, v);
}
