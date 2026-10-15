/*
 * function: WF2DMAP_SCENE_Dispatch
 * address: 0x021D8F78
 * packet: pkt_ov129_021D8F78
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D9F40 0x021D9F40 thumb ov129
 *   func_021DA004 0x021DA004 thumb ov129
 *   d_021DA718 0x021DA718 data a4 ov129
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern int (*d_021DA718[])(char *);
extern void func_021D9F40(char *),func_021DA004(char *);
int WF2DMAP_SCENE_Dispatch(char *p) { int v; v=d_021DA718[*(u32 *)(p+0x22c)](p); func_021D9F40(p); func_021DA004(p); return v; }
