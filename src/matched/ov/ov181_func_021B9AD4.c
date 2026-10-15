/*
 * function: STAFF_ROLL_VblankTask
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
 *   STAFF_ROLL_FlushWindows 0x021B9DDC thumb ov181
 *   BG_SYS_Update 0x020419E4 arm
 */
extern void STAFF_ROLL_FlushWindows(char *),BG_SYS_Update(void);
extern unsigned SDK_AUTOLOAD_MAIN_TWL_START[];
void STAFF_ROLL_VblankTask(void *task,char *p){STAFF_ROLL_FlushWindows(p);BG_SYS_Update();*(volatile unsigned *)((unsigned)SDK_AUTOLOAD_MAIN_TWL_START+0x3ff8) |=1;}
