/*
 * function: func_021B7AB4
 * address: 0x021B7AB4
 * packet: pkt_ov102_021B7AB4
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * declaration: 0204ABF0 forwards the live result of int-returning 0204AC18; 0204B294 forwards the pointer result of 0204CFDC. Its fifth word is copied unchanged as 0204CFDC's request pointer.
 * symbols:
 * func_02082BCC 0x02082BCC arm
 * func_0204A48C 0x0204A48C arm
 * func_0204B100 0x0204B100 arm
 * func_0204B270 0x0204B270 arm
 * func_020434DC 0x020434DC arm
 * func_02043598 0x02043598 arm
 * func_020490F4 0x020490F4 arm
 * func_0204ABF0 0x0204ABF0 arm
 * func_0204A6C8 0x0204A6C8 arm
 * func_0204AF28 0x0204AF28 arm
 * func_02049238 0x02049238 arm
 * func_0204B294 0x0204B294 arm
 * func_0204B3DC 0x0204B3DC arm
 * func_0204B84C 0x0204B84C arm
 * func_0204B92C 0x0204B92C arm
 * d_020A1448 0x020A1448 data a4
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern char d_020A1448[];
extern void func_02082BCC(void *,int,u32);
extern void func_0204A48C(const void *,u32,u32);
typedef unsigned char  u8;
struct Bank;
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_020434DC(u32,u32),func_02043598(u32,u32);
extern void *func_020490F4(unsigned int id, u16 heap);
extern int func_0204ABF0(void *,u32,u32,u32,u16);
extern int func_0204A6C8(void *,u32,u32,u32,u16);
extern int func_0204AF28(void *,u32,u32,u32);
extern void func_02049238(void *);
struct Obj;
extern struct Obj *func_0204B294(void *,u32,u32,u32,const void *,u16,u16);
extern void func_0204B3DC(void *,u32),func_0204B84C(void *,u32),func_0204B92C(struct Obj *,u32);
struct State { void *bank; u32 palette, chars, other; void *actors[32]; };
void func_021B7AB4(struct State *p,const void *config,u16 heap)
{
    void *arc;
    int i;
    u16 point[4];
    func_02082BCC(p,0,0x90);
    func_0204A48C(d_020A1448,(u32)config,heap);
    p->bank=func_0204B100(128,0,heap);
    func_0204B270(p->bank);
    func_020434DC(16,1);
    func_02043598(16,1);
    arc=func_020490F4(94,heap);
    p->palette=func_0204ABF0(arc,12,1,0,heap);
    p->chars=func_0204A6C8(arc,11,0,1,heap);
    p->other=func_0204AF28(arc,10,9,heap);
    func_02049238(arc);
    func_02082BCC(point,0,8);
    for(i=0;i<30;i++) {
        p->actors[i]=func_0204B294(p->bank,p->chars,p->palette,p->other,point,1,heap);
        func_0204B3DC(p->actors[i],0);
        func_0204B84C(p->actors[i],3);
        func_0204B92C(p->actors[i],1);
    }
    point[0]=129; point[1]=104; point[2]=15;
    p->actors[31]=func_0204B294(p->bank,p->chars,p->palette,p->other,point,1,heap);
    func_0204B3DC(p->actors[31],1);
    func_0204B84C(p->actors[31],2);
    func_0204B92C(p->actors[31],0);
}
