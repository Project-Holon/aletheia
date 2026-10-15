/*
 * function: POKETRADE_PROC_RedrawAndSyncGrid
 * address: 0x021DB7AC
 * packet: pkt_ov119_021DB7AC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_2D_UpdateVisibleColumns 0x021E4E64 thumb ov119
 *   POKETRADE_2D_DrawBoxGridScreen 0x021E42B4 thumb ov119
 *   POKETRADE_2D_DrawBoxNames 0x021E4598 thumb ov119
 *   GFL_USE_IsAnySeBusy 0x02006238 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   POKETRADE_PROC_IsNetSession 0x021D8A24 thumb ov119
 *   GFL_NET_IsNetTypeWifi 0x0203D29C arm
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendData 0x0203D3F8 arm
 */
typedef short s16;
typedef unsigned u32;
extern void POKETRADE_2D_UpdateVisibleColumns(int,char *,int);
extern void POKETRADE_2D_DrawBoxGridScreen(char *);
extern void POKETRADE_2D_DrawBoxNames(char *);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern int GFL_USE_IsAnySeBusy(void);
extern int POKETRADE_PROC_IsNetSession(void *);
extern u32 GFL_NET_IsNetTypeWifi(void);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_SendData(u32,u32,u32,u32,u32,u32,u32,u32);
#define H(o) (*(s16 *)(p+(o)))
#define I(o) (*(int *)(p+(o)))
void POKETRADE_PROC_RedrawAndSyncGrid(char *p,int a,int b)
{
    if(H(0x107c)<0) H(0x107c)+=(s16)I(0x63c);
    if(I(0x63c)<=H(0x107c)) H(0x107c)-=(s16)I(0x63c);
    POKETRADE_2D_UpdateVisibleColumns(I(0x828),p,1);
    POKETRADE_2D_DrawBoxGridScreen(p);
    POKETRADE_2D_DrawBoxNames(p);
    if(GFL_USE_IsAnySeBusy()==0 && a) GFL_USE_PlaySeDefaultVolume(0x72b);
    if(POKETRADE_PROC_IsNetSession(p) && b) {
        if(GFL_NET_IsNetTypeWifi()) {
            if(H(0x107c)%16==0) {
                GFL_NET_SendData((u32)GFL_NET_HANDLE_GetCurrentHandle(),255,0xc0c,2,(u32)(p+0x107c),0,1,1);
                return;
            }
        } else {
            GFL_NET_SendData((u32)GFL_NET_HANDLE_GetCurrentHandle(),255,0xc0c,2,(u32)(p+0x107c),0,1,1);
            return;
        }
    } else {
        if(POKETRADE_PROC_IsNetSession(p)==0) H(0x107e)=H(0x107c);
    }
}
