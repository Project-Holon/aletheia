/*
 * function: disp
 * address:  0x021D1868
 * packet:   pkt_ov016_021D1868
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      disp (libdwcutil.TWL.HYB.a window.o)
 *
 * The two u16 screen-x lookups are hoisted into named locals before the y1
 * clamp: spelled inline the 1.1p1 scheduler issues the &r add and the clamp
 * cmp ahead of the pair of ldrh, giving 10 reordered instructions at +0128.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021D1868.c \n *       --func disp --addr 0x021D1868 --region ov016 --arm --cc 1.1p1 --lang c99
 *
 * symbols:
 *   DWCi_CELLlSetPosition  0x021D5118  arm  ov016
 *   func_021D19F4  0x021D19F4  arm  ov016
 *   DWCi_InputRect  0x021D5FF4  arm  ov016
 *   DWCi_GXlSetWndPosition  0x021D60EC  arm  ov016
 *   gWindowWork  0x021DE658  data
 *   sWindowTable11  0x021DA9FE  data
 *   sWindowTable2  0x021DA9A6  data
 *   sWindowTable4  0x021DA9B4  data
 *   sWindowTable14  0x021DAA2E  data
 *   sWindowTable13  0x021DAA18  data
 *   sWindowTable12  0x021DAA16  data
 */

#include "../include/G_MemWinT.h"
#include "../include/G_CoordT.h"
#include "../include/G_021DAA2E.h"

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u16 x;
    u16 y;
} CoordT;

typedef struct {
    u16 l, t, r, b;
} RectT;

typedef struct {
    void *cellWin;
    void *cellChar;
    void *button[2];
    void *canv;
    void *task;
    u16 countWait;
    signed char count;
    signed char input;
    u8 type;
    u8 wait;
    u8 dark;
} MemWinT;

extern void DWCi_CELLlSetPosition(void *cell, int idx, int x, int y);
extern void func_021D19F4(void *cell, int y);
extern void DWCi_InputRect(int x0, int y0, int x1, int y1, RectT *r);
extern void DWCi_GXlSetWndPosition(int a, int b, RectT *r);
extern struct MemWinT *gWindowWork;
extern struct CoordT sWindowTable11[];
extern u8 sWindowTable2[6];
extern u8 sWindowTable4[][2];
extern struct G_021DAA2E sWindowTable14[][2];
extern u16 sWindowTable13[][2];
extern u16 sWindowTable12[][2];

void disp(int y)
{
    RectT r;
    int y0;
    int y1;
    int i;
    u16 x1, x2;

    DWCi_CELLlSetPosition(gWindowWork->cellWin, -1, sWindowTable11[gWindowWork->type].x, y);
    DWCi_CELLlSetPosition(gWindowWork->cellChar, -1, sWindowTable11[gWindowWork->type].x + 8, y + 8);
    func_021D19F4(gWindowWork->cellWin, y);
    func_021D19F4(gWindowWork->cellChar, y);
    for (i = 0; i < sWindowTable2[gWindowWork->type]; i++) {
        int idx = sWindowTable4[gWindowWork->type][i];
        DWCi_CELLlSetPosition(gWindowWork->button[i], -1,
                      sWindowTable14[gWindowWork->type][idx].x,
                      y + sWindowTable14[gWindowWork->type][idx].y - sWindowTable11[gWindowWork->type].y);
        func_021D19F4(gWindowWork->button[i], y);
    }
    y0 = (u8)y;
    if (y0 >= 0xc0) {
        y1 = 0;
        y0 = y1;
    } else {
        y1 = y0 + sWindowTable13[gWindowWork->type][0];
    }
    x1 = sWindowTable11[gWindowWork->type].x;
    x2 = sWindowTable12[gWindowWork->type][0];
    if (y1 > 0xc0)
        y1 = 0xc0;
    DWCi_InputRect(x1, y0, x1 + x2, y1, &r);
    DWCi_GXlSetWndPosition(0, 0, &r);
}
