/*
 * function: func_021F6590
 * address: 0x021F6590
 * packet: pkt_ov097_021F6590
 * region: ov097
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   D_021F7608 0x021F7608 data a4
 *   func_0202CD94 0x0202CD94 thumb
 *   func_021F6B38 0x021F6B38 thumb ov097
 *   func_0204A600 0x0204A600 arm
 */
struct WinMgr;
extern int (*D_021F7608[])(char *);
extern void func_0202CD94(struct WinMgr *mgr);
extern void func_021F6B38(char *);
extern void func_0204A600(void);
int func_021F6590(int a,int *b,int c,char *d) { *b=D_021F7608[*b](d); if(*b==5) return 1; func_0202CD94(*(struct WinMgr **)(d+8)); func_021F6B38(d); func_0204A600(); return 0; }
