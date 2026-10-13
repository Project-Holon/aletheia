/*
 * function: PLIST_BATTLE_UpdateTeamPanel
 * address:  0x021BD1BC
 * packet:   pkt_ov091_021BD1BC
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PLIST_BATTLE_UpdateMiniCell  0x021BD480  thumb  ov091
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 */
#include "../include/Obj09934.h"

typedef unsigned char u8;

struct PrintSys;
extern unsigned int PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
struct Cfg;
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
typedef unsigned int   u32;
extern void func_02041B6C(u32 bit);
extern void PLIST_BATTLE_UpdateMiniCell(char *a, int *b);

void PLIST_BATTLE_UpdateTeamPanel(char *a, int *b)
{
    u8 i;
    int q;
    for (i = 0; i < 6; i++) {
        if (b[2 + i] != 0)
            PLIST_BATTLE_UpdateMiniCell(a, (int *)b[2 + i]);
    }
    if (b[0] == 1 && PRINTSYS_QUE_IsExistTarget((struct PrintSys *)(((struct Obj09934 *)a)->f140), (void *)BMP_WIN_GetBmp((struct Descriptor *)b[1])) == 0) {
        q = b[1];
        b[0] = 0;
        BMP_WIN_TransferChars((struct Descriptor *)q);
        BMP_WIN_MakeScreen((struct Cfg *)q);
        func_02041B6C(BMP_WIN_GetBgLayer((struct Descriptor *)q));
    }
}
