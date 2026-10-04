/*
 * function: func_021739E0
 * address: 0x021739E0
 * packet: pkt_ov011_021739E0
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: func_021736D8's matched void forwarder leaves r0 live; caller
 *       tests r0 at 021739E6. func_0203D3A8's void body calls the send
 *       routine last; caller returns its live r0 at 021739FC.
 * symbols:
 *   func_021736D8 0x021736D8 thumb ov011
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
int func_021736D8(void);
struct Entry;
struct Entry *func_020399A8(void);
int func_0203D3A8(int a, int b, int c, void *d);

int func_021739E0(void)
{
    if (func_021736D8() == 0) return 1;
    return func_0203D3A8((int)func_020399A8(), 0x206, 0, 0);
}
