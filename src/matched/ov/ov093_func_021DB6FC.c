/*
 * function: func_021DB6FC
 * address: 0x021DB6FC
 * packet: pkt_ov093_021DB6FC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D5B40 0x021D5B40 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 */
extern int func_021D775C(int);
typedef unsigned short u16;
struct QI;
extern void *func_021C7CF4(int *p, int i);
extern u16 func_021D5B40(struct QI *p);
extern void *func_021C88A4(void *,int,int);
extern void func_021C88C8(void *,void *);
void func_021DB6FC(int a,void *b,int c) { unsigned char *p; if(c==func_021D775C(2) && func_021D5B40(func_021C7CF4(b,c))) { p=func_021C88A4(b,0x21,c); p[4]=c; func_021C88C8(b,p); } }
