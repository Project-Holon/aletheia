/*
 * function: SCRCMD_CountBattleBoxOtherOtIds
 * address:  0x021CF9AC
 * packet:   pkt_ov021_021CF9AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Counts the six entries for which SCRCMD_AddOtherOtId accepts the value read from them.
 *
 * symbols:
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200BAC8  0x0200BAC8  thumb
 *   func_0200BBEC  0x0200BBEC  thumb
 *   func_02017E88  0x02017E88  thumb
 *   SCRCMD_AddOtherOtId  0x021CFA04  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Big;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200BAC8(void *p);
extern void *func_0200BBEC(void *base, u32 i, u32 j);
extern u32   func_02017E88(void *p, u32 id, u32 v);
extern int SCRCMD_AddOtherOtId(int a, int v, void *l);

int SCRCMD_CountBattleBoxOtherOtIds(void *a, void *heap, int x, int y)
{
    void *h;
    int i;
    int n;

    h = func_0200BAC8(GAME_DATA_GetSaveControl(heap));
    n = 0;
    for (i = 0; i < 6; i++) {
        void *p = func_0200BBEC(h, x, i);
        if (func_02017E88(p, 0xa9, 0) != 0) {
            u32 v = func_02017E88(p, 7, 0);
            if (SCRCMD_AddOtherOtId((int)a, v, (void *)y) != 0) {
                n++;
            }
        }
    }
    return n;
}
