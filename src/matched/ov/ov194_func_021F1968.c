/*
 * function: func_021F1968
 * address: 0x021F1968
 * packet: pkt_ov194_021F1968
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0204B3B4(void *);
extern void func_0204ADA4(int);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(int);
void func_021F1968(u8 *p) { int i; for(i=0;i<21;i++) { void *q=*(void **)((u32)p+(u32)i*4+12); if(q)func_0204B3B4(q); } func_0204ADA4(*(int *)p);func_0204A8D4((u32)(*(void **)(p+4)));func_0204AFD8(*(int *)(p+8)); }
