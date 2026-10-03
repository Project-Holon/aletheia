/*
 * function: func_021B9AD4
 * address: 0x021B9AD4
 * packet: pkt_ov181_021B9AD4
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: SDK OS_SetIrqCheckFlag read-modify-write at 0x02FE3FF8.
 * symbols:
 *   SDK_AUTOLOAD_MAIN_TWL_START 0x02FE0000 data
 *   func_021B9DDC 0x021B9DDC thumb ov181
 *   func_020419E4 0x020419E4 arm
 */
extern void func_021B9DDC(char *),func_020419E4(void);
extern unsigned SDK_AUTOLOAD_MAIN_TWL_START[];
void func_021B9AD4(void *task,char *p){func_021B9DDC(p);func_020419E4();*(volatile unsigned *)((unsigned)SDK_AUTOLOAD_MAIN_TWL_START+0x3ff8) |=1;}
