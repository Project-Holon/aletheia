/*
 * function: func_021DE12C
 * address: 0x021DE12C
 * packet: pkt_ov119_021DE12C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MSGDATA_ReadString 0x02045CAC arm
 *   func_021E1024 0x021E1024 thumb ov119
 *   func_021E1030 0x021E1030 thumb ov119
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_021D9468 0x021D9468 thumb ov119
 *   POKE_TOOL_GetPartyParamSize 0x020173EC thumb
 *   func_021D8FA4 0x021D8FA4 thumb ov119
 *   func_02082D44 0x02082D44 arm
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DDF74 0x021DDF74 thumb ov119
 *   func_021DE0F0 0x021DE0F0 thumb ov119
 */
#include "../include/Obj05329.h"
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, unsigned int index, void *dest);
extern void func_021E1024(void *);
typedef unsigned int   u32;
extern void func_021E1030(char *p);
extern int func_021D8A24(void *);
extern void func_021D9468(void *,int,void *);
extern u32 POKE_TOOL_GetPartyParamSize(void);
extern void *func_021D8FA4(void *,int);
extern void func_02082D44(void *,const void *,int);
extern void func_021D8E84(void *,int);
extern void func_021DDF74(char *p);
extern void func_021DE0F0(void *);
void func_021DE12C(char *p)
{
    void *obj;
    int n;
    MSGDATA_ReadString((struct MsgBank *)(((struct Obj05329 *)p)->f720),0x88,(void *)(((struct Obj05329 *)p)->f738));
    func_021E1024(p);
    func_021E1030(p);
    p[0x11f1]=120;
    if(func_021D8A24(p)==0) {
        p[0x11e0]=11;
        p[0x11e1]=11;
        obj=((struct Obj05329 *)p)->fFD8;
        func_021D9468(p,1,obj);
        n=POKE_TOOL_GetPartyParamSize();
        func_02082D44(obj,func_021D8FA4(p,1),n);
        func_021D8E84(p,(int)func_021DDF74);
        return;
    }
    func_021D8E84(p,(int)func_021DE0F0);
}
