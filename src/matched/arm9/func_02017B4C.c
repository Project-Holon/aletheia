/*
 * function: POKE_TOOL_HatchBoxEgg
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
 * three caller arguments to SAVE_EVENT_WriteMode before releasing the lock.
 *
 * WHAT WAS WRONG IN THE EARLIER NOTE, AND WHAT CLOSED IT
 * -----------------------------------------------------
 * docs/notes/POKE_TOOL_HatchBoxEgg.diff.c.txt records this function as a 104-byte
 * DIFF at 120 bytes against 124, and that source is four bytes short with the
 * whole body misaligned.  The note's skeleton is correct; only two
 * declarations are wrong, and they are the whole difference.
 *
 * The note declares the two accessor externs as returning narrow types --
 * `u8 POKE_TOOL_DecodeBoxParam(...)` and `u16 func_02017E88(...)` -- and assigns their
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
 * The third argument of POKE_TOOL_SetBoxValue is a plain u32 and not a pointer: the
 * note spells it `void *` and passes `(void *)0x78`, which compiles the same
 * here but is a claim the bytes do not support, since id 9 is a byte field.
 *
 * Nothing here is version specific: 5, 9, 0x4C, 0x6F and 0x74 are field
 * selectors and 0x20 is a halfword count.  gSpeciesNameBank and gNameBuf are
 * globals, so their addresses are build properties.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_TOOL_HatchBoxEgg.c \
 *       --func POKE_TOOL_HatchBoxEgg --addr 0x02017B4C --cc 1.1p1 --thumb
 *
 * symbols:
 *   POKE_TOOL_DecodeBoxParam  0x02017DBC  thumb
 *   func_02017E88  0x02017E88  thumb
 *   POKE_TOOL_SetBoxValue  0x02017E64  thumb
 *   MSGDATA_ReadUnits  0x02045F5C  arm
 *   SAVE_EVENT_WriteMode  0x0202F1B4  thumb
 *   POKE_TOOL_EncodeBoxParam  0x02017DE4  thumb
 *   gSpeciesNameBank     0x020A7370  data
 *   gNameBuf     0x021462F0  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sav;
extern u32 POKE_TOOL_DecodeBoxParam(struct Sav *p);
extern u32  func_02017E88(void *a0, u32 a1, u32 a2);
extern void POKE_TOOL_SetBoxValue(void *a0, u32 a1, u32 a2);
struct MsgData;
extern void MSGDATA_ReadUnits(struct MsgData *msg, u32 msgIndex, u16 *str, u32 maxLen);
extern void SAVE_EVENT_WriteMode(u32 a, u32 b, u32 c, u32 d, u32 e);
extern u32 POKE_TOOL_EncodeBoxParam(struct Sav *p, u32 f);

extern void *gSpeciesNameBank;
extern u8    gNameBuf[];

u32 POKE_TOOL_HatchBoxEgg(void *a0, u32 a1, u32 a2, u32 a3)
{
    u8  v = (u8)POKE_TOOL_DecodeBoxParam(a0);
    u16 w = (u16)func_02017E88(a0, 5, 0);

    func_02017E88(a0, 0x6f, 0);
    POKE_TOOL_SetBoxValue(a0, 0x4c, 0);
    POKE_TOOL_SetBoxValue(a0, 9, 0x78);
    MSGDATA_ReadUnits(gSpeciesNameBank, w, (u16 *)gNameBuf, 0x20);
    POKE_TOOL_SetBoxValue(a0, 0x74, (u32)gNameBuf);
    SAVE_EVENT_WriteMode((u32)a0, 2, a1, a2, a3);
    return POKE_TOOL_EncodeBoxParam(a0, v);
}
