/*
 * function: func_021CDD50
 * address: 0x021CDD50
 * packet: pkt_ov093_021CDD50
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021EFFEC 0x021EFFEC data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int (*Callback)(u8 *,int *);
typedef struct { u8 id; u8 flag; u16 pad; Callback callbacks[3]; } Entry;
extern const Entry d_021EFFEC[15];
Callback func_021CDD50(u8 *p,u32 id,int *out)
{
    u32 i;
    for (i=0; i<15; i++) {
        if (d_021EFFEC[i].id == id) {
            if (out) *out = d_021EFFEC[i].flag;
            return d_021EFFEC[i].callbacks[p[0x1a7]];
        }
    }
    return 0;
}
