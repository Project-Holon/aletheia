#ifndef GAME_OV121_MYSTERY_ALBUM_H
#define GAME_OV121_MYSTERY_ALBUM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of mystery_album.c, prototypes copied from their definitions. */

struct MysteryAlbumWork;
struct MysteryAlbumWorkVolatile;
struct MysteryAlbumCard;
struct MysteryAlbumView;
struct CtxB;
struct TcbTask;
typedef struct MysteryAlbumWork MysteryAlbumWork;
typedef struct MysteryAlbumWorkVolatile MysteryAlbumWorkVolatile;
typedef struct MysteryAlbumCard MysteryAlbumCard;

#include "../ov121/mystery_album_types.h"
#include "../types.h"

char *MYSTERY_ALBUM_Create(const MysteryAlbumCreateInput *src,u16 heap);
void MYSTERY_ALBUM_DeleteWork(MysteryAlbumWork *obj);
void MYSTERY_ALBUM_Update(MysteryAlbumWorkVolatile *obj);
void MYSTERY_ALBUM_UpdateWindows(char *p);
int MYSTERY_ALBUM_GetWindowState(char *p);
void MYSTERY_ALBUM_Setup(u8 *p, u16 heap);
void MYSTERY_ALBUM_Cleanup(char *p);
void MYSTERY_ALBUM_SetCursor(char *p,int a,int b,int c,u16 heap);
void MYSTERY_ALBUM_DeleteSlotActors(char *p,int a);
void MYSTERY_ALBUM_SetupSlot(char *p, int a, int b, int c, u16 index, u16 heap);
void MYSTERY_ALBUM_DeleteSlotActor(char *p,int a,u16 index);
void MYSTERY_ALBUM_StartScroll(u8 *p,int a);
int MYSTERY_ALBUM_UpdateScroll(char *p);
void MYSTERY_ALBUM_RemoveCard(MysteryAlbumWork *o, int idx);
void MYSTERY_ALBUM_SwapCards(MysteryAlbumWork *o, u32 a, u32 b);
int MYSTERY_ALBUM_GetColumnCount(char *p);
u32 MYSTERY_ALBUM_CountValidCards(u32 p);
void MYSTERY_ALBUM_SetupEntry(char *out,const MysteryAlbumCard *src,char *p,u16 heap);
void MYSTERY_ALBUM_ClearEntry(u32 p);
int MYSTERY_ALBUM_IsEntryValid(int *p);
void *MYSTERY_ALBUM_GetEntryBmp(void *p);
void *MYSTERY_ALBUM_CreateEntryArc(void *p,u16 heap);
u32 MYSTERY_ALBUM_GetEntryPaletteResId(void *p);
u32 MYSTERY_ALBUM_GetEntryIconPalette(void *p);
int MYSTERY_ALBUM_GetEntryGraphicIndex(void *p);
int MYSTERY_ALBUM_GetEntryCellResId(void *p);
int MYSTERY_ALBUM_GetEntryCellAnimResId(void *p);
int MYSTERY_ALBUM_GetEntryKind(void *p);
char *MYSTERY_ALBUM_GetEntryCard(void *p);
int MYSTERY_ALBUM_GetEntryEggFlag(u32 p);
int MYSTERY_ALBUM_GetEntryIconX(void *p);
int MYSTERY_ALBUM_GetEntryIconY(void *p);
void MYSTERY_ALBUM_SelectHandler(void *task,u32 *state,char *p);
void MYSTERY_ALBUM_ConfirmHandler(void *task,u32 *state,u8 *p);
void MYSTERY_ALBUM_InfoHandler(void *task,u32 *state,char *p);
void MYSTERY_ALBUM_MoveHandler(void *task,u32 *state,char *p);
void MYSTERY_ALBUM_SaveHandler(void *arg,u32 *state,char *p);
void MYSTERY_ALBUM_SingleHandler(void *arg,int *state,char *p);
void MYSTERY_ALBUM_SetupIconSprite(char *p,void *arc,int id,int index,u8 other,u16 heap);
void MYSTERY_ALBUM_UpdateIconSprite(u8 *p,int b,int c,u16 d);
void *MYSTERY_ALBUM_CreateSlotWork(const MysteryAlbumDesc *p,u16 heap);
void MYSTERY_ALBUM_DeleteSlotWork(void **p);
int MYSTERY_ALBUM_UpdateSlotWork(void **p);
struct MysteryAlbumView *MYSTERY_ALBUM_CreateAlbumView(MysteryAlbumCard *card, struct CtxB *slotWork, void *gameData, u16 heap);
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
