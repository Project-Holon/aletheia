/*
 * function: func_021BAE14
 * address: 0x021BAE14
 * packet: pkt_ov100_021BAE14
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA3A4 0x021BA3A4 thumb ov100
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021BB270 0x021BB270 thumb ov100
 *   func_021BA290 0x021BA290 thumb ov100
 */
struct Word { int x; };
extern void func_021BA3A4(struct Word *,int);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_021B95B8(u8 *p, u32 v);
extern void func_021BB270(void);
extern void func_021BA290(int,int);
void func_021BAE14(int a) {
 struct Word x;
 x.x=*(int *)(a+0xcb0);
 func_021BA3A4(&x,a);
 func_021B95B8((u8 *)a,(u32)func_021BB270);
 if(*(int *)(a+0x24c)==9 && *(int *)(a+0xce8)>0) { func_021BA290(a,1); return; }
 func_021BA290(a,0);
}
