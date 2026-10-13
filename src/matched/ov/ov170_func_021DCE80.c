/*
 * function: func_021DCE80
 * address: 0x021DCE80
 * packet: pkt_ov170_021DCE80
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two bytes alignment padding at 0x021DCEBE.
 * symbols:
 *   STRBUF_Delete 0x02045808 arm
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   MSGDATA_Delete 0x02045C04 arm
 */
struct PrintSys;
struct Rec;
struct U16Vec;
struct WordSet;
extern void STRBUF_Delete(struct U16Vec *vec);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern unsigned int func_0201ED04(struct WordSet *p);
typedef unsigned int   u32;
extern u32 GF_FONT_Delete(void *ptr);
extern u32 MSGDATA_Delete(struct Rec *rec);
#define WORK(p) (*(char **)((p)+0x2c))
#define PTR(p,n) (*(void **)(WORK(p)+(n)))
void func_021DCE80(char *p)
{
    STRBUF_Delete(PTR(p,0x88));
    PRINTSYS_QUE_Delete(PTR(p,0x8c));
    func_0201ED04(PTR(p,0x84));
    GF_FONT_Delete(PTR(p,0x7c));
    GF_FONT_Delete(PTR(p,0x78));
    MSGDATA_Delete(PTR(p,0x80));
}
