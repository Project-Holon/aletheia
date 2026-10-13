/*
 * function: UNION_COMM_ExitWait
 * address: 0x02172CE8
 * packet: pkt_ov012_02172CE8
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   UNION_COMM_Delete 0x02172C1C thumb ov012
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0200FBA0 0x0200FBA0 thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void UNION_COMM_Delete(void *a, u8 *p);
extern u32 func_0200FB24(void);
extern void func_0200FBA0(void);
int UNION_COMM_ExitWait(void *a, void *b, u8 *p) { if (p[0x3560] == 5) { UNION_COMM_Delete(b,p); if (func_0200FB24() != 0) func_0200FBA0(); return 1; } return 0; }
