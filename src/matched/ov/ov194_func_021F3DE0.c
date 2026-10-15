/*
 * function: NAMEIN_GRAPHIC_PrintPokeMsg
 * address: 0x021F3DE0
 * packet: pkt_ov194_021F3DE0
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   POKE_TOOL_Create 0x020173F0 thumb
 *   POKE_TOOL_SetPartyValue 0x02017E40 thumb
 *   NAMEIN_GRAPHIC_PrintMonMsg 0x021F3E18 thumb ov194
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
/* Callee species is u16; this caller passes r2 without truncation. */
extern void *POKE_TOOL_Create(u32,u16,u64,u16);
extern void POKE_TOOL_SetPartyValue(void *,u32,u32);
extern void NAMEIN_GRAPHIC_PrintMonMsg(char *,int,void *);
extern u32 func_020307B0(void *p);
void NAMEIN_GRAPHIC_PrintPokeMsg(char *p,int value,u32 id,u32 form,u16 heap) {void *mon;mon=POKE_TOOL_Create(id,1,0,heap);POKE_TOOL_SetPartyValue(mon,111,form);NAMEIN_GRAPHIC_PrintMonMsg(p,value,mon);func_020307B0(mon);}
