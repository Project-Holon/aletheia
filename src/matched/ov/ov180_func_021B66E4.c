/*
 * function: func_021B66E4
 * address: 0x021B66E4
 * packet: pkt_ov180_021B66E4
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02047964 0x02047964 arm
 *   func_020479D8 0x020479D8 arm
 *   MCSS_Main 0x02014C08 thumb
 *   MCSS_Draw 0x02014D2C thumb
 *   func_02047970 0x02047970 arm
 */
#include "../include/Obj14398.h"
typedef unsigned int u32;
typedef unsigned short u16;
struct McssSys;
extern void func_02047964(void);
extern void func_020479D8(void);
extern void MCSS_Main(char *);
extern void MCSS_Draw(struct McssSys *);
extern void func_02047970(void);
void func_021B66E4(char *p) {func_02047964();func_020479D8();MCSS_Main(*(char * *)&((struct Obj14398 *)p)->f18);MCSS_Draw(*(struct McssSys * *)&((struct Obj14398 *)p)->f18);func_02047970();}
