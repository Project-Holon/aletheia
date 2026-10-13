/*
 * function: TRCARD_SYS_CreateViewWork
 * address: 0x0216F7BC
 * packet: pkt_ov010_0216F7BC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   d_02172B64 0x02172B64 data ov010 a1
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { void *f00; void *f04; void *f08; u32 f0c; u32 f10; u32 f14; } Record;
extern char d_02172B64[];
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_02082BCC(void *,int,int);
Record *TRCARD_SYS_CreateViewWork(void *a,u32 heap,void *b) { Record *p; p=func_02030734(heap,24,1,d_02172B64,0x321); func_02082BCC(p,0,24); p->f00=0; p->f04=a; p->f0c=0; p->f08=b; return p; }
