/*
 * function: func_02188AD8
 * address: 0x02188AD8
 * packet: pkt_ov096_02188AD8
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02188AF8 0x02188AF8 thumb ov096
 */
struct Cursor;
extern int func_02188AF8(struct Cursor *a, unsigned char *b, int c);
int func_02188AD8(void *a, unsigned char *b) { func_02188AF8(a,b,2); return *(int *)(b+0xC4); }
