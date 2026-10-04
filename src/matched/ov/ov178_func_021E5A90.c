/*
 * function: func_021E5A90
 * address: 0x021E5A90
 * packet: pkt_ov178_021E5A90
 * region: ov178
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0200FB38 0x0200FB38 thumb
 *   func_020399A8 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_0217E258 0x0217E258 thumb ov176
 *   func_0217E298 0x0217E298 thumb ov176
 *   func_0217E074 0x0217E074 thumb ov176
 */
typedef unsigned int   u32;
struct Entry;
extern u32 func_0200FB24(void);
extern void func_0200FB38(void);
extern struct Entry *func_020399A8(void);
struct Link;
extern void func_02039C68(struct Link *,u32,u32);
extern u32 func_02039CB4(struct Link *,u32,u32);
extern int func_0217E258(void *,unsigned);
extern int func_0217E298(void *,unsigned);
extern void func_0217E074(void *);
unsigned func_021E5A90(void **d,unsigned *c,unsigned *state)
{
 if(func_0200FB24()!=0){func_0200FB38();c[2]=2;return 1;}
 switch(*state) {
 case 0:++*state;break;
 case 1:func_02039C68((struct Link *)func_020399A8(),0x11,0x1F);++*state;break;
 case 2:if(func_02039CB4((struct Link *)func_020399A8(),0x11,0x1F)!=0)++*state;break;
 case 3:if(func_0217E258(*d,c[3])!=0)++*state;break;
 case 4:if(func_0217E298(*d,c[4])!=0)++*state;break;
 case 5:return 1;
 }
 func_0217E074(*d);return 0;
}
