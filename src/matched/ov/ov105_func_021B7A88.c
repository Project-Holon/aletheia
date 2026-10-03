/*
 * function: func_021B7A88
 * address: 0x021B7A88
 * packet: pkt_ov105_021B7A88
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: later pos2 declaration reproduces its lower stack slot.
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_020490F4 0x020490F4 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B84C 0x0204B84C arm
 *   func_0204B800 0x0204B800 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B878 0x0204B878 arm
 *   d_020A1448 0x020A1448 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_02082BCC(void *,int,int);
extern void func_0204A48C(const void *,const void *,int);
typedef unsigned int   u32;
struct Bank;
struct Node;
struct Obj;
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void *func_0204ABF0(void *,int,int,int,int);
extern void *func_0204A6C8(void *,int,int,int,int);
extern void *func_0204AF28(void *,int,int,int);
extern void func_02049238(void *);
extern void *func_0204B294(void *,void *,void *,void *,void *,int,int);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B84C(void *,int);
extern void func_0204B800(struct Node *node, u32 val);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
extern const u8 d_020A1448[];
void func_021B7A88(void **p,const void *config,int heap)
{
    u16 pos[4],pos2[4];
    void *archive;
    int i;
    func_02082BCC(p,0,0xa8);
    func_0204A48C(d_020A1448,config,heap);
    p[0]=func_0204B100(128,0,heap);
    func_0204B270(p[0]);
    func_020434DC(16,1); func_02043598(16,1);
    archive=func_020490F4(0x5e,heap);
    p[1]=func_0204ABF0(archive,12,0,0,heap);
    p[2]=func_0204A6C8(archive,11,0,0,heap);
    p[3]=func_0204AF28(archive,10,9,heap);
    func_02049238(archive);
    func_02082BCC(pos,0,8);
    for(i=0;i<3;++i) p[4+i]=func_0204B294(p[0],p[2],p[1],p[3],pos,0,heap);
    func_02082BCC(pos2,0,8);
    pos2[0]=128; pos2[1]=96;
    p[41]=func_0204B294(p[0],p[2],p[1],p[3],pos2,0,heap);
    func_0204B3DC(p[41],0); func_0204B84C(p[41],0); func_0204B800(p[41],0);
    func_0204B92C(p[41],1); func_0204B878(p[41],11);
    for(i=0;i<3;++i) {
        func_0204B3DC(p[4+i],0); func_0204B84C(p[4+i],0); func_0204B800(p[4+i],0);
    }
}
