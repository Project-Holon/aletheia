/*
 * function: func_021BAF3C
 * address: 0x021BAF3C
 * packet: pkt_ov072_021BAF3C
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA774 0x021BA774 thumb ov072
 *   func_0204B404 0x0204B404 arm
 */
typedef unsigned int u32;
typedef struct { short x,y; } Pt;
extern int func_021BA774(char *p, int i);
extern void func_0204B404(void *,void *,int);
void func_021BAF3C(u32 *p,const u32 *v) { Pt t; if(p[1]!=0) { t.x=v[0]+func_021BA774((char *)p[1],2); t.y=v[1]+func_021BA774((char *)p[1],3); } func_0204B404((void *)p[0],&t,0); }
