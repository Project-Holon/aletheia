/*
 * function: MB_COMM_SYS_CreateNetState
 * address: 0x021F0DE8
 * packet: pkt_ov107_021F0DE8
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   POKE_TOOL_GetBoxParamSize 0x020173E8 thumb
 *   d_021F6E28 0x021F6E28 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u32,u32,int,const char *,u16);
extern u32 POKE_TOOL_GetBoxParamSize(void);
extern const char d_021F6E28[];
typedef struct {u16 f00,pad02;u32 f04,f08,f0C;void *f10;u32 f14;u16 pad18:11;u16 f18:1;u16 pad19:4;u8 pad1A[14];} Object;
Object *MB_COMM_SYS_CreateNetState(u16 heap){Object *p;p=func_02030734(heap,40,1,d_021F6E28,159);p->f00=heap;p->f04=0;p->f14=0;p->f18=0;p->f0C=0;p->f08=0;p->f10=func_02030734(p->f00,6*POKE_TOOL_GetBoxParamSize()+4,1,d_021F6E28,169);return p;}
