/*
 * function: COMM_BTL_DEMO_GRAPHIC_GetCamera
 * address: 0x021BAC94
 * packet: pkt_ov213_021BAC94
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   COMM_BTL_DEMO_GRAPHIC_GetClactBank 0x021BADC4 thumb ov213
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void *COMM_BTL_DEMO_GRAPHIC_GetClactBank(void **p);
u32 COMM_BTL_DEMO_GRAPHIC_GetCamera(char *p) { return (u32)COMM_BTL_DEMO_GRAPHIC_GetClactBank((void **)((u32 *)(p+4))); }
