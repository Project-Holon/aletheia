/*
 * function: DENDOU_VIEW_ExitText
 * address: 0x021DCC88
 * packet: pkt_ov171_021DCC88
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STRBUF_Delete 0x02045808 arm
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   WORDSET_Delete 0x0201ED04 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   MSGDATA_Delete 0x02045C04 arm
 */
struct PrintSys;
struct Rec;
struct U16Vec;
struct WordSet;
extern void STRBUF_Delete(struct U16Vec *vec);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern unsigned int WORDSET_Delete(struct WordSet *p);
typedef unsigned int   u32;
extern u32 GF_FONT_Delete(void *ptr);
extern u32 MSGDATA_Delete(struct Rec *rec);
#define PTR(p,n) (*(void **)((p)+(n)))
void DENDOU_VIEW_ExitText(char *p)
{
    STRBUF_Delete(PTR(p,0xb68));
    PRINTSYS_QUE_Delete(PTR(p,0xb6c));
    WORDSET_Delete(PTR(p,0xb64));
    GF_FONT_Delete(PTR(p,0xb5c));
    GF_FONT_Delete(PTR(p,0xb58));
    MSGDATA_Delete(PTR(p,0xb60));
}
