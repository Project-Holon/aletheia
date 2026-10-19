/*
 * function: pushButton
 * address:  0x021D1A80
 * packet:   pkt_ov016_021D1A80
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      pushButton (libdwcutil.TWL.HYB.a window.o)
 *
 * symbols:
 *   DWCi_CELLlGetObj  0x021D4FE0  arm  ov016
 *   DWCi_CEINlSet  0x021D52D4  arm  ov016
 *   DWCi_CELLlSetPosition  0x021D5118  arm  ov016
 *   DWCi_CELLlSetPriority  0x021D51F0  arm  ov016
 *   gWindowWork     0x021DE658  data
 *   sWindowTable7     0x021DA9C8  data
 *   sWindowTable4     0x021DA9B4  data
 *   sWindowTable14     0x021DAA2E  data
 *   g_021DAA30     0x021DAA30  data
 */

#include "../include/G_MemWinT.h"

typedef unsigned char u8;
typedef unsigned short u16;

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

extern char *DWCi_CELLlGetObj(char *p, unsigned int i);
extern void DWCi_CEINlSet();
extern void DWCi_CELLlSetPosition(void *cell, int idx, int x, int y);
extern void DWCi_CELLlSetPriority(void *cell, int idx, int priority);
extern struct MemWinT *gWindowWork;
extern u8 sWindowTable7[][2];
extern u8 sWindowTable4[][2];
extern u16 sWindowTable14[][4];
extern u16 g_021DAA30[][4];

void pushButton(int idx)
{
    void *obj;

    obj = DWCi_CELLlGetObj(gWindowWork->button[idx], 0);
    DWCi_CEINlSet(0, sWindowTable7[gWindowWork->type][idx] + 1, obj);
    DWCi_CELLlSetPosition(gWindowWork->button[idx], -1,
                  sWindowTable14[gWindowWork->type][sWindowTable4[gWindowWork->type][idx] * 2],
                  g_021DAA30[gWindowWork->type][sWindowTable4[gWindowWork->type][idx] * 2]);
    DWCi_CELLlSetPriority(gWindowWork->button[idx], -1, 0);
}
