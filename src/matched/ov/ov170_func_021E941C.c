/*
 * function: BOX2_SEQ_StatePmVoiceClose
 * address: 0x021E941C
 * packet: pkt_ov170_021E941C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BOX2_SEQ_ShowWindowObject 0x021EBA5C thumb ov170
 *   BOX2_MAIN_RefreshCursorBox 0x021DD14C thumb ov170
 *   CURSOR_MOVE_SetCurrent 0x020260E4 thumb
 *   BOX2_SEQ_SetSlotActors 0x021ECB20 thumb ov170
 *   BOX2_SEQ_SetSlotDim 0x021ED6E4 thumb ov170
 *   func_020355C4 0x020355C4 arm
 *   CURSOR_MOVE_SetState 0x020260F4 thumb
 */
#define WORK(p) (*(char **)((p)+0x2C))
extern void BOX2_SEQ_ShowWindowObject(char *,int);
extern void BOX2_MAIN_RefreshCursorBox(char *p);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Sound;
struct Struct_02025CD0;
extern void CURSOR_MOVE_SetCurrent(struct Sound *obj, u8 sel);
extern void BOX2_SEQ_SetSlotActors(char *p, int f, int c);
extern void BOX2_SEQ_SetSlotDim(char **p, int v);
extern u8 func_020355C4(void);
extern void CURSOR_MOVE_SetState(struct Struct_02025CD0 *obj, u32 state);
int BOX2_SEQ_StatePmVoiceClose(unsigned char *p) {
 BOX2_SEQ_ShowWindowObject(WORK(p),0x1B); BOX2_MAIN_RefreshCursorBox((char *)p);
 CURSOR_MOVE_SetCurrent(*(void **)(WORK(p)+0x70),p[0x16]);
 BOX2_SEQ_SetSlotActors((char *)p,0x81,1); BOX2_SEQ_SetSlotDim((char **)p,0);
 if(func_020355C4()==1) CURSOR_MOVE_SetState(*(void **)(WORK(p)+0x70),0);
 else CURSOR_MOVE_SetState(*(void **)(WORK(p)+0x70),1);
 return 0x4B;
}
