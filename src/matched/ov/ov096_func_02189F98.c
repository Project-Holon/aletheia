/*
 * function: func_02189F98
 * address: 0x02189F98
 * packet: pkt_ov096_02189F98
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Two-byte zero alignment padding follows the compiled function.
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_0218A0F4 0x0218A0F4 thumb ov096
 */
#include "../include/Obj21983.h"
struct Cursor;
extern unsigned int func_0201134C(struct Cursor *);
extern int func_0218A0F4(unsigned char *, int, int, int, int);
int func_02189F98(unsigned char *a, unsigned char *b, int c) { int x,y; x=func_0201134C((struct Cursor *)a); y=func_0201134C((struct Cursor *)a); return func_0218A0F4(a,c,((struct Obj21983 *)b)->fCC,x,y); }
