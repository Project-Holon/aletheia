/*
 * function: func_02160FB4
 * address: 0x02160FB4
 * packet: pkt_ov010_02160FB4
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020120F8 0x020120F8 thumb
 *   func_02012AC8 0x02012AC8 thumb
 *   func_02013CC8 0x02013CC8 thumb
 *   func_02013CE0 0x02013CE0 thumb
 */

typedef unsigned int u32;
extern void *func_020120F8(void *);
extern unsigned short func_02012AC8(void *);
extern u32 func_02013CC8(u32);
extern u32 func_02013CE0(u32);
int func_02160FB4(void *p) { unsigned short id=func_02012AC8(func_020120F8(p)); if(func_02013CC8(id)==1) return 1; if(func_02013CE0(id)==1) return 3; return 0; }
