/*
 * function: TRCARD_SYS_StateStartCardProc
 * address: 0x0216F288
 * packet: pkt_ov010_0216F288
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * PROCSYS_Create forwards r0 to 02031354, which reads the heap input
 * and returns the allocation in r0. PROCSYS_Push forwards all four
 * inputs to 020314F4, which reads/stores r0-r3. Legacy void(void)
 * prototypes omit these live inputs and the observed return value.
 * symbols:
 *   PROCSYS_Create 0x02031324 arm
 *   PROCSYS_Push 0x02031348 arm
 *   d_021725FC 0x021725FC data a4
 */

typedef unsigned short u16;
extern void *PROCSYS_Create(int a0);
extern void PROCSYS_Push(void *,int,void *,int);
extern char d_021725FC[];
int TRCARD_SYS_StateStartCardProc(int *p) { if(p[2]==0) p[2]=(int)PROCSYS_Create((u16)p[0]); PROCSYS_Push((void *)p[2],-1,d_021725FC,p[6]); return 2; }
