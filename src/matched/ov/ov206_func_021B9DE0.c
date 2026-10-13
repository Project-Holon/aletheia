/*
 * function: func_021B9DE0
 * address: 0x021B9DE0
 * packet: pkt_ov206_021B9DE0
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02017E1C 0x02017E1C thumb
 *   POKE_TOOL_GetGender 0x02017F00 thumb
 *   func_02017EAC 0x02017EAC thumb
 *   func_021B9E68 0x021B9E68 thumb ov206
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern unsigned func_02017E1C(void *,unsigned,unsigned);
extern u8 POKE_TOOL_GetGender(void *);
extern unsigned func_02017EAC(void *);
extern void *func_021B9E68(unsigned,u16,u16,unsigned,u16,unsigned,unsigned,unsigned,unsigned,unsigned,u8,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);
void *func_021B9DE0(u16 heap,void *mon,unsigned a2,unsigned a3,unsigned a4,unsigned a5,u8 a6,unsigned a7,unsigned a8,unsigned a9,unsigned a10,unsigned a11,unsigned a12)
{
    u16 species,form,move;
    unsigned gender;
    species=(u16)func_02017E1C(mon,5,0);
    form=(u16)func_02017E1C(mon,111,0);
    gender=POKE_TOOL_GetGender(mon);
    move=(u16)func_02017EAC(mon);
    return func_021B9E68(heap,species,form,gender,move,func_02017E1C(mon,0,0),a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12);
}
