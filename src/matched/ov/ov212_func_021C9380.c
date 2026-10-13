/*
 * function: func_021C9380
 * address: 0x021C9380
 * packet: pkt_ov212_021C9380
 * region: ov212
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   ZUKAN_SAVE_GetViewMode 0x0200CA70 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Blk37; extern u32 ZUKAN_SAVE_GetViewMode(struct Blk37 *);
void func_021C9380(struct Blk37 *p, u8 *out) {
    if(ZUKAN_SAVE_GetViewMode(p)==1) out[0]=0; else out[0]=1;
    out[1]=0; out[2]=255; out[3]=255; out[4]=255; out[5]=255; out[6]=255;
}
