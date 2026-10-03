/*
 * function: func_021F7028
 * address: 0x021F7028
 * packet: pkt_ov215_021F7028
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020480E4 0x020480E4 arm
 *   func_021F6718 0x021F6718 thumb ov215
 */
struct Ctx;
extern void func_020480E4(struct Ctx *,unsigned),func_021F6718(void *);
void func_021F7028(char *p){func_020480E4(*(struct Ctx **)(p+0x48),*(unsigned short *)(p+0x4c));func_021F6718(*(void **)(p+0x54));*(unsigned short *)(p+0x50)=0;}
