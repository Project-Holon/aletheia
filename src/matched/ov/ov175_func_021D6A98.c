/*
 * function: WIFIBATTLEMATCH_NET_CompDestroy
 * address: 0x021D6A98
 * packet: pkt_ov175_021D6A98
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   WIFIBATTLEMATCH_NET_RestartNet 0x021DD008 thumb ov175
 *   WIFIBATTLEMATCH_VIEW_DeleteActorArray 0x021E7DF0 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_DeleteCallback 0x021E8A78 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_Delete 0x021E8628 thumb ov177
 *   WIFIBATTLEMATCH_NET_DeleteNetContext 0x021D9EA0 thumb ov175
 *   WIFIBATTLEMATCH_NET_DeleteCompPartyWindow 0x021D98B8 thumb ov175
 *   WIFIBATTLEMATCH_NET_DeleteCompRegCard 0x021D9854 thumb ov175
 *   WIFIBATTLEMATCH_NET_DeleteCompStatusWindow 0x021D97A4 thumb ov175
 *   WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu 0x021D99F4 thumb ov175
 *   WORDSET_Delete 0x0201ED04 thumb
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
#include "../include/Obj01563.h"
typedef unsigned int u32;
extern const char ov114_id[],ov067_id[];
extern u32 func_020307B0(void *p);
extern void WIFIBATTLEMATCH_NET_RestartNet(char *,int);
typedef unsigned char  u8;
struct PrintSys;
struct Rec;
struct WordSet;
extern void WIFIBATTLEMATCH_VIEW_DeleteActorArray(int *p);
extern void WIFIBATTLEMATCH_UTIL_DeleteCallback(void *p);
extern void WIFIBATTLEMATCH_UTIL_Delete(char *p);
extern void WIFIBATTLEMATCH_NET_DeleteNetContext(u8 *p);
extern void WIFIBATTLEMATCH_NET_DeleteCompPartyWindow(char *);
extern void WIFIBATTLEMATCH_NET_DeleteCompRegCard(char *);
extern void WIFIBATTLEMATCH_NET_DeleteCompStatusWindow(char *);
extern void WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(char *);
extern u32 WORDSET_Delete(struct WordSet *p);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void WIFIBATTLEMATCH_VIEW_Delete(u32);
extern void WIFIBATTLEMATCH_GRAPHIC_Delete(char *p);
struct Proc;
extern void func_020315D4(struct Proc *p);
extern void GFL_HEAP_DeleteChecked(u32);
extern void func_02034A5C(int);
int WIFIBATTLEMATCH_NET_CompDestroy(u32 sys,u32 unused,u32 arg,char *p)
{
    func_020307B0(((struct Obj01563 *)p)->fFC);
    WIFIBATTLEMATCH_NET_RestartNet((char *)((u32 *)p)[13],0);
    WIFIBATTLEMATCH_VIEW_DeleteActorArray((int *)(((u32 *)p)[10]));
    WIFIBATTLEMATCH_UTIL_DeleteCallback((void *)(((u32 *)p)[15])); WIFIBATTLEMATCH_UTIL_DeleteCallback((void *)(((u32 *)p)[14]));
    WIFIBATTLEMATCH_UTIL_Delete((char *)(((u32 *)p)[11]));
    if(((u32 *)p)[13]) WIFIBATTLEMATCH_NET_DeleteNetContext((u8 *)(((u32 *)p)[13]));
    WIFIBATTLEMATCH_NET_DeleteCompPartyWindow(p); WIFIBATTLEMATCH_NET_DeleteCompRegCard(p); WIFIBATTLEMATCH_NET_DeleteCompStatusWindow(p); WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(p);
    WORDSET_Delete((struct WordSet *)(((u32 *)p)[6])); MSGDATA_Delete((struct Rec *)(((u32 *)p)[5]));
    PRINTSYS_QUE_Delete((struct PrintSys *)(((u32 *)p)[4])); GF_FONT_Delete((void *)(((u32 *)p)[3])); GF_FONT_Delete((void *)(((u32 *)p)[2]));
    WIFIBATTLEMATCH_VIEW_Delete(((u32 *)p)[1]); WIFIBATTLEMATCH_GRAPHIC_Delete((char *)(((u32 *)p)[0]));
    func_020315D4((struct Proc *)sys); GFL_HEAP_DeleteChecked(87);
    func_02034A5C((int)ov114_id); func_02034A5C((int)ov067_id);
    return 1;
}
