/*
 * function: func_021D9828
 * address: 0x021D9828
 * packet: pkt_ov121_021D9828
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: u8 extern parameter reproduces original truncation before BLX.
 * symbols:
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_02082BCC 0x02082BCC arm
 *   d_021DF634 0x021DF634 data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 id; u32 config[8]; u32 a; u32 b; } Entry;
extern const Entry d_021DF634[];
extern void func_020403F4(u8),func_020450C8(void),func_0203F9B4(void),func_02082BCC(void *,int,u32);
void func_021D9828(void *p) {
    u32 i=0;
    do { func_020403F4(d_021DF634[i].id); ++i; } while(i<7);
    func_020450C8();
    func_0203F9B4();
    func_02082BCC(p,0,4);
}
