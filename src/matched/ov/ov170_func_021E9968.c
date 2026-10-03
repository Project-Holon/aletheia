/*
 * function: func_021E9968
 * address: 0x021E9968
 * packet: pkt_ov170_021E9968
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EB988 0x021EB988 thumb ov170
 *   func_021EF4E4 0x021EF4E4 thumb ov170
 *   func_021EBC58 0x021EBC58 thumb ov170
 *   func_021ECB20 0x021ECB20 thumb ov170
 *   func_021ED888 0x021ED888 thumb ov170
 *   func_021EA75C 0x021EA75C thumb ov170
 *   func_021ED588 0x021ED588 thumb ov170
 *   d_021EF950 0x021EF950 data a1
 */
#define WORK(p) (*(char **)((p)+0x2C))
struct WinMgr;
extern void func_021EB988(unsigned char *, const void *, unsigned);
extern void func_021EF4E4(struct WinMgr *mgr);
extern void func_021EBC58(unsigned char *, int, int, int);
extern void func_021ECB20(unsigned char *, int, int);
extern void func_021ED888(char *, int);
extern void func_021EA75C(unsigned char *);
extern void func_021ED588(unsigned char *);
extern const unsigned char d_021EF950[];
int func_021E9968(unsigned char *p) {
 func_021EB988(p,d_021EF950,5);
 func_021EF4E4(*(struct WinMgr **)(WORK(p)+0x74));
 func_021EBC58(p,p[0x16],1,0x18);
 func_021ECB20(p,1,1); func_021ED888(WORK(p),0);
 func_021EA75C(p); func_021ED588(p); return 0x31;
}
