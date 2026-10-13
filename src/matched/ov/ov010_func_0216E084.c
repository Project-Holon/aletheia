/*
 * function: FLDMMDL_InitGridPosition
 * address: 0x0216E084
 * packet: pkt_ov010_0216E084
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   FLDMMDL_InitPosition 0x0216E014 thumb ov010
 */

typedef unsigned short u16;
extern void FLDMMDL_InitPosition(void *, int *, int);
void FLDMMDL_InitGridPosition(void *a, unsigned int x, unsigned int y, unsigned int z, u16 k) { int p[3]; p[0]=(x<<16)+0x8000; p[1]=y<<16; p[2]=(z<<16)+0x8000; FLDMMDL_InitPosition(a,p,k); }
