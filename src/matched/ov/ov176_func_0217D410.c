/*
 * function: DIGITALCARDCHECK_Delete
 * address: 0x0217D410
 * packet: pkt_ov176_0217D410
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFIBATTLEMATCH_UTIL_DeleteCallback 0x021E8A78 thumb ov177
 *   DIGITALCARDCHECK_DeleteInitRecord 0x0217DE60 thumb ov176
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Rec;
struct WordSet;
extern void WIFIBATTLEMATCH_UTIL_DeleteCallback(void *p);
extern void DIGITALCARDCHECK_DeleteInitRecord(int *);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 func_020307B0(void *p);
void DIGITALCARDCHECK_Delete(int *p) {WIFIBATTLEMATCH_UTIL_DeleteCallback((void *)p[4]);DIGITALCARDCHECK_DeleteInitRecord(p);WORDSET_DeleteStrbufED04((struct WordSet *)p[1]);MSGDATA_Delete((struct Rec *)p[0]);func_020307B0(p);}
