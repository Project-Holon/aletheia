/*
 * function: UNION_APP_SendOwnEntry
 * address: 0x02183DAC
 * packet: pkt_ov022_02183DAC
 * region: ov022
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Original 02183DBA consumes pointer result of 020399A8 in r0,
 * passed to 0203D1A4; 020399A8 ends with 0203996C and leaves result live.
 * The ov012 02174010 leaves 0203D4D0 result live, read at 02183DD0.
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   UNION_COMMAND_SendAppData 0x02174010 thumb ov012
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Link;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_GetHandleNetID(struct Link *);
extern u32 UNION_COMMAND_SendAppData(u32 a, void *p);
void UNION_APP_SendOwnEntry(u8 *p)
{
    u32 i;
    if (p[13] != 0) {
        i = GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle());
        if (UNION_COMMAND_SendAppData(p[13], p + 0x2c + i * 40) == 1) p[13] = 0;
    }
}
