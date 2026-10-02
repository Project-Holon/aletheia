/*
 * function: func_02157870
 * address: 0x02157870
 * packet: pkt_ov010_02157870
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 28-byte lead followed by existing matched ov010_func_0215788C.c.
 * symbols:
 *   func_0203D010 0x0203D010 arm
 *   func_021576C4 0x021576C4 thumb ov010
 *   func_02157760 0x02157760 thumb ov010
 */
extern void func_0203D010(void);
extern void func_021576C4(void *, void (*)(void), int);
extern void func_02157760(void);
void func_02157870(void *p) { func_0203D010(); func_021576C4(p, func_02157760, 0x1d7); }
