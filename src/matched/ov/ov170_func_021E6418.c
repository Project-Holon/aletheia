/*
 * function: BOX2_SEQ_StateSelectItem
 * address: 0x021E6418
 * packet: pkt_ov170_021E6418
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0x020260E4 has no outside code-start witness. Scratch one EXACT.
 *   void CURSOR_MOVE_SetCurrent(unsigned char *p, unsigned value) {
 *       p[13] = value; p[14] = 255; p[15] = 255;
 *   }
 * symbols:
 *   CURSOR_MOVE_SetCurrent 0x020260E4 thumb
 *   BOX2_UI_SetCursorPos 0x021EE3E4 thumb ov170
 *   BOX2_SEQ_SetCursorDraw 0x021ED55C thumb ov170
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Sound;
extern void CURSOR_MOVE_SetCurrent(struct Sound *obj, u8 sel);
extern void BOX2_UI_SetCursorPos(char **,unsigned);
extern void BOX2_SEQ_SetCursorDraw(char **,int);
int BOX2_SEQ_StateSelectItem(u8 *p){int sel;sel=37;if(*(u16 *)(*(char **)(p+0x2c)+0xa16c)!=0)sel=36;CURSOR_MOVE_SetCurrent(*(void **)(*(char **)(p+0x2c)+0x70),sel);BOX2_UI_SetCursorPos((char **)p,sel);BOX2_SEQ_SetCursorDraw((char **)p,1);return 57;}
