/*
 * function: func_01FF8700
 * address:  0x01FF8700
 * packet:   itcm
 * region:   arm9_autoload0_ITCM
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef volatile u8 vu8;
typedef volatile u32 vu32;

void func_01FF8700(u32 src, void *dst, int len)
{
    vu8  *const reg_CARD_MASTERCNT = (vu8 *)(0x04000000 + 0x1a1);
    vu8  *const reg_CARD_CMD = (vu8 *)(0x04000000 + 0x1a8);
    vu32 *const reg_CARD_CNT = (vu32 *)(0x04000000 + 0x1a4);
    vu32 *const reg_CARD_DATA = (vu32 *)(0x04000000 + 0x100010);
    vu32 *const hdr_GAME_BUF = (vu32 *)(0x02FFFE00 + 0x60);

    const u32 ctrl_start = (u32)((*hdr_GAME_BUF & ~0x07000000)
                                 | (0x01000000 | 0x00000000
                                    | 0x80000000 | 0x20000000));

    int pos = -(int)(src & (512 - 1));

    while ((*reg_CARD_CNT & 0x80000000) != 0)
    {
    }
    *reg_CARD_MASTERCNT = (u32)(0x00 | 0x80);

    for (src = (u32)(src + pos); pos < len; src += 512)
    {
        reg_CARD_CMD[0] = (u8)(0xb7);
        reg_CARD_CMD[1] = (u8)(src >> 24);
        reg_CARD_CMD[2] = (u8)(src >> 16);
        reg_CARD_CMD[3] = (u8)(src >> 8);
        reg_CARD_CMD[4] = (u8)(src >> 0);
        reg_CARD_CMD[5] = (u8)(0);
        reg_CARD_CMD[6] = (u8)(0);
        reg_CARD_CMD[7] = (u8)(0);

        *reg_CARD_CNT = ctrl_start;
        for (;;)
        {
            u32 ctrl = *reg_CARD_CNT;

            if ((ctrl & 0x00800000) != 0)
            {
                const u32 data = *reg_CARD_DATA;

                if ((pos >= 0) && (pos < len))
                {
                    *(u32 *)((u32)dst + pos) = data;
                }

                pos += sizeof(u32);
            }

            if (!(ctrl & 0x80000000))
            {
                break;
            }
        }
    }
}
