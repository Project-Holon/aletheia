/*
 * function: INTRUDE_COMM_SendTimeoutWarning
 * address: 0x021739E0
 * packet: pkt_ov011_021739E0
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: INTRUDE_COMM_IsLinked's matched void forwarder leaves r0 live; caller
 *       tests r0 at 021739E6. func_0203D3A8's void body calls the send
 *       routine last; caller returns its live r0 at 021739FC.
 * symbols:
 *   INTRUDE_COMM_IsLinked 0x021736D8 thumb ov011
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
int INTRUDE_COMM_IsLinked(void);
struct Entry;
struct Entry *func_020399A8(void);
typedef unsigned short u16;
int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);

int INTRUDE_COMM_SendTimeoutWarning(void)
{
    if (INTRUDE_COMM_IsLinked() == 0) return 1;
    return func_0203D3A8((struct Entry *)((int)func_020399A8()), 0x206, 0, 0);
}
