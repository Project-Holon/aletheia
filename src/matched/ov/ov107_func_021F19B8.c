/*
 * function: func_021F19B8
 * address: 0x021F19B8
 * packet: pkt_ov107_021F19B8
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02027858 0x02027858 thumb
 */
struct TaskMenu;
extern void func_02027858(struct TaskMenu *);
void func_021F19B8(unsigned char *a) { func_02027858(*(struct TaskMenu **)(a+0x3c)); *(void **)(a+0x3c)=0; }
