/*
 * function: ZUKAN_DETAIL_INFO_Exit
 * address: 0x021BEA90
 * packet: pkt_ov208_021BEA90
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * matching: full-width stack argument reloads; small pool operands are overlay ID symbols.
 * symbols:
 *   ZUKAN_DETAIL_INFO_ClearButtonHighlight 0x021BF63C thumb ov208
 *   ZUKAN_DETAIL_INFO_NoOpHighlight 0x021BF61C thumb ov208
 *   func_021BA2CC 0x021BA2CC thumb ov206
 *   ZUKAN_DETAIL_INFO_DeleteLanguageButtons 0x021BF41C thumb ov208
 *   GF_FONT_Delete 0x0201D83C thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   ZUKAN_DETAIL_COMMON_FreeBlendWork 0x021BC464 thumb ov208
 *   func_02030EAC 0x02030EAC arm
 *   ZUKAN_DETAIL_PROCSYS_FreeBuffer 0x021BC34C thumb ov208
 *   func_02034A5C 0x02034A5C arm
 *   ov206_id 0x000000CE data
 *   ov067_id 0x00000043 data
 * Caller visibly supplies third arguments to helpers and a live r0 to BC464.
 */
#include "../include/Obj03362.h"
struct Rec;struct Node;
extern char ov206_id[],ov067_id[];
extern void ZUKAN_DETAIL_INFO_ClearButtonHighlight(int,char *,unsigned);
extern void ZUKAN_DETAIL_INFO_NoOpHighlight(int,char *,unsigned);
extern void func_021BA2CC(char *);
extern void ZUKAN_DETAIL_INFO_DeleteLanguageButtons(int,char *,unsigned);
typedef unsigned int   u32;
extern u32 GF_FONT_Delete(void *ptr);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void ZUKAN_DETAIL_COMMON_FreeBlendWork(void *);
extern void func_02030EAC(struct Node *);
extern void ZUKAN_DETAIL_PROCSYS_FreeBuffer(char *);
extern void func_02034A5C(int);
int ZUKAN_DETAIL_INFO_Exit(char *first,unsigned unused,int owner,char *q,unsigned heap)
{
    ZUKAN_DETAIL_INFO_ClearButtonHighlight(owner,q,heap);ZUKAN_DETAIL_INFO_NoOpHighlight(owner,q,heap);
    func_021BA2CC(*(char * *)&((struct Obj03362 *)q)->f8);func_021BA2CC(*(char * *)&((struct Obj03362 *)q)->f4);
    ZUKAN_DETAIL_INFO_DeleteLanguageButtons(owner,q,heap);
    GF_FONT_Delete(((struct Obj03362 *)q)->f110);
    MSGDATA_Delete(*(struct Rec * *)&((struct Obj03362 *)q)->f11C);
    MSGDATA_Delete(*(struct Rec * *)&((struct Obj03362 *)q)->f118);
    MSGDATA_Delete(*(struct Rec * *)&((struct Obj03362 *)q)->f114);
    ZUKAN_DETAIL_COMMON_FreeBlendWork(((struct Obj03362 *)q)->f10);ZUKAN_DETAIL_COMMON_FreeBlendWork(((struct Obj03362 *)q)->fC);
    func_02030EAC(*(struct Node * *)&((struct Obj03362 *)q)->f0);ZUKAN_DETAIL_PROCSYS_FreeBuffer(first);
    func_02034A5C((int)ov206_id);func_02034A5C((int)ov067_id);return 1;
}
