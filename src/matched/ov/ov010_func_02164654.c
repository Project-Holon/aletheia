/*
 * function: func_02164654
 * address: 0x02164654
 * packet: pkt_ov010_02164654
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_021645E0 0x021645E0 thumb ov010
 */

typedef unsigned int u32;
typedef struct { void *p; u32 n; } Work;
extern void *func_020122C0(void *, void *, void *, u32);
extern Work *func_020124E8(void *);
extern int func_021645E0(void *, int *, int *);
void *func_02164654(void *unused, void *a) { void *task; Work *w; int zero=0; task=func_020122C0(a,0,(void *)func_021645E0,8); w=func_020124E8(task); w->p=a; w->n=zero; return task; }
