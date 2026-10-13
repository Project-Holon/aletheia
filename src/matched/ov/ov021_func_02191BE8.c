/*
 * function: FIELD_MSGBG_BgWinMain
 * address:  0x02191BE8
 * packet:   pkt_ov021_02191BE8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STRBUF_GetLength  0x020458F8  arm
 *   STRBUF_Create  0x020457B0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   FIELD_MSGBG_PrintTwoLines  0x0219214C  thumb  ov021
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02040618  0x02040618  arm
 *   FIELD_MSGBG_IsLineMissing  0x02192138  thumb  ov021
 *   KEY_GetTrg  0x020362DC  arm
 *   FIELD_MSGBG_AnimateCursor  0x021928C0  thumb  ov021
 *   FIELD_MSGBG_ClearCursor  0x021927FC  thumb  ov021
 *   BMP_CopyPixels  0x02043814  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FIELD_MSGBG_RollLines  0x021921C8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Bmp;
struct U16Vec;
extern u16 STRBUF_GetLength(struct U16Vec *vec);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *w);
extern int FIELD_MSGBG_PrintTwoLines(u32 a, u32 b, u32 c, u32 d, u32 *cnt, u8 col);
extern void BMP_WIN_TransferChars(struct Descriptor *w);
extern void func_020409B4(u32 layer);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern int FIELD_MSGBG_IsLineMissing(u32 a, u32 b, u32 c);
extern u32 KEY_GetTrg(void);
struct Cur;
extern void FIELD_MSGBG_AnimateCursor(struct Cur *c, u32 win, u32 col);
extern void FIELD_MSGBG_ClearCursor(struct Cur *c, u32 win, u32 col);
extern void BMP_CopyPixels(struct Bmp *dst, const struct Bmp *src);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern int FIELD_MSGBG_RollLines(u32 a, u32 b, u32 c, int n, u16 col);

u32 FIELD_MSGBG_BgWinMain(u32 *p, u32 b)
{
    switch (p[6]) {
    case 0:
        p[4] = b;
        p[5] = (u32)STRBUF_Create(STRBUF_GetLength((struct U16Vec *)b) + 2, *(u16 *)p[0]);
        FIELD_MSGBG_PrintTwoLines((u32)BMP_WIN_GetBmp((struct Descriptor *)p[1]), p[12], p[4], p[5], p + 9, 15);
        BMP_WIN_TransferChars((struct Descriptor *)p[1]);
        func_020409B4((u8)((u16 *)p[0])[1]);
        p[6]++;
        break;
    case 1:
        *(int *)&p[7] += 12;
        if (*(int *)&p[7] >= 0) {
            p[7] = 0;
            p[6]++;
        }
        func_02040618((u8)((u16 *)p[0])[1], 3, p[7]);
        break;
    case 2:
        if (FIELD_MSGBG_IsLineMissing(p[4], p[5], p[9]) == 1) {
            p[6] = 5;
            break;
        }
        p[6]++;
    case 3:
        if ((KEY_GetTrg() & 3) == 0) {
            FIELD_MSGBG_AnimateCursor((struct Cur *)(p + 10), (u32)BMP_WIN_GetBmp((struct Descriptor *)p[1]), 15);
            BMP_WIN_TransferChars((struct Descriptor *)p[1]);
            break;
        }
        FIELD_MSGBG_ClearCursor((struct Cur *)(p + 10), (u32)BMP_WIN_GetBmp((struct Descriptor *)p[1]), 15);
        BMP_CopyPixels((struct Bmp *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p[1])), (const struct Bmp *)p[3]);
        FIELD_MSGBG_PrintTwoLines(p[2], p[12], p[4], p[5], p + 9, 15);
        p[8] = 0;
        GFL_USE_PlaySeDefaultVolume(0x547);
        p[6]++;
    case 4:
        if (FIELD_MSGBG_RollLines((u32)BMP_WIN_GetBmp((struct Descriptor *)p[1]), p[3], p[2], p[8], 15) == 1) {
            p[6] = 2;
        } else {
            p[8] += 4;
        }
        BMP_WIN_TransferChars((struct Descriptor *)p[1]);
        func_020409B4((u8)((u16 *)p[0])[1]);
        break;
    case 5:
        if ((KEY_GetTrg() & 0xf3) == 0) {
            break;
        }
        p[6]++;
    case 6:
        *(int *)&p[7] -= 12;
        if (*(int *)&p[7] <= -48) {
            p[7] = -48;
        }
        func_02040618((u8)((u16 *)p[0])[1], 3, p[7]);
        if (*(int *)&p[7] == -48) {
            p[6]++;
            return 1;
        }
        break;
    case 7:
        return 1;
    }
    return 0;
}
