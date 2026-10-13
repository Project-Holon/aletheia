/*
 * function: NNSi_SndSeqPlayerSetPriority
 * address:  0x02073760
 * packet:   pkt_02073624
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   gSndActiveSeqList  0x0214E018  data
 *   NNSi_SndPlayerInsertSeqPlayer  0x02073548  arm
 *   NNSi_SndInsertActiveSeqPlayer  0x02073598  arm
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;


struct A { u32 f0; u32 f4; u8 p8[0x3d - 8]; u8 f3d; };
struct DList;
struct Obj_02073548;
extern void func_020605B4(volatile struct DList *list, void *elem);
extern void NNSi_SndPlayerInsertSeqPlayer(void *list, struct Obj_02073548 *obj);
extern void NNSi_SndInsertActiveSeqPlayer(struct Obj_02073548 *obj);
extern u8 gSndActiveSeqList[];
void NNSi_SndSeqPlayerSetPriority(struct A *o, u32 v) {
    u32 q = o->f4;
    if (q != 0) { func_020605B4((void *)q, o); o->f4 = 0; }
    func_020605B4((volatile struct DList *)gSndActiveSeqList, o);
    o->f3d = (u8)v;
    if (q != 0) NNSi_SndPlayerInsertSeqPlayer((void *)q, (struct Obj_02073548 *)o);
    NNSi_SndInsertActiveSeqPlayer((struct Obj_02073548 *)o);
}
