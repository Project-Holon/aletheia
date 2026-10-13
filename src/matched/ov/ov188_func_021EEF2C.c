/*
 * function: func_021EEF2C
 * address: 0x021EEF2C
 * packet: pkt_ov188_021EEF2C
 * region: ov188
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKE_TOOL_GetPartyParamSize 0x020173EC thumb
 *   func_02030734 0x02030734 arm
 *   POKEPARTY_InitEx 0x0201A954 thumb
 *   func_021EEBF0 0x021EEBF0 thumb ov188
 *   POKE_TOOL_SetPartyValue 0x02017E40 thumb
 *   POKEPARTY_Add 0x0201A98C thumb
 *   func_020307B0 0x020307B0 arm
 *   d_021EF360 0x021EF360 data a4
 */
#include "../include/Obj14491.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 POKE_TOOL_GetPartyParamSize(void);
extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
typedef signed int     s32;
struct Party;
extern void POKEPARTY_InitEx(struct Party *p, s32 capacity);
struct Mon;
struct PartyMon;
extern void func_021EEBF0(char *p, struct Mon *q);
extern void POKE_TOOL_SetPartyValue(void *,u32,u32);
extern u32 POKEPARTY_Add(struct Party *p, const struct PartyMon *src);
extern u32 func_020307B0(void *p);
extern char d_021EF360[];
void func_021EEF2C(u8 *a,void *b,u32 c)
{
    int i;
    u8 *p;
    p=func_02030734((u16)((c & 0x7FFF)|0x8000),POKE_TOOL_GetPartyParamSize(),1,d_021EF360,173);
    POKEPARTY_InitEx(b,((struct Obj14491 *)a)->f0);
    for(i=0;i<((struct Obj14491 *)a)->f2;i++) {
        func_021EEBF0((char *)(a+4+i*112),(struct Mon *)p);
        POKE_TOOL_SetPartyValue(p,159,0);
        POKEPARTY_Add(b,(const struct PartyMon *)p);
    }
    func_020307B0(p);
}
