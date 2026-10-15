/*
 * function: BOX2_SEQ_StateOpenItemC
 * address: 0x021E4EAC
 * packet: pkt_ov170_021E4EAC
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0x020260E4 has no outside code-start witness. Scratch one EXACT.
 *   void func_020260E4(unsigned char *p, unsigned value) {
 *       p[13] = value; p[14] = 255; p[15] = 255;
 *   }
 * symbols:
 *   BOX2_MAIN_UpdateBoxSlots 0x021DD530 thumb ov170
 *   BOX2_SEQ_Delete 0x021EA1E8 thumb ov170
 *   func_020260E4 0x020260E4 thumb
 *   BOX2_UI_SetCursorPos 0x021EE3E4 thumb ov170
 *   BOX2_UI_DeleteSlotObjects 0x021EE038 thumb ov170
 *   BOX2_SEQ_PrintPrompt 0x021EBC58 thumb ov170
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BOX2_MAIN_UpdateBoxSlots(u8 *);
extern void BOX2_SEQ_Delete(char *);
struct Sound;
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void BOX2_UI_SetCursorPos(char **,unsigned);
extern void BOX2_UI_DeleteSlotObjects(char *,int,int,int);
extern void BOX2_SEQ_PrintPrompt(u8 *,int,int,int);
int BOX2_SEQ_StateOpenItemC(u8 *p){BOX2_MAIN_UpdateBoxSlots(p);BOX2_SEQ_Delete((char *)p);func_020260E4(*(void **)(*(char **)(p+0x2c)+0x70),9);BOX2_UI_SetCursorPos((char **)p,9);BOX2_UI_DeleteSlotObjects((char *)p,0,0,1);BOX2_SEQ_PrintPrompt(p,p[0x16],1,24);return 39;}
