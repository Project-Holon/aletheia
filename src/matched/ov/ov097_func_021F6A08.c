/*
 * function: func_021F6A08
 * address: 0x021F6A08
 * packet: pkt_ov097_021F6A08
 * region: ov097
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: SDK OS_SetIrqCheckFlag read-modify-write at 021F6A18/021F6A1C, HW_INTR_CHECK_BUF.
 * symbols:
 *   func_020419E4 0x020419E4 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   SDK_AUTOLOAD_DTCM_START 0x02FE0000 data
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_020419E4(void);
extern void CLACT_VBlankSystem(void);
extern u32 SDK_AUTOLOAD_DTCM_START[];
static inline void OS_SetIrqCheckFlag(u32 intr) { *(volatile u32 *)((u32)SDK_AUTOLOAD_DTCM_START + 0x3ff8) |= intr; }
void func_021F6A08(void) { func_020419E4(); CLACT_VBlankSystem(); OS_SetIrqCheckFlag(1); }
