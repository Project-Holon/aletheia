/*
 * function: func_021B657C
 * address: 0x021B657C
 * packet: pkt_ov101_021B657C
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B685C 0x021B685C thumb ov101
 */
typedef struct R { int words[11]; } R;
extern void func_021B685C(int *,R *);
void func_021B657C(int *p,R *out) { if(!p[30]) func_021B685C(p+1,out); }
