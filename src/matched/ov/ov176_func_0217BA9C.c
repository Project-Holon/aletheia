/*
 * function: LIVEBATTLEMATCH_FLOW_Delete
 * address: 0x0217BA9C
 * packet: pkt_ov176_0217BA9C
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   UI_ClearSoftResetInhibitGlobal 0x020351A0 arm
 *   DIGITALCARDCHECK_DeleteRecord 0x0217D174 thumb ov176
 *   DIGITALCARDCHECK_DeleteRecord2 0x0217D224 thumb ov176
 *   WIFIBATTLEMATCH_VIEW_DeleteActorArray 0x021E7DF0 thumb ov177
 *   LIVEBATTLEMATCH_IRC_Delete 0x0217E058 thumb ov176
 *   WIFIBATTLEMATCH_UTIL_DeleteCallback 0x021E8A78 thumb ov177
 *   GF_FONT_Delete 0x0201D83C thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   WORDSET_Delete 0x0201ED04 thumb
 */
extern unsigned int func_020307B0(void *p);
typedef unsigned int   u32;
extern int UI_ClearSoftResetInhibitGlobal(u32 v);
extern void DIGITALCARDCHECK_DeleteRecord(int *);
extern void DIGITALCARDCHECK_DeleteRecord2(int *);
struct Rec;
struct WordSet;
extern void WIFIBATTLEMATCH_VIEW_DeleteActorArray(int *p);
extern void LIVEBATTLEMATCH_IRC_Delete(int *p);
extern void WIFIBATTLEMATCH_UTIL_DeleteCallback(void *p);
extern u32 GF_FONT_Delete(void *ptr);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 WORDSET_Delete(struct WordSet *p);
void LIVEBATTLEMATCH_FLOW_Delete(int *p)
{
    func_020307B0((void *)p[12]);
    if (p[0x67] == 1) UI_ClearSoftResetInhibitGlobal(8);
    DIGITALCARDCHECK_DeleteRecord(p);
    DIGITALCARDCHECK_DeleteRecord2(p);
    WIFIBATTLEMATCH_VIEW_DeleteActorArray((int *)p[7]);
    LIVEBATTLEMATCH_IRC_Delete((int *)p[3]);
    WIFIBATTLEMATCH_UTIL_DeleteCallback((void *)p[0]);
    GF_FONT_Delete((void *)p[10]);
    MSGDATA_Delete((struct Rec *)p[9]);
    MSGDATA_Delete((struct Rec *)p[8]);
    WORDSET_Delete((struct WordSet *)p[11]);
    func_020307B0(p);
}
