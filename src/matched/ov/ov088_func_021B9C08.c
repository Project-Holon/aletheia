/*
 * function: STARTMENU_LogoDelete
 * address:  0x021B9C08
 * packet:   pkt_ov088_021B9C08
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STRBUF_Delete  0x02045808  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   BMP_WIN_Delete  0x020452E8  arm
 */

struct Descriptor;
struct PrintSys;
struct Rec;
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
typedef unsigned int   u32;
extern u32 GF_FONT_Delete(void *ptr);
extern u32 BMP_WIN_Delete(struct Descriptor *d);

void STARTMENU_LogoDelete(int *p)
{
    STRBUF_Delete((struct U16Vec *)p[9]);
    MSGDATA_Delete((struct Rec *)p[8]);
    PRINTSYS_QUE_Delete((struct PrintSys *)p[6]);
    GF_FONT_Delete((void *)p[5]);
    BMP_WIN_Delete((struct Descriptor *)p[0]);
}
