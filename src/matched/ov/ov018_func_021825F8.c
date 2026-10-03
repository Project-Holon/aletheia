/*
 * function: func_021825F8
 * address: 0x021825F8
 * packet: pkt_ov018_021825F8
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
 *   func_0218261C 0x0218261C thumb ov018
 * Interface: callback payload passed as pointer; owner body stores unchanged word at +4.
 */

typedef unsigned char u8;
typedef unsigned short u16;
extern void func_0201232C(void *, void *, int);
struct Obj;
struct Outer;
extern void *func_020124E8(struct Obj *p);
extern void func_02082D44(void *, void *, int);
extern int func_0218261C(void *a, int *state, struct Outer *c);
void func_021825F8(void *a, void *b) { func_0201232C(a,(void *)func_0218261C,0xa4); func_02082D44(b,func_020124E8(a),0x98); }
