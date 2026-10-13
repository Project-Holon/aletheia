/*
 * function: func_021F0CF8
 * address:  0x021F0CF8
 * packet:   pkt_ov032_021F0CF8
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F0CF8  0x021F0CF8  thumb
 *   APP_TASKMENU_WIN_Update  0x02028178  thumb
 *   APP_TASKMENU_WIN_IsFinish  0x02028230  thumb
 *   APP_TASKMENU_WIN_Delete  0x02028148  thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void APP_TASKMENU_WIN_Update(u8 *p);
extern u32 APP_TASKMENU_WIN_IsFinish(u8 *p);
extern void APP_TASKMENU_WIN_Delete(u8 *p);

int func_021F0CF8(char *p, int i)
{
    char *q;
    int j;

    q = p + 0xc0;
    APP_TASKMENU_WIN_Update((u8 *)(*(u32 *)(q + i * 16)));
    if (APP_TASKMENU_WIN_IsFinish(*(u8 **)(q + i * 16)) != 0) {
        for (j = 0; j < 3; j++) {
            APP_TASKMENU_WIN_Delete((u8 *)(*(u32 *)(p + j * 16 + 0xc0)));
            *(u32 *)(p + j * 16 + 0xc0) = 0;
        }
        return 1;
    }
    return 0;
}
