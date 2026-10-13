/*
 * unit: yes
 * function: INTRUDE_CMD_SendRecordAccept, INTRUDE_CMD_RecvMemberValue
 * address: 0x02173FC0
 * packet: pkt_ov011_02173FC0
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: Lead one run is EXACT*, followed by the root-claimed 02173FE4
 *       tail stub; tu verifies the complete 52-byte unit. INTRUDE_COMM_IsLinked's void forwarder
 *       leaves r0 live, tested at 02173FC8; GFL_NET_SendToHandle's final send
 *       result is returned at 02173FE2. Follower loads a full word at
 *       02173FEA and forwards it without caller truncation.
 * symbols:
 *   INTRUDE_COMM_IsLinked 0x021736D8 thumb ov011
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   INTRUDE_COMM_StartSessionTimer 0x021759F8 thumb ov011
 */
typedef unsigned char u8;
typedef unsigned int u32;
int INTRUDE_COMM_IsLinked(void);
struct Entry;
struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned short u16;
int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
void INTRUDE_COMM_StartSessionTimer(u8 *a, int b);

int INTRUDE_CMD_SendRecordAccept(int a, u8 *b)
{
    if (INTRUDE_COMM_IsLinked() == 0) return 0;
    return GFL_NET_SendToHandle((struct Entry *)((int)GFL_NET_HANDLE_GetCurrentHandle()), 0x214, 0x34, (u32)(b + 0x78));
}

void INTRUDE_CMD_RecvMemberValue(int a, int b, int *c, u8 *d)
{
    INTRUDE_COMM_StartSessionTimer(d + 0x1ac, *c);
}
