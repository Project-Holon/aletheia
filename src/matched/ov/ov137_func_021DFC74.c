/*
 * function: GURU2_MAIN_LoadBgPalette
 * address: 0x021DFC74
 * packet: pkt_ov137_021DFC74
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_MAIN_LoadArcMember 0x021E1634 thumb ov137
 *   NNS_G2dGetUnpackedPaletteData 0x02062A98 arm
 *   PALANM_CopyToSlot 0x020215BC thumb
 *   func_020307B0 0x020307B0 arm
 *   PALANM_BlendChannelMask 0x02022004 thumb
 *   NNS_G2dGetUnpackedCharacterData 0x02062A00 arm
 *   BG_SYS_LoadTileData 0x02040B1C arm
 *   NNS_G2dGetUnpackedScreenData 0x02062B30 arm
 *   BG_SYS_DecodeTile 0x02040AE0 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 */
#include "../include/Obj00835.h"
#include "../include/Obj02870.h"
#include "../include/Obj23767.h"
#include "../include/Obj23768.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *GURU2_MAIN_LoadArcMember(char *,u32,int);
typedef signed int     s32;
struct NitroFileHeader;
struct PalAnmSlot;
extern s32 NNS_G2dGetUnpackedPaletteData(struct NitroFileHeader *file, void **out);
extern void PALANM_CopyToSlot(struct PalAnmSlot *slots, const void *src, u32 idx, u32 off, u16 size);
extern u32 func_020307B0(void *p);
extern void PALANM_BlendChannelMask(u32,u32,u16,u32,u32);
extern s32 NNS_G2dGetUnpackedCharacterData(struct NitroFileHeader *file, void **out);
extern void BG_SYS_LoadTileData(int index, const void *src, u32 size, u32 tile);
extern int NNS_G2dGetUnpackedScreenData(void *,void **);
extern void BG_SYS_DecodeTile(u32,const void *,u32);
extern void BG_SYS_PushTile(u32);
void GURU2_MAIN_LoadBgPalette(char *p)
{
    void *buf;
    u8 *data;
    buf=GURU2_MAIN_LoadArcMember(p,17,0);
    NNS_G2dGetUnpackedPaletteData(buf,(void **)(p+0xd64));
    PALANM_CopyToSlot(((struct Obj00835 *)p)->fD78,((struct Obj23767 *)(*(u8 * *)&((struct Obj00835 *)p)->fD64))->fC,0,0,64);
    func_020307B0(buf);
    buf=GURU2_MAIN_LoadArcMember(p,20,0);
    NNS_G2dGetUnpackedPaletteData(buf,(void **)(p+0xd64));
    PALANM_CopyToSlot(((struct Obj00835 *)p)->fD78,((struct Obj23768 *)(*(u8 * *)&((struct Obj00835 *)p)->fD64))->fC,1,0,64);
    func_020307B0(buf);
    PALANM_BlendChannelMask(*(u32 *)&((struct Obj00835 *)p)->fD78,1,65535,8,0);
    buf=GURU2_MAIN_LoadArcMember(p,16,0);
    NNS_G2dGetUnpackedCharacterData(buf,(void **)(p+0xd60));
    data=*(u8 * *)&((struct Obj00835 *)p)->fD60;
    BG_SYS_LoadTileData(3,((struct Obj02870 *)data)->f14,((struct Obj02870 *)data)->f10,0);
    func_020307B0(buf);
    buf=GURU2_MAIN_LoadArcMember(p,22,0);
    NNS_G2dGetUnpackedCharacterData(buf,(void **)(p+0xd60));
    data=*(u8 * *)&((struct Obj00835 *)p)->fD60;
    BG_SYS_LoadTileData(6,((struct Obj02870 *)data)->f14,((struct Obj02870 *)data)->f10,0);
    func_020307B0(buf);
    buf=GURU2_MAIN_LoadArcMember(p,21,0);
    NNS_G2dGetUnpackedCharacterData(buf,(void **)(p+0xd60));
    data=*(u8 * *)&((struct Obj00835 *)p)->fD60;
    BG_SYS_LoadTileData(7,((struct Obj02870 *)data)->f14,((struct Obj02870 *)data)->f10,0);
    func_020307B0(buf);
    buf=GURU2_MAIN_LoadArcMember(p,19,0);
    NNS_G2dGetUnpackedScreenData(buf,(void **)(p+0xd5c));
    data=*(u8 * *)&((struct Obj00835 *)p)->fD5C;
    BG_SYS_DecodeTile(2,data+12,((struct Obj02870 *)data)->f8);
    BG_SYS_PushTile(2);
    func_020307B0(buf);
    buf=GURU2_MAIN_LoadArcMember(p,18,0);
    NNS_G2dGetUnpackedScreenData(buf,(void **)(p+0xd5c));
    data=*(u8 * *)&((struct Obj00835 *)p)->fD5C;
    BG_SYS_DecodeTile(3,data+12,((struct Obj02870 *)data)->f8);
    BG_SYS_PushTile(3);
    func_020307B0(buf);
    buf=GURU2_MAIN_LoadArcMember(p,24,0);
    NNS_G2dGetUnpackedScreenData(buf,(void **)(p+0xd5c));
    data=*(u8 * *)&((struct Obj00835 *)p)->fD5C;
    BG_SYS_DecodeTile(6,data+12,((struct Obj02870 *)data)->f8);
    BG_SYS_PushTile(6);
    func_020307B0(buf);
    buf=GURU2_MAIN_LoadArcMember(p,23,0);
    NNS_G2dGetUnpackedScreenData(buf,(void **)(p+0xd5c));
    data=*(u8 * *)&((struct Obj00835 *)p)->fD5C;
    BG_SYS_DecodeTile(7,data+12,((struct Obj02870 *)data)->f8);
    BG_SYS_PushTile(7);
    func_020307B0(buf);
}
