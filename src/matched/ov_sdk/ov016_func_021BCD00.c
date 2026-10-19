/*
 * function: taskMain
 * address:  0x021BCD00
 * packet:   pkt_ov016_021BCD00
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      taskMain (libdwcutil.TWL.HYB.a button.o)
 *
 * symbols:
 *   DWCi_Coord2Rect  0x021D600C  arm  ov016
 *   DWCi_TPlCheckTrigger  0x021D696C  arm  ov016
 *   DWCi_CELLlGetObj  0x021D4FE0  arm  ov016
 *   DWCi_CEINlSet  0x021D52D4  arm  ov016
 *   DWCi_CELLlSetPosition  0x021D5118  arm  ov016
 *   DWCi_CELLlSetPriority  0x021D51F0  arm  ov016
 *   DWCi_TSKlForm  0x021D7680  arm  ov016
 *   func_021BCF5C  0x021BCF5C  arm  ov016
 *   gButtonWork  0x021DE508  data
 *   sButtonCountByKind  0x021DA008  data
 *   sButtonPositions  0x021DA010  data
 *   sButtonPositionIndex  0x021DA026  data
 *   sButtonSize  0x021DA004  data
 *   sButtonCellIds  0x021DA018  data
 */

#include "../include/G_tagMEMBTN.h"

typedef struct { unsigned short l, t, r, b; } Rect;
typedef struct { unsigned short x, y; } Coord;

typedef unsigned short u16;
struct tagCOORD;
struct tagRECT;
extern void DWCi_Coord2Rect(const struct tagCOORD *coord, const struct tagCOORD *size, struct tagRECT *rect);
extern int DWCi_TPlCheckTrigger(u16 *a);
extern char *DWCi_CELLlGetObj(char *p, unsigned int i);
extern void DWCi_CEINlSet(int lcd, int idx, void *obj);
extern void DWCi_CELLlSetPosition(void *cell, int idx, int x, int y);
extern void DWCi_CELLlSetPriority(void *cell, int idx, int priority);
extern void *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
extern void func_021BCF5C(void *task);
extern struct tagMEMBTN *gButtonWork;
extern unsigned char sButtonCountByKind[7];
extern Coord sButtonPositions[2];
extern unsigned char sButtonPositionIndex[7][2];
extern Coord sButtonSize;
extern unsigned char sButtonCellIds[7][2];

void taskMain(void)
{
    Rect r;
    int btnNum;
    int i;

    btnNum = sButtonCountByKind[gButtonWork->kind];
    if (!gButtonWork->disable) {
        if (gButtonWork->input != -1)
            return;
        for (i = 0; i < btnNum; i++) {
            DWCi_Coord2Rect((const struct tagCOORD *)(&sButtonPositions[sButtonPositionIndex[gButtonWork->kind][i]]), (const struct tagCOORD *)(&sButtonSize), (struct tagRECT *)(&r));
            if (DWCi_TPlCheckTrigger((u16 *)(&r))) {
                if (gButtonWork->release)
                    break;
                {
                    int cellIdx = sButtonCellIds[gButtonWork->kind][i];
                    DWCi_CEINlSet(0, cellIdx + 1, DWCi_CELLlGetObj(gButtonWork->cellButton[i], 0));
                }
                DWCi_CELLlSetPosition(gButtonWork->cellButton[i], -1,
                              sButtonPositions[sButtonPositionIndex[gButtonWork->kind][i]].x,
                              sButtonPositions[sButtonPositionIndex[gButtonWork->kind][i]].y);
                DWCi_CELLlSetPriority(gButtonWork->cellButton[i], -1, 1);
                gButtonWork->release = DWCi_TSKlForm(0, (void (*)(void *, void *))func_021BCF5C, 0, 0x6e);
                gButtonWork->input = i;
                return;
            }
        }
    }
    gButtonWork->input = -1;
}
