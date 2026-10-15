/*
 * function: func_021D4644
 * address: 0x021D4644
 * packet: pkt_ov115_021D4644
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0200FB24 0x0200FB24 thumb
 *   GFL_NET_STATE_GetError 0x0203CA98 arm
 *   func_021D5F7C 0x021D5F7C thumb ov115
 *   func_021D5D3C 0x021D5D3C thumb ov115
 *   func_021D5C94 0x021D5C94 thumb ov115
 *   GFL_NET_ERR_ShowSimpleScreen 0x0200F83C thumb
 *   func_021D5938 0x021D5938 thumb ov115
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   func_0200FBB0 0x0200FBB0 thumb
 *   GFL_NET_STATE_SetWifiError 0x0203CA04 arm
 *   func_0200FBA0 0x0200FBA0 thumb
 *   GFL_NET_STATE_ClearErrorMode 0x0203C968 arm
 *   func_021D5ED8 0x021D5ED8 thumb ov115
 *   WIFILOGIN_COMMON_SetStateHandler 0x021D426C thumb ov115
 *   func_021D460C 0x021D460C thumb ov115
 *   func_0200FA84 0x0200FA84 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_0200FB24(void);
extern u32 GFL_NET_STATE_GetError(void);
extern void func_021D5F7C(u8 *p);
extern void func_021D5D3C(u8 *p);
extern void func_021D5C94(u8 *p);
extern void GFL_NET_ERR_ShowSimpleScreen(void);
extern void func_021D5938(u8 *p);
extern int GFL_NET_GetRunState(void);
extern u32 func_0200FBB0(void);
extern void GFL_NET_STATE_SetWifiError(void);
extern void func_0200FBA0(void);
extern void GFL_NET_STATE_ClearErrorMode(void);
extern void func_021D5ED8(u8 *p, u32 n);
extern void WIFILOGIN_COMMON_SetStateHandler(u8 *,u32);
extern void func_021D460C(u8 *);
extern void func_0200FA84(void);

#define W(k) (*(int *)(p+(k)))
#define P(k) (*(u8 **)(p+(k)))
int func_021D4644(u8 *p) {
 if(func_0200FB24()) { switch(*(u32 *)(GFL_NET_STATE_GetError()+4)) { case 1: case 2: case 3: case 4: case 5: case 6: func_021D5F7C((u8 *)W(0x38)); func_021D5D3C((u8 *)W(0x38)); func_021D5C94((u8 *)W(0x38)); GFL_NET_ERR_ShowSimpleScreen(); func_021D5938((u8 *)W(0x34)); if(GFL_NET_GetRunState()) func_0200FBB0(); GFL_NET_STATE_SetWifiError(); func_0200FBA0(); GFL_NET_STATE_ClearErrorMode(); func_021D5ED8((u8 *)W(0x38),37); WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D460C); return 1; case 7: func_0200FA84(); break; case 0: default: break; } } return 0;
}
