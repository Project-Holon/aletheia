/*
 * function: func_021B9BE8
 * address: 0x021B9BE8
 * packet: pkt_ov071_021B9BE8
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B7118 0x021B7118 thumb ov071
 *   func_0204B3DC 0x0204B3DC arm
 */

extern void *func_021B7118(void *, int, int, int);
extern void func_0204B3DC(void *, int);
void func_021B9BE8(char *p, char *q) { *(void **)(q + 0x18) = func_021B7118(*(void **)(p + 4), 0x80, 0x1c, 9); *(void **)(q + 0x1c) = func_021B7118(*(void **)(p + 4), 0x80, 0xa4, 10); func_0204B3DC(*(void **)(q + 0x18), 0); func_0204B3DC(*(void **)(q + 0x1c), 0); }
