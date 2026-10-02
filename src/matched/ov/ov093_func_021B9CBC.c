/*
 * function: func_021B9CBC
 * address: 0x021B9CBC
 * packet: pkt_ov093_021B9CBC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D5440 0x021D5440 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 func_021D5440(void *);
int func_021B9CBC(u8 *p,u8 v) {
    int i;
    for(i=0;i<p[24];i++) if(v==func_021D5440(*(void **)((u32)p+(u32)i*4))) return i;
    return -1;
}
