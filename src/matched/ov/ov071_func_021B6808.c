/*
 * function: MONOLITH_TOOL_FreeText
 * address: 0x021B6808
 * packet: pkt_ov071_021B6808
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MSGDATA_Delete 0x02045C04 arm
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   TCBL_Destroy 0x02031140 arm
 */
struct Rec;
struct WordSet;
struct PrintSys;
struct S02031140;
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern unsigned int WORDSET_DeleteStrbufED04(struct WordSet *p);
extern void PRINTSYS_QUE_Clear(struct PrintSys *);
extern void PRINTSYS_QUE_Delete(struct PrintSys *);
typedef unsigned int   u32;
extern u32 GF_FONT_Delete(void *ptr);
extern void TCBL_Destroy(struct S02031140 *);
void MONOLITH_TOOL_FreeText(void **p)
{
    MSGDATA_Delete(p[7]);
    MSGDATA_Delete(p[8]);
    MSGDATA_Delete(p[9]);
    MSGDATA_Delete(p[10]);
    WORDSET_DeleteStrbufED04(p[4]);
    PRINTSYS_QUE_Clear(p[2]);
    PRINTSYS_QUE_Delete(p[2]);
    GF_FONT_Delete(p[3]);
    TCBL_Destroy(p[6]);
}
