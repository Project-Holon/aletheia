/*
 * function: POKE_SUMMARY_ACTOR_HandleCursorInput
 * address: 0x021B7DA0
 * packet: pkt_ov173_021B7DA0
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 020260E4 is omitted from unit_020260E0.c's function header.
 *   one --thumb, no region: EXACT, 10 bytes, blocker260E4.log.
 *   void CURSOR_MOVE_SetCurrent(unsigned char *p,unsigned value) {
 *       p[13]=value; p[14]=255; p[15]=255;
 *   }
 * symbols:
 *   POKE_SUMMARY_ACTOR_ToggleTaskMenu 0x021B7EB0 thumb ov173
 *   POKE_SUMMARY_MAIN_GetRecordWord 0x021B7438 thumb ov173
 *   POKE_SUMMARY_MAIN_DrawMoveDetail 0x021B71C4 thumb ov173
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   POKE_SUMMARY_MAIN_RedrawMoveList 0x021B70D8 thumb ov173
 *   POKE_SUMMARY_ACTOR_UpdateScrollArrows 0x021B7F64 thumb ov173
 *   POKE_SUMMARY_ACTOR_SetScrollAnim 0x021B7FD0 thumb ov173
 *   CURSOR_MOVE_SetCurrent 0x020260E4 thumb
 *   POKE_SUMMARY_ACTOR_PositionMonActor 0x021B7ADC thumb ov173
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void POKE_SUMMARY_ACTOR_ToggleTaskMenu(char *,int);
extern u16 POKE_SUMMARY_MAIN_GetRecordWord(char **);
extern void POKE_SUMMARY_MAIN_DrawMoveDetail(char *,int);
extern void GFL_USE_PlaySeDefaultVolume(unsigned);
extern void POKE_SUMMARY_MAIN_RedrawMoveList(char *);
extern void POKE_SUMMARY_ACTOR_UpdateScrollArrows(char *);
extern void POKE_SUMMARY_ACTOR_SetScrollAnim(u8 *,int);
struct Sound;
extern void CURSOR_MOVE_SetCurrent(struct Sound *obj, u8 sel);
typedef unsigned int   u32;
extern void POKE_SUMMARY_ACTOR_PositionMonActor(unsigned char *p, u32 idx, int unused);
#define S(p) (*(char **)(p))
void POKE_SUMMARY_ACTOR_HandleCursorInput(char *p,int i)
{
    if(i<=3) {
        *(u16 *)(S(p)+0x14)=i;
        if(*(u16 *)(S(p)+0x16)+*(u16 *)(S(p)+0x14)<*(u8 *)(p+0x1B8)) {
            POKE_SUMMARY_ACTOR_ToggleTaskMenu(p,1);
            POKE_SUMMARY_MAIN_DrawMoveDetail(p,POKE_SUMMARY_MAIN_GetRecordWord((char **)p));
        } else {
            POKE_SUMMARY_ACTOR_ToggleTaskMenu(p,0);
            POKE_SUMMARY_MAIN_DrawMoveDetail(p,-2);
        }
    } else if(i==4) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        i=*(u16 *)(S(p)+0x14);
        (*(u16 *)(S(p)+0x16))++;
        POKE_SUMMARY_MAIN_DrawMoveDetail(p,POKE_SUMMARY_MAIN_GetRecordWord((char **)p));
        POKE_SUMMARY_MAIN_RedrawMoveList(p);
        POKE_SUMMARY_ACTOR_ToggleTaskMenu(p,0);
        POKE_SUMMARY_ACTOR_UpdateScrollArrows(p);
        POKE_SUMMARY_ACTOR_SetScrollAnim((u8 *)p,1);
        CURSOR_MOVE_SetCurrent(*(void **)(p+0x1C8),i);
    } else if(i==5) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        i=*(u16 *)(S(p)+0x14);
        (*(u16 *)(S(p)+0x16))--;
        POKE_SUMMARY_MAIN_DrawMoveDetail(p,POKE_SUMMARY_MAIN_GetRecordWord((char **)p));
        POKE_SUMMARY_MAIN_RedrawMoveList(p);
        POKE_SUMMARY_ACTOR_ToggleTaskMenu(p,0);
        POKE_SUMMARY_ACTOR_UpdateScrollArrows(p);
        POKE_SUMMARY_ACTOR_SetScrollAnim((u8 *)p,-1);
        CURSOR_MOVE_SetCurrent(*(void **)(p+0x1C8),i);
    } else if(i==6) {
        if(*(u16 *)(p+0x1CC)!=6) {
            i=*(u16 *)(S(p)+0x14);
            CURSOR_MOVE_SetCurrent(*(void **)(p+0x1C8),i);
        }
    } else if(i==7) {
        i=*(u16 *)(S(p)+0x14);
        CURSOR_MOVE_SetCurrent(*(void **)(p+0x1C8),i);
    } else if(i==8) {
        if(*(u16 *)(p+0x1CC)!=6) {
            i=*(u16 *)(S(p)+0x14);
            CURSOR_MOVE_SetCurrent(*(void **)(p+0x1C8),i);
        }
    }
    POKE_SUMMARY_ACTOR_PositionMonActor((u8 *)p,(u8)i,3);
}
