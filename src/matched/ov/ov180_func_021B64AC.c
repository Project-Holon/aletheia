/*
 * function: func_021B64AC
 * address: 0x021B64AC
 * packet: pkt_ov180_021B64AC
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021B8018 0x021B8018 data a4
 *   func_02005A98 0x02005A98 thumb
 *   func_02005D90 0x02005D90 thumb
 */
typedef unsigned int u32;
typedef unsigned short u16;
struct Sub02005A98Hdr;
extern const u32 d_021B8018[];
extern struct Sub02005A98Hdr *func_02005A98(const u32 *,u32);
extern void func_02005D90(u32,u32);
void func_021B64AC(char *p) {*(struct Sub02005A98Hdr **)(p+12)=func_02005A98(d_021B8018,1);func_02005D90(1015,65535);}
