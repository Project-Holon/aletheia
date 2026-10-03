/*
 * unit: yes
 * function: func_021BE0EC, func_021BE100, func_021BE108
 * address: 0x021BE0EC
 * packet: pkt_ov204_021BE0EC
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02048AD0 0x02048AD0 arm
 *   func_02047964 0x02047964 arm
 *   func_020479D8 0x020479D8 arm
 *   func_02047970 0x02047970 arm
 */
struct Light;
/* Original consumes 02048AD0's live r0 through the next veneer call. */
extern void *func_02048AD0(struct Light *);
extern void func_02047964(void *);
extern void func_020479D8(void);
void func_021BE0EC(char *p){func_02047964(func_02048AD0(*(struct Light **)p));func_020479D8();}
extern void func_02047970(void);
void func_021BE100(char *unused){func_02047970();}
int func_021BE108(void){return 1;}
