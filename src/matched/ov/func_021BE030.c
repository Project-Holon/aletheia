/*
 * function: func_021BE030
 * address:  0x021BE030
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   data_021C3AA0  0x021C3AA0  data
 *
 * Hands the block at 0x021C3AA0 to an arm9 routine.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern u8 data_021C3AA0[];

void func_021BE030(void)
{
    BG_SYS_SetVramBanks((const struct DispVram *)data_021C3AA0);
}
