/*
 * function: func_021FE444
 * address: 0x021FE444
 * packet: pkt_ov186_021FE444
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: inline pair copy loads y then x before storing; aggregate copy differed by 20 bytes, raw field stores by 23, const raw stores by 22.
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   func_021FE478 0x021FE478 thumb ov186
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {int x,y;} Pair; extern void MI_CpuFill8(void *,int,u32); extern int func_021FE478(int *,Pair *,int);
static inline void copyPair(Pair *dest,const Pair *src) { int y,x; y=src->y; x=src->x; dest->y=y; dest->x=x; }
void func_021FE444(int *p,const Pair *a,const Pair *b,int c,int d) { MI_CpuFill8(p,0,0x20); copyPair((Pair *)p,a); copyPair((Pair *)(p+2),b); p[7]=d; p[6]=c; func_021FE478(p,0,0); }
