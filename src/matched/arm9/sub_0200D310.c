/*
 * function: ZUKAN_SAVE_CountCaughtRegionalCounted
 * address:  0x0200D310
 * packet:   pkt_0200D2D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZUKAN_SAVE_IsCountedForRegionalCompletion   0x0200C7A0  thumb
 *   ZUKAN_SAVE_IsCaught   0x0200CED4  thumb
 *   POKE_PERSONAL_LoadFormTable   0x0201AF80  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned short u16;

typedef unsigned int   u32;
struct Blk37;
extern u32 ZUKAN_SAVE_IsCaught(struct Blk37 *p, u16 id);
extern int ZUKAN_SAVE_IsCountedForRegionalCompletion(u32 v);
extern u16 *POKE_PERSONAL_LoadFormTable(u32 heap, u16 *countOut);
extern u32 func_020307B0(void *p);

int ZUKAN_SAVE_CountCaughtRegionalCounted(void *a0, int a1)
{
    u16 *t = POKE_PERSONAL_LoadFormTable(a1, 0);
    u16 i;
    u16 n = 0;

    for (i = 1; i <= 0x289; i++) {
        if (ZUKAN_SAVE_IsCaught(a0, i) != 1) {
            continue;
        }
        if (t[i] == 0x3e7) {
            continue;
        }
        if (ZUKAN_SAVE_IsCountedForRegionalCompletion(i) == 1) {
            n++;
        }
    }
    func_020307B0(t);
    return n;
}
