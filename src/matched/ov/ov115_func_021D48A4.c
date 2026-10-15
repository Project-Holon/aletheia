/*
 * function: func_021D48A4
 * address: 0x021D48A4
 * packet: pkt_ov115_021D48A4
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D5E6C 0x021D5E6C thumb ov115
 *   func_021D5EA8 0x021D5EA8 thumb ov115
 *   func_021D5D3C 0x021D5D3C thumb ov115
 *   func_021D5ED8 0x021D5ED8 thumb ov115
 *   WIFILOGIN_COMMON_SetStateHandler 0x021D426C thumb ov115
 *   func_021D4878 0x021D4878 thumb ov115
 *   func_021D5F7C 0x021D5F7C thumb ov115
 *   func_021D5CCC 0x021D5CCC thumb ov115
 *   func_021D4AB0 0x021D4AB0 thumb ov115
 *   func_021D5E34 0x021D5E34 thumb ov115
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021D5E6C(u8 *p);
extern u8 func_021D5EA8(u8 *p);
extern void func_021D5D3C(u8 *p);
extern void func_021D5ED8(u8 *p, u32 n);
extern void WIFILOGIN_COMMON_SetStateHandler(u8 *,u32);
extern void func_021D4878(u8 *);
extern void func_021D5F7C(u8 *p);
extern void func_021D5CCC(u8 *p, u32 n);
extern void func_021D4AB0(unsigned char *a);
extern void func_021D5E34(u8 *p);
#define W(k) (*(int *)(p+(k)))
#define P(k) (*(u8 **)(p+(k)))
void func_021D48A4(u8 *p) {
 if(func_021D5E6C((u8 *)W(0x30))) { if(!func_021D5EA8((u8 *)W(0x30))) { *(int *)(P(0x40)+0x1c)=0; func_021D5D3C((u8 *)W(0x38)); func_021D5ED8((u8 *)W(0x38),22); WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D4878); } else { *(int *)(P(0x40)+0x1c)=1; func_021D5F7C((u8 *)W(0x38)); if(!*(int *)(P(0x40)+4)) func_021D5CCC((u8 *)W(0x38),35); WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D4AB0); } func_021D5E34((u8 *)W(0x30)); W(0x30)=0; }
}
