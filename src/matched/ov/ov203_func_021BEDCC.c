/*
 * unit: yes
 * function: DEMO3D_DATA_ApplySeFade,DEMO3D_DATA_PlayBgm,DEMO3D_DATA_StopBgm
 * address: 0x021BEDCC
 * packet: pkt_ov203_021BEDCC
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_USE_SetSeSlotVolume 0x020062BC thumb
 *   GFL_USE_SetSeSlotParams 0x02006268 thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 */
extern void GFL_USE_SetSeSlotVolume(int,unsigned);
extern void GFL_USE_SetSeSlotParams(int,unsigned,unsigned,unsigned);
extern void GFL_USE_CancelChangeAndPlayBgm(int,int);
extern void GFL_USE_CancelChangeAndStopBgm(void);
void DEMO3D_DATA_ApplySeFade(int mode,int channel,int value)
{
    switch(mode){case 0:GFL_USE_SetSeSlotVolume(channel,value);break;case 1:GFL_USE_SetSeSlotParams(channel,-1,-1,value);break;case 2:GFL_USE_SetSeSlotParams(channel,-1,value,-1);break;}
}
void DEMO3D_DATA_PlayBgm(int a,int b,int *s){GFL_USE_CancelChangeAndPlayBgm(s[0],0xffff);}
void DEMO3D_DATA_StopBgm(void){GFL_USE_CancelChangeAndStopBgm();}
