/*
 * function: func_0218236C
 * address: 0x0218236C
 * packet: pkt_ov018_0218236C
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201232C 0x0201232C thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_02082D44 0x02082D44 arm
 *   func_021823A8 0x021823A8 thumb ov018
 *   func_021756D0 0x021756D0 thumb ov011
 * Interface: callback payload passed as pointer; owner body stores unchanged word at +4.
 */

typedef unsigned char u8;
typedef unsigned short u16;
extern void func_0201232C(char *p, int a1, int a2);
struct Obj;
extern void *func_020124E8(struct Obj *p);
extern void func_02082D44(void *, void *, int);
typedef unsigned int   u32;
struct Outer;
extern int func_021823A8(void *a, int *state, struct Outer *c);
extern int func_021756D0(u32 x);
void func_0218236C(void *a, void *b) { u16 *h; func_0201232C(a,(int)((void *)func_021823A8),0xa4); a = func_020124E8(a); func_02082D44(b,a,0x98); h = (u16 *)((u8 *)a+0x58); if (func_021756D0(*h) == 0) *h = 17; }
