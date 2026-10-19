/*
 * function: taskMain
 * address:  0x021D16B0
 * packet:   pkt_ov016_021D16B0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      taskMain (libdwcutil.TWL.HYB.a window.o)
 *
 * symbols:
 *   DWCi_Coord2Rect  0x021D600C  arm  ov016
 *   DWCi_TPlCheckTrigger  0x021D696C  arm  ov016
 *   DWCi_IPTlCheckTrigger  0x021D6824  arm  ov016
 *   func_021D1A80  0x021D1A80  arm  ov016
 *   gWindowWork  0x021DE658  data
 *   sWindowTable2  0x021DA9A6  data
 *   sWindowTable14  0x021DAA2E  data
 *   sWindowTable4  0x021DA9B4  data
 *   sWindowTable8  0x021DA9D2  data
 *   sWindowTable5  0x021DA9BE  data
 *   sWindowTable6  0x021DA9BF  data
 */

#include "../include/G_MemWinT.h"
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

struct tagCOORD;
struct tagRECT;
extern void DWCi_Coord2Rect(const struct tagCOORD *coord, const struct tagCOORD *size, struct tagRECT *rect);
extern int DWCi_TPlCheckTrigger(u16 *a);
extern int DWCi_IPTlCheckTrigger(unsigned int f);
extern void func_021D1A80(int idx);
extern struct MemWinT *gWindowWork;
extern u8 sWindowTable2[6];
extern struct G_021DAA2E sWindowTable14[][2];
extern u8 sWindowTable4[][2];
extern CoordT sWindowTable8[];
extern signed char sWindowTable5[][2];
extern signed char sWindowTable6[][2];

void taskMain(void)
{
    RectT r;
    int i;

    for (i = 0; i < sWindowTable2[gWindowWork->type]; i++) {
        DWCi_Coord2Rect((const struct tagCOORD *)(&sWindowTable14[gWindowWork->type][sWindowTable4[gWindowWork->type][i]]),
                      (const struct tagCOORD *)(&sWindowTable8[gWindowWork->type]), (struct tagRECT *)(&r));
        if (DWCi_TPlCheckTrigger((u16 *)(&r))) {
            gWindowWork->input = i;
            break;
        }
    }
    if (DWCi_IPTlCheckTrigger(1))
        gWindowWork->input = sWindowTable5[gWindowWork->type][0];
    if (DWCi_IPTlCheckTrigger(2))
        gWindowWork->input = sWindowTable6[gWindowWork->type][0];
    for (i = 0; i < sWindowTable2[gWindowWork->type]; i++) {
        if (i == gWindowWork->input) {
            func_021D1A80(i);
            return;
        }
    }
    gWindowWork->input = -1;
}
