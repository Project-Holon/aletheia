/*
 * function: func_021B7DC4
 * address: 0x021B7DC4
 * packet: pkt_ov102_021B7DC4
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 */
struct Descriptor;
extern void *func_02045770(struct Descriptor *); extern int func_0201C6C4(int,int); extern void func_02045334(int);
int func_021B7DC4(unsigned char *p,unsigned char *q) { int a=*(int *)(q+8); if (p[8]) { if (!func_0201C6C4(a,(int)func_02045770((struct Descriptor *)*(int *)(p+4)))) { func_02045334(*(int *)(p+4)); p[8]=0; } } if (!p[8]) return 1; return 0; }
