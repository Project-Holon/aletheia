#ifndef GAME_OV186_BR_BTN_H
#define GAME_OV186_BR_BTN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of br_btn.c, prototypes copied from their definitions. */

struct BrBtn;
struct BrRes;
struct BrBtnResultSet;
struct Button;
struct BrUtilTask;
struct MsgBank;
struct BrButton;
typedef struct Button Button;

#include "../types.h"
#include "../ov186/br_types.h"
#include "../ov186/br_types.h"

struct BrBtn *BR_BTN_Create(int a, void *b, struct BrRes *c, int d, struct BrBtnResultSet *e, void *f, u16 heap);
void BR_BTN_Delete(u8 *p);
void BR_BTN_UpdatePrint(char *p);
int BR_BTN_GetPlacement(char *p,int *x,int *y);
int BR_BTN_GetPressed(char *p);
int BR_BTN_GetResultValue(char *p);
void BR_BTN_PushRecord(struct BrBtn *ctx, const Button *source, int mode);
int BR_BTN_Init(struct BrBtn *ctx, Button *out);
void BR_BTN_BuildSection(struct BrBtn *p,int section,const int *pos);
void BR_BTN_PushPosPair(char *p,int x,int y);
void BR_BTN_PopPosPair(char *p);
void BR_BTN_SetTailSelection(struct BrBtn *ctx, int mode);
void BR_BTN_SetupInput(struct BrUtilTask *p);
void BR_BTN_HandleInput(struct BrUtilTask *p,int *state,struct BrBtn *ctx);
void BR_BTN_UpdateSpread(struct BrUtilTask *p, int *state, struct BrBtn *ctx);
void BR_BTN_UpdatePress(struct BrUtilTask *p,int *state,struct BrBtn *ctx);
void BR_BTN_UpdateRestore(struct BrUtilTask *p, int *state, struct BrBtn *ctx);
void BR_BTN_UpdateHide(struct BrUtilTask *p, int *state, struct BrBtn *ctx);
void BR_BTN_UpdateExpand(struct BrUtilTask *p,int *state,struct BrBtn *ctx);
void BR_BTN_UpdateCollapse(struct BrUtilTask *task,int *state,struct BrBtn *ctx);
void BR_BTN_UpdateBack(struct BrUtilTask *p, int *state, struct BrBtn *ctx);
void BR_BTN_UpdateTextInput(struct BrUtilTask *p, int *state, struct BrBtn *ctx);
void BR_BTN_UpdateSlide(struct BrUtilTask *p, int *state, struct BrBtn *ctx);
void BR_BTN_UpdateHide2(struct BrUtilTask *p, int *state, struct BrBtn *ctx);
void BR_BTN_InitRecord(Button *ctx, void *object, void *a, void *b, struct BrRes *owner, const void *arg, unsigned index, unsigned short heap);
void BR_BTN_DeleteRecord(Button *p);
int BR_BTN_HitTest(Button *p, int x, int y);
void BR_BTN_SetAnimMode(Button *ctx, int mode, const int *target);
int BR_BTN_StepAnim(Button *ctx);
void BR_BTN_SetMode(Button *ctx, int mode);
void BR_BTN_CopyRecord(void *ctx, Button *dest, const Button *source, int mode);
void BR_BTN_PlaceIndexed(Button *p, unsigned index);
void BR_BTN_GetPos(Button *p, int *out);
void BR_BTN_SetPosY(Button *p, int y);
int BR_BTN_GetRowField(Button *ctx, int kind);
void BR_BTN_SetDrawPriority(Button *p, int b);
void BR_BTN_SetBgPriority(Button *p, int b);
void BR_BTN_SetSelected(Button *p, unsigned value);
void BR_BTN_SetPos(Button *p, int *value);
int BR_BTN_AnimMove(Button *ctx);
int BR_BTN_AnimMoveRow(Button *ctx);
int BR_BTN_AnimFlyOut(Button *p);
int BR_BTN_AnimFlyIn(Button *p);
int BR_BTN_AnimMove2(Button *ctx);
void *BR_BTN_CreateFromMessage(void *ctx, u16 file, unsigned short a, int b, void *c, void *d, void *e, struct MsgBank *archive, void *config, unsigned short heap);
struct BrButton *BR_BTN_CreateObject(const BrBtnPlacement *pt,void *data,u16 a,u32 b,void *c,void *owner,void *font,const BrBtnSpriteIds *triple,u16 heap);
void BR_BTN_DeleteObject(struct BrButton *p);
int BR_BTN_HitTestWithSound(struct BrButton *obj, int x, int y);
int BR_BTN_TestHitBox(struct BrButton *p, int x, int y);
void BR_BTN_SetObjectPos(struct BrButton *p, short x, int y);
void BR_BTN_GetObjectPos(struct BrButton *p,short *x,short *y);
void BR_BTN_SetObjectDrawPriority(struct BrButton *p, unsigned char b);
int BR_BTN_GetObjectDrawPriority(struct BrButton *p);
void BR_BTN_SetObjectBgPriority(struct BrButton *p, int b);
unsigned BR_BTN_GetObjectBgPriority(struct BrButton *p);
void BR_BTN_SetObjectPalette(struct BrButton *p,int n);
/* END mkheaders: generated region */

#endif
