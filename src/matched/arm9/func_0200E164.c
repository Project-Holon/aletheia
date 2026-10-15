/*
 * function: SYMBOL_SAVE_RemoveSlotAndFind
 * address:  0x0200E164
 * packet:   pkt_0200E024
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Runs SYMBOL_SAVE_FinalizeChecksum, then SYMBOL_SAVE_FindFreeSlot, then the initialiser, returning
 * the middle result.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SYMBOL_SAVE_RemoveSlotAndFind.c \
 *       --func SYMBOL_SAVE_RemoveSlotAndFind --addr 0x0200E164 --thumb --cc 1.1p1
 *
 * symbols:
 *   SYMBOL_SAVE_UpdateChecksum  0x0200E024  thumb
 *   SYMBOL_SAVE_FinalizeChecksum  0x0200E06C  thumb
 *   SYMBOL_SAVE_FindFreeSlot  0x0200E0E8  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void SYMBOL_SAVE_FinalizeChecksum(char *p);
struct Slot;
extern u32  SYMBOL_SAVE_FindFreeSlot(const struct Slot *p, int a);
extern void SYMBOL_SAVE_UpdateChecksum(void *obj);

u32 SYMBOL_SAVE_RemoveSlotAndFind(u32 *p, u32 a)
{
    SYMBOL_SAVE_FinalizeChecksum((char *)p);
    {
        u32 r = SYMBOL_SAVE_FindFreeSlot((const struct Slot *)p, (int)a);

        SYMBOL_SAVE_UpdateChecksum(p);
        return r;
    }
}
