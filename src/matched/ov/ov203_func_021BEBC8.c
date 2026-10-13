/*
 * function: func_021BEBC8
 * address: 0x021BEBC8
 * packet: pkt_ov203_021BEBC8
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two-byte zero alignment padding at 021BEC22.
 * symbols:
 *   func_0200616C 0x0200616C thumb
 *   func_020061E4 0x020061E4 thumb
 *   GFL_USE_GetSeSlot 0x02006148 thumb
 *   GFL_USE_SetSeSlotVolume 0x020062BC thumb
 *   GFL_USE_SetSeSlotParams 0x02006268 thumb
 */
extern void func_0200616C(void *,int);
extern void func_020061E4(unsigned);
extern int GFL_USE_GetSeSlot(unsigned);
extern void GFL_USE_SetSeSlotVolume(int,unsigned);
extern void GFL_USE_SetSeSlotParams(int,unsigned,unsigned,unsigned);
void func_021BEBC8(void *unused,int ignored,int *s)
{
    int channel;
    if(s[4]!=-1){func_0200616C((void *)s[0],s[4]);channel=s[4];}
    else {func_020061E4(s[0]);channel=GFL_USE_GetSeSlot(s[0]);}
    if(s[1]!=-1)GFL_USE_SetSeSlotVolume(channel,s[1]);
    if(s[2]!=-1)GFL_USE_SetSeSlotParams(channel,-1,-1,s[2]);
    if(s[3]!=-1)GFL_USE_SetSeSlotParams(channel,-1,s[3],-1);
}
