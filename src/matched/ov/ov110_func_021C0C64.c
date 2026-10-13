/*
 * function: PMS_SELECT_GRAPHIC_DrawRows
 * address: 0x021C0C64
 * packet: pkt_ov110_021C0C64
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 Thumb 0x02024910 lacks an outside witness. Full 8-byte
 *   primary body reads r0/r1, no memory; fixed-flag scratch EXACT8,
 *   blocker-24910-two.log terminal0, no ARM9 source/shard filed.
 *   void *PMS_WORD_GetSaveEntry(char *p,unsigned i) { return p+8+i*8; }
 * Caller explicitly narrows the outgoing index to u8. Own ARM9 units and
 *   complete overlay callee bodies fix arity; observed caller truncations
 *   fix the u8 index externs. Both bounded row loops retain indices0..3.
 * A named u8 which before the comparison/call removes duplicate narrowing
 *   (DIFF84/212 -> MATCH208); no volatile or uninitialized local.
 * Caller-only tu --suggest-split: MATCH208, no viable partition.
 * symbols:
 *   PMS_DRAW_IsPrintEnd 0x0202DC98 thumb
 *   func_02041570 0x02041570 arm
 *   PMS_WORD_GetSaveEntry 0x02024910 thumb
 *   PMSI_PARAM_GetSentenceType 0x0202452C thumb
 *   PMS_SELECT_GRAPHIC_ColorTitleBg 0x021C09E8 thumb ov110
 *   sub_0202DCC4 0x0202DCC4 thumb
 *   PMS_DRAW_Clear 0x0202DC9C thumb
 *   PMS_SELECT_GRAPHIC_DrawSavedRow 0x021C124C thumb ov110
 *   PMS_SELECT_GRAPHIC_DrawNewRow 0x021C11B8 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj0202DC98;
struct Obj0202DCC4;
extern u32 PMS_DRAW_IsPrintEnd(struct Obj0202DC98 *o);
extern void func_02041570(int,u16);
extern void *PMS_WORD_GetSaveEntry(char *p, int idx);
extern int PMSI_PARAM_GetSentenceType(const u16 *p);
extern void PMS_SELECT_GRAPHIC_ColorTitleBg(char *p, int pal);
extern u32 sub_0202DCC4(const struct Obj0202DCC4 *p, u32 i);
extern void PMS_DRAW_Clear(struct Obj0202DC98 *o, int i, u32 a1);
extern void PMS_SELECT_GRAPHIC_DrawSavedRow(u8 *p, int index, u8 which, int flag);
extern void PMS_SELECT_GRAPHIC_DrawNewRow(u8 *p, int index, int unused, int flag);
void PMS_SELECT_GRAPHIC_DrawRows(u8 *p,int flag)
{
    int i;
    if(flag && !PMS_DRAW_IsPrintEnd(*(void **)(p+0x8c))) return;
    func_02041570(2,0);
    if(p[0x96]) {
        PMS_SELECT_GRAPHIC_ColorTitleBg((char *)(p+0x24),PMSI_PARAM_GetSentenceType(PMS_WORD_GetSaveEntry(*(void **)(p+0x20),(u8)(p[0x96]-1))));
    }
    for(i=0;i<4;i++) {
        if(sub_0202DCC4(*(void **)(p+0x8c),(u8)i)) PMS_DRAW_Clear(*(void **)(p+0x8c),(u8)i,0);
    }
    for(i=0;p[0x96]+i<p[0x97] && i<4;i++) {
        u8 which;
        which=p[0x96]+i;
        PMS_SELECT_GRAPHIC_DrawSavedRow(p,(u8)i,which,which==p[0x95]);
    }
    if(p[0x97]<20 && i<4) {
        u8 which;
        which=p[0x96]+i;
        PMS_SELECT_GRAPHIC_DrawNewRow(p,(u8)i,0,which==p[0x95]);
    }
}
