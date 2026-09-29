/*
 * function: func_021F3D04
 * address:  0x021F3D04
 * packet:   pkt_ov107_021F3D04
 * region:   ov107
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MBi_MakeGameInfo (mb_gameinfo.o)
 *
 * symbols:
 *   MIi_CpuClear16   0x02082A48  arm
 *   func_021F3DF4    0x021F3DF4  arm  ov107
 *   MIi_CpuClearFast 0x02082AC0  arm
 *   MIi_CpuCopy16    0x02082A60  arm
 *   func_021F3F0C    0x021F3F0C  arm  ov107
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void MIi_CpuClear16(u16 data, void *destp, u32 size);
extern int func_021F3DF4(const char *filePathp, u8 *iconp, int char_flag);
extern void MIi_CpuClearFast(u32 data, void *destp, u32 size);
extern void MIi_CpuCopy16(const void *srcp, void *destp, u32 size);
extern int func_021F3F0C(const u16 *str);

void func_021F3D04(u8 *gameInfop, const u8 *mbGameRegp, const u8 *parent)
{
    int len;
    int icon_disable;
    int icon_disable2;

    MIi_CpuClear16(0, gameInfop, 0x4c0);
    icon_disable = 1;
    gameInfop[0x4b2] = 0;
    if (func_021F3DF4(*(const char **)(mbGameRegp + 0xc), gameInfop, 1))
        icon_disable = 0;
    icon_disable2 = 0;
    if (!func_021F3DF4(*(const char **)(mbGameRegp + 0x10), gameInfop, 0))
        icon_disable2 = 1;
    icon_disable |= icon_disable2;
    if (icon_disable) {
        gameInfop[0x4b2] = 1;
        MIi_CpuClearFast(0, gameInfop, 0x220);
    }
    *(u32 *)(gameInfop + 0x4b8) = *(const u32 *)(mbGameRegp + 0x14);
    if (parent != 0)
        MIi_CpuCopy16(parent, gameInfop + 0x220, 0x16);
    gameInfop[0x236] = mbGameRegp[0x18];
    len = func_021F3F0C(*(const u16 **)(mbGameRegp + 4));
    MIi_CpuCopy16(*(const u16 **)(mbGameRegp + 4), gameInfop + 0x238, (u16)(len * 2));
    MIi_CpuCopy16(*(const u16 **)(mbGameRegp + 8), gameInfop + 0x298, 0xc0);
    gameInfop[0x358] = 1;
    *(u16 *)(gameInfop + 0x35a) = 1;
    *(u16 *)(gameInfop + 0x4b0) = 1;
}
