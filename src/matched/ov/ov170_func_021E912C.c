/*
 * function: BOX2_SEQ_StateUseItemDone
 * address: 0x021E912C
 * packet: pkt_ov170_021E912C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_SEQ_SetSlotDim 0x021ED6E4 thumb ov170
 *   BOX2_SEQ_HideWindowObject 0x021EBA70 thumb ov170
 *   BOX2_MAIN_RefreshCursorBox 0x021DD14C thumb ov170
 *   BOX2_UI_ToggleSlotPair 0x021ED888 thumb ov170
 *   BOX2_SEQ_SetSlotActors 0x021ECB20 thumb ov170
 *   func_020355C4 0x020355C4 arm
 *   func_020260F4 0x020260F4 thumb
 *   BOX2_SEQ_SetCursorDraw 0x021ED55C thumb ov170
 *   BOX2_SEQ_ReturnAfterClear 0x021E8F50 thumb ov170
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb ov170
 *   BOX2_MAIN_IsWindowMoving 0x021E0190 thumb ov170
 */
#define WORK(p) (*(char **)((p)+0x2C))
extern void BOX2_SEQ_SetSlotDim(char **p, int v);
extern void BOX2_SEQ_HideWindowObject(char *,int);
extern void BOX2_MAIN_RefreshCursorBox(char *p);
extern void BOX2_UI_ToggleSlotPair(char *,int);
extern void BOX2_SEQ_SetSlotActors(char *p, int f, int c);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Struct_02025CD0;
extern u8 func_020355C4(void);
extern void func_020260F4(struct Struct_02025CD0 *obj, u32 state);
extern void BOX2_SEQ_SetCursorDraw(char **p, int flag);
extern int BOX2_SEQ_ReturnAfterClear(char *p, int v);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
extern int BOX2_MAIN_IsWindowMoving(char *p);
int BOX2_SEQ_StateUseItemDone(unsigned char *p) {
 BOX2_SEQ_SetSlotDim((char **)p,1); BOX2_SEQ_HideWindowObject(WORK(p),0x18); BOX2_MAIN_RefreshCursorBox((char *)p);
 if(p[0x16]<0x1E) { BOX2_UI_ToggleSlotPair(WORK(p),1); BOX2_SEQ_SetSlotActors((char *)p,1,0); }
 else BOX2_SEQ_SetSlotActors((char *)p,2,0);
 if(func_020355C4()==1) func_020260F4(*(void **)(WORK(p)+0x70),0);
 else { func_020260F4(*(void **)(WORK(p)+0x70),1); BOX2_SEQ_SetCursorDraw((char **)p,0); }
 return BOX2_SEQ_SetSeqThird((char *)p,(int)BOX2_MAIN_IsWindowMoving,BOX2_SEQ_ReturnAfterClear((char *)p,0xE));
}
