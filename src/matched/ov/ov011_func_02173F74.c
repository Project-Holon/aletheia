/*
 * function: INTRUDE_CMD_SendRecordEcho
 * address: 0x02173F74
 * packet: pkt_ov011_02173F74
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: The matched void forwarder INTRUDE_COMM_IsLinked leaves r0 live and this
 *       caller tests it at 02173F7C. func_0203D3A8's final send result is
 *       returned in live r0 at 02173F94, so both externs return int here.
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

int INTRUDE_CMD_SendRecordEcho(int a, u8 *b)
{
    if (INTRUDE_COMM_IsLinked() == 0) return 0;
    return func_0203D3A8((struct Entry *)((int)func_020399A8()), 0x213, 0x34, (u32)(b + 0x78));
}
