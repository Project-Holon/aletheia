/*
 * function: INTRUDE_SUBDISP_SystemExit
 * address:  0x0217D6C8
 * packet:   pkt_ov018_0217D6C8
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STRBUF_Delete  0x02045808  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   TCBL_Destroy  0x02031140  arm
 *   BMP_OAM_DeleteSys  0x02025588  thumb
 *   CLACT_DeleteRenderer  0x0204B084  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 */

struct Bank;
struct PrintSys;
struct Rec;
struct S02031140;
struct U16Vec;
struct WordSet;
extern void STRBUF_Delete(struct U16Vec *vec);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern unsigned int func_0201ED04(struct WordSet *p);
typedef unsigned int   u32;
extern u32 GF_FONT_Delete(void *ptr);
extern void TCBL_Destroy(struct S02031140 *p);
extern void BMP_OAM_DeleteSys(void *p);
extern void CLACT_DeleteRenderer(int);
extern u32 CLACT_DeleteUnit(struct Bank *bank);

void INTRUDE_SUBDISP_SystemExit(int *p)
{
    STRBUF_Delete((struct U16Vec *)p[0x38 / 4]);
    STRBUF_Delete((struct U16Vec *)p[0x3c / 4]);
    STRBUF_Delete((struct U16Vec *)p[0x40 / 4]);
    MSGDATA_Delete((struct Rec *)p[0x2c / 4]);
    MSGDATA_Delete((struct Rec *)p[0x30 / 4]);
    PRINTSYS_QUE_Clear((struct PrintSys *)p[0x28 / 4]);
    PRINTSYS_QUE_Delete((struct PrintSys *)p[0x28 / 4]);
    func_0201ED04((struct WordSet *)p[0x24 / 4]);
    GF_FONT_Delete((void *)p[0x1c / 4]);
    TCBL_Destroy((struct S02031140 *)p[0x20 / 4]);
    BMP_OAM_DeleteSys((void *)p[0xb0 / 4]);
    CLACT_DeleteRenderer(p[0x58 / 4]);
    CLACT_DeleteUnit((struct Bank *)p[0x54 / 4]);
}
