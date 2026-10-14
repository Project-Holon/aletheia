/*
 * function: GSYNC_STATE_LoadReceivedMon
 * address: 0x021D7224
 * packet: pkt_ov123_021D7224
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: update the call-result local in both clamp arms to preserve its register.
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_02030734 0x02030734 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   d_021DAB78 0x021DAB78 data a1
 *   func_02009290 0x02009290 thumb
 *   func_020092F8 0x020092F8 thumb
 *   func_020093D4 0x020093D4 thumb
 *   POKE_TOOL_GetBoxParam  0x020185F4  thumb  arm9
 *   POKE_TOOL_GetPartyParamSize  0x020173EC  thumb  arm9
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb  arm9
 */
#include "../include/Obj01736.h"
typedef unsigned short u16;
typedef signed int     s32;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Sub02009210Obj;
struct Sub02009448Obj;
extern struct Sub02009448Obj *func_02009448(void *sys);
extern u32 func_020307B0(void *p);
extern int func_020076D0(void *save, int *pbox, int *pslot);
extern u32 POKE_TOOL_GetPartyParamSize(void);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u8 *func_02009290(struct Sub02009210Obj *obj);
extern void MI_CpuCopy8(void *,void *,int);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern void func_02019CA0(void *p, u32 v);
extern void *POKE_TOOL_GetBoxParam(void *p);
struct Sub02007454Entry;
extern int func_020074D8(void **save, const struct Sub02007454Entry *src);
extern void func_020092F8(struct Sub02009210Obj *obj, u8 value);
extern void func_020093D4(struct Sub02009210Obj *obj, s32 value);
extern const char d_021DAB78[];
void GSYNC_STATE_LoadReceivedMon(char *p)
{
    void *g;
    void *q;
    int size;
    int n;
    g=func_02009448(((struct Obj01736 *)p)->f28);
    if (((struct Obj01736 *)p)->fC) {
        func_020307B0(((struct Obj01736 *)p)->fC);
        ((struct Obj01736 *)p)->fC=0;
    }
    if (func_020076D0(((struct Obj01736 *)p)->f24,(int *)(p+0x48),(int *)(p+0x4c))) {
        q=func_02030734(((struct Obj01736 *)p)->f0,POKE_TOOL_GetPartyParamSize(),1,d_021DAB78,0x245);
        size=POKE_TOOL_GetPartyParamSize();
        MI_CpuCopy8(func_02009290(g),q,size);
        if (((struct Obj01736 *)p)->f6C) {
            n=POKE_TOOL_GetPartyValue(q,158,0);
            if (n==100) ((struct Obj01736 *)p)->f6C=0;
            if (n+((struct Obj01736 *)p)->f6C>100) {
                ((struct Obj01736 *)p)->f6C=100-n;
                n=100;
            } else {
                n+=((struct Obj01736 *)p)->f6C;
            }
            func_02019CA0(q,n);
        }
        func_020074D8(((struct Obj01736 *)p)->f24,(const struct Sub02007454Entry *)((int)POKE_TOOL_GetBoxParam(q)));
        ((struct Obj01736 *)p)->fC=q;
        func_020092F8(g,0);
        func_020093D4(g,((struct Obj01736 *)p)->f7C);
    }
}
