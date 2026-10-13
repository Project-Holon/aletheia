/*
 * function: func_021F199C
 * address:  0x021F199C
 * packet:   pkt_ov032_021F199C
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F199C 0x021F199C thumb
 *   GAME_BEACON_ACCESSOR_GetDistributionSerial 0x02165EBC thumb ov010
 *   GAME_BEACON_ACCESSOR_GetInfoVersion 0x02165D20 thumb ov010
 *   GPOWER_GetActiveIdOfSameType  0x02010EA0 thumb
 *   GAME_BEACON_ACCESSOR_RegisterRecordWords 0x02165FCC thumb ov010
 *   func_0201F250 0x0201F250 thumb
 *   func_021F1A28 0x021F1A28 thumb
 */
#include "../include/Obj00007.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Rec;
extern u16 GAME_BEACON_ACCESSOR_GetDistributionSerial(struct Rec *r);
extern u8 GAME_BEACON_ACCESSOR_GetInfoVersion(struct Rec *r);
extern u8 GPOWER_GetActiveIdOfSameType(int slot, u8 *rec);
extern void GAME_BEACON_ACCESSOR_RegisterRecordWords(void *r, u32 win, u32 heap);
struct WordSet;
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021F1A28(char *p, int b, u8 c, int *r);

int func_021F199C(char *p, void *x, int flag)
{
    int r;

    if (flag)
        r = GAME_BEACON_ACCESSOR_GetDistributionSerial(x);
    else
        r = GAME_BEACON_ACCESSOR_GetInfoVersion(x);
    if (r == 0x30 || r > 0x2d)
        return 0;
    if (r == GPOWER_GetActiveIdOfSameType(r, *(u8 * *)&((struct Obj00007 *)p)->f24))
        return 0;
    GAME_BEACON_ACCESSOR_RegisterRecordWords(x, *(u32 *)&((struct Obj00007 *)p)->f110, ((struct Obj00007 *)p)->f96);
    func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00007 *)p)->f110), (void *)(*(u32 *)&((struct Obj00007 *)p)->f11C), (void *)(*(u32 *)&((struct Obj00007 *)p)->f118));
    func_021F1A28(p, r, 1, (int *)(p + 0xa8));
    return 1;
}
