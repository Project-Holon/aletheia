/*
 * function: SYMBOL_SAVE_RemoveSlotAndCommit
 * address:  0x0200E18C
 * packet:   pkt_0200E024
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Runs SYMBOL_SAVE_FinalizeChecksum, then SYMBOL_SAVE_RemoveSlot, then the initialiser.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SYMBOL_SAVE_RemoveSlotAndCommit.c \
 *       --func SYMBOL_SAVE_RemoveSlotAndCommit --addr 0x0200E18C --thumb --cc 1.1p1
 *
 * symbols:
 *   SYMBOL_SAVE_UpdateChecksum  0x0200E024  thumb
 *   SYMBOL_SAVE_FinalizeChecksum  0x0200E06C  thumb
 *   SYMBOL_SAVE_RemoveSlot  0x0200E124  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void SYMBOL_SAVE_FinalizeChecksum(char *p);
extern void SYMBOL_SAVE_RemoveSlot(u32 *p, u32 a);
extern void SYMBOL_SAVE_UpdateChecksum(void *obj);

void SYMBOL_SAVE_RemoveSlotAndCommit(u32 *p, u32 a)
{
    SYMBOL_SAVE_FinalizeChecksum((char *)p);
    SYMBOL_SAVE_RemoveSlot((u32 *)p, a);
    SYMBOL_SAVE_UpdateChecksum(p);
}
