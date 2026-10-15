/*
 * function: GDS_SOCKET_InitSslTemplate
 * address: 0x021D8B44
 * packet: pkt_ov125_021D8B44
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * resolved: unlabelled ov125 ARM leaf 0x021D8B3C attested by its matched shard.
 * symbols:
 *   OS_GetLowEntropyData 0x02088168 arm
 *   CPS_SslAddRandomSeed 0x02162248 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GDS_SOCKET_SetSslTemplate 0x021D8BC0 arm ov125
 *   GDS_SOCKET_SetRootCa 0x021D8BF8 arm ov125
 *   GDS_SOCKET_SetSslAuthCallback 0x021D8BE4 arm ov125
 *   gGdsEntropyBuffer 0x021DAA8C data a4
 *   gGdsSslTemplatePtr 0x021DAA88 data a4
 *   gGdsSslTemplate 0x021DAAAC data a4
 *   sGdsRootCaList 0x021D8D38 data a4
 *   GDS_SOCKET_SslAuthCallback 0x021D8B3C arm ov125
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 gGdsEntropyBuffer[], gGdsSslTemplate[];
extern u32 gGdsSslTemplatePtr;
extern void OS_GetLowEntropyData(u32 *buffer);
extern void CPS_SslAddRandomSeed(void *, u32);
extern void MI_CpuFill8(void *, u32, u32);
extern void GDS_SOCKET_SetSslTemplate(u32 value);
extern void GDS_SOCKET_SetRootCa(int a, int b);
extern void GDS_SOCKET_SetSslAuthCallback(int a);
extern const u32 sGdsRootCaList[];
extern int GDS_SOCKET_SslAuthCallback(void);
void GDS_SOCKET_InitSslTemplate(void)
{
    OS_GetLowEntropyData((u32 *)gGdsEntropyBuffer);
    CPS_SslAddRandomSeed(gGdsEntropyBuffer, 32);
    if (gGdsSslTemplatePtr) return;
    MI_CpuFill8(gGdsSslTemplate, 0, 0x830);
    *(u32 *)(gGdsSslTemplate + 0x800) = 0;
    GDS_SOCKET_SetSslTemplate((u32)gGdsSslTemplate);
    GDS_SOCKET_SetRootCa((int)((void *)sGdsRootCaList), 1);
    GDS_SOCKET_SetSslAuthCallback((int)GDS_SOCKET_SslAuthCallback);
}
