/*
 * function: func_0215F630
 * address: 0x0215F630
 * packet: pkt_ov010_0215F630
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02159F80 0x02159F80 thumb ov010
 *   func_02012914 0x02012914 thumb
 */

extern int func_02159F80(void *);
extern unsigned short func_02012914(const void *);
typedef enum { FALSE = 0, TRUE = 1 } BOOL;
BOOL func_0215F630(void *p) { int a = func_02159F80(p); if(a == func_02012914(p)) return FALSE; else return TRUE; }
