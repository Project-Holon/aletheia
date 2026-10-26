#ifndef GAME_OV121_MYSTERY_ALBUM_H
#define GAME_OV121_MYSTERY_ALBUM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of mystery_album.c, prototypes copied from their definitions. */

struct MysteryAlbumWork;
struct MysteryAlbumEntry;
struct MysteryAlbumCard;
struct MysteryAlbumSlotWork;
struct MysteryAlbumView;
struct TcbTask;
typedef struct MysteryAlbumWork MysteryAlbumWork;
typedef struct MysteryAlbumEntry MysteryAlbumEntry;
typedef struct MysteryAlbumCard MysteryAlbumCard;
typedef struct MysteryAlbumSlotWork MysteryAlbumSlotWork;

#include "../ov121/mystery_album_types.h"
#include "../types.h"
#include "../ov121/mystery_util_shared_types.h"

MysteryAlbumWork *MYSTERY_ALBUM_Create(const MysteryAlbumCreateInput *src,u16 heap);
void MYSTERY_ALBUM_DeleteWork(MysteryAlbumWork *obj);
void MYSTERY_ALBUM_Update(MysteryAlbumWork *obj);
void MYSTERY_ALBUM_UpdateWindows(MysteryAlbumWork *p);
int MYSTERY_ALBUM_GetWindowState(MysteryAlbumWork *p);
void MYSTERY_ALBUM_Setup(MysteryAlbumWork *p, u16 heap);
void MYSTERY_ALBUM_Cleanup(MysteryAlbumWork *p);
void MYSTERY_ALBUM_SetCursor(MysteryAlbumWork *p,int a,int b,int c,u16 heap);
void MYSTERY_ALBUM_DeleteSlotActors(MysteryAlbumWork *p,int a);
void MYSTERY_ALBUM_SetupSlot(MysteryAlbumWork *p, int a, int b, int c, u16 index, u16 heap);
void MYSTERY_ALBUM_DeleteSlotActor(MysteryAlbumWork *p,int a,u16 index);
void MYSTERY_ALBUM_StartScroll(MysteryAlbumWork *p,int a);
int MYSTERY_ALBUM_UpdateScroll(MysteryAlbumWork *p);
void MYSTERY_ALBUM_RemoveCard(MysteryAlbumWork *o, int idx);
void MYSTERY_ALBUM_SwapCards(MysteryAlbumWork *o, u32 a, u32 b);
int MYSTERY_ALBUM_GetColumnCount(MysteryAlbumWork *p);
u32 MYSTERY_ALBUM_CountValidCards(MysteryAlbumWork *p);
void MYSTERY_ALBUM_SetupEntry(MysteryAlbumEntry *out,const MysteryAlbumCard *src,const MysteryAlbumCreateInput *p,u16 heap);
void MYSTERY_ALBUM_ClearEntry(MysteryAlbumEntry *p);
int MYSTERY_ALBUM_IsEntryValid(MysteryAlbumEntry *p);
void *MYSTERY_ALBUM_GetEntryBmp(void *p);
void *MYSTERY_ALBUM_CreateEntryArc(void *p,u16 heap);
u32 MYSTERY_ALBUM_GetEntryPaletteResId(void *p);
u32 MYSTERY_ALBUM_GetEntryIconPalette(void *p);
int MYSTERY_ALBUM_GetEntryGraphicIndex(void *p);
int MYSTERY_ALBUM_GetEntryCellResId(void *p);
int MYSTERY_ALBUM_GetEntryCellAnimResId(void *p);
int MYSTERY_ALBUM_GetEntryKind(void *p);
char *MYSTERY_ALBUM_GetEntryCard(void *p);
int MYSTERY_ALBUM_GetEntryEggFlag(MysteryAlbumEntry *p);
int MYSTERY_ALBUM_GetEntryIconX(void *p);
int MYSTERY_ALBUM_GetEntryIconY(void *p);
void MYSTERY_ALBUM_SelectHandler(void *task, int *state, void *pArg);
void MYSTERY_ALBUM_ConfirmHandler(void *task, int *state, void *pArg);
void MYSTERY_ALBUM_InfoHandler(void *task, int *state, void *pArg);
void MYSTERY_ALBUM_MoveHandler(void *task, int *state, void *pArg);
void MYSTERY_ALBUM_SaveHandler(void *arg, int *state, void *pArg);
void MYSTERY_ALBUM_SingleHandler(void *arg,int *state,MysteryAlbumWork *p);
void MYSTERY_ALBUM_SetupIconSprite(MysteryUtilBlendPalettes *p,void *arc,int id,int index,u8 other,u16 heap);
void MYSTERY_ALBUM_UpdateIconSprite(MysteryUtilBlendPalettes *p,int b,int c,u16 d);
void *MYSTERY_ALBUM_CreateSlotWork(const MysteryAlbumDesc *p,u16 heap);
void MYSTERY_ALBUM_DeleteSlotWork(MysteryAlbumSlotWork *p);
int MYSTERY_ALBUM_UpdateSlotWork(MysteryAlbumSlotWork *p);
struct MysteryAlbumView *MYSTERY_ALBUM_CreateAlbumView(MysteryAlbumCard *card, MysteryAlbumSlotWork *slotWork, void *gameData, u16 heap);
void MYSTERY_ALBUM_Delete(MysteryAlbum *album);
void MYSTERY_ALBUM_StepIntro(MysteryAlbum *album);
void MYSTERY_ALBUM_SetBlendMain(int eva, int evb);
void MYSTERY_ALBUM_SetBlendSub(int eva, int evb);
void MYSTERY_ALBUM_LoadBgWithTilemap(const MysteryAlbumBgSetup *bgSetup,MysteryAlbum *album,u16 heapId);
void MYSTERY_ALBUM_LoadBgPalette(MysteryAlbumBgSetup *bgSetup,MysteryAlbum *album,u16 heapId);
void MYSTERY_ALBUM_SetupIcons(MysteryAlbum *album,MysteryAlbumUi *ui,u16 heapId);
void MYSTERY_ALBUM_StartIntro(MysteryAlbum *album);
void MYSTERY_ALBUM_ResetIntro(MysteryAlbum *album);
int MYSTERY_ALBUM_IsIntroIdle(MysteryAlbum *album);
void MYSTERY_ALBUM_SetupTask(struct TcbTask *unused,void *work);
void MYSTERY_ALBUM_RequestSetup(MysteryAlbum *album,u32 mode);
void MYSTERY_ALBUM_HideScreen(MysteryAlbumUi *ui);
void MYSTERY_ALBUM_PathAnimInit(MysteryAlbumPathAnim *anim,u16 frameId,int x,int y);
int MYSTERY_ALBUM_PathAnimStep(MysteryAlbumPathAnim *anim, u16 *outFrameId, MysteryAlbumPathPoint *outPosition);
/* END mkheaders: generated region */

#endif
