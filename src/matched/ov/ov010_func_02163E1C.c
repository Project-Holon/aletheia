/*
 * function: func_02163E1C
 * address: 0x02163E1C
 * packet: pkt_ov010_02163E1C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0216D67C 0x0216D67C thumb ov010
 *   func_0216D52C 0x0216D52C thumb ov010
 *   func_0218DAEC 0x0218DAEC thumb ov021
 */

typedef unsigned short u16;
typedef struct { u16 a,b,c,d; int p,q; } E;
extern void *func_0216D67C(void *);
extern void *func_0216D52C(void *);
extern int func_0218DAEC(char *, char *, E *);
int func_02163E1C(void *a, char *b, E *c) { return func_0218DAEC(func_0216D52C(func_0216D67C(a)),b,c); }
