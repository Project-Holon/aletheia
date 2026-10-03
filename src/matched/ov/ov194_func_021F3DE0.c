/*
 * function: func_021F3DE0
 * address: 0x021F3DE0
 * packet: pkt_ov194_021F3DE0
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020173F0 0x020173F0 thumb
 *   func_02017E40 0x02017E40 thumb
 *   func_021F3E18 0x021F3E18 thumb ov194
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
/* Callee species is u16; this caller passes r2 without truncation. */
extern void *func_020173F0(u32,u16,u64,u16);
extern void func_02017E40(void *,u32,u32),func_021F3E18(char *,int,void *),func_020307B0(void *);
void func_021F3DE0(char *p,int value,u32 id,u32 form,u16 heap) {void *mon;mon=func_020173F0(id,1,0,heap);func_02017E40(mon,111,form);func_021F3E18(p,value,mon);func_020307B0(mon);}
