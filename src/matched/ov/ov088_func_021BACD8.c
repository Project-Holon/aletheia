/*
 * function: STARTMENU_DeleteTextSystem
 * address:  0x021BACD8
 * packet:   pkt_ov088_021BACD8
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   APP_KEYCURSOR_Delete  0x02028604  thumb
 *   TCBL_Destroy  0x02031140  arm
 *   STRBUF_Delete  0x02045808  arm
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   WORDSET_Delete  0x0201ED04  thumb
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   MSGDATA_Delete  0x02045C04  arm
 */

extern int APP_KEYCURSOR_Delete(int a0);
struct PrintSys;
struct Rec;
struct S02031140;
struct U16Vec;
struct WordSet;
extern void TCBL_Destroy(struct S02031140 *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern unsigned int WORDSET_Delete(struct WordSet *p);
typedef unsigned int   u32;
extern u32 GF_FONT_Delete(void *ptr);
extern u32 MSGDATA_Delete(struct Rec *rec);

void STARTMENU_DeleteTextSystem(int *p)
{
    APP_KEYCURSOR_Delete(p[0x74 / 4]);
    TCBL_Destroy((struct S02031140 *)p[0x70 / 4]);
    STRBUF_Delete((struct U16Vec *)p[0x64 / 4]);
    PRINTSYS_QUE_Delete((struct PrintSys *)p[0x68 / 4]);
    WORDSET_Delete((struct WordSet *)p[0x60 / 4]);
    GF_FONT_Delete((void *)p[0x58 / 4]);
    MSGDATA_Delete((struct Rec *)p[0x5c / 4]);
}
