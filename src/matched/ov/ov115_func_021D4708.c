/*
 * function: func_021D4708
 * address: 0x021D4708
 * packet: pkt_ov115_021D4708
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D5E6C 0x021D5E6C thumb ov115
 *   func_021D5EA8 0x021D5EA8 thumb ov115
 *   REGULATION_GetCard 0x0200B1D4 thumb
 *   BATTLE_COMPETITION_GetFromSave 0x0200B358 thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BATTLE_BOX_ClearLockFlags 0x0200BBD8 thumb
 *   BATTLE_BOX_GetFromSave 0x0200BAC8 thumb
 *   REGULATION_Card_SetValue 0x0200B110 thumb
 *   func_02009800 0x02009800 thumb
 *   WIFILOGIN_COMMON_SetStateHandler 0x021D426C thumb ov115
 *   func_021D4474 0x021D4474 thumb ov115
 *   func_021D497C 0x021D497C thumb ov115
 *   func_021D5F7C 0x021D5F7C thumb ov115
 *   func_021D5CCC 0x021D5CCC thumb ov115
 *   func_021D5E34 0x021D5E34 thumb ov115
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021D5E6C(u8 *p);
extern u8 func_021D5EA8(u8 *p);
typedef signed int     s32;
struct Big;
struct Obj;
struct Rec160;
struct Reg2;
extern struct Rec160 *REGULATION_GetCard(struct Rec160 *arr, u32 index);
extern void *BATTLE_COMPETITION_GetFromSave(void *);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void BATTLE_BOX_ClearLockFlags(struct Obj *p, int v);
extern void *BATTLE_BOX_GetFromSave(void *);
extern void REGULATION_Card_SetValue(struct Reg2 *p, u32 id, s32 value);
extern void func_02009800(void *p);
extern void WIFILOGIN_COMMON_SetStateHandler(u8 *,u32);
extern void func_021D4474(u8 *);
extern void func_021D497C(u8 *);
extern void func_021D5F7C(u8 *p);
extern void func_021D5CCC(u8 *p, u32 n);
extern void func_021D5E34(u8 *p);

#define W(k) (*(int *)(p+(k)))
#define P(k) (*(u8 **)(p+(k)))
void func_021D4708(u8 *p) {
 void *v; if(func_021D5E6C((u8 *)W(0x30))) { if(!func_021D5EA8((u8 *)W(0x30))) { v=REGULATION_GetCard(BATTLE_COMPETITION_GetFromSave(GAME_DATA_GetSaveControl((void *)W(0x44))),0); BATTLE_BOX_ClearLockFlags(BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl((void *)W(0x44))),1); REGULATION_Card_SetValue(v,10,5); *(int *)(P(0x40)+0x1c)=0; func_02009800((void *)W(0x3c)); WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D4474); } else { *(int *)(P(0x40)+0x1c)=1; WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D497C); } func_021D5F7C((u8 *)W(0x38)); if(!*(int *)(P(0x40)+4)) func_021D5CCC((u8 *)W(0x38),35); func_021D5E34((u8 *)W(0x30)); W(0x30)=0; }
}
