/*
 * function: func_021BB08C
 * address: 0x021BB08C
 * packet: pkt_ov070_021BB08C
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_020456F8 0x020456F8 arm
 *   func_021BAFC4 0x021BAFC4 thumb ov070
 */
extern void func_0204B3DC(void *, unsigned);
extern void func_020456F8(void *);
extern void func_021BAFC4(void *);
void func_021BB08C(char *p) { func_0204B3DC(*(void **)(p + 0x710), 0); func_0204B3DC(*(void **)(p + 0x714), 0); func_020456F8(*(void **)(p + 0x504)); func_021BAFC4(p); }
