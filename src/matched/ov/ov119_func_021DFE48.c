/*
 * function: func_021DFE48
 * address: 0x021DFE48
 * packet: pkt_ov119_021DFE48
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Repeat the message call in each arm; an id local factors the argument loads and is 20 bytes short.
 * symbols:
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   MSGDATA_ReadString 0x02045CAC arm
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   func_021D8FA4 0x021D8FA4 thumb ov119
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201F02C 0x0201F02C thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201F5DC 0x0201F5DC thumb
 *   func_021E0FF4 0x021E0FF4 thumb ov119
 *   func_021DFD30 0x021DFD30 thumb ov119
 *   func_02040588 0x02040588 arm
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DFF40 0x021DFF40 thumb ov119
 */
#include "../include/Obj00985.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct MsgBank;
struct WordSet;
extern void GFL_USE_CancelChangeAndPlayBgm(int,int);
extern void GFL_USE_FadeInBgmFull(u32 a);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern int func_021D8AA8(void *);
extern void *func_0201F5DC(void *a0, u32 a1, u32 a2, u32 a3);
extern void *func_021D8FA4(void *,int);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021E0FF4(void *,int,int);
extern void func_021DFD30(u8 *,u32);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_021D8E84(void *,int);
extern void func_021DFF40(char *p);
void func_021DFE48(char *p)
{
    void *mon;
    int z,state;
    if(((struct Obj00985 *)p)->fF2C<6) return;
    GFL_USE_CancelChangeAndPlayBgm(0x518,0xffff);
    GFL_USE_FadeInBgmFull(6);
    state=((struct Obj00985 *)p)->f118C;
    if(state==7) MSGDATA_ReadString((struct MsgBank *)(((struct Obj00985 *)p)->f720),153,(void *)(((struct Obj00985 *)p)->f73C));
    else if(state==8) MSGDATA_ReadString((struct MsgBank *)(((struct Obj00985 *)p)->f720),156,(void *)(((struct Obj00985 *)p)->f73C));
    else if(((struct Obj00985 *)p)->f11EE) MSGDATA_ReadString((struct MsgBank *)(((struct Obj00985 *)p)->f720),131,(void *)(((struct Obj00985 *)p)->f73C));
    else MSGDATA_ReadString((struct MsgBank *)(((struct Obj00985 *)p)->f720),48,(void *)(((struct Obj00985 *)p)->f73C));
    if(func_021D8AA8(p)) mon=func_021D8FA4(p,0);
    else mon=func_021D8FA4(p,1);
    func_0201EEF4(((struct Obj00985 *)p)->f724,1,mon);
    z=0;
    func_0201F02C((struct WordSet *)(*(int *)&((struct Obj00985 *)p)->f724),0,(void *)(((struct Obj00985 *)p)->f834));
    func_0201F250((struct WordSet *)(*(int *)&((struct Obj00985 *)p)->f724),(void *)(((struct Obj00985 *)p)->f738),(void *)(((struct Obj00985 *)p)->f73C));
    ((struct Obj00985 *)p)->f644=(int)func_0201F5DC((void *)6,15,0,((struct Obj00985 *)p)->f5F4);
    func_021E0FF4(p,1,0);
    func_021DFD30((u8 *)p,0);
    func_02040588(6,1);
    ((struct Obj00985 *)p)->fF2C=z;
    func_021D8E84(p,(int)func_021DFF40);
}
