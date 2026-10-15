/*
 * function: BOX2_SEQ_StateCloseItemB
 * address: 0x021E6CD4
 * packet: pkt_ov170_021E6CD4
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0x020260F0 has no outside code-start witness. Scratch one EXACT.
 *   unsigned CURSOR_MOVE_GetState(unsigned char *p) { return *(unsigned *)(p+4); }
 * symbols:
 *   BOX2_SEQ_HideWindowObject 0x021EBA70 thumb ov170
 *   BOX2_MAIN_RefreshCursorBox 0x021DD14C thumb ov170
 *   CURSOR_MOVE_GetState 0x020260F0 thumb
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb ov170
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BOX2_SEQ_HideWindowObject(char *,int);
extern void BOX2_MAIN_RefreshCursorBox(char *);
struct Sound;
extern u32 CURSOR_MOVE_GetState(struct Sound *obj);
extern void BOX2_SEQ_SetActorDrawEnable(char *,int,int);
int BOX2_SEQ_StateCloseItemB(u8 *p){BOX2_SEQ_HideWindowObject(*(char **)(p+0x2c),24);BOX2_MAIN_RefreshCursorBox((char *)p);if(CURSOR_MOVE_GetState(*(void **)(*(char **)(p+0x2c)+0x70))==1)BOX2_SEQ_SetActorDrawEnable(*(char **)(p+0x2c),4,1);return 64;}
