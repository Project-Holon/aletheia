/*
 * function: func_021B9AD8
 * address: 0x021B9AD8
 * packet: pkt_ov100_021B9AD8
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_0201BA34 0x0201BA34 thumb
 *   func_021B9AB4 0x021B9AB4 thumb ov100
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021B9A54 0x021B9A54 thumb ov100
 *   func_021B96B8 0x021B96B8 thumb ov100
 */
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern unsigned int func_02039CB4(struct Link *,unsigned int,unsigned int);
extern void func_0201BA34(int);
extern int func_021B9AB4(unsigned a);
extern void func_021B95B8(int,void (*)(void));
extern void func_021B9A54(void);
extern void func_021B96B8(void);
void func_021B9AD8(int a)
{
 if(func_02039CB4((struct Link *)func_020399A8(),0x7a,12)!=0) {
  switch(*(unsigned *)(a+0x24c)) {
  case 7: func_021B95B8(a,func_021B9A54); return;
  case 1: case 2: case 3: case 4:
   func_0201BA34((*(int **)(a+0x244))[2]);
   func_0201BA34((*(int **)(a+0x244))[3]);
   switch(func_021B9AB4(a)) {
    case 0: break;
    case 1: (*(int **)(a+0x244))[7]=1; break;
    case 2: if((*(int **)(a+0x244))[7]>2) (*(int **)(a+0x244))[7]=2; break;
   }
   func_021B95B8(a,func_021B96B8);
  default: case 0: case 5: case 6: func_021B95B8(a,func_021B96B8); break;
  }
 }
}
