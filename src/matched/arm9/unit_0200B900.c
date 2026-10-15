/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x0200B900
 * packet:   pkt_0200B448
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: BATTLE_REC_Decode, BATTLE_REC_Encode, BATTLE_REC_GetWork, BATTLE_REC_GetBody,
 *           BATTLE_REC_GetHeader, BATTLE_REC_GetHeaderOf
 *
 * 56 bytes, 0x0200B900..0x0200B938, 6 functions, none of which carries a
 * label in the generated listing.
 *
 * Four accessors on the single object whose address lives at 0x0214616C and
 * two forwarders to a pair of ARM routines.  The three pool words holding
 * 0x0214616C inside this range are not its only ones: seven literal pools in
 * the image hold that address, so the `literal` class keeps a witness outside
 * whatever is compared.
 *
 * The two forwarders are written with their parameters declared and **not**
 * passed on, and that is a property of the codegen rather than a claim about
 * the callees.  This front end only emits the pool-word tail call
 * `ldr r3, [pc, #0]; bx r3` when there is no argument register to set up; a
 * call that names its arguments, even when every one of them is already in
 * the right register, comes out as `push {r3, lr}; blx; pop {r3, pc}`, which
 * is four instructions and eight bytes wrong.  The callers do pass four
 * arguments through BATTLE_REC_Decode (BATTLE_REC_SetData sets r0 through r3 before
 * the `bl`), so the forwarding is real and is simply not expressible here.
 * See docs/idioms/tail-call-is-a-pool-word-and-bx.md.
 *
 * symbols:
 *   GF_STANDARD_ShuffleEx  0x0203F37C  arm
 *   GF_STANDARD_Shuffle  0x0203F328  arm
 *   pBattleRec  0x0214616C  data
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern void GF_STANDARD_ShuffleEx(void *p, u32 size, u32 seed);
typedef unsigned short u16;
extern void GF_STANDARD_Shuffle(u16 *p, u32 size, u32 seed);

struct ObjC4 {
    u8 unk00[0x80];
    u8 unk80[0x44];
    u8 unkC4[0x44];
};

extern struct ObjC4 *pBattleRec;

void BATTLE_REC_Decode(void *a, u32 b, u32 c)
{
    GF_STANDARD_ShuffleEx(a, b, c);
}

void BATTLE_REC_Encode(void *a, u32 b, u32 c)
{
    GF_STANDARD_Shuffle(a, b, c);
}

struct ObjC4 *BATTLE_REC_GetWork(void)
{
    return pBattleRec;
}

u8 *BATTLE_REC_GetBody(void)
{
    return pBattleRec->unkC4;
}

u8 *BATTLE_REC_GetHeader(void)
{
    return pBattleRec->unk80;
}

u8 *BATTLE_REC_GetHeaderOf(struct ObjC4 *p)
{
    return p->unk80;
}
