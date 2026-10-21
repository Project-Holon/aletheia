#ifndef GAME_OV186_BR_BTN_H
#define GAME_OV186_BR_BTN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of br_btn.c, prototypes copied from their definitions. */

struct BrBtn;
struct Button;
struct MsgBank;
struct BrButton;
typedef struct Button Button;

#include "../types.h"
#include "../ov186/br_types.h"
#include "../ov186/br_types.h"

struct BrBtn *BR_BTN_Create(int a, int b, int c, int d, int e, int f, u16 heap);
void BR_BTN_Delete(u8 *p);
void BR_BTN_UpdatePrint(char *p);
int BR_BTN_GetPlacement(char *p,int *x,int *y);
int BR_BTN_GetPressed(char *p);
int BR_BTN_GetResultValue(char *p);
void BR_BTN_PushRecord(struct BrBtn *ctx, int source, int mode);
int BR_BTN_Init(struct BrBtn *ctx, Button *out);
void BR_BTN_BuildSection(struct BrBtn *p,int section,const int *pos);
void BR_BTN_PushPosPair(char *p,int x,int y);
void BR_BTN_PopPosPair(char *p);
void BR_BTN_SetTailSelection(struct BrBtn *ctx, int mode);
void BR_BTN_SetupInput(void *p);
void BR_BTN_HandleInput(void *p,int *state,struct BrBtn *ctx);
void BR_BTN_UpdateSpread(void *p, int *state, struct BrBtn *ctx);
void BR_BTN_UpdatePress(void *p,int *state,struct BrBtn *ctx);
void BR_BTN_UpdateRestore(void *p, int *state, struct BrBtn *ctx);
void BR_BTN_UpdateHide(void *p, int *state, struct BrBtn *ctx);
void BR_BTN_UpdateExpand(void *p,int *state,struct BrBtn *ctx);
void BR_BTN_UpdateCollapse(int *task,int *state,struct BrBtn *ctx);
void BR_BTN_UpdateBack(void *p, int *state, struct BrBtn *ctx);
void BR_BTN_UpdateTextInput(void *p, int *state, struct BrBtn *ctx);
void BR_BTN_UpdateSlide(void *p, int *state, struct BrBtn *ctx);
void BR_BTN_UpdateHide2(void *p, int *state, struct BrBtn *ctx);
void BR_BTN_InitRecord(Button *ctx, void *object, unsigned a, void *b, char *owner, const void *arg, unsigned index, unsigned short heap);
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
void BR_BTN_SetPos(Button *p, unsigned value);
int BR_BTN_AnimMove(Button *ctx);
int BR_BTN_AnimMoveRow(Button *ctx);
int BR_BTN_AnimFlyOut(Button *p);
int BR_BTN_AnimFlyIn(Button *p);
int BR_BTN_AnimMove2(Button *ctx);
void *BR_BTN_CreateFromMessage(void *ctx, u16 file, unsigned short a, int b, void *c, void *d, void *e, struct MsgBank *archive, void *config, unsigned short heap);
struct BrButton *BR_BTN_CreateObject(const BrBtnPlacement *pt,void *data,u16 a,u32 b,void *c,void *owner,void *font,const BrBtnSpriteIds *triple,u16 heap);
void BR_BTN_DeleteObject(char *p);
int BR_BTN_HitTestWithSound(unsigned int *obj, int x, int y);
int BR_BTN_TestHitBox(u32 *p, int x, int y);
void BR_BTN_SetObjectPos(char *p, short x, int y);
void BR_BTN_GetObjectPos(char *p,short *x,short *y);
void BR_BTN_SetObjectDrawPriority(int *p, unsigned char b);
int BR_BTN_GetObjectDrawPriority(char *p);
void BR_BTN_SetObjectBgPriority(int *p, int b);
unsigned BR_BTN_GetObjectBgPriority(char *p);
void BR_BTN_SetObjectPalette(char *p,int n);
/* END mkheaders: generated region */

#endif
