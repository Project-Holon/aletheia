/*
 * function: func_021BB0BC
 * address: 0x021BB0BC
 * packet: pkt_ov070_021BB0BC
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_020456F8 0x020456F8 arm
 *   func_021BAF38 0x021BAF38 thumb ov070
 */
typedef unsigned int   u32;
struct Descriptor;
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_020456F8(struct Descriptor *d);
extern void func_021BAF38(int, int);
void func_021BB0BC(char *p) { func_0204B3DC(*(void **)(p + 0x710), 1); func_0204B3DC(*(void **)(p + 0x714), 1); func_020456F8(*(void **)(p + 0x764)); func_020456F8(*(void **)(p + 0x75C)); func_021BAF38((int)p, *(int *)(p + 0x80C)); }
