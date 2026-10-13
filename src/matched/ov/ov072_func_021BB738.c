/*
 * function: TOWNMAP_GRH_Delete
 * address: 0x021BB738
 * packet: pkt_ov072_021BB738
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   TOWNMAP_GRH_ExitSprites 0x021BBAB4 thumb ov072
 *   TOWNMAP_GRH_ExitBgLayers 0x021BB968 thumb ov072
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned int u32;
struct Node;
extern void func_02030EAC(struct Node *n);
extern void TOWNMAP_GRH_ExitSprites(u32 *);
extern void TOWNMAP_GRH_ExitBgLayers(void *);
extern u32 func_020307B0(void *p);
void TOWNMAP_GRH_Delete(u32 *p) { func_02030EAC((void *)p[10]); TOWNMAP_GRH_ExitSprites(p+1); TOWNMAP_GRH_ExitBgLayers(p); func_020307B0(p); }
