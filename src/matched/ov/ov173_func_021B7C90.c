/*
 * function: POKE_SUMMARY_ACTOR_SelectRow
 * address: 0x021B7C90
 * packet: pkt_ov173_021B7C90
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05 (final push G7L6): the row=3 in the old==3 arm is written as the call argument,
 *   CURSOR_MOVE_SetCurrent(obj, row=3). As a separate statement before the call the colours of p and row swap
 *   (37 B); the argument form keeps the def of row after the p+0x1C8 load, as the original does.
 * symbols:
 *   POKE_SUMMARY_ACTOR_ToggleTaskMenu 0x021B7EB0 thumb ov173
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   CURSOR_MOVE_SetCurrent 0x020260E4 thumb
 *   POKE_SUMMARY_MAIN_GetRecordWord 0x021B7438 thumb ov173
 *   POKE_SUMMARY_MAIN_DrawMoveDetail 0x021B71C4 thumb ov173
 *   POKE_SUMMARY_MAIN_RedrawMoveList 0x021B70D8 thumb ov173
 *   POKE_SUMMARY_ACTOR_UpdateScrollArrows 0x021B7F64 thumb ov173
 *   POKE_SUMMARY_ACTOR_SetScrollAnim 0x021B7FD0 thumb ov173
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
void POKE_SUMMARY_ACTOR_SelectRow(char *p,int row,int old)
{
    
    POKE_SUMMARY_ACTOR_ToggleTaskMenu(p,0);
    if(row<=3) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        *(u16 *)(S(p)+0x14)=row;
        if(*(u16 *)(S(p)+0x16)+*(u16 *)(S(p)+0x14)<*(u8 *)(p+0x1B8)) POKE_SUMMARY_MAIN_DrawMoveDetail(p,POKE_SUMMARY_MAIN_GetRecordWord((char **)p));
        else POKE_SUMMARY_MAIN_DrawMoveDetail(p,-2);
    } else if(row==6) {
        if(old==3 && *(u16 *)(S(p)+0x16)+4<*(u8 *)(p+0x1B8)) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            CURSOR_MOVE_SetCurrent(*(void **)(p+0x1C8),row=3);
            (*(u16 *)(S(p)+0x16))++;
            POKE_SUMMARY_MAIN_RedrawMoveList(p);
            POKE_SUMMARY_MAIN_DrawMoveDetail(p,POKE_SUMMARY_MAIN_GetRecordWord((char **)p));
            POKE_SUMMARY_ACTOR_UpdateScrollArrows(p);
            POKE_SUMMARY_ACTOR_SetScrollAnim((u8 *)p,1);
        } else if(old==0) {
            if(*(u16 *)(S(p)+0x16)!=0) {
                GFL_USE_PlaySeDefaultVolume(0x54C);
                (*(u16 *)(S(p)+0x16))--;
                POKE_SUMMARY_MAIN_RedrawMoveList(p);
                POKE_SUMMARY_MAIN_DrawMoveDetail(p,POKE_SUMMARY_MAIN_GetRecordWord((char **)p));
                POKE_SUMMARY_ACTOR_UpdateScrollArrows(p);
                POKE_SUMMARY_ACTOR_SetScrollAnim((u8 *)p,-1);
            }
            row=0;
            CURSOR_MOVE_SetCurrent(*(void **)(p+0x1C8),0);
        } else {
            row=3;
            CURSOR_MOVE_SetCurrent(*(void **)(p+0x1C8),3);
        }
    } else GFL_USE_PlaySeDefaultVolume(0x54C);
    POKE_SUMMARY_ACTOR_PositionMonActor((u8 *)p,(u8)row,3);
}
