/*
 * function: func_021F62B0
 * address: 0x021F62B0
 * packet: pkt_ov112_021F62B0
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020627D8 0x020627D8 arm
 *   func_021F659C 0x021F659C thumb ov112
 *   func_0206469C 0x0206469C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct AnimBank;
struct AnimSequence;
extern struct AnimSequence *func_020627D8(struct AnimBank *bank, u32 idx); extern void func_021F659C(char *,int); extern void func_0206469C(void *,void *);
void func_021F62B0(char *p,u32 n) {void *a; a=func_020627D8(*(void **)(p+28),n);func_021F659C(p,1);func_0206469C(p+40,a);}
