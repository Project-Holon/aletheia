#ifndef GAME_OV208_ZKND_TBAR_H
#define GAME_OV208_ZKND_TBAR_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of zknd_tbar.c, prototypes copied from their definitions. */

struct Ov208Mgr;
struct Ov208ActList;
struct Ov208Rec;
struct Ov208Bg;
struct Ov208ActDesc;
struct ClactActor;

#include "../types.h"

struct Ov208Mgr *ZKND_TBAR_CreateButtonList(struct Ov208ActList *list, u16 heap);
void ZKND_TBAR_DeleteButtonList(struct Ov208Mgr *mgr);
void ZKND_TBAR_UpdateButtons(struct Ov208Mgr *p);
int ZKND_TBAR_GetPressedKey(struct Ov208Mgr *p);
int ZKND_TBAR_GetHeldKey(struct Ov208Mgr *mgr);
void ZKND_TBAR_SetButtonDrawEnable(struct Ov208Mgr *p, int enable);
void ZKND_TBAR_SetTouchEnable(struct Ov208Mgr *p, int enable);
int ZKND_TBAR_GetTouchEnable(struct Ov208Mgr *p);
void ZKND_TBAR_ClearButtonState(struct Ov208Mgr *p);
void ZKND_TBAR_SetButtonAnimSeq(struct Ov208Mgr *mgr, int key, int enabled);
void ZKND_TBAR_SetButtonVisible(struct Ov208Mgr *mgr, int key, int visible);
int ZKND_TBAR_GetButtonVisible(struct Ov208Mgr *mgr, int key);
void ZKND_TBAR_SetButtonAnimSeqLoop(struct Ov208Mgr *mgr, int key, int keyMask);
void ZKND_TBAR_SetButtonAnimSeqOnce(struct Ov208Mgr *mgr, int key, int pressed);
int ZKND_TBAR_IsButtonAnimActive(struct Ov208Mgr *mgr, int key);
int ZKND_TBAR_GetButtonActor(struct Ov208Mgr *mgr, int key);
void ZKND_TBAR_AddButtonPos(struct Ov208Mgr *p, int key, u16 *pos);
void ZKND_TBAR_GetButtonActorRaw(struct Ov208Mgr *mgr, int key);
struct Ov208Rec *ZKND_TBAR_FindButtonActor(struct Ov208Mgr *p, int key);
void *ZKND_TBAR_IsKeyAnimActive(void *mgr, int key);
void ZKND_TBAR_LoadButtonResources(struct Ov208Bg *p, u32 channel, u32 objChannel, u32 palOfs, u32 kind, u8 pal, u8 objPal, u32 skip, u16 heap);
void ZKND_TBAR_ReleaseButtonResources(char *p);
int ZKND_TBAR_GetResourceSlot(int *p, int i);
void ZKND_TBAR_LoadCellArchive(void *narc, u32 fileId, u32 channel, u32 add, u8 srcX, u8 srcY, u8 srcW, u8 srcH, u8 x, u8 y, u8 w, u8 h, u8 pal, u32 decompress, u16 heap);
void ZKND_TBAR_CreateButton(struct Ov208Rec *p, u32 owner, const int *res, struct Ov208ActDesc *desc, u32 prio, u16 mode);
void ZKND_TBAR_DeleteButton(char *p);
int ZKND_TBAR_UpdateButtonTouch(char *p);
int ZKND_TBAR_IsButtonAnimating(int *p);
int ZKND_TBAR_GetButtonActorBase(char *p);
void ZKND_TBAR_SetActorDrawEnable(struct ClactActor **p, unsigned int enable);
unsigned ZKND_TBAR_GetActorDrawEnable(int *p);
void ZKND_TBAR_SetActorAnimSeq(char *p, int enabled);
void ZKND_TBAR_SetPressedAnim(char *p, int keyMask);
void ZKND_TBAR_SetAnimByState(char *p, int which);
int ZKND_TBAR_GetButtonSound(const void *p);
void ZKND_TBAR_GetButtonCount(char *p);
void ZKND_TBAR_PlayCancelAnim(char *p);
void ZKND_TBAR_PlayButtonAnim(char *p);
/* END mkheaders: generated region */

#endif
