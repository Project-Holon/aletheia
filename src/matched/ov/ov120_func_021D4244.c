/*
 * function: GTSNEGO_DISP_SetStateCallback
 * address: 0x021D4244
 * packet: pkt_ov120_021D4244
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GTSNEGO_DISP_SetCallback 0x021D4240 thumb ov120
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void GTSNEGO_DISP_SetCallback(int *,int);
void GTSNEGO_DISP_SetStateCallback(int *p, int v, int a2) {GTSNEGO_DISP_SetCallback(p,v);}
