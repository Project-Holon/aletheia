/*
 * function: WF2DMAP_SCRDRAW_GetTileSource
 * address: 0x021C5E2C
 * packet: pkt_ov127_021C5E2C
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:

 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
char *WF2DMAP_SCRDRAW_GetTileSource(char *p, u8 x, u8 y, unsigned mode, int w, int h, u16 *out)
{
    u16 offset;
    switch(mode) {
    case 0: out[0]=w; out[1]=h; return p;
    case 1:
        out[0]=(x+1)*32<=w?32:w-x*32;
        out[1]=h;
        return p+(s16)(h*64)*x;
    case 2:
        out[0]=w;
        out[1]=(y+1)*32<=h?32:h-y*32;
        return p+(s16)(w*64)*y;
    case 3:
        out[0]=(x+1)*32<=w?32:w-x*32;
        out[1]=(y+1)*32<=h?32:h-y*32;
        if(y==0) { offset=0; if(x!=0) offset+=2048; }
        else { offset=(u16)(w*64); if(x!=0) offset+=(u16)(h*64); }
        return p+offset;
    }
    return 0;
}
