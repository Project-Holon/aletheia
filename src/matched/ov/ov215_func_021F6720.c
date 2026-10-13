/*
 * function: func_021F6720
 * address: 0x021F6720
 * packet: pkt_ov215_021F6720
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: sole callback 021F6AB4 resolved after owned leaf shard verification.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   func_020056A0 0x020056A0 thumb
 *   func_021F6AB4 0x021F6AB4 thumb ov215
 *   func_021F6AB8 0x021F6AB8 thumb ov215
 *   func_021F6AEC 0x021F6AEC thumb ov215
 *   func_021F6DB4 0x021F6DB4 thumb ov215
 *   func_021F6EF8 0x021F6EF8 thumb ov215
 *   func_021F6F64 0x021F6F64 thumb ov215
 *   d_021F73F4 0x021F73F4 data a4
 *   d_021F7340 0x021F7340 data a4
 *   d_021F7314 0x021F7314 data a4
 */
#include "../include/Obj00317.h"
typedef unsigned short u16;
extern const char d_021F73F4[];
extern const unsigned d_021F7340[],d_021F7314[];
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
typedef unsigned int   u32;
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern void *func_020056A0(void (*)(void),void *,unsigned);
extern void func_021F6AB4(void);
extern void func_021F6AB8(char *p);
extern void func_021F6AEC(char *p);
extern char *func_021F6DB4(unsigned,unsigned,const void *);
extern void func_021F6EF8(char *p);
extern void func_021F6F64(char *p);
char *func_021F6720(unsigned heap,void *mon)
{
    char *p;
    p=func_02030734(heap,96,1,d_021F73F4,433);
    ((struct Obj00317 *)p)->f0=heap;
    ((struct Obj00317 *)p)->f4=mon;
    ((struct Obj00317 *)p)->f8=POKE_TOOL_GetPartyValue(mon,5,0);
    ((struct Obj00317 *)p)->fC=0;
    ((struct Obj00317 *)p)->f10=0;
    ((struct Obj00317 *)p)->f14=0;
    ((struct Obj00317 *)p)->f18=0;
    ((struct Obj00317 *)p)->f1C=0;
    ((struct Obj00317 *)p)->f24=0;
    ((struct Obj00317 *)p)->f28=0;
    ((struct Obj00317 *)p)->f2C=func_020056A0(func_021F6AB4,p,1);
    func_021F6AB8(p);
    func_021F6AEC(p);
    if(((struct Obj00317 *)p)->f8==490)
        ((struct Obj00317 *)p)->f44=func_021F6DB4(((struct Obj00317 *)p)->f0,5,d_021F7340);
    else
        ((struct Obj00317 *)p)->f44=func_021F6DB4(((struct Obj00317 *)p)->f0,3,d_021F7314);
    func_021F6EF8(p);
    func_021F6F64(p);
    return p;
}
