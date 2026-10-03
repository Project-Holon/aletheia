/*
 * function: func_021BB1AC
 * address: 0x021BB1AC
 * packet: pkt_ov070_021BB1AC
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02027858 0x02027858 thumb
 */
struct TaskMenu;
extern void func_02027858(struct TaskMenu *m);
void func_021BB1AC(char *p) { func_02027858(*(void **)(p + 0x77C)); *(void **)(p + 0x77C) = 0; }
