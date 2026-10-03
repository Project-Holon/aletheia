/*
 * function: func_021C93E4
 * address: 0x021C93E4
 * packet: pkt_ov212_021C93E4
 * region: ov212
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02041EE4(u32,u32,u32);
void func_021C93E4(u32 a, u32 b, u32 *counter) {
    ++*counter;
    if(*counter==4) { func_02041EE4(a,1,1); func_02041EE4(b,1,1); *counter=0; }
}
