/*
 * function: WIFIBATTLEMATCH_NET_SendRegDataAlt
 * address: 0x021DC200
 * packet: pkt_ov175_021DC200
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   GFL_NET_SendData 0x0203D3F8 arm
 *   POKE_REGULATION_GetDataSize 0x0201A918 thumb
 */
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
struct Link;
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
extern unsigned long GFL_NET_SendData(unsigned long,unsigned long,unsigned long,unsigned long,unsigned long,unsigned long,unsigned long,unsigned long);
extern int POKE_REGULATION_GetDataSize(void);
u32 WIFIBATTLEMATCH_NET_SendRegDataAlt(char *p,unsigned long data)
{
    unsigned long busy=GFL_NET_GetHandleNetID((struct Link *)((unsigned long)GFL_NET_HANDLE_GetCurrentHandle()));
    int flag=1;
    if(busy!=0) flag=0;
    return GFL_NET_SendData((unsigned long)GFL_NET_HANDLE_GetCurrentHandle(),(unsigned char)flag,0x2403,POKE_REGULATION_GetDataSize(),data,1,1,1);
}
