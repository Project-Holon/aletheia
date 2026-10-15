/*
 * function: WIFIBATTLEMATCH_NET_TaskDestroy
 * address: 0x021D4448
 * packet: pkt_ov175_021D4448
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFIBATTLEMATCH_NET_RestartNet 0x021DD008 thumb ov175
 *   WIFIBATTLEMATCH_VIEW_DeleteActorArray 0x021E7DF0 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_DeleteCallback 0x021E8A78 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_Delete 0x021E8628 thumb ov177
 *   WIFIBATTLEMATCH_NET_DeleteNetContext 0x021D9EA0 thumb ov175
 *   WIFIBATTLEMATCH_NET_DeleteRegCard 0x021D644C thumb ov175
 *   WIFIBATTLEMATCH_NET_DeleteBoxRecord 0x021D639C thumb ov175
 *   WIFIBATTLEMATCH_NET_DeleteSprite 0x021D65C8 thumb ov175
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   WIFIBATTLEMATCH_VIEW_Delete 0x021E5868 thumb ov177
 *   WIFIBATTLEMATCH_GRAPHIC_Delete 0x021E54E0 thumb ov177
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov114_id 0x00000072 data
 *   ov067_id 0x00000043 data
 */
extern const char ov114_id[],ov067_id[];
extern void WIFIBATTLEMATCH_NET_RestartNet(char *,int);
typedef unsigned char  u8;
struct PrintSys;
struct WordSet;
extern void WIFIBATTLEMATCH_VIEW_DeleteActorArray(int *p);
extern void WIFIBATTLEMATCH_UTIL_DeleteCallback(void *p);
extern void WIFIBATTLEMATCH_UTIL_Delete(char *p);
extern void WIFIBATTLEMATCH_NET_DeleteNetContext(u8 *p);
extern void WIFIBATTLEMATCH_NET_DeleteRegCard(char *);
extern void WIFIBATTLEMATCH_NET_DeleteBoxRecord(char *);
extern void WIFIBATTLEMATCH_NET_DeleteSprite(char *);
extern unsigned int WORDSET_DeleteStrbufED04(struct WordSet *p);
struct Rec;
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
typedef unsigned int   u32;
extern u32 GF_FONT_Delete(void *ptr);
extern void WIFIBATTLEMATCH_VIEW_Delete(int);
extern void WIFIBATTLEMATCH_GRAPHIC_Delete(char *p);
struct Proc;
extern void func_020315D4(struct Proc *);
extern void GFL_HEAP_DeleteChecked(unsigned int);
extern void func_02034A5C(int);
int WIFIBATTLEMATCH_NET_TaskDestroy(int sys,int unused,int unused2,int *p)
{
    WIFIBATTLEMATCH_NET_RestartNet((char *)p[12],0);
    WIFIBATTLEMATCH_VIEW_DeleteActorArray((int *)p[8]);
    WIFIBATTLEMATCH_UTIL_DeleteCallback((void *)p[14]);
    WIFIBATTLEMATCH_UTIL_DeleteCallback((void *)p[13]);
    WIFIBATTLEMATCH_UTIL_Delete((char *)p[9]);
    if(p[12]) WIFIBATTLEMATCH_NET_DeleteNetContext((u8 *)p[12]);
    WIFIBATTLEMATCH_NET_DeleteRegCard((char *)p);
    WIFIBATTLEMATCH_NET_DeleteBoxRecord((char *)p);
    WIFIBATTLEMATCH_NET_DeleteSprite((char *)p);
    WORDSET_DeleteStrbufED04((struct WordSet *)p[5]);
    MSGDATA_Delete((void *)p[4]);
    PRINTSYS_QUE_Delete((struct PrintSys *)p[3]);
    GF_FONT_Delete((void *)p[2]);
    WIFIBATTLEMATCH_VIEW_Delete(p[1]);
    WIFIBATTLEMATCH_GRAPHIC_Delete((char *)p[0]);
    func_020315D4((struct Proc *)sys);
    GFL_HEAP_DeleteChecked(0x57);
    func_02034A5C((int)ov114_id);
    func_02034A5C((int)ov067_id);
    return 1;
}
