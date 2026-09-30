/*
 * unit: yes
 * function: func_021BD894, func_021BD8A8, func_021BD8B8, func_021BD8C8
 * address: 0x021BD894
 * packet: pkt_ov110_021BD894
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021C3920 0x021C3920 data a4
 *   func_021BAE24 0x021BAE24 thumb ov110
 *   func_021BAE94 0x021BAE94 thumb ov110
 *   func_021BAED0 0x021BAED0 thumb ov110
 */
typedef unsigned char u8;
extern int (*const d_021C3920[])(u8 *,void *);
extern int func_021BAE24(void *,u8 *,void *);
extern int func_021BAE94(void *,u8 *,void *);
extern int func_021BAED0(void *,u8 *,void *);
int func_021BD894(u8 *p,void *q) { return d_021C3920[*(unsigned *)(p+4)](p,q); }
int func_021BD8A8(u8 *p) { return func_021BAE24(*(void **)(p+0x14),p,*(void **)(p+0x18)); }
int func_021BD8B8(u8 *p) { return func_021BAE94(*(void **)(p+0x14),p,*(void **)(p+0x18)); }
int func_021BD8C8(u8 *p) { return func_021BAED0(*(void **)(p+0x14),p,*(void **)(p+0x18)); }
