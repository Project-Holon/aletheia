/*
 * function: LIVEBATTLEMATCH_IRC_SendRegulation
 * address: 0x0217E1FC
 * packet: pkt_ov176_0217E1FC
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: remaining code is the separate leaf LIVEBATTLEMATCH_IRC_GetRegulation
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   POKE_REGULATION_GetDataSize 0x0201A918 thumb
 *   GFL_NET_SendData 0x0203D3F8 arm
 */
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
struct Link;
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
extern int POKE_REGULATION_GetDataSize(void);
extern u32 GFL_NET_SendData(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
int LIVEBATTLEMATCH_IRC_SendRegulation(int unused, int arg)
{
    int flag;
    int obj;
    unsigned n;
    int r;
    r = GFL_NET_GetHandleNetID((struct Link *)((int)GFL_NET_HANDLE_GetCurrentHandle()));
    flag = 1;
    if (r != 0)
        flag = 0;
    obj = (int)GFL_NET_HANDLE_GetCurrentHandle();
    n = POKE_REGULATION_GetDataSize();
    return GFL_NET_SendData((int)obj, (unsigned char)flag, (int)0x1F00, n + 0xD4, (int)arg, (int)1, (int)1, (int)1);
}
