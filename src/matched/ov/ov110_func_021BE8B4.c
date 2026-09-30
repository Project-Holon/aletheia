/*
 * function: func_021BE8B4
 * address: 0x021BE8B4
 * packet: pkt_ov110_021BE8B4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021C38F8 0x021C38F8 data a1
 *   func_021BB1F4 0x021BB1F4 thumb ov110
 *   func_021BB224 0x021BB224 thumb ov110
 *   func_02035C08 0x02035C08 arm
 */
typedef unsigned char u8;
typedef struct { u8 b[8]; } Box;
extern const Box d_021C38F8;
extern int func_021BB1F4(void);
extern void func_021BB224(unsigned,int *,int *);
extern int func_02035C08(const Box *);
int func_021BE8B4(void) {
 Box box;
 int x,y;
 Box template;
 int i,count;
 count=func_021BB1F4();
 i=0;
 if(count>0) {
  template=d_021C38F8;
  do { box=template; func_021BB224(i,&x,&y); box.b[0]=y+48; box.b[1]=y+64; box.b[2]=x+8; box.b[3]=x+24; if(func_02035C08(&box)!=-1) return i; i++; } while(i<count);
 }
 return -1;
}
