/*
 * function: func_0216435C
 * address: 0x0216435C
 * packet: pkt_ov010_0216435C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0216D69C 0x0216D69C thumb ov010
 */

typedef unsigned short u16;
extern void *func_0216D69C(void *p);
void func_0216435C(void *a, const u16 *b) { u16 *p=func_0216D69C(a); p[2]=b[0]; p[3]=b[1]; p[4]=b[2]; p[5]=b[3]; *(unsigned *)p=0xEFEFEFEF; }
