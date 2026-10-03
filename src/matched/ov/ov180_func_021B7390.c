/*
 * function: func_021B7390
 * address: 0x021B7390
 * packet: pkt_ov180_021B7390
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02025588 0x02025588 thumb
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern void func_02025588(void *);
struct Bank;
extern void func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
void func_021B7390(char *p){func_02025588(*(void **)(p+37148));func_0204B1CC(*(void **)(p+36932));func_0204A5AC();}
