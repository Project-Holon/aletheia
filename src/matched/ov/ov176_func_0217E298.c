/*
 * function: func_0217E298
 * address: 0x0217E298
 * packet: pkt_ov176_0217E298
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201A918 0x0201A918 thumb
 *   func_02082D44 0x02082D44 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_0201A918(void);
extern void func_02082D44(void *,const void *,u32);
int func_0217E298(u8 *p,const void *q) {int v;v=*(int *)(p+0x100c);if(v) {*(int *)(p+0x100c)=0;func_02082D44(p+6,q,func_0201A918());}return v;}
