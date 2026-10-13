/*
 * function: UNION_MSG_SetGreetingWordFlag
 * address:  0x0217EFE0
 * packet:   pkt_ov019_0217EFE0
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   PMS_WORD_GetSaveData  0x02024988  thumb
 *   PMS_WORD_SetFlag  0x020249A0  thumb
 *   d_0218044C     0x0218044C  data
 */

struct Big;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *PMS_WORD_GetSaveData(int a0);
extern void PMS_WORD_SetFlag(int *p, int bit);
extern int d_0218044C[];

void UNION_MSG_SetGreetingWordFlag(int a, unsigned int n)
{
    int r;
    unsigned short i;
    r = (int)PMS_WORD_GetSaveData((int)GAME_DATA_GetSaveControl((struct Big *)a));
    i = n - 1;
    if (n >= 1 && n <= 8) {
        if (i < 8) {
            PMS_WORD_SetFlag((int *)r, d_0218044C[i]);
            return;
        }
        PMS_WORD_SetFlag((int *)r, 7);
        return;
    }
    PMS_WORD_SetFlag((int *)r, 7);
}
