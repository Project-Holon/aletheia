#ifndef GAME_OV135_WORLDTRADE_ADAPTER_H
#define GAME_OV135_WORLDTRADE_ADAPTER_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of worldtrade_adapter.c, prototypes copied from their definitions. */

struct Strbuf;
struct WorldtradeObj;

struct PokemonParam;
struct WordSet;
struct MsgBank;
struct BoxPokemon;

#include "../ov135/worldtrade_types.h"
#include "../types.h"

void WORLDTRADE_ADAPTER_RemovePartyMon(WorldtradeWork *p, int flag);
void WORLDTRADE_ADAPTER_RegisterReceivedMon(WorldtradeWork *p, void *mon, u32 box, int hatch);
void WORLDTRADE_ADAPTER_RegisterReceivedMonB(WorldtradeWork *p,void *mon,void *unused2,void *unused3,u32 index);
void WORLDTRADE_ADAPTER_StoreDateAsLastId(void *p, int which);
void WORLDTRADE_ADAPTER_RegisterLanguageVersion(void *obj,WorldtradeEntry *p);
int WORLDTRADE_ADAPTER_CheckPartyHasOther(WorldtradeWork *p, void *mon);
void WORLDTRADE_ADAPTER_SetPair(WorldtradeWork *p, u16 stateAfterSaveWait, u16 stateAfterSave);
u32 WORLDTRADE_ADAPTER_CanProceed(WorldtradeWork *p);
void WORLDTRADE_ADAPTER_CreateMail(void *mon, u32 heap);
void WORLDTRADE_ADAPTER_CreateMonFromBox(u32 wordSet, u32 slot, u32 boxMon);
void *WORLDTRADE_ADAPTER_AllocHeapBuf(u32 heap);
void WORLDTRADE_ADAPTER_CopyMon(u32 src, struct PokemonParam *dst);
void WORLDTRADE_ADAPTER_ClearWindowScreen(void *win, int kind);
u32 WORLDTRADE_ADAPTER_CreateString(struct WordSet *wordSet, struct MsgBank *bank, u32 msgId, u32 heapId);
void WORLDTRADE_ADAPTER_CopyBoxMon(u8 *p, struct PokemonParam *dst);
struct BoxPokemon *WORLDTRADE_ADAPTER_GetBoxParam(void *mon);
int WORLDTRADE_ADAPTER_StrObjThunk(u32 *p, u32 unused1, struct Strbuf *str, u32 margin);
void WORLDTRADE_ADAPTER_InitPrinter(Printer *ctx, u32 arg);
void WORLDTRADE_ADAPTER_ExitPrinter(Printer *p);
void WORLDTRADE_ADAPTER_UpdatePrinter(Printer *p);
u32 WORLDTRADE_ADAPTER_IsStreamBusy(PrintStreamCtx *p);
u32 WORLDTRADE_ADAPTER_QueuePrintDefaultColor(void *win,u8 unused1,void *str,u32 x,u32 y,void *printer);
void WORLDTRADE_ADAPTER_StartPrintStream(void *win, unsigned unused1, struct Strbuf *str, int x, int y, PrintStreamCtx *p);
u32 WORLDTRADE_ADAPTER_PrintQueColor(void *win, u8 unused1, struct Strbuf *str, u32 x, u32 y, u32 unused2, u16 color, Printer *printer);
void WORLDTRADE_ADAPTER_DeletePrintStream(struct WorldtradeObj *p);
MsgSys *WORLDTRADE_ADAPTER_InitMessageSystem(u32 unused1, u32 unused2, u32 unused3, u16 heap);
void WORLDTRADE_ADAPTER_ExitMessageSystem(MsgSys *p);
void WORLDTRADE_ADAPTER_UpdateMessageSystem(MsgSys *msgSys);
void WORLDTRADE_ADAPTER_PrintNumber(MsgSys *ctx, u32 num, u32 digits, u32 mode, void *win, int x, int y);
void WORLDTRADE_ADAPTER_QueueMessagePrint(MsgSys *p, int unusedArg, void *win, int x, int y);
/* END mkheaders: generated region */

#endif
