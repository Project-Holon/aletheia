/*
 * function: func_021D6A98
 * address: 0x021D6A98
 * packet: pkt_ov175_021D6A98
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_021DD008 0x021DD008 thumb ov175
 *   func_021E7DF0 0x021E7DF0 thumb ov177
 *   func_021E8A78 0x021E8A78 thumb ov177
 *   func_021E8628 0x021E8628 thumb ov177
 *   func_021D9EA0 0x021D9EA0 thumb ov175
 *   func_021D98B8 0x021D98B8 thumb ov175
 *   func_021D9854 0x021D9854 thumb ov175
 *   func_021D97A4 0x021D97A4 thumb ov175
 *   func_021D99F4 0x021D99F4 thumb ov175
 *   func_0201ED04 0x0201ED04 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   func_021E5868 0x021E5868 thumb ov177
 *   func_021E54E0 0x021E54E0 thumb ov177
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov114_id 0x00000072 data
 *   ov067_id 0x00000043 data
 */
#include "../include/Obj01563.h"
typedef unsigned int u32;
extern const char ov114_id[],ov067_id[];
extern u32 func_020307B0(void *p);
extern void func_021DD008(char *,int);
typedef unsigned char  u8;
struct PrintSys;
struct Rec;
struct WordSet;
extern void func_021E7DF0(int *p);
extern void func_021E8A78(void *p);
extern void func_021E8628(char *p);
extern void func_021D9EA0(u8 *p);
extern void func_021D98B8(char *);
extern void func_021D9854(char *);
extern void func_021D97A4(char *);
extern void func_021D99F4(char *);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void func_021E5868(u32);
extern void func_021E54E0(char *p);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(u32);
extern void func_02034A5C(int);
int func_021D6A98(u32 sys,u32 unused,u32 arg,char *p)
{
    func_020307B0(((struct Obj01563 *)p)->fFC);
    func_021DD008((char *)((u32 *)p)[13],0);
    func_021E7DF0((int *)(((u32 *)p)[10]));
    func_021E8A78((void *)(((u32 *)p)[15])); func_021E8A78((void *)(((u32 *)p)[14]));
    func_021E8628((char *)(((u32 *)p)[11]));
    if(((u32 *)p)[13]) func_021D9EA0((u8 *)(((u32 *)p)[13]));
    func_021D98B8(p); func_021D9854(p); func_021D97A4(p); func_021D99F4(p);
    func_0201ED04((struct WordSet *)(((u32 *)p)[6])); MSGDATA_Delete((struct Rec *)(((u32 *)p)[5]));
    PRINTSYS_QUE_Delete((struct PrintSys *)(((u32 *)p)[4])); GF_FONT_Delete((void *)(((u32 *)p)[3])); GF_FONT_Delete((void *)(((u32 *)p)[2]));
    func_021E5868(((u32 *)p)[1]); func_021E54E0((char *)(((u32 *)p)[0]));
    func_020315D4((struct S020315D4 *)sys); func_020306F0(87);
    func_02034A5C((int)ov114_id); func_02034A5C((int)ov067_id);
    return 1;
}
