/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x0200B400
 * packet:   pkt_0200B400
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: BATTLE_REC_AllocWork, func_0200B424, BATTLE_REC_Delete, BATTLE_REC_GetWorkSize
 *
 * 72 bytes, 0x0200B400..0x0200B448, 4 functions, three of which carry no
 * label in the generated listing: the last three save nothing or nothing but
 * r4, so the range arrives as a run of `.word`s.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * alias: this continues "battle_rec.c", whose constructor BATTLE_REC_Create is
 * the last function of src/matched/unit_0200B394.c and is what BATTLE_REC_AllocWork
 * calls.  The object it builds is hung off the single global at 0x0214616C,
 * the same one src/matched/unit_0200B900.c reads.
 *
 * BATTLE_REC_AllocWork frees the old object before building the new one and clears
 * the global in between, which is a guard the source wrote rather than dead
 * code: the store of NULL is inside the `if`, and the fresh pointer is
 * assigned unconditionally afterwards.  The address of the global is
 * materialised twice, once for the test and free and once for the final
 * store, because the pool word is reloaded after the call rather than kept
 * in the callee-saved register that already holds it.
 *
 * BATTLE_REC_GetWorkSize returns 0x18A4 out of its own pool word, which is the
 * "a block file opens with a function returning its own size" shape this
 * region keeps producing, except that here the size belongs to whatever the
 * next file allocates rather than to the 0x2000 buffer above it.
 *
 * symbols:
 *   func_020307B0   0x020307B0  arm
 *   pBattleRec   0x0214616C  data
 *   BATTLE_REC_Create  0x0200B3DC  thumb
 */

typedef unsigned int u32;

extern u32 func_020307B0(void *p);
extern void *BATTLE_REC_Create(u32 heap);

extern void *pBattleRec;

void BATTLE_REC_AllocWork(u32 heap)
{
    if (pBattleRec != 0) {
        func_020307B0(pBattleRec);
        pBattleRec = 0;
    }
    pBattleRec = BATTLE_REC_Create(heap);
}

void func_0200B424(void)
{
    func_020307B0(pBattleRec);
    pBattleRec = 0;
}

void BATTLE_REC_Delete(void *p)
{
    func_020307B0(p);
}

u32 BATTLE_REC_GetWorkSize(void)
{
    return 0x18A4;
}
