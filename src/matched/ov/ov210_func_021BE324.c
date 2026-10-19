/*
 * function: ZKNSEARCH_MAIN_ToggleSaveFlag
 * address: 0x021BE324
 * packet: pkt_ov210_021BE324
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 021BE366..021BE368 is zero alignment padding.
 * proof: 071CC forwards to 0319A4, which forwards fixed r1=0x36 to
 *        033B68; their full matched bodies use no incoming r2/r3.
 * ABI: 02012BF8's full 20-byte body preserves r1 across EC0/C404 and
 *      supplies only r0/r1 to C44C. EC0 reads only r0; C404 forwards r0
 *      through C40C/071CC with fixed r1=0x36. C44C reads r0/r1 only.
 *      Legacy trailing a2/a3 are omitted; all original visible inputs remain.
 * symbols:
 *   GAME_DATA_ContainsRecentId 0x02012BF8 thumb
 *   GAME_DATA_SetRecentId 0x02012BE0 thumb
 *   ZKNSEARCH_MAIN_SetActorAnimAuto 0x021BEDB8 thumb ov210
 */
#include "../include/Obj10921.h"
typedef unsigned char u8;
extern int GAME_DATA_ContainsRecentId(int a0, int a1);
extern void GAME_DATA_SetRecentId(void *, unsigned, unsigned);
extern void ZKNSEARCH_MAIN_SetActorAnimAuto(int p, int i, int v);
void ZKNSEARCH_MAIN_ToggleSaveFlag(u8 *p)
{
    if (GAME_DATA_ContainsRecentId((int)(**(void ** *)&((struct Obj10921 *)p)->f0), 16) == 1) {
        GAME_DATA_SetRecentId(**(void ** *)&((struct Obj10921 *)p)->f0, 16, 0);
        ZKNSEARCH_MAIN_SetActorAnimAuto((int)p, 4, 6);
    } else {
        GAME_DATA_SetRecentId(**(void ** *)&((struct Obj10921 *)p)->f0, 16, 1);
        ZKNSEARCH_MAIN_SetActorAnimAuto((int)p, 4, 7);
    }
}
