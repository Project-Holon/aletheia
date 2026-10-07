/*
 * file:     trcard_sys_p05.c
 * unit:     yes
 * function: func_0216F288, func_0216F2B4
 * address:  0x0216F288
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02031324 0x02031324 arm
 *   func_02031348 0x02031348 arm
 *   d_021725FC 0x021725FC data a4
 *   func_0216F088 0x0216F088 thumb ov010
 */
#include "../../matched/include/Obj01640.h"
#include "../../matched/include/Obj19154.h"

typedef unsigned short u16;

extern void *func_02031324(int a0);
extern void func_02031348(void *,int,void *,int);
extern int func_0216F088(int a0);
int func_0216F288(int *p);
int func_0216F2B4(char *p);
extern char d_021725FC[];

/*
 * func_02031324 forwards r0 to 02031354, which reads the heap input
 * and returns the allocation in r0. func_02031348 forwards all four
 * inputs to 020314F4, which reads/stores r0-r3. Legacy void(void)
 * prototypes omit these live inputs and the observed return value.
 */
int func_0216F288(int *p) { if(p[2]==0) p[2]=(int)func_02031324((u16)p[0]); func_02031348((void *)p[2],-1,d_021725FC,p[6]); return 2; }

/*
 * Extent: two-byte zero alignment padding at 0216F2DE.
 */
int func_0216F2B4(char *p) { int v; if (!func_0216F088((int)(p+8))) return 2; v=((struct Obj19154 *)(*(char * *)&((struct Obj01640 *)p)->f18))->fC; if(v==1) return 3; if(v==2) return 5; return 7; }
