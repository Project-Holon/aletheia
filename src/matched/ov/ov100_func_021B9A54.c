/*
 * function: func_021B9A54
 * address: 0x021B9A54
 * packet: pkt_ov100_021B9A54
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: one-word aggregate assignment schedules the stack address before its load/store.
 * symbols:
 *   func_021BA3A4 0x021BA3A4 thumb ov100
 *   func_021BA454 0x021BA454 thumb ov100
 *   func_020061E4 0x020061E4 thumb
 *   func_020399A8 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021B9A1C 0x021B9A1C thumb ov100
 *   d_021BB664 0x021BB664 data a4
 *   d_021BB678 0x021BB678 data a4
 */
struct Word { int x; };
extern const struct Word d_021BB664,d_021BB678;
extern void func_021BA3A4(struct Word *,int);
extern void func_021BA454(int,int);
typedef unsigned int   u32;
extern void func_020061E4(u32 a);
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern void func_02039C68(struct Link *,unsigned int,unsigned int);
extern void func_021B95B8(int,void (*)(void));
extern void func_021B9A1C(void);
void func_021B9A54(int a)
{
 if(*(int *)(a+0xc90)!=0) {
  struct Word x=d_021BB664;
  func_021BA3A4(&x,a);
 } else {
  struct Word x=d_021BB678;
  func_021BA3A4(&x,a);
 }
 func_021BA454(0x22,a);
 func_020061E4(0x764);
 func_02039C68((struct Link *)func_020399A8(),0x7f,12);
 func_021B95B8(a,func_021B9A1C);
}
