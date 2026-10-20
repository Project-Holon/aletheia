#ifndef GAME_OV036_DAILY_LAYOUT_H
#define GAME_OV036_DAILY_LAYOUT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of daily_layout.c, prototypes copied from their definitions. */

struct DailyLayoutWork;
struct CellDeck;
typedef struct DailyLayoutWork DailyLayoutWork;
typedef struct CellDeck CellDeck;

void DAILY_LAYOUT_Generate(DailyLayoutWork *work);
void DAILY_LAYOUT_PickDistinct(int poolSize, int pickCount, unsigned char *scratch, unsigned char *picks);
void DAILY_LAYOUT_ResetDeck(CellDeck *deck);
int DAILY_LAYOUT_FindPoolCell(CellDeck *deck, int cell);
int DAILY_LAYOUT_GetPoolCell(CellDeck *deck, int poolIdx);
int DAILY_LAYOUT_RemovePoolCell(CellDeck *deck, int poolIdx);
int DAILY_LAYOUT_DealCells(CellDeck *deck);
/* END mkheaders: generated region */

#endif
