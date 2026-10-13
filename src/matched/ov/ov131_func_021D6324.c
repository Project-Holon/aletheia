/*
 * function: P_STATUS_ProcInit
 * address: 0x021D6324
 * packet: pkt_ov131_021D6324
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note 2026-10-02 (lane R4): the two Moves copies per branch come from an inline helper
 *   taking the struct by value (argument temp + parameter copy), which sets the slot order.
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02030734 0x02030734 arm
 *   func_0203630C 0x0203630C arm
 *   func_0201A920 0x0201A920 thumb
 *   func_0201A954 0x0201A954 thumb
 *   func_020173F0 0x020173F0 thumb
 *   func_02017E40 0x02017E40 thumb
 *   func_0201A98C 0x0201A98C thumb
 *   func_020307B0 0x020307B0 arm
 *   POKE_TOOL_GetBoxParamSize 0x020173E8 thumb
 *   POKE_TOOL_ClearBoxParam 0x02017550 thumb
 *   func_02005728 0x02005728 thumb
 *   POKE_TOOL_SetupBoxParam 0x02017600 thumb
 *   POKE_TOOL_SetBoxValue 0x02017E64 thumb
 *   GAME_DATA_Create 0x020124F4 thumb
 *   func_020355D8 0x020355D8 arm
 *   P_STATUS_InitWork 0x021D4240 thumb ov131
 *   d_021DC80C 0x021DC80C data a1
 *   d_021DC138 0x021DC138 data a2
 *   d_021DC144 0x021DC144 data a2
 */
#include "../include/Obj00830.h"
#include "../include/Obj14064.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u16 v[5];} Moves;
extern void func_0203064C(unsigned int,unsigned int,unsigned int);
struct Obj0203159C;
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,int,int);
typedef signed int     s32;
struct Party;
struct PartyMon;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_0203630C(void);
extern struct Party *func_0201A920(u32 heap);
extern void func_0201A954(struct Party *p, s32 capacity);
extern void *func_020173F0(u16,u16,u32,u32,u32);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern u32 func_020307B0(void *p);
extern u32 POKE_TOOL_GetBoxParamSize(void);
struct Sav;
extern void POKE_TOOL_ClearBoxParam(struct Sav *p);
extern u32 func_02005728(u32 range);
typedef unsigned long long u64;
extern void POKE_TOOL_SetupBoxParam(void *obj,u16 species,u16 level,u64 id);
extern void POKE_TOOL_SetBoxValue(void *p, u32 id, u32 v);
extern void *GAME_DATA_Create(u16);
extern void func_020355D8(u8 v);
extern int P_STATUS_InitWork(char *);
extern const char d_021DC80C[];
extern const Moves d_021DC138,d_021DC144;
static inline void SetA(void *p, Moves m) { func_02017E40(p,0x8e,(u32)(&m)); }
static inline void SetB(void *p, Moves m) { POKE_TOOL_SetBoxValue(p,0x8e,(u32)(&m)); }
int P_STATUS_ProcInit(u32 heap,int *st,u8 *obj,char *d) {
    switch(*st) {
    case 0: {
        u8 *c=obj;
        u8 *o;
        u8 i;
                func_0203064C(1,0x42,0x50000);
        o=func_0203159C((void *)heap,0x264,0x42);
        func_02082BCC(o,0,0x264);
        ((struct Obj14064 *)o)->f0=0x42;
        i=0;
        if(c==0) {
            c=func_02030734(1,0x28,0,d_021DC80C,0x4d);
            if((func_0203630C()&0x400)==0) {
                void *party;
                void *pt;
                party=func_0201A920(1);
                func_0201A954(party,6);
                for(i=0;i<5;i++) {
                    pt=func_020173F0(i+3,10,-1,0,1);
                    SetA(pt,d_021DC138);
                    func_02017E40(pt,0x9a,0);
                    func_0201A98C(party,pt);
                    func_020307B0(pt);
                }
                c[0xf]=0;
                ((struct Obj00830 *)c)->f0=party;
                c[0xc]=1;
                c[0xe]=5;
            } else {
                int n;
                u8 *base;
                u32 off;
                n=POKE_TOOL_GetBoxParamSize();
                ((struct Obj00830 *)c)->f0=func_02030734(1,n*0x1e,1,d_021DC80C,0x81);
                c[0xc]=2;
                c[0xe]=0x1e;
                c[0xf]=0xff;
                for(i=0;i<c[0xe];i++) {
                    n=POKE_TOOL_GetBoxParamSize();
                    base=*(u8 * *)&((struct Obj00830 *)c)->f0;
                    off=i*n;
                    POKE_TOOL_ClearBoxParam((struct Sav *)(base+off));
                    if(func_02005728(3)!=0) {
                        POKE_TOOL_SetupBoxParam(base+off,i+1,0x32,(u64)-1);
                        SetB(base+off,d_021DC144);
                        POKE_TOOL_SetBoxValue(base+off,0x9a,0);
                        if(c[0xf]==0xff) c[0xf]=i;
                    }
                }
            }
            i=0;
            c[0xd]=0;
            c[0x10]=0;
            ((struct Obj00830 *)c)->f20=1;
            ((struct Obj00830 *)c)->f18=1;
            ((struct Obj00830 *)c)->f8=GAME_DATA_Create(1);
            if(func_0203630C()&0x400) {
                c[0xd]=2;
                ((struct Obj00830 *)c)->f20=i;
                ((struct Obj00830 *)c)->f14=10;
            }
            if(func_0203630C()&0x100) {
                c[0xd]=1;
                ((struct Obj00830 *)c)->f20=0;
            }
            func_020355D8(1);
        }
        *(u8 * *)&((struct Obj14064 *)o)->f8=c;
        *st=1;
        break;
    }
    case 1:
        if(P_STATUS_InitWork(d)==1) return 1;
        break;
    }
    return 0;
}
