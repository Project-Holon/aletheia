/*
 * file:     btl_pokeparam.c
 * unit:     yes
 * function: func_021D4D84, func_021D4EFC, func_021D4F84, func_021D505C, func_021D50B4, func_021D5150, func_021D51CC, func_021D51DC, func_021D5208, func_021D5244, func_021D52B4, func_021D533C, func_021D5364, func_021D539C, func_021D53B8, func_021D53C0, func_021D53C8, func_021D53DC, func_021D5440, func_021D5444, func_021D5448, func_021D5450, func_021D5478, func_021D54B4, func_021D54C0, func_021D54D0, func_021D54E0, func_021D54F4, func_021D5528, func_021D554C, func_021D5568, func_021D5584, func_021D55A0, func_021D55D8, func_021D5608, func_021D5640, func_021D5674, func_021D56A0, func_021D56CC, func_021D5734, func_021D5750, func_021D5778, func_021D57A8, func_021D57FC, func_021D5814, func_021D5844, func_021D5848, func_021D5854, func_021D5864, func_021D587C, func_021D58A8, func_021D590C, func_021D5970, func_021D59B4, func_021D5AD8, func_021D5B40, func_021D5B44, func_021D5B48, func_021D5B68, func_021D5B7C, func_021D5BA4, func_021D5BB0, func_021D5BDC, func_021D5C08, func_021D5C30, func_021D5C44, func_021D5CB4, func_021D5D14, func_021D5D50, func_021D5D68, func_021D5DC0, func_021D5E38, func_021D5EA8, func_021D5EFC, func_021D5F08, func_021D5F14, func_021D5F38, func_021D5F90, func_021D5FA4, func_021D5FB8, func_021D5FC0, func_021D5FE4, func_021D6008, func_021D6034, func_021D6064, func_021D6130, func_021D61A8, func_021D61F0, func_021D621C, func_021D6238, func_021D6264, func_021D62A8, func_021D62C4, func_021D62D8, func_021D6314, func_021D631C, func_021D6324, func_021D63B8, func_021D63EC, func_021D6408, func_021D6440, func_021D646C, func_021D64F0, func_021D6580, func_021D65C8, func_021D66B0, func_021D66D0, func_021D66D8, func_021D6730, func_021D6738, func_021D6740, func_021D6744, func_021D679C, func_021D67A8, func_021D67B0, func_021D67B8, func_021D67C4, func_021D67D0, func_021D67D8, func_021D67E8, func_021D67F4, func_021D6824, func_021D6848, func_021D6920, func_021D6940, func_021D69A0, func_021D69AC, func_021D69B8, func_021D6B6C, func_021D6B84, func_021D6BFC, func_021D6C24, func_021D6C2C, func_021D6C3C, func_021D6C50, func_021D6D54, func_021D6D5C, func_021D6D70, func_021D6D7C, func_021D6D90, func_021D6D9C, func_021D6DC4, func_021D6E04, func_021D6E0C, func_021D6E24, func_021D6E40, func_021D6E50, func_021D6E74, func_021D6E88, func_021D6EA0
 * address:  0x021D4D84
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D6730 0x021D6730 thumb ov093
 *   func_021D6744 0x021D6744 thumb ov093
 *   func_021D5FE4 0x021D5FE4 thumb ov093
 *   func_021D6008 0x021D6008 thumb ov093
 *   func_021D5FC0 0x021D5FC0 thumb ov093
 *   func_021D6440 0x021D6440 thumb ov093
 *   func_021D66D0 0x021D66D0 thumb ov093
 *   func_021D64F0   0x021D64F0  thumb
 *   func_021EF9F4 0x021EF9F4 thumb ov093
 *   func_021EFAD8 0x021EFAD8 thumb ov093
 *   func_021EFB34 0x021EFB34 thumb ov093
 *   func_021EFA94 0x021EFA94 thumb ov093
 *   func_021D69A0 0x021D69A0 thumb ov093
 *   func_021D65C8 0x021D65C8 thumb ov093
 *   func_021D6D5C 0x021D6D5C thumb ov093
 *   func_021D6D70   0x021D6D70  thumb
 *   func_021CD9F4 0x021CD9F4 thumb ov093
 *   func_021B9B10 0x021B9B10 thumb ov093
 *   func_021B9AEC 0x021B9AEC thumb ov093
 *   func_021B9D10 0x021B9D10 thumb ov093
 *   func_021D6738   0x021D6738  thumb
 *   func_021D6264 0x021D6264 thumb ov093
 *   func_021D6848 0x021D6848 thumb ov093
 *   func_021D6408 0x021D6408 thumb ov093
 *   func_021D6E88 0x021D6E88 thumb ov093
 *   func_021EFC78   0x021EFC78  thumb
 *   func_021D67D8 0x021D67D8 thumb ov093
 *   func_021EF9A8 0x021EF9A8 thumb ov093
 *   func_021B9F84 0x021B9F84 thumb ov093
 *   d_021EFF74  0x021EFF74  data  a1
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D805C  0x021D805C  thumb  ov093
 *   func_021D7B60  0x021D7B60  thumb  ov093
 *   d_021EFF94  0x021EFF94  data  ov093  a1
 *   func_021D5F14  0x021D5F14  thumb  ov093
 *   d_021EFFA0 0x021EFFA0 data a1
 *   func_021EAE74 0x021EAE74 thumb ov093
 *   func_021EAE64 0x021EAE64 thumb ov093
 *   func_021EAE04 0x021EAE04 thumb ov093
 *   func_021EAECC 0x021EAECC thumb ov093
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   GFL_USE_SetPlayersAudible 0x02005CA4 thumb
 *   PM_VOICE_SetMasterVolume 0x02006734 thumb
 *   func_021F8B10 0x021F8B10 thumb ov094
 *   func_021B92A0 0x021B92A0 thumb ov093
 *   func_021EAE14 0x021EAE14 thumb ov093
 *   d_021F3B88 0x021F3B88 data ov093 a4
 *   d_021F3A98 0x021F3A98 data ov093 a4
 *   func_02030734 0x02030734 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_0203D1B4 0x0203D1B4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0203D3A8  0x0203D3A8  arm
 *   func_0203D3F8  0x0203D3F8  arm
 *   POKE_REGULATION_GetDataSize 0x0201A918 thumb
 *   sub_02030734   0x02030734  arm
 *   func_02007B50  0x02007B50  thumb
 *   func_02007B00  0x02007B00  thumb
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02008468 0x02008468 thumb
 *   func_021F3A98   0x021F3A98  data
 *   func_02045A98  0x02045A98  arm
 *   MIi_CpuClear16 0x02082A48  arm
 *   STRBUF_GetLength   0x020458F8  arm
 *   STRBUF_GetChars   0x02045A90  arm
 *   sub_0201F41C   0x0201F41C  thumb
 *   GFL_NET_HANDLE_SetUserInfo 0x0203A424 arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_02082D44 0x02082D44 arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02019C90  0x02019C90  thumb
 *   POKE_TOOL_GetStatusCondition  0x02017F90  thumb
 *   func_021D63B8  0x021D63B8  thumb  ov093
 *   func_021D7D18  0x021D7D18  thumb  ov093
 *   func_021D67F4  0x021D67F4  thumb  ov093
 *   func_021D6DC4  0x021D6DC4  thumb  ov093
 *   d_021F3AA4     0x021F3AA4  data  a1
 *   POKE_TOOL_DecodePartyParam 0x02017D30 thumb
 *   POKE_TOOL_EncodePartyParam 0x02017D70 thumb
 *   func_020181F4  0x020181F4  thumb
 *   func_02017E40  0x02017E40  thumb
 *   WAZA_TOOL_GetMaxPP 0x0201C158 thumb
 *   POKE_TOOL_GetGender  0x02017F00  thumb
 *   func_021E8CE0  0x021E8CE0  thumb  ov093
 *   func_021EF948 0x021EF948 thumb ov093
 *   func_021D78E4  0x021D78E4  thumb  ov093
 *   data_021F040C  0x021F040C  data  ov093
 *   _dflt   0x0209B750  arm
 *   _dfltu  0x0209B790  arm
 *   _ddiv   0x0209D1E0  arm
 *   _dgr    0x0209B864  arm
 *   _dmul   0x0209B2E8  arm
 *   _dadd   0x0209AC04  arm
 *   _dsub   0x0209AF34  arm
 *   _dfix   0x0209C508  arm
 *   func_0689C868  0x0689C868  thumb
 *   func_021D53DC  0x021D53DC  thumb  ov093
 *   func_021D53C8  0x021D53C8  thumb  ov093
 *   func_021D5BDC  0x021D5BDC  thumb  ov093
 *   func_021D7D6C  0x021D7D6C  thumb  ov093
 *   func_021E8AFC  0x021E8AFC  thumb  ov093
 *   func_021E8B80  0x021E8B80  thumb  ov093
 *   func_021E8918  0x021E8918  thumb  ov093
 *   func_021D5750  0x021D5750  thumb  ov093
 *   func_021E8928  0x021E8928  thumb  ov093
 *   func_021E8A98  0x021E8A98  thumb  ov093
 *   func_021E8A78  0x021E8A78  thumb  ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   func_02082BCC  0x02082BCC  arm
 *   func_021D6824  0x021D6824  thumb  ov093
 *   func_020185C4  0x020185C4  thumb
 *   func_021D533C  0x021D533C  thumb  ov093
 *   func_021D5150  0x021D5150  thumb  ov093
 *   func_021D5364  0x021D5364  thumb  ov093
 *   func_021D539C  0x021D539C  thumb  ov093
 *   func_021D6C2C  0x021D6C2C  thumb  ov093
 *   func_021D53C0  0x021D53C0  thumb  ov093
 *   func_021D4EFC  0x021D4EFC  thumb  ov093
 *   func_021D58A8  0x021D58A8  thumb  ov093
 *   func_021D5970  0x021D5970  thumb  ov093
 *   func_021E8CFC 0x021E8CFC thumb ov093
 *   func_021E8D04 0x021E8D04 thumb ov093
 *   func_02017988  0x02017988  thumb
 *   func_021D52B4  0x021D52B4  thumb  ov093
 *   func_02018584 0x02018584 thumb
 *   func_021D505C 0x021D505C thumb ov093
 *   POKE_TOOL_SetStatusCondition  0x02017F9C  thumb
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   func_021D4F84 0x021D4F84 thumb ov093
 *   func_021D50B4 0x021D50B4 thumb ov093
 *   func_021D51DC  0x021D51DC  thumb  ov093
 *   d_021F3B8C     0x021F3B8C  data  a4
 *   d_021F3BC4     0x021F3BC4  data  a4
 *   func_021D6238 0x021D6238 thumb ov093
 *   PALANM_GetPairedCodeForFirst 0x0202142C thumb
 *   d_021F4470  0x021F4470  data  a4
 *   d_021F3CBC  0x021F3CBC  data  a4
 *   g_021F3CB0  0x021F3CB0  data  a4
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D5BB0 0x021D5BB0 thumb ov093
 *   func_021E03E8  0x021E03E8  thumb  ov093
 *   g_021F3ECC 0x021F3ECC data a4
 *   data_021F3AB4  0x021F3AB4  data
 *   func_02034714  0x02034714  arm
 *   _ll_mul        0x0209C054  arm
 *   d_021F6360 0x021F6360 data a4
 *   d_021F3AB8 0x021F3AB8 data a1
 *   data_021F6360  0x021F6360  data  ov093
 *   _ull_mul       0x0209C054  arm
 *   d_021F0448 0x021F0448 data a1
 *   _u32_div_f 0x0209C2B0 arm
 */
#include "btl_pokeparam_types.h"

typedef struct BtlPokeParam BtlPokeParam;
typedef struct PokemonParam PokemonParam;

int func_021D62C4(BtlPokeParam *pp, int condition);
extern u32 func_020307B0(void *p);
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern u32 func_02017E1C(PokemonParam *mon, u32 paramId, u32 arg);
extern u32 func_02019C90(u16 species, u16 form, u32 paramId);
extern u32 POKE_TOOL_GetStatusCondition(PokemonParam *mon);
void func_021D63B8(BtlPokeParam *pp, int all);
extern union SickCont func_021D7D18(int condition);
void func_021D67F4(BtlPokeParam *pp);
void func_021D6DC4(BtlPokeParam *pp);
extern u32 POKE_TOOL_DecodePartyParam(PokemonParam *mon);
extern u32 POKE_TOOL_EncodePartyParam(PokemonParam *mon, u32 wasDecoded);
extern void func_020181F4(PokemonParam *mon, u16 moveId, u32 slot);
extern void func_02017E40(PokemonParam *mon, u32 paramId, u32 value);
extern u32 WAZA_TOOL_GetMaxPP(u32 moveId, u32 ppUps);
extern u8 POKE_TOOL_GetGender(PokemonParam *mon);
extern u16 func_021E8CE0(u32 type1, u32 type2);
extern int func_021EF948(int);
extern unsigned short func_021D78E4(unsigned short stat, int stage);
extern const char d_021F3AA4[];
extern const u32 data_021F040C[4];
BtlPokeParam *func_021D4D84(PokemonParam *mon, u8 pokeId, u32 heapId);
void func_021D4EFC(BtlPokeParam *pp, PokemonParam *mon, u32 withHp, u32 withAbility);
int func_021D4F84(BtlPokeParam *pp, PokemonParam *mon, int reset);
void func_021D505C(BtlPokeParam *pp);
void func_021D50B4(BtlPokeParam *pp);
void func_021D5150(BtlPokeParam *pp);
void func_021D51CC(struct BattleMoveSlot *slot);
void func_021D51DC(struct BattleMoveSlot *slot, u32 moveId, u32 ppCap, u32 toReal);
void func_021D5208(struct MoveInfo *info, u32 moveId, u32 ppCap);
int func_021D5244(struct MoveInfo *info, PokemonParam *mon, u8 slotIndex);
void func_021D52B4(BtlPokeParam *pp, PokemonParam *mon, u32 withTypes);
void func_021D533C(BtlPokeParam *pp);
void func_021D5364(BtlPokeParam *pp);
void func_021D539C(BtlPokeParam *pp);
void func_021D53B8(BtlPokeParam *pp);
void func_021D53C0(unsigned char *stages);
void func_021D53C8(unsigned char *stages);
int func_021D53DC(signed char *stages);
u8 func_021D5440(BtlPokeParam *pp);
u16 func_021D5444(BtlPokeParam *pp);
u8 func_021D5448(BtlPokeParam *pp);
u8 func_021D5450(BtlPokeParam *pp);
u8 func_021D5478(BtlPokeParam *pp);
u8 func_021D54B4(BtlPokeParam *pp);
u16 func_021D54C0(BtlPokeParam *pp, int slot);
u32 func_021D54D0(BtlPokeParam *pp, u8 slot);
u32 func_021D54E0(BtlPokeParam *pp, u32 slot);
void func_021D54F4(BtlPokeParam *src, BtlPokeParam *dst);
u16 func_021D5528(BtlPokeParam *pp, u8 slot, u8 *pp_, u8 *ppMax);
u8 func_021D554C(BtlPokeParam *pp, u8 slot);
u8 func_021D5568(BtlPokeParam *pp, u32 slot);
u8 func_021D5584(BtlPokeParam *pp, u32 slot);
int func_021D55A0(BtlPokeParam *pp, int moveId);
int func_021D55D8(BtlPokeParam *pp, int slot, int useReal);
void func_021D5608(BtlPokeParam *pp, int slot, u8 amount);
void func_021D5640(BtlPokeParam *pp, u32 slot, u32 amount);
u16 func_021D5674(BtlPokeParam *pp, u32 slot, u8 amount);
u16 func_021D56A0(BtlPokeParam *pp, u32 slot, u8 amount);
void func_021D56CC(BtlPokeParam *pp, int slot);
void func_021D5734(BtlPokeParam *pp, u8 slot, u16 moveId, u8 ppCap, u32 toReal);
int func_021D5750(BtlPokeParam *pp, u16 moveId);
u8 func_021D5778(BtlPokeParam *pp, u16 moveId);
void func_021D57A8(BtlPokeParam *pp, u8 *type1, u8 *type2);
u16 func_021D57FC(BtlPokeParam *pp);
int func_021D5814(BtlPokeParam *pp, int type);
PokemonParam *func_021D5844(BtlPokeParam *pp);
void func_021D5848(BtlPokeParam *pp, PokemonParam *fakeMon);
void func_021D5854(BtlPokeParam *pp);
PokemonParam *func_021D5864(BtlPokeParam *pp);
int func_021D587C(BtlPokeParam *pp, int valueId);
int func_021D58A8(BtlPokeParam *pp, int valueId);
void func_021D590C(PokemonParam **monPtr, u16 *stats);
void func_021D5970(BtlPokeParam *pp, int valueId, u16 value);
int func_021D59B4(BtlPokeParam *pp, int valueId);
int func_021D5AD8(BtlPokeParam *pp, int valueId);
u16 func_021D5B40(BtlPokeParam *pp);
void func_021D5B44(BtlPokeParam *pp, u16 item);
int func_021D5B48(BtlPokeParam *pp);
int func_021D5B68(BtlPokeParam *pp);
int func_021D5B7C(BtlPokeParam *pp);
unsigned short func_021D5BA4(BtlPokeParam *pp);
int func_021D5BB0(BtlPokeParam *pp, u32 flag);
int func_021D5BDC(BtlPokeParam *pp, u32 flag);
u32 func_021D5C08(BtlPokeParam *pp);
int func_021D5C30(BtlPokeParam *pp);
int func_021D5C44(BtlPokeParam *pp);
s8 *func_021D5CB4(BtlPokeParam *pp, int stageId, u8 *minStage, u8 *maxStage);
int func_021D5D14(BtlPokeParam *pp, int stageId, int direction);
int func_021D5D50(BtlPokeParam *pp, int stageId);
int func_021D5D68(BtlPokeParam *pp);
u8 func_021D5DC0(BtlPokeParam *pp, int stageId, u8 amount);
typedef enum { SICK_SLOT_FIRST, SICK_SLOT_COUNT = 36, SICK_SLOT_FORCE_UNSIGNED = 0xFFFFFFFF } SickSlotIndex;
extern int func_021D7D6C(int sickIndex);
extern u8 func_021E8AFC(union SickCont cont);
extern u16 func_021E8B80(union SickCont cont);
extern union SickCont func_021E8918(void);
extern int func_021E8928(union SickCont cont);
extern int func_021E8A98(union SickCont cont);
extern int func_021E8A78(union SickCont cont);
extern int func_021D7B74(struct BtlPokeParam *bpp, u32 divisor);
extern void func_02082BCC(void *dst, int value, u32 size);
void func_021D6824(struct BtlPokeParam *bpp);
extern void func_020185C4(void *mon);
void func_021D6E88(struct BtlPokeParam *bpp);
void func_021D6C2C(struct BtlPokeParam *bpp);
void func_021D6D70(struct BtlPokeParam *bpp);
extern int func_0689C868(u32 sickIndex);
void func_021D5EA8(struct BtlPokeParam *bpp, int statIndex, u8 stage);
int func_021D5EFC(struct BtlPokeParam *bpp);
void func_021D5F08(struct BtlPokeParam *bpp);
u8 func_021D5F14(struct BtlPokeParam *bpp);
int func_021D5F38(struct BtlPokeParam *bpp, int delta);
void func_021D5F90(struct BtlPokeParam *bpp, u16 damage);
void func_021D5FA4(struct BtlPokeParam *bpp, u16 amount);
void func_021D5FB8(struct BtlPokeParam *bpp);
void func_021D5FC0(struct BtlPokeParam *bpp, u32 flagIndex);
void func_021D5FE4(struct BtlPokeParam *bpp, unsigned int flagIndex);
void func_021D6008(struct BtlPokeParam *bpp, unsigned int flagIndex);
void func_021D6034(struct BtlPokeParam *bpp, int sickIndex, union SickCont cont);
int func_021D6064(struct BtlPokeParam *bpp, u32 sickIndex, union SickCont *outCont, int *outCured);
int func_021D6130(struct BtlPokeParam *bpp);
int func_021D61A8(struct BtlPokeParam *bpp);
void func_021D61F0(struct BtlPokeParam *bpp);
void func_021D621C(struct BtlPokeParam *bpp, int sickIndex);
void func_021D6238(struct BtlPokeParam *bpp, int sickIndex);
void func_021D6264(struct BtlPokeParam *bpp, int sourceId);
int func_021D62A8(struct BtlPokeParam *bpp);
u16 func_021D62D8(struct BtlPokeParam *bpp, int sickIndex);
u32 func_021D6314(struct BtlPokeParam *bpp, int sickIndex);
u8 func_021D631C(struct BtlPokeParam *bpp, int sickIndex);
int func_021D6324(struct BtlPokeParam *bpp, int sickIndex);
void func_021D63EC(struct BtlPokeParam *bpp, u16 threshold);
void func_021D6408(struct BtlPokeParam *bpp);
void func_021D6440(struct BtlPokeParam *bpp, u32 flagIndex);
void func_021D646C(struct BtlPokeParam *bpp);
void func_021D64F0(struct BtlPokeParam *bpp);
void func_021D6580(struct BtlPokeParam *bpp);
void func_021D65C8(struct BtlPokeParam *dst, struct BtlPokeParam *src);
extern u8 func_021E8CFC(int typePair);
extern int func_021E8D04(int typePair);
extern u32 func_02017988(void *pokeParam, u32 form);
extern u32 func_02018584(u16 species, u16 form, u16 level);
extern void POKE_TOOL_SetStatusCondition(void *pokeParam, u32 condition);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern u8 d_021F3B8C[0x38];
extern BtlPokeParamKept d_021F3BC4;
extern unsigned short PALANM_GetPairedCodeForFirst(int a0);
unsigned char func_021D6E04(BtlPokeParam *pp);
u8 func_021D6E0C(BtlPokeParam *pp, u32 slot);
void func_021D6E24(BtlPokeParam *pp, int value);
void func_021D6E40(BtlPokeParam *pp, u8 pokeId, u16 key);
int func_021D6E50(BtlPokeParam *pp, u8 *pokeId, u16 *key);
u32 func_021D6E74(BtlPokeParam *pp);
void func_021D6EA0(BtlPokeParam *pp);

/*
 * BTL_POKEPARAM_Create: func_021D7D18 (the initial volatile-condition entry)
 * returns a one-word union by value, as in its own definition. That return
 * reserves the frame word (push r4-r6 + sub sp,#8) and stops mwcc from
 * deriving 0x272 from the hoisted 0x1f8 and 0x143 from the argument 0x9e.
 * With a u32 return every spelling of the body keeps the constant chain.
 */
BtlPokeParam *func_021D4D84(PokemonParam *mon, u8 pokeId, u32 heapId)
{
    BtlPokeParam *pp;
    u32 statusCondition;

    pp = sub_02030734(heapId, 0x1f8, 1, d_021F3AA4, 0xe3);
    pp->partyIndex = pokeId;
    pp->species = func_02017E1C(mon, 5, 0);
    pp->mon = mon;
    pp->hp = func_02017E1C(mon, 0xa0, 0);
    pp->maxHp = func_02017E1C(mon, 0xa1, 0);
    pp->heldItem = func_02017E1C(mon, 6, 0);
    if (pp->heldItem > 0x272) pp->heldItem = 0;
    pp->consumedItem = 0;
    pp->isTransformed = 0;
    pp->illusionMon = 0;
    pp->illusionActive = 0;
    pp->thresholdArmed = 0;
    pp->baseForm = func_02017E1C(mon, 0x6f, 0);
    pp->baseAbility = func_02017E1C(mon, 0xa, 0);
    pp->level = func_02017E1C(mon, 0x9e, 0);
    pp->genderRatio = func_02019C90(pp->species, pp->baseForm, 1);
    func_021D4EFC(pp, mon, 1, 1);
    pp->moveCount = func_021D4F84(pp, mon, 1);
    pp->usedMoveCount = 0;
    func_021D53C0(pp->stages.stage);
    func_021D63B8(pp, 1);
    statusCondition = POKE_TOOL_GetStatusCondition(mon);
    if (statusCondition != 0) {
        pp->sickCont[statusCondition] = func_021D7D18(statusCondition);
        pp->sickTurn[statusCondition] = 0;
    }
    pp->turnThreshold = 10000;
    pp->turnsOnField = 0;
    pp->substituteHp = 0;
    pp->lastSelectedMoveId = 0;
    pp->lastUsedMoveId = 0;
    pp->lastTargetPos = 0x11;
    pp->moveStreak = 0;
    pp->storedMoveId = 0;
    pp->storedPokeId = 0x1f;
    pp->critStage = 0;
    MI_CpuFill8(pp->turnFlags, 0, sizeof(pp->turnFlags));
    MI_CpuFill8(pp->contFlags, 0, sizeof(pp->contFlags));
    func_021D67F4(pp);
    func_021D6DC4(pp);
    return pp;
}

/* BTL_POKEPARAM_ReloadFromMon: withHp also reloads hp and maxHp, withAbility reloads the stats, ability and form. */
void func_021D4EFC(BtlPokeParam *pp, PokemonParam *mon, u32 withHp, u32 withAbility)
{
    if (withHp != 0) {
        pp->hp = func_02017E1C(mon, 0xa0, 0);
        pp->maxHp = func_02017E1C(mon, 0xa1, 0);
    }
    pp->exp = func_02017E1C(mon, 8, 0);
    func_021D52B4(pp, mon, withAbility);
    if (withAbility != 0) {
        pp->ability = func_02017E1C(mon, 0xa, 0);
    }
    pp->form = func_02017E1C(mon, 0x6f, 0);
    pp->weight = func_02019C90(pp->species, pp->form, 0x26);
    if (pp->weight < 1) {
        pp->weight = 1;
    }
}

/* BTL_POKEPARAM_LoadMoves: reads the four moves from the Pokemon, returns how many exist. */
int func_021D4F84(BtlPokeParam *pp, PokemonParam *mon, int reset)
{
    u8 wasDecoded = POKE_TOOL_DecodePartyParam(mon);
    u32 moveCount = 0;
    u32 i;
    if (reset) {
        for (i = 0; i < 4; i++) {
            pp->moves[i].cur.counterLow = 0;
            pp->moves[i].cur.counterHigh = 0;
        }
    }
    for (i = 0; i < 4; i++) {
        if (func_021D5244(&pp->moves[i].cur, mon, i)) moveCount++;
    }
    if (reset) {
        for (i = 0; i < 4; i++) {
            pp->moves[i].halves[3] = pp->moves[i].halves[0];
            pp->moves[i].halves[4] = pp->moves[i].halves[1];
            pp->moves[i].halves[5] = pp->moves[i].halves[2];
            pp->moves[i].savedActive = 1;
        }
    }
    POKE_TOOL_EncodePartyParam(mon, wasDecoded);
    return moveCount;
}

/* BTL_POKEPARAM_SaveMovesToMon */
void func_021D505C(BtlPokeParam *pp)
{
    PokemonParam *mon = pp->mon;
    u32 i;

    for (i = 0; i < 4; i++) {
        func_020181F4(mon, pp->moves[i].cur.id, (u8)i);
        func_02017E40(mon, 0x3a + i, pp->moves[i].cur.pp);
        func_02017E40(mon, 0x3e + i, pp->moves[i].cur.ppUp);
    }
}

/* BTL_POKEPARAM_SyncMovesFromMon */
void func_021D50B4(BtlPokeParam *pp)
{
    PokemonParam *mon = pp->mon;
    u32 i;
    pp->moveCount = 0;
    for (i = 0; i < 4; i++) {
        if (func_021D5244(&pp->moves[i].cur, mon, i)) pp->moveCount++;
        if (pp->moves[i].savedActive != 0) {
            pp->moves[i].halves[3] = pp->moves[i].halves[0];
            pp->moves[i].halves[4] = pp->moves[i].halves[1];
            pp->moves[i].halves[5] = pp->moves[i].halves[2];
        }
    }
}

/* BTL_POKEPARAM_ResetBattleMoves: copies the real moves over the battle moves and relinks them. */
void func_021D5150(BtlPokeParam *pp)
{
    u32 i;
    pp->moveCount = 0;
    for (i = 0; i < 4; i++) {
        pp->moves[i].halves[3] = pp->moves[i].halves[0];
        pp->moves[i].halves[4] = pp->moves[i].halves[1];
        pp->moves[i].halves[5] = pp->moves[i].halves[2];
        if (pp->moves[i].halves[3] != 0) pp->moveCount++;
        pp->moves[i].savedActive = 1;
    }
}

/*
 * BTL_POKEPARAM_ClearMoveUsedFlags: `info &= ~0xf` on a u8 narrowed the mask
 * to 0xf0 and used ands; the image keeps a 32-bit intermediate and bics with
 * 0xf. Leaf of 8 instructions: the battle view first, then the real view.
 */
void func_021D51CC(struct BattleMoveSlot *slot)
{
    u32 flags;
    flags = slot->saved.counters;
    flags &= ~0xf;
    slot->saved.counters = flags;
    flags = slot->cur.counters;
    flags &= ~0xf;
    slot->cur.counters = flags;
}

/* BTL_POKEPARAM_ReplaceMoveSlot: toReal sets the real move (and the battle copy while linked), else only the battle move. */
void func_021D51DC(struct BattleMoveSlot *slot, u32 moveId, u32 ppCap, u32 toReal)
{
    if (toReal != 0) {
        func_021D5208(&slot->cur, moveId, ppCap);
        if (slot->savedActive != 0) {
            slot->halves[3] = slot->halves[0];
            slot->halves[4] = slot->halves[1];
            slot->halves[5] = slot->halves[2];
        }
    } else {
        func_021D5208(&slot->saved, moveId, ppCap);
        slot->savedActive = 0;
    }
}

/* BTL_POKEPARAM_SetMoveInfo: full PP from the move table, limited to ppCap when ppCap is nonzero. */
void func_021D5208(struct MoveInfo *info, u32 moveId, u32 ppCap)
{
    info->id = moveId;
    info->counterLow = 0;
    info->counterHigh = 0;
    if (moveId != 0) info->ppMax = WAZA_TOOL_GetMaxPP(moveId, 0);
    else info->ppMax = 0;
    if (ppCap != 0 && info->ppMax > ppCap) info->ppMax = ppCap;
    info->pp = info->ppMax;
}

/* BTL_POKEPARAM_LoadMoveInfo: reads one move slot from the Pokemon, returns 1 when the slot holds a move. */
int func_021D5244(struct MoveInfo *info, PokemonParam *mon, u8 slotIndex)
{
    int hasMove = 1;
    u16 moveId = func_02017E1C(mon, slotIndex + 0x36, 0);
    if (info->id != moveId) {
        info->counterLow = 0;
        info->counterHigh = 0;
    }
    info->id = moveId;
    if (info->id != 0) {
        info->pp = func_02017E1C(mon, slotIndex + 0x3a, 0);
        info->ppMax = func_02017E1C(mon, slotIndex + 0x42, 0);
        info->ppUp = func_02017E1C(mon, slotIndex + 0x3e, 0);
    } else {
        hasMove = 0;
        info->pp = 0;
        info->ppMax = 0;
        info->ppUp = 0;
    }
    return hasMove;
}

/* BTL_POKEPARAM_LoadStats: withTypes also reloads both types. */
void func_021D52B4(BtlPokeParam *pp, PokemonParam *mon, u32 withTypes)
{
    if (withTypes) {
        pp->type1 = func_02017E1C(mon, 0xae, 0);
        pp->type2 = func_02017E1C(mon, 0xaf, 0);
    }
    pp->gender = POKE_TOOL_GetGender(mon);
    pp->attack = func_02017E1C(mon, 0xa2, 0);
    pp->defense = func_02017E1C(mon, 0xa3, 0);
    pp->spAttack = func_02017E1C(mon, 0xa5, 0);
    pp->spDefense = func_02017E1C(mon, 0xa6, 0);
    pp->speed = func_02017E1C(mon, 0xa4, 0);
}

/* BTL_POKEPARAM_RestoreIfNeeded */
void func_021D533C(BtlPokeParam *pp)
{
    if (pp->isTransformed != 0) {
        func_021D4EFC(pp, pp->mon, 0, 1);
        func_021D5150(pp);
        pp->isTransformed = 0;
    }
}

/* BTL_POKEPARAM_ResetMoveHistory */
void func_021D5364(BtlPokeParam *pp)
{
    u32 i;
    for (i = 0; i < 4; i++) func_021D51CC(&pp->moves[i]);
    pp->lastSelectedMoveId = 0;
    pp->lastUsedMoveId = 0;
    pp->lastTargetPos = 0x11;
    pp->moveStreak = 0;
}

/* BTL_POKEPARAM_ClearMoveFlags */
void func_021D539C(BtlPokeParam *pp)
{
    u32 i;
    for (i = 0; i < 5; i++) pp->counters[i] = 0;
}

/* BTL_POKEPARAM_Delete: tail-call thunk to the heap release function. */
void func_021D53B8(BtlPokeParam *pp)
{
    func_020307B0(pp);
}

/* BTL_POKEPARAM_InitStatStages: tail-call thunk to BTL_POKEPARAM_SetNeutralStatStages. */
void func_021D53C0(unsigned char *stages)
{
    func_021D53C8(stages);
}

/* BTL_POKEPARAM_SetNeutralStatStages: writes 6 into the seven stage bytes. */
void func_021D53C8(unsigned char *stages)
{
    stages[0] = 6;
    stages[1] = 6;
    stages[2] = 6;
    stages[3] = 6;
    stages[4] = 6;
    stages[5] = 6;
    stages[6] = 6;
}

/* BTL_POKEPARAM_RaiseLowStatStagesInArray: returns 1 when any stage changed. */
int func_021D53DC(signed char *stages)
{
    int changed = 0;
    int i = 0;
    if (stages[i] < 6) { stages[i] = 6; changed = 1; }
    i = 1;
    if (stages[i] < 6) { stages[i] = 6; changed = 1; }
    i = 2;
    if (stages[i] < 6) { stages[i] = 6; changed = 1; }
    i = 3;
    if (stages[i] < 6) { stages[i] = 6; changed = 1; }
    i = 4;
    if (stages[i] < 6) { stages[i] = 6; changed = 1; }
    i = 5;
    if (stages[i] < 6) { stages[i] = 6; changed = 1; }
    i = 6;
    if (stages[i] < 6) { stages[i] = 6; changed = 1; }
    return changed;
}

/* BTL_POKEPARAM_GetPokeId */
u8 func_021D5440(BtlPokeParam *pp) { return pp->partyIndex; }

/* BTL_POKEPARAM_GetSpecies */
u16 func_021D5444(BtlPokeParam *pp) { return pp->species; }

/* BTL_POKEPARAM_GetMoveCount: leaf of 4 instructions (the offset 0x140 is built with movs/lsls). */
u8 func_021D5448(BtlPokeParam *pp) { return pp->moveCount; }

/* BTL_POKEPARAM_CountRealMoves: counts the leading real moves that exist. */
u8 func_021D5450(BtlPokeParam *pp)
{
    u32 count;
    u32 i;
    i = 0;
    count = 0;
    for (; i < 4; i++) {
        if (pp->moves[i].cur.id == 0) break;
        count++;
    }
    return count;
}

/*
 * BTL_POKEPARAM_CountUsedMoves: counts the battle moves marked as used since
 * switch-in. stand-in: volatile, because the image re-reads moveCount as the
 * loop bound (at 021D54A6); the plain field read, in for, while and u32-index
 * forms, compiles 4 bytes short.
 */
u8 func_021D5478(BtlPokeParam *pp)
{
    u8 count;
    u8 i;
    i = 0;
    count = 0;
    for (; i < *(volatile u8 *)&pp->moveCount; i++) {
        if (pp->moves[i].saved.counterLow != 0) count++;
    }
    return count;
}

/* BTL_POKEPARAM_GetUsedMoveTotal: reads a byte at +0x143 (offset in the literal pool). */
u8 func_021D54B4(BtlPokeParam *pp)
{
    return pp->usedMoveCount;
}

/*
 * BTL_POKEPARAM_GetMoveId: the halfword is the first member of a 14-byte
 * record in the array at +0x10a; the image folds the constant 0x10a with the
 * stride (adds r2,#0xfc), it is not a +0xa field.
 */
u16 func_021D54C0(BtlPokeParam *pp, int slot)
{
    return pp->moves[slot].saved.id;
}

/* BTL_POKEPARAM_GetRealMoveId */
u32 func_021D54D0(BtlPokeParam *pp, u8 slot) { return pp->moves[slot].cur.id; }

/*
 * BTL_POKEPARAM_GetMoveUsedFlag: the image extracts with lsls #0x1c / lsrs
 * #0x1c, a 4-bit unsigned bitfield read; neither `& 0xf` nor the shift pair
 * in C reproduces it (both narrow to a mask).
 */
u32 func_021D54E0(BtlPokeParam *pp, u32 slot)
{
    return pp->moves[slot].saved.counterLow;
}

/* BTL_POKEPARAM_CopyMoves */
void func_021D54F4(BtlPokeParam *src, BtlPokeParam *dst)
{
    u32 i;
    for (i = 0; i < 4; i++) dst->moves[i] = src->moves[i];
    dst->moveCount = src->moveCount;
}

/* BTL_POKEPARAM_GetMovePP: returns the battle move id and writes its PP and PP maximum. */
u16 func_021D5528(BtlPokeParam *pp, u8 slot, u8 *ppOut, u8 *ppMaxOut)
{
    *ppOut = pp->moves[slot].saved.pp;
    *ppMaxOut = pp->moves[slot].saved.ppMax;
    return pp->moves[slot].saved.id;
}

/* BTL_POKEPARAM_GetMovePPLost */
u8 func_021D554C(BtlPokeParam *pp, u8 slot) { return pp->moves[slot].saved.ppMax - pp->moves[slot].saved.pp; }

/* BTL_POKEPARAM_GetRealMovePPLost */
u8 func_021D5568(BtlPokeParam *pp, u32 slot) { return pp->moves[slot].cur.ppMax - pp->moves[slot].cur.pp; }

/* BTL_POKEPARAM_GetMovePPChecked: 0 for a slot past the move count. */
u8 func_021D5584(BtlPokeParam *pp, u32 slot)
{
    if (slot < pp->moveCount) return pp->moves[slot].saved.pp;
    return 0;
}

/* BTL_POKEPARAM_GetMovePPById: PP of the battle move with this id, 0 when absent. stand-in: volatile re-read of moveCount as in BTL_POKEPARAM_CountUsedMoves (plain read is 4 bytes short). */
int func_021D55A0(BtlPokeParam *pp, int moveId)
{
    u32 i;
    for (i = 0; i < *(volatile u8 *)&pp->moveCount; i++) {
        if (moveId == pp->moves[i].saved.id) return pp->moves[i].saved.pp;
    }
    return 0;
}

/*
 * BTL_POKEPARAM_IsMovePPFull: the index is added in each arm of the view
 * select, so the sum is formed once and shared by the halfword and byte loads.
 */
int func_021D55D8(BtlPokeParam *pp, int slot, int useReal)
{
    struct MoveInfo *info;
    if (useReal) info = &pp->moves[slot].cur; else info = &pp->moves[slot].saved;
    if (info->id != 0 && info->pp == info->ppMax) return 1;
    return 0;
}

/* BTL_POKEPARAM_DecrementMovePP: subtracts down to 0; a linked slot also updates the real move and the Pokemon. */
void func_021D5608(BtlPokeParam *pp, int slot, u8 amount)
{
    if (pp->moves[slot].saved.pp >= amount) pp->moves[slot].saved.pp -= amount;
    else pp->moves[slot].saved.pp = 0;
    if (pp->moves[slot].savedActive != 0) {
        pp->moves[slot].cur.pp = pp->moves[slot].saved.pp;
        func_02017E40(pp->mon, slot + 0x3A, pp->moves[slot].cur.pp);
    }
}

/* BTL_POKEPARAM_DecrementRealMovePP: only for an unlinked slot (a linked slot went through the battle move). */
void func_021D5640(BtlPokeParam *pp, u32 slot, u32 amount)
{
    int newPp;
    if (pp->moves[slot].savedActive == 0) {
        newPp = (int)((u32)pp->moves[slot].cur.pp - amount);
        if (newPp < 0) newPp = 0;
        pp->moves[slot].cur.pp = newPp;
        func_02017E40(pp->mon, slot + 0x3a, pp->moves[slot].cur.pp);
    }
}

/* BTL_POKEPARAM_RestoreMovePP: adds up to ppMax, returns the battle move id. */
u16 func_021D5674(BtlPokeParam *pp, u32 slot, u8 amount)
{
    struct BattleMoveSlot *moveSlot = &pp->moves[slot];
    moveSlot->saved.pp += amount;
    if (moveSlot->saved.pp > moveSlot->saved.ppMax) moveSlot->saved.pp = moveSlot->saved.ppMax;
    if (moveSlot->savedActive) moveSlot->cur.pp = moveSlot->saved.pp;
    return moveSlot->saved.id;
}

/* BTL_POKEPARAM_RestoreRealMovePP */
u16 func_021D56A0(BtlPokeParam *pp, u32 slot, u8 amount)
{
    struct BattleMoveSlot *moveSlot = &pp->moves[slot];
    moveSlot->cur.pp += amount;
    if (moveSlot->cur.pp > moveSlot->cur.ppMax) moveSlot->cur.pp = moveSlot->cur.ppMax;
    if (moveSlot->savedActive) moveSlot->saved.pp = moveSlot->cur.pp;
    return moveSlot->cur.id;
}

/* BTL_POKEPARAM_MarkMoveUsed */
void func_021D56CC(BtlPokeParam *pp, int slot)
{
    struct BattleMoveSlot *moveSlot = &pp->moves[slot];
    if (moveSlot->saved.counterHigh == 0) {
        moveSlot->saved.counterHigh = 1;
        pp->usedMoveCount++;
    }
    moveSlot->saved.counterLow = 1;
    if (moveSlot->savedActive != 0) {
        moveSlot->cur.counterLow = moveSlot->saved.counterLow;
        moveSlot->cur.counterHigh = moveSlot->saved.counterHigh;
    }
}

/* BTL_POKEPARAM_ReplaceMove */
void func_021D5734(BtlPokeParam *pp, u8 slot, u16 moveId, u8 ppCap, u32 toReal)
{ func_021D51DC(&pp->moves[slot], moveId, ppCap, toReal); }

/* BTL_POKEPARAM_HasMove */
int func_021D5750(BtlPokeParam *pp, u16 moveId)
{ u32 i; for(i=0;i<4;i++) if(moveId == pp->moves[i].saved.id) return 1; return 0; }

/* BTL_POKEPARAM_FindMoveSlot: 4 when the move is absent or the id is 0. */
u8 func_021D5778(BtlPokeParam *pp, u16 moveId)
{
    u32 i;
    if (moveId != 0) {
        for (i = 0; i < 4; i++) {
            if (moveId == pp->moves[i].saved.id) return (u8)i;
        }
    }
    return 4;
}

/* BTL_POKEPARAM_GetTypes: both types; a flying type is hidden while condition 0x18 holds, and a hidden type takes the other one. */
void func_021D57A8(BtlPokeParam *pp, u8 *type1, u8 *type2)
{
    int typeHidden = func_021D62C4(pp, 0x18);
    u8 type;
    type = pp->type1;
    if (type == 2 && typeHidden) *type1 = 0x11;
    else *type1 = type;
    type = pp->type2;
    if (type == 2 && typeHidden) *type2 = 0x11;
    else *type2 = type;
    if (*type1 == 0x11) {
        if (*type2 == 0x11) *type2 = 0;
        *type1 = *type2;
    } else if (*type2 == 0x11) {
        *type2 = *type1;
    }
}

/* BTL_POKEPARAM_GetTypePair */
u16 func_021D57FC(BtlPokeParam *pp)
{
    u8 type1;
    u8 type2;
    func_021D57A8(pp, &type1, &type2);
    return func_021E8CE0(type1, type2);
}

/* BTL_POKEPARAM_HasType */
int func_021D5814(BtlPokeParam *pp, int type)
{
    u8 type1;
    u8 type2;
    if (type != 0x11) {
        func_021D57A8(pp, &type1, &type2);
        if (type1 == type || type2 == type) return 1;
    }
    return 0;
}

/* BTL_POKEPARAM_GetMon */
PokemonParam *func_021D5844(BtlPokeParam *pp) { return pp->mon; }

/* BTL_POKEPARAM_SetFakeMon: leaf of 6 instructions. */
void func_021D5848(BtlPokeParam *pp, PokemonParam *fakeMon)
{
    pp->illusionMon = fakeMon;
    pp->illusionActive = 1;
}

/* BTL_POKEPARAM_ClearFakeMon */
void func_021D5854(BtlPokeParam *pp) { pp->illusionMon = 0; pp->illusionActive = 0; }

/* BTL_POKEPARAM_GetDisplayMon */
PokemonParam *func_021D5864(BtlPokeParam *pp) { if (pp->illusionMon && pp->illusionActive) return pp->illusionMon; return pp->mon; }

/* BTL_POKEPARAM_RemapStatId: with the swap condition 6 active, defense (9) and spDefense (11) trade places. */
int func_021D587C(BtlPokeParam *pp, int valueId)
{
    switch(valueId) {
    case 9: if (func_021EF948(6)) valueId = 11; break;
    case 11: if (func_021EF948(6)) valueId = 9; break;
    }
    return valueId;
}

/* BTL_POKEPARAM_GetStatRaw: a stat without its stage (ids 8 to 12), 6 for ids 6 and 7, else GetValue. */
int func_021D58A8(BtlPokeParam *pp, int valueId)
{
    int id = func_021D587C(pp, valueId);
    switch (id) {
    case 8:
        return pp->attack;
    case 9:
        return pp->defense;
    case 10:
        return pp->spAttack;
    case 11:
        return pp->spDefense;
    case 12:
        return pp->speed;
    case 6:
        return 6;
    case 7:
        return 6;
    }
    return func_021D59B4(pp, id);
}

/* BTL_POKEPARAM_ReadStatsFromMon: writes maxHp, attack, defense, spAttack, spDefense, speed to stats[1..6]. */
void func_021D590C(PokemonParam **monPtr, u16 *stats)
{
    u8 wasDecoded = POKE_TOOL_DecodePartyParam(*monPtr);
    stats[1] = func_02017E1C(*monPtr, 0xa1, 0);
    stats[2] = func_02017E1C(*monPtr, 0xa2, 0);
    stats[3] = func_02017E1C(*monPtr, 0xa3, 0);
    stats[4] = func_02017E1C(*monPtr, 0xa5, 0);
    stats[5] = func_02017E1C(*monPtr, 0xa6, 0);
    stats[6] = func_02017E1C(*monPtr, 0xa4, 0);
    POKE_TOOL_EncodePartyParam(*monPtr, wasDecoded);
}

/* BTL_POKEPARAM_SetStat */
void func_021D5970(BtlPokeParam *pp, int valueId, u16 value)
{
    switch (func_021D587C(pp, valueId)) {
    case 8:
        pp->attack = value;
        break;
    case 9:
        pp->defense = value;
        break;
    case 10:
        pp->spAttack = value;
        break;
    case 11:
        pp->spDefense = value;
        break;
    case 12:
        pp->speed = value;
        break;
    }
}

/*
 * BTL_POKEPARAM_GetValue: the generic accessor. Ids 1 to 7 are the stat
 * stages, 8 to 12 the stats with their stage applied, 13 hp, 14 maxHp,
 * 15 level, 16 base-ability slot, 17 ability (0 while condition 0x10 holds),
 * 18 gender, 19 base form, 20 exp, 21 the base attack stat.
 * lever: the switch value stays in r1 and is the hidden second argument of
 * BTL_POKEPARAM_GetStatRaw; case 17 falls through into case 16.
 */
int func_021D59B4(BtlPokeParam *pp, int valueId)
{
    int id = func_021D587C(pp, valueId);

    switch (id) {
    case 8:
        return func_021D78E4(func_021D58A8(pp, id), *(u8 *)&pp->stages.attack);
    case 9:
        return func_021D78E4(func_021D58A8(pp, id), *(u8 *)&pp->stages.defense);
    case 10:
        return func_021D78E4(func_021D58A8(pp, id), *(u8 *)&pp->stages.spAttack);
    case 11:
        return func_021D78E4(func_021D58A8(pp, id), *(u8 *)&pp->stages.spDefense);
    case 12:
        return func_021D78E4(func_021D58A8(pp, id), pp->stages.speed);
    case 1:
        return pp->stages.attack;
    case 2:
        return pp->stages.defense;
    case 3:
        return pp->stages.spAttack;
    case 4:
        return pp->stages.spDefense;
    case 5:
        return *(s8 *)&pp->stages.speed;
    case 6:
        return pp->stages.accuracy;
    case 7:
        return pp->stages.evasion;
    case 15:
        return pp->level;
    case 18:
        return pp->gender;
    case 13:
        return pp->hp;
    case 14:
        return pp->maxHp;
    case 21:
        return pp->genderRatio;
    case 17:
        if (func_021D62C4(pp, 0x10) != 0)
            return 0;
    case 16:
        return pp->ability;
    case 19:
        return pp->form;
    case 20:
        return pp->exp;
    case 0:
        break;
    }
    return 0;
}

/* BTL_POKEPARAM_GetStatForCrit: the raw stat when the stage works against the attacker, else the staged stat. */
int func_021D5AD8(BtlPokeParam *pp, int valueId)
{
    int useRaw = 0;
    switch (func_021D587C(pp, valueId)) {
    case 8:
        if (pp->stages.attack < 6) useRaw = 1;
        break;
    case 10:
        if (pp->stages.spAttack < 6) useRaw = 1;
        break;
    case 9:
        if (pp->stages.defense > 6) useRaw = 1;
        break;
    case 11:
        if (pp->stages.spDefense > 6) useRaw = 1;
        break;
    }
    if (useRaw) return func_021D58A8(pp, valueId);
    return func_021D59B4(pp, valueId);
}

/* BTL_POKEPARAM_GetItem */
u16 func_021D5B40(BtlPokeParam *pp) { return pp->heldItem; }

/* BTL_POKEPARAM_SetItem */
void func_021D5B44(BtlPokeParam *pp, u16 item) { pp->heldItem = item; }

/* BTL_POKEPARAM_IsHpFull */
int func_021D5B48(BtlPokeParam *pp)
{
    if (func_021D59B4(pp, 0xd) == func_021D59B4(pp, 0xe)) return 1;
    return 0;
}

/* BTL_POKEPARAM_IsFainted */
int func_021D5B68(BtlPokeParam *pp)
{
    if (func_021D59B4(pp, 13) == 0) return 1;
    return 0;
}

/* BTL_POKEPARAM_IsAbleToBattle: 0 for an egg or a fainted Pokemon. */
int func_021D5B7C(BtlPokeParam *pp)
{
    int ok;
    ok = 0;
    if (func_02017E1C(pp->mon, 0x4c, 0)) return ok;
    if (func_021D5B68(pp) == 0) ok = 1;
    return ok;
}

/* BTL_POKEPARAM_GetTurnCount: unlabelled leaf hidden in a .word run. */
unsigned short func_021D5BA4(BtlPokeParam *pp)
{
    return pp->turnsOnField;
}

/* BTL_POKEPARAM_TestTurnFlag */
int func_021D5BB0(BtlPokeParam *pp, u32 flag)
{
    return (pp->turnFlags[(u8)(flag >> 3)] & (u8)(1 << (flag & 7))) ? 1 : 0;
}

/* BTL_POKEPARAM_TestContFlag */
int func_021D5BDC(BtlPokeParam *pp, u32 flag)
{
    return (pp->contFlags[(u8)(flag >> 3)] & (u8)(1 << (flag & 7))) ? 1 : 0;
}

/* BTL_POKEPARAM_GetSemiInvulnerableFlag: the first of four table flags that is set, 0x10 when none. */
u32 func_021D5C08(BtlPokeParam *pp)
{
    u32 i;
    for (i = 0; i < 4; i++) {
        if (func_021D5BDC(pp, data_021F040C[i])) return data_021F040C[i];
    }
    return 0x10;
}

/* BTL_POKEPARAM_IsSemiInvulnerable */
int func_021D5C30(BtlPokeParam *pp)
{
    if (func_021D5C08(pp) != 16) return 1;
    return 0;
}

/* BTL_POKEPARAM_GetHpRatioFixed: hp * 100 / maxHp as a 20.12 fixed-point value, rounded half away from zero. */
int func_021D5C44(BtlPokeParam *pp)
{
    double ratio = (double)(100 * pp->hp) / (double)pp->maxHp;
    double scaled;
    if (ratio > 0)
        scaled = 4096.0 * ratio + 0.5;
    else
        scaled = 4096.0 * ratio - 0.5;
    return (int)scaled;
}

/* BTL_POKEPARAM_GetStatStagePtr: the stage byte for stageId 1 to 7 (NULL otherwise); the range is 0 to 12. */
s8 *func_021D5CB4(BtlPokeParam *pp, int stageId, u8 *minStage, u8 *maxStage)
{
    *minStage = 0;
    *maxStage = 12;
    switch (stageId) {
    case 1: return &pp->stages.attack;
    case 2: return &pp->stages.defense;
    case 3: return &pp->stages.spAttack;
    case 4: return &pp->stages.spDefense;
    case 5: return (s8 *)&pp->stages.speed;
    case 6: return &pp->stages.accuracy;
    case 7: return &pp->stages.evasion;
    default: return 0;
    }
}

/*
 * BTL_POKEPARAM_CanChangeStatStage: direction above 0 asks for a rise.
 * extent: final two bytes are zero alignment padding.
 * evidence: BTL_POKEPARAM_GetStatStagePtr unconditionally writes both outputs
 * before its switch.
 */
int func_021D5D14(BtlPokeParam *pp, int stageId, int direction)
{
    s8 minStage;
    s8 maxStage;
    s8 *stage;
    stage = func_021D5CB4(pp, stageId, (u8 *)&minStage, (u8 *)&maxStage);
    if (direction > 0) return *stage < maxStage;
    else return *stage > minStage;
}

/*
 * BTL_POKEPARAM_GetStatStageRoom: how far the stage can still rise.
 * lever: minStage declared before maxStage places maxStage at stack offset zero.
 * evidence: BTL_POKEPARAM_GetStatStagePtr unconditionally writes both outputs
 * before its switch.
 */
int func_021D5D50(BtlPokeParam *pp, int stageId)
{
    s8 minStage;
    s8 maxStage;
    s8 *stage;
    stage = func_021D5CB4(pp, stageId, (u8 *)&minStage, (u8 *)&maxStage);
    return maxStage - *stage;
}

/* BTL_POKEPARAM_HasLoweredStatStage */
int func_021D5D68(BtlPokeParam *pp)
{
    if (pp->stages.attack < 6) return 1;
    if (pp->stages.defense < 6) return 1;
    if (pp->stages.spAttack < 6) return 1;
    if (pp->stages.spDefense < 6) return 1;
    if (*(s8 *)&pp->stages.speed < 6) return 1;
    if (pp->stages.accuracy < 6) return 1;
    if (pp->stages.evasion < 6) return 1;
    return 0;
}

/* BTL_POKEPARAM_RaiseStatStage: raises up to 12, returns the amount applied. */
u8 func_021D5DC0(BtlPokeParam *pp, int stageId, u8 amount)
{
    s8 *stage;
    int current;
    switch (stageId) {
    case 1: stage = &pp->stages.attack; break;
    case 2: stage = &pp->stages.defense; break;
    case 3: stage = &pp->stages.spAttack; break;
    case 4: stage = &pp->stages.spDefense; break;
    case 5: stage = (s8 *)&pp->stages.speed; break;
    case 6: stage = &pp->stages.accuracy; break;
    case 7: stage = &pp->stages.evasion; break;
    default: return 0;
    }
    current = stage[0];
    if (current < 12) {
        if (current + amount > 12) amount = 12 - current;
        stage[0] += amount;
        return amount;
    }
    return 0;
}

/*
 * Lower one stat stage of a battle Pokemon (1 attack, 2 defense, 3 special
 * attack, 4 special defense, 5 speed, 6 accuracy, 7 evasion). Stages run
 * 0..12 with 6 as neutral. Returns the number of steps actually applied.
 * Counterpart of func_021D5DC0 (raise), which this function follows in
 * the original file.
 */
u8 func_021D5E38(struct BtlPokeParam *pokeParam, int statIndex, u8 steps)
{
    s8 *stage;
    int current;

    switch (statIndex) {
    case 1: stage = &pokeParam->stages.attack; break;
    case 2: stage = &pokeParam->stages.defense; break;
    case 3: stage = &pokeParam->stages.spAttack; break;
    case 4: stage = &pokeParam->stages.spDefense; break;
    case 5: stage = (s8 *)&pokeParam->stages.speed; break;
    case 6: stage = &pokeParam->stages.accuracy; break;
    case 7: stage = &pokeParam->stages.evasion; break;
    default: return 0;
    }
    current = stage[0];
    if (current > 0) {
        if (current - steps < 0) steps = current;
        stage[0] -= steps;
        return steps;
    }
    return 0;
}

/* Set one stat stage (index 1..7), only when the new stage is at most 12. */
void func_021D5EA8(struct BtlPokeParam *bpp, int statIndex, u8 stage)
{
    u8 *slot;
    switch (statIndex) {
    case 1: slot = &bpp->stages.stage[0]; break;
    case 2: slot = &bpp->stages.stage[1]; break;
    case 3: slot = &bpp->stages.stage[2]; break;
    case 4: slot = &bpp->stages.stage[3]; break;
    case 5: slot = &bpp->stages.stage[4]; break;
    case 6: slot = &bpp->stages.stage[5]; break;
    case 7: slot = &bpp->stages.stage[6]; break;
    default: return;
    }
    if (stage <= 12) slot[0] = stage;
}

/* Raise every lowered stat stage back to neutral; nonzero if any changed. */
int func_021D5EFC(struct BtlPokeParam *bpp)
{
    return func_021D53DC((signed char *)bpp->stages.stage);
}

/* Reset all seven stat stages to neutral. */
void func_021D5F08(struct BtlPokeParam *bpp)
{
    func_021D53C8((unsigned char *)bpp->stages.stage);
}

/* Critical hit stage, 0 to 4; the condition with flag index 9 adds 2. */
u8 func_021D5F14(struct BtlPokeParam *bpp)
{
    u8 stage;
    stage = bpp->critStage;
    if (func_021D5BDC(bpp, 9)) {
        stage += 2;
        if (stage > 4) stage = 4;
    }
    return stage;
}

/*
 * Change the critical hit stage by delta, clamped to 0..4. Returns 1 when the
 * stage could move.
 * Lever: the clamp at the bottom stores the field in each arm
 * (`if (p->f > k) p->f = p->f - (u8)k; else p->f = 0;`). A local assigned in the arms
 * and stored once, or a ternary, keeps k out of r4 (no push {r3,r4}; 8 bytes short).
 * `n * 0xffffffff` keeps the mvns/muls (a-multiply-by-minus-one-is-strength-reduced-but-by-0xffffffff-is-not.md).
 */
int func_021D5F38(struct BtlPokeParam *bpp, int delta)
{
    int decrement;

    if (delta > 0) {
        if (bpp->critStage < 4) {
            bpp->critStage = bpp->critStage + (u8)delta;
            if (bpp->critStage > 4) bpp->critStage = 4;
            return 1;
        }
    } else {
        decrement = delta * 0xffffffff;
        if (bpp->critStage != 0) {
            if (bpp->critStage > decrement) bpp->critStage = bpp->critStage - (u8)decrement; else bpp->critStage = 0;
            return 1;
        }
    }
    return 0;
}

/*
 * Subtract damage from the current HP, stopping at 0.
 * lever: plain subtraction avoids compound-assignment operand narrowing.
 */
void func_021D5F90(struct BtlPokeParam *bpp, u16 damage)
{
    if (bpp->hp > damage) {
        bpp->hp = bpp->hp - damage;
        return;
    }
    bpp->hp = 0;
}

/* Add recovered HP, stopping at the maximum. */
void func_021D5FA4(struct BtlPokeParam *bpp, u16 amount)
{
    bpp->hp += amount;
    if (bpp->hp > bpp->maxHp) bpp->hp = bpp->maxHp;
}

/* Set the current HP to 0. */
void func_021D5FB8(struct BtlPokeParam *bpp)
{
    bpp->hp = 0x0;
}

/* Set one per-turn flag (cleared at the start of the next turn). */
void func_021D5FC0(struct BtlPokeParam *bpp, u32 flagIndex)
{
    bpp->turnFlags[(u8)(flagIndex >> 3)] |= (u8)(1 << (flagIndex & 7));
}

/*
 * Set one continuous flag (kept until the Pokemon leaves the battle).
 * lever: index the offset base (p + 0x155), preserving its separate add.
 */
void func_021D5FE4(struct BtlPokeParam *bpp, unsigned int flagIndex)
{
    bpp->contFlags[(u8)(flagIndex >> 3)] |= (u8)(1 << (flagIndex & 7));
}

/* Clear one continuous flag. */
void func_021D6008(struct BtlPokeParam *bpp, unsigned int flagIndex)
{
    bpp->contFlags[(u8)(flagIndex >> 3)] &= (u8)~(u8)(1 << (flagIndex & 7));
}

/* Store a condition in slot sickIndex with a fresh turn counter; a major status replaces all other major ones. */
void func_021D6034(struct BtlPokeParam *bpp, int sickIndex, union SickCont cont)
{
    if (func_021D7D6C(sickIndex)) func_021D61F0(bpp);
    bpp->sickCont[(u32)sickIndex] = cont;
    bpp->sickTurn[(u32)sickIndex] = 0;
}

/*
 * Advance the turn counter of one condition. Returns 1 when the slot is
 * active (and copies it to *outCont); *outCured is set to 1 when the
 * condition ran out and the slot was cleared. Slots 2 and 6 are ticked by
 * their own functions and return 0 here.
 */
int func_021D6064(struct BtlPokeParam *bpp, u32 sickIndex, union SickCont *outCont, int *outCured)
{
    u8 turnLimit;
    union SickCont cont;
    u32 index;
    if (sickIndex == 2 || sickIndex == 6) return 0;
    if (bpp->sickCont[sickIndex].byPart.kind != 0) {
        turnLimit = func_021E8AFC(bpp->sickCont[sickIndex]);
        cont = bpp->sickCont[sickIndex];
        if (outCont != 0) *outCont = cont;
        if (outCured != 0) *outCured = 0;
        if (sickIndex == 27 && func_021D5750(bpp, func_021E8B80(cont)) == 0) {
            bpp->sickCont[sickIndex] = func_021E8918();
            bpp->sickTurn[sickIndex] = 0;
            if (outCured != 0) *outCured = 1;
        }
        if (turnLimit != 0) {
            bpp->sickTurn[sickIndex]++;
            if (bpp->sickTurn[sickIndex] >= turnLimit) {
                bpp->sickCont[sickIndex] = func_021E8918();
                bpp->sickTurn[sickIndex] = 0;
                if (outCured != 0) *outCured = 1;
            }
        } else if (bpp->sickCont[sickIndex].byPart.kind == 1 && bpp->sickCont[sickIndex].byPart.paramLow != 0) {
            index = sickIndex;
            if (bpp->sickTurn[sickIndex] < bpp->sickCont[index].byPart.paramLow) bpp->sickTurn[sickIndex]++;
        }
        return 1;
    }
    return 0;
}

/* Tick the sleep counter (slot 2); it runs twice as fast with the ability 0x30 (Early Bird). Returns 1 when the Pokemon wakes up. */
int func_021D6130(struct BtlPokeParam *bpp)
{
    union SickCont *sleep = &bpp->sickCont[2];
    u8 turnLimit;
    int earlyBird;
    int step;
    if (sleep->byPart.kind != 0) {
        turnLimit = func_021E8AFC(*sleep);
        if (turnLimit != 0) {
            earlyBird = func_021D62C4(bpp, 0x10) ? 0 : (bpp->ability == 0x30);
            step = 2;
            if (earlyBird == 0) step = 1;
            bpp->sickTurn[2] += (u8)step;
            if (bpp->sickTurn[2] >= turnLimit) {
                *sleep = func_021E8918();
                func_021D6238(bpp, 2);
                return 1;
            }
        }
    }
    return 0;
}

/* Tick the counter of the condition in slot 6. Returns 1 when it ran out. */
int func_021D61A8(struct BtlPokeParam *bpp)
{
    union SickCont *cont = &bpp->sickCont[6];
    u8 turnLimit;
    if (cont->byPart.kind != 0) {
        turnLimit = func_021E8AFC(*cont);
        if (turnLimit != 0) {
            bpp->sickTurn[6]++;
            if (bpp->sickTurn[6] >= turnLimit) {
                *cont = func_021E8918();
                func_021D6238(bpp, 6);
                return 1;
            }
        }
    }
    return 0;
}

/* Clear the five major status slots (1..5). */
void func_021D61F0(struct BtlPokeParam *bpp)
{
    u32 i;
    for (i = 1; i < 6; i++) {
        bpp->sickCont[i] = func_021E8918();
        bpp->sickTurn[i] = 0;
        func_021D621C(bpp, i);
    }
}

/* Clearing slot 2 (sleep) also clears the condition in slot 9 that depends on it. */
void func_021D621C(struct BtlPokeParam *bpp, int sickIndex)
{
    if (sickIndex == 2) {
        bpp->sickCont[9] = func_021E8918();
        bpp->sickTurn[9] = 0;
    }
}

/* Clear one condition; clearing a major status clears all major ones. */
void func_021D6238(struct BtlPokeParam *bpp, int sickIndex)
{
    if (func_021D7D6C(sickIndex) != 0) {
        func_021D61F0(bpp);
        return;
    }
    bpp->sickCont[sickIndex] = func_021E8918();
    bpp->sickTurn[sickIndex] = 0;
}

/* Clear every condition that was caused by the source sourceId (0x1f means none). */
void func_021D6264(struct BtlPokeParam *bpp, int sourceId)
{
    u32 i;
    if (sourceId != 0x1f) {
        for (i = 0; i < 0x24; i++) {
            if (func_021E8928(bpp->sickCont[i]) == 0 && sourceId == func_021E8A98(bpp->sickCont[i])) {
                bpp->sickCont[i] = func_021E8918();
                func_021D621C(bpp, i);
            }
        }
    }
}

/* Index of the first active major status (1..5), or 0 when there is none. */
int func_021D62A8(struct BtlPokeParam *bpp)
{
    u32 i;
    for (i = 1; i < 6; i++) {
        if (bpp->sickCont[i].byPart.kind) return i;
    }
    return 0;
}

/* 1 when slot sickIndex holds a condition. */
int func_021D62C4(struct BtlPokeParam *bpp, int sickIndex)
{
    if (bpp->sickCont[sickIndex].byPart.kind) return 1;
    return 0;
}

/* The parameter of the condition, chosen by its kind (value, low part or high part). */
u16 func_021D62D8(struct BtlPokeParam *bpp, int sickIndex)
{
    switch (bpp->sickCont[sickIndex].byPart.kind) {
    case 2: return bpp->sickCont[sickIndex].byValue.value;
    case 3: return bpp->sickCont[sickIndex].byPart.paramLow;
    case 4: return bpp->sickCont[sickIndex].byPart.paramHigh;
    }
    return 0;
}

u32 func_021D6314(struct BtlPokeParam *bpp, int sickIndex) { return bpp->sickCont[sickIndex].raw; }

u8 func_021D631C(struct BtlPokeParam *bpp, int sickIndex) { return bpp->sickTurn[sickIndex]; }

/* Damage taken per turn from the condition in slot sickIndex (a fraction of the maximum HP). */
int func_021D6324(struct BtlPokeParam *bpp, int sickIndex)
{
    if (func_021D62C4(bpp, sickIndex) != 0) {
        switch (sickIndex) {
        case 5:
            if (func_021E8A78(bpp->sickCont[sickIndex]) != 0)
                return func_021D7B74(bpp, 0x10) * bpp->sickTurn[sickIndex];
            return func_021D7B74(bpp, 8);
        case 4:
            return func_021D7B74(bpp, 8);
        case 9:
            if (func_021D62C4(bpp, 2) != 0)
                return func_021D7B74(bpp, 4);
            break;
        case 10:
            return func_021D7B74(bpp, 4);
        default:
            return 0;
        }
    }
    return 0;
}

/*
 * Clear the conditions and their counters: all of them, or only the
 * non-major ones (from slot 6) when clearMajor is 0.
 * lever: enum loop counter with unsigned bound retains the entry guard;
 *   word-array indexing settles zero/offset scratch register allocation.
 */
void func_021D63B8(struct BtlPokeParam *bpp, int clearMajor)
{
    SickSlotIndex i;
    i = 0;
    if (clearMajor == 0) i = 6;
    for (; i < 36U; i++) {
        bpp->sickCont[i].raw = 0;
        bpp->sickCont[i].byPart.kind = 0;
    }
    func_02082BCC(bpp->sickTurn, 0, 36);
}

/* Start counting turns: restart the turn counter and arm the threshold. */
void func_021D63EC(struct BtlPokeParam *bpp, u16 threshold)
{
    bpp->turnThreshold = threshold;
    bpp->turnsOnField = 0;
    bpp->thresholdArmed = 1;
    func_021D67F4(bpp);
}

/*
 * Start of a new turn: clear the per-turn flags and count the turn (at most 9999).
 */
void func_021D6408(struct BtlPokeParam *bpp)
{
    func_02082BCC(bpp->turnFlags, 0, 2);
    if (bpp->turnsOnField < 9999)
        bpp->turnsOnField += 1;
    func_021D6824(bpp);
}

/* Clear one per-turn flag. */
void func_021D6440(struct BtlPokeParam *bpp, u32 flagIndex)
{
    u8 *flags;
    u8 byteIndex;
    u8 mask;
    flags = bpp->turnFlags;
    byteIndex = flagIndex >> 3;
    mask = 1 << (flagIndex & 7);
    flags[byteIndex] &= (u8)~mask;
}

/* Reset all battle effects (flags, history, conditions, stages) and reload the form and ability. */
void func_021D646C(struct BtlPokeParam *bpp)
{
    func_02082BCC(bpp->turnFlags, 0, 2);
    func_02082BCC(bpp->contFlags, 0, 2);
    func_021D533C(bpp);
    func_021D5150(bpp);
    func_021D5364(bpp);
    func_021D539C(bpp);
    func_021D6E88(bpp);
    func_021D6C2C(bpp);
    func_021D6D70(bpp);
    func_021D63B8(bpp, 1);
    func_021D53C0(bpp->stages.stage);
    bpp->form = bpp->baseForm;
    bpp->ability = bpp->baseAbility;
    func_02017E40(bpp->mon, 0x6f, bpp->form);
    func_020185C4(bpp->mon);
}

/* Switch-out reset: like the full reset, but keeps conditions, stages and continuous flags when flag 0xe is set. */
void func_021D64F0(struct BtlPokeParam *bpp)
{
    func_02082BCC(bpp->turnFlags, 0, 2);
    func_021D533C(bpp);
    func_021D5150(bpp);
    func_021D5364(bpp);
    func_021D539C(bpp);
    func_021D6E88(bpp);
    func_021D6C2C(bpp);
    if (func_021D5BDC(bpp, 0xe) == 0) {
        func_021D6D70(bpp);
        func_021D63B8(bpp, 0);
        func_021D53C0(bpp->stages.stage);
        func_02082BCC(bpp->contFlags, 0, 2);
    }
    bpp->form = bpp->baseForm;
    bpp->ability = bpp->baseAbility;
    func_02017E40(bpp->mon, 0x6f, bpp->form);
    func_020185C4(bpp->mon);
}

/* Reload the Pokemon from its party data and reset its effects, keeping the major status. */
void func_021D6580(struct BtlPokeParam *bpp)
{
    func_021D4EFC(bpp, bpp->mon, 0, 1);
    func_02082BCC(bpp->contFlags, 0, 2);
    func_02082BCC(bpp->turnFlags, 0, 2);
    func_021D6D70(bpp);
    func_021D5364(bpp);
    func_021D63B8(bpp, 0);
    func_021D53C0(bpp->stages.stage);
}

/* Pass the transferable effects (stages, conditions, some flags) from src to dst, then clear them on src. */
void func_021D65C8(struct BtlPokeParam *dst, struct BtlPokeParam *src)
{
    unsigned long i;
    u16 first;
    u16 second;
    dst->stages = src->stages;
    dst->substituteHp = src->substituteHp;
    for (i = 0; i < 36; i++) {
        if (src->sickCont[i].byPart.kind != 0 && func_0689C868(i)) {
            dst->sickCont[i] = src->sickCont[i];
            dst->sickTurn[i] = src->sickTurn[i];
        }
    }
    if (func_021D5BDC(src, 10)) {
        func_021D5FE4(dst, 10);
        first = func_021D58A8(dst, 8);
        second = func_021D58A8(dst, 9);
        func_021D5970(dst, 8, second);
        func_021D5970(dst, 9, first);
    }
    if (func_021D5BDC(src, 9)) func_021D5FE4(dst, 9);
    func_021D6D70(src);
    func_021D63B8(src, 0);
    func_021D53C0(src->stages.stage);
    func_02082BCC(src->contFlags, 0, 2);
}

void func_021D66B0(struct BtlPokeParam *poke, int typePair)
{
    poke->type1 = func_021E8CFC(typePair);
    poke->type2 = func_021E8D04(typePair);
}

void func_021D66D0(struct BtlPokeParam *poke, u32 ability)
{
    poke->ability = ability;
}

void func_021D66D8(struct BtlPokeParam *poke, u32 form)
{
    u32 savedState;
    poke->form = form;
    savedState = POKE_TOOL_DecodePartyParam(poke->mon);
    func_02017988(poke->mon, form);
    func_021D52B4(poke, poke->mon, 1);
    if (poke->species == 0x1ec && form == 0) {
        poke->baseForm = 0;
        poke->ability = func_02017E1C(poke->mon, 10, 0);
    }
    POKE_TOOL_EncodePartyParam(poke->mon, savedState);
}

/* Uses up the held item: it is remembered as consumed and the hand is empty. */
void func_021D6730(struct BtlPokeParam *poke, u16 itemId)
{
    poke->consumedItem = itemId;
    poke->heldItem = 0;
}

void func_021D6738(struct BtlPokeParam *poke)
{
    poke->consumedItem = 0;
}

u16 func_021D6740(struct BtlPokeParam *poke)
{
    return poke->consumedItem;
}

/* Remembers the last move used; moveStreak counts uses of the same move in a row. */
void func_021D6744(struct BtlPokeParam *poke, u8 moveSlot, int keepStreak, u8 targetPos, u16 usedMoveId, u16 selectedMoveId)
{
    u16 previousMoveId = poke->lastUsedMoveId;
    poke->lastSelectedMoveId = selectedMoveId;
    poke->lastUsedMoveId = usedMoveId;
    poke->lastMoveSlot = moveSlot;
    poke->lastTargetPos = targetPos;
    if (previousMoveId == usedMoveId) {
        if (keepStreak) poke->moveStreak += 1;
        else poke->moveStreak = 0;
    } else {
        poke->moveStreak = keepStreak ? 1 : 0;
    }
}

u16 func_021D679C(struct BtlPokeParam *poke)
{
    return poke->moveStreak;
}

u16 func_021D67A8(struct BtlPokeParam *poke)
{
    return poke->lastUsedMoveId;
}

u8 func_021D67B0(struct BtlPokeParam *poke)
{
    return poke->lastTargetPos;
}

u16 func_021D67B8(struct BtlPokeParam *poke)
{
    return poke->lastSelectedMoveId;
}

u8 func_021D67C4(struct BtlPokeParam *poke)
{
    return poke->lastMoveSlot;
}

int func_021D67D0(struct BtlPokeParam *poke)
{
    return poke->thresholdArmed;
}

/* The weight is never below 1. */
void func_021D67D8(struct BtlPokeParam *poke, u32 weight)
{
    if (weight < 1) weight = 1;
    poke->weight = weight;
}

u16 func_021D67E8(struct BtlPokeParam *poke)
{
    return poke->weight;
}

void func_021D67F4(struct BtlPokeParam *poke)
{
    func_02082BCC(poke->hitHistory, 0, sizeof(poke->hitHistory));
    func_02082BCC(poke->hitCount, 0, sizeof(poke->hitCount));
    poke->hitTurnIndex = 0;
    poke->hitHistorySpare = 0;
}

/* Starts the next turn of the three turn history and empties it. */
void func_021D6824(struct BtlPokeParam *poke)
{
    poke->hitTurnIndex++;
    if (poke->hitTurnIndex >= BTL_POKEPARAM_HIT_TURNS) poke->hitTurnIndex = 0;
    poke->hitCount[poke->hitTurnIndex] = 0;
}

/*
 * Adds a hit to the current turn; when the turn holds 6 hits the oldest is dropped.
 * stand-in: the new hit is written through a BtlPokeParam view at its address, the
 * direct array form changes the bytes (the original adds the field offset last).
 */
void func_021D6848(struct BtlPokeParam *poke, struct BtlHitRecord *record)
{
    u8 count;
    u8 turn = poke->hitTurnIndex;
    u32 i;
    struct BtlPokeParam *slot;
    count = poke->hitCount[turn];
    if (count == BTL_POKEPARAM_HIT_MAX) {
        for (i = 0; i < BTL_POKEPARAM_HIT_MAX - 1; i++) {
            poke->hitHistory[turn][i].moveId = poke->hitHistory[turn][i + 1].moveId;
            poke->hitHistory[turn][i].damage = poke->hitHistory[turn][i + 1].damage;
            poke->hitHistory[turn][i].moveType = poke->hitHistory[turn][i + 1].moveType;
            poke->hitHistory[turn][i].attackerId = poke->hitHistory[turn][i + 1].attackerId;
        }
        count--;
    }
    slot = (struct BtlPokeParam *)((u8 *)poke + turn * sizeof(poke->hitHistory[0]) + count * sizeof(struct BtlHitRecord));
    slot->hitHistory[0][0].moveId = record->moveId;
    slot->hitHistory[0][0].damage = record->damage;
    slot->hitHistory[0][0].moveType = record->moveType;
    slot->hitHistory[0][0].attackerId = record->attackerId;
    if (poke->hitCount[turn] < BTL_POKEPARAM_HIT_MAX) poke->hitCount[turn]++;
}

/* Number of hits taken turnsAgo turns ago (0 to 2); 0 when out of range. */
int func_021D6920(struct BtlPokeParam *poke, u32 turnsAgo)
{
    if (turnsAgo < BTL_POKEPARAM_HIT_TURNS) {
        turnsAgo = poke->hitTurnIndex - turnsAgo;
        if ((int)turnsAgo < 0) turnsAgo += BTL_POKEPARAM_HIT_TURNS;
        return poke->hitCount[turnsAgo];
    }
    return 0;
}

/*
 * Reads the hit that is hitsAgo hits back in the turn turnsAgo turns ago; 0 if there is none.
 * stand-in: read through a BtlPokeParam view at the hit's address (same reason as func_021D6848).
 */
int func_021D6940(const struct BtlPokeParam *poke, int turnsAgo, u32 hitsAgo, struct BtlHitRecord *out)
{
    int turn;
    u32 count;
    const struct BtlPokeParam *slot;

    if ((u32)turnsAgo < BTL_POKEPARAM_HIT_TURNS) {
        turn = poke->hitTurnIndex - turnsAgo;
        if (turn < 0) turn += BTL_POKEPARAM_HIT_TURNS;
        count = poke->hitCount[turn];
        if (hitsAgo < count) {
            slot = (const struct BtlPokeParam *)((const u8 *)poke + turn * sizeof(poke->hitHistory[0]) + (u8)(count - hitsAgo - 1) * sizeof(struct BtlHitRecord));
            out->moveId = slot->hitHistory[0][0].moveId;
            out->damage = slot->hitHistory[0][0].damage;
            out->moveType = slot->hitHistory[0][0].moveType;
            out->attackerId = slot->hitHistory[0][0].attackerId;
            return 1;
        }
    }
    return 0;
}

void func_021D69A0(struct BtlPokeParam *poke, int index, u8 value)
{
    poke->counters[index] = value;
}

u8 func_021D69AC(struct BtlPokeParam *poke, int index)
{
    return poke->counters[index];
}

/*
 * Gives up to *remaining exp: stops at the next level. Returns 1 and fills
 * result when a level was gained (the used exp is taken from *remaining).
 */
int func_021D69B8(struct BtlPokeParam *poke, u32 *remaining, struct BtlLevelUpResult *result)
{
    u32 oldExp, newExp, used, nextLevelExp;
    u16 oldMaxHp, oldAttack, oldDefense, oldSpAttack, oldSpDefense, oldSpeed;
    u8 savedState;
    if (poke->level < 100) {
        oldExp = poke->exp;
        newExp = oldExp + *remaining;
        nextLevelExp = func_02018584(poke->species, poke->form, poke->level + 1);
        if (newExp >= nextLevelExp) {
            used = nextLevelExp - oldExp;
            oldMaxHp = poke->maxHp;
            savedState = POKE_TOOL_DecodePartyParam(poke->mon);
            oldAttack = func_02017E1C(poke->mon, 0xa2, 0);
            oldDefense = func_02017E1C(poke->mon, 0xa3, 0);
            oldSpeed = func_02017E1C(poke->mon, 0xa4, 0);
            oldSpAttack = func_02017E1C(poke->mon, 0xa5, 0);
            oldSpDefense = func_02017E1C(poke->mon, 0xa6, 0);
            poke->exp = oldExp + used;
            func_02017E40(poke->mon, 8, poke->exp);
            func_020185C4(poke->mon);
            poke->maxHp = func_02017E1C(poke->mon, 0xa1, 0);
            poke->level = func_02017E1C(poke->mon, 0x9e, 0);
            oldMaxHp = poke->maxHp - oldMaxHp;
            result->attackGain = func_02017E1C(poke->mon, 0xa2, 0);
            result->defenseGain = func_02017E1C(poke->mon, 0xa3, 0);
            result->spAttackGain = func_02017E1C(poke->mon, 0xa5, 0);
            result->spDefenseGain = func_02017E1C(poke->mon, 0xa6, 0);
            result->speedGain = func_02017E1C(poke->mon, 0xa4, 0);
            if (poke->isTransformed == 0) {
                poke->attack = result->attackGain;
                poke->defense = result->defenseGain;
                poke->spAttack = result->spAttackGain;
                poke->spDefense = result->spDefenseGain;
                poke->speed = result->speedGain;
            }
            result->level = poke->level;
            result->maxHpGain = oldMaxHp;
            result->attackGain -= oldAttack;
            result->defenseGain -= oldDefense;
            result->spAttackGain -= oldSpAttack;
            result->spDefenseGain -= oldSpDefense;
            result->speedGain -= oldSpeed;
            poke->hp += oldMaxHp;
            func_02017E40(poke->mon, 0xa0, poke->hp);
            func_021D505C(poke);
            POKE_TOOL_EncodePartyParam(poke->mon, savedState);
            *remaining -= used;
            return 1;
        } else {
            poke->exp = newExp;
            func_02017E40(poke->mon, 8, newExp);
        }
    }
    if (result != 0) func_02082BCC(result, 0, sizeof(struct BtlLevelUpResult));
    return 0;
}

/* Exp needed to reach level 100. */
u32 func_021D6B6C(struct BtlPokeParam *poke)
{
    return func_02018584(poke->species, poke->form, 100);
}

/* Writes exp, HP, status, held item and form back into the party Pokemon. */
void func_021D6B84(struct BtlPokeParam *poke, int useOriginalForm)
{
    void *pokeParam = poke->mon;
    u32 form;

    func_02017E40(pokeParam, 8, poke->exp);
    func_02017E40(pokeParam, 0xa0, poke->hp);
    if (poke->hp != 0)
        POKE_TOOL_SetStatusCondition(pokeParam, func_021D62A8(poke));
    else
        POKE_TOOL_SetStatusCondition(pokeParam, 0);
    func_021D505C(poke);
    if (poke->isTransformed || useOriginalForm != 0)
        form = poke->baseForm;
    else
        form = poke->form;
    func_02017E40(pokeParam, 0x6f, (u8)form);
    func_020185C4(pokeParam);
    func_02017E40(pokeParam, 6, poke->heldItem);
}

void func_021D6BFC(struct BtlPokeParam *poke)
{
    if (!poke->isTransformed) {
        func_021D4EFC(poke, poke->mon, 1, 0);
        func_021D50B4(poke);
    } else {
        func_021D4F84(poke, poke->mon, 0);
    }
}

int func_021D6C24(struct BtlPokeParam *poke)
{
    return poke->illusionActive;
}

void func_021D6C2C(struct BtlPokeParam *poke)
{
    poke->illusionActive = 0;
    poke->illusionMon = 0;
}

void func_021D6C3C(void **pokeParamSlot, void *pokeParam)
{
    func_02017E1C(pokeParam, 5, 0);
    *pokeParamSlot = pokeParam;
}

/*
 * Transform: poke becomes a copy of target (its stats and moves) but keeps
 * its identity part; the copied moves get 5 PP. Fails (returns 0) when either
 * is already transformed or the target has a substitute.
 */
int func_021D6C50(struct BtlPokeParam *poke, struct BtlPokeParam *target)
{
    u16 savedSubstituteHp;
    int i;
    if (poke->isTransformed == 0 && target->isTransformed == 0 && target->substituteHp == 0) {
        MI_CpuCopy8(poke->moves, d_021F3B8C, sizeof(poke->moves));
        d_021F3BC4 = *(BtlPokeParamKept *)poke;
        savedSubstituteHp = poke->substituteHp;
        *poke = *target;
        *(BtlPokeParamKept *)poke = d_021F3BC4;
        poke->substituteHp = savedSubstituteHp;
        MI_CpuCopy8(d_021F3B8C, poke->moves, sizeof(poke->moves));
        for (i = 0; i < BTL_POKEPARAM_MOVE_COUNT; i++)
            func_021D51DC(&poke->moves[i], target->moves[i].saved.id, 5, 0);
        MI_CpuFill8(poke->turnFlags, 0, sizeof(poke->turnFlags));
        MI_CpuFill8(poke->contFlags, 0, sizeof(poke->contFlags));
        poke->turnThreshold = 10000;
        poke->turnsOnField = 0;
        poke->lastSelectedMoveId = 0;
        poke->lastUsedMoveId = 0;
        poke->lastTargetPos = 0x11;
        poke->moveStreak = 0;
        poke->isTransformed = 1;
        return 1;
    }
    return 0;
}

int func_021D6D54(struct BtlPokeParam *poke)
{
    return poke->isTransformed;
}

void func_021D6D5C(struct BtlPokeParam *poke, u16 hp)
{
    poke->substituteHp = hp;
    func_021D6238(poke, 8);
}

void func_021D6D70(struct BtlPokeParam *poke)
{
    poke->substituteHp = 0;
}

u32 func_021D6D7C(struct BtlPokeParam *poke)
{
    return (poke->substituteHp != 0);
}

int func_021D6D90(struct BtlPokeParam *poke)
{
    return poke->substituteHp;
}

/*
 * Lets the substitute take *damage: returns 1 and lowers *damage to what the
 * substitute still had when it breaks, else lowers the substitute and returns 0.
 */
int func_021D6D9C(struct BtlPokeParam *poke, u16 *damage)
{
    u16 requested;
    requested = *damage;
    if (poke->substituteHp <= requested) {
        *damage = poke->substituteHp;
        poke->substituteHp = 0;
        return 1;
    }
    poke->substituteHp -= requested;
    return 0;
}

void func_021D6DC4(struct BtlPokeParam *poke)
{
    poke->foughtCount = 0;
}

/* Adds an opponent to the fought list unless it is already there. */
void func_021D6DCC(struct BtlPokeParam *poke, u32 pokeId)
{
    u32 i;
    u8 count = poke->foughtCount;

    for (i = 0; i < count; i++) {
        if (pokeId == poke->foughtIds[i]) return;
    }
    if (i < BTL_POKEPARAM_FOUGHT_MAX) {
        poke->foughtIds[i] = pokeId;
        poke->foughtCount++;
    }
}

unsigned char func_021D6E04(BtlPokeParam *pp)
{
    return pp->foughtCount;
}


u8 func_021D6E0C(BtlPokeParam *pp, u32 slot)
{
    if (slot < pp->foughtCount) return pp->foughtIds[slot];
    return BTL_POKEPARAM_NO_POKE;
}


void func_021D6E24(BtlPokeParam *pp, int value)
{
    u32 code;
    code = PALANM_GetPairedCodeForFirst(value);
    if (code == 0) code = 4;
    func_02017E40(pp->mon, 0x98, code);
}


void func_021D6E40(BtlPokeParam *pp, u8 pokeId, u16 key)
{
    pp->storedPokeId = pokeId;
    pp->storedMoveId = key;
}


int func_021D6E50(BtlPokeParam *pp, u8 *pokeId, u16 *key)
{
    if (pp->storedPokeId != BTL_POKEPARAM_NO_POKE) {
        *pokeId = pp->storedPokeId;
        *key = pp->storedMoveId;
        return 1;
    }
    return 0;
}


u32 func_021D6E74(BtlPokeParam *pp)
{
    return (pp->storedPokeId != BTL_POKEPARAM_NO_POKE);
}


void func_021D6E88(BtlPokeParam *pp)
{
    if (pp->storedPokeId != BTL_POKEPARAM_NO_POKE) {
        pp->storedPokeId = BTL_POKEPARAM_NO_POKE;
        pp->storedMoveId = 0;
    }
}

void func_021D6EA0(BtlPokeParam *pp)
{
    func_020185C4(pp->mon);
}
