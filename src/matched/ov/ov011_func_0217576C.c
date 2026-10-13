/*
 * function: INTRUDE_COMM_InitSession
 * address: 0x0217576C
 * packet: pkt_ov011_0217576C
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   INTRUDE_COMM_ResetMemberName 0x02175EE8 thumb ov011
 *   func_021757A8 0x021757A8 thumb ov011
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void MI_CpuFill8(void *, u8, u32);
extern void INTRUDE_COMM_ResetMemberName(u8 *);
extern void func_021757A8(u8 *);
void INTRUDE_COMM_InitSession(u8 *p)
{
    int i;
    MI_CpuFill8(p, 0, 0x1A8);
    p[0xA4] = 4;
    INTRUDE_COMM_ResetMemberName(p + 0x90);
    p[0xD8] = 4;
    for (i = 0; i < 3; i++) p[0xE0 + i] = 4;
    func_021757A8(p);
}
