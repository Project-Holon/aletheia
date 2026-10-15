/*
 * function: WIFI_BSUBWAY_GRAPHIC_CheckNetError, WIFI_BSUBWAY_GRAPHIC_IsPrintDone
 * address: 0x021D7B00
 * packet: pkt_ov116_021D7B00
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * unit: yes
 * status: EXACT
 * symbols:
 *   DWC_RAPCOMMON_HandleNetError 0x02157170 thumb ov009
 *   func_0200FB24 0x0200FB24 thumb
 *   GFL_NET_STATE_GetError 0x0203CA98 arm
 *   WIFI_BSUBWAY_AsyncHasError 0x021D7158 thumb ov116
 *   WIFI_BSUBWAY_CheckFatalError 0x021D7200 thumb ov116
 *   WIFI_BSUBWAY_GetErrorState 0x021D7184 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon 0x021D81B4 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_PrintMessage 0x021D8010 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream 0x021D80CC thumb ov116
 */
typedef unsigned char u8;
extern int DWC_RAPCOMMON_HandleNetError(int,int);
typedef unsigned int   u32;
extern u32 func_0200FB24(void);
extern u32 GFL_NET_STATE_GetError(void);
extern int WIFI_BSUBWAY_AsyncHasError(u8 *p);
extern int WIFI_BSUBWAY_CheckFatalError(int *p);
extern int WIFI_BSUBWAY_GetErrorState(int *p);
extern void WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon(u8 *p);
extern void WIFI_BSUBWAY_GRAPHIC_PrintMessage(void *p, u32 a);
extern int WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(void *);
int WIFI_BSUBWAY_GRAPHIC_CheckNetError(u8 *p) {
    int yes=1;
    int no=0;
    if(DWC_RAPCOMMON_HandleNetError(1,0)!=0) return no;
    if(func_0200FB24()!=0) {
        GFL_NET_STATE_GetError();
        return no;
    }
    if(WIFI_BSUBWAY_AsyncHasError(p+0x182c)!=0) {
        int v;
        if(WIFI_BSUBWAY_CheckFatalError((int *)(p+0x182c))!=0) return no;
        v=WIFI_BSUBWAY_GetErrorState((int *)(p+0x182c));
        WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon(p+4);
        WIFI_BSUBWAY_GRAPHIC_PrintMessage(p+4,v);
        return yes;
    }
    return no;
}
int WIFI_BSUBWAY_GRAPHIC_IsPrintDone(u8 *p) { return WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(p+4); }
