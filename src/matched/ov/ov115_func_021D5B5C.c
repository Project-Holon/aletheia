/*
 * function: func_021D5B5C
 * address: 0x021D5B5C
 * packet: pkt_ov115_021D5B5C
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MSGDATA_ReadString 0x02045CAC arm
 *   func_021D5FA0 0x021D5FA0 thumb ov115
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   func_02028470 0x02028470 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 * note 2026-10-05 (wD9r lane A6): first read of the field at +0x50 is an int read, later reads u32; the same-type form gets CSE'd and loads r1 for +0x2c. Row set after the first call.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct MsgBank;
struct Descriptor;
struct CharBuf;
struct Cfg;
struct Rec3;
extern void MSGDATA_ReadString(struct MsgBank *, u32, void *);
extern u32 func_021D5FA0(u32);
extern u32 BMP_WIN_Create(u32, u32, u32, u32, u8, u8, u8);
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *, u8);
extern void GF_FONT_SetTextColor(u32, u32, u32);
extern void func_02028470(u8 *p, u32 v);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *);
extern signed char MSG_SPEED_GetWait(void);
extern u32 PRINTSYS_PrintStream(u32, u32, u32, u32, u32, u32, u32, u32, u16, u16);
extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void BMP_WIN_MakeScreen(struct Cfg *);
extern void func_02041B6C(u32);
void func_021D5B5C(char *p, struct MsgBank *a, int b)
{
    int row;
    int kind;
    u32 w;
    MSGDATA_ReadString(a, b, *(void **)(p + 0x28));
    row = 1;
    if (*(int *)(p + 0x50) != 0) row = 19;
    if (*(u32 *)(p + 0x2c) == 0) {
        *(u32 *)(p + 0x2c) = BMP_WIN_Create(func_021D5FA0(*(u32 *)(p + 0x50)), 1, row, 30, 4, 11, 1);
    }
    w = *(u32 *)(p + 0x2c);
    BMP_Clear((struct CharBuf *)BMP_WIN_GetBmp((struct Descriptor *)w), 15);
    GF_FONT_SetTextColor(1, 2, 15);
    kind = 2;
    if (*(u32 *)(p + 0x50) == 0) kind = 6;
    func_02028470((u8 *)(p + 0x3c), (int)kind);
    if (*(u32 *)(p + 0x38) != 0) PRINTSYS_PrintStreamDelete(*(struct Rec3 **)(p + 0x38));
    *(u32 *)(p + 0x38) = PRINTSYS_PrintStream(w, 0, 0, *(u32 *)(p + 0x28), *(u32 *)(p + 0x24), MSG_SPEED_GetWait(), *(u32 *)(p + 0x44), 2, *(u16 *)(p + 0x4c), 15);
    BMP_MENUWORK_DrawWindow((void *)w, 1, (u16)(*(u32 *)p), 12);
    BMP_WIN_TransferChars((struct Descriptor *)w);
    BMP_WIN_MakeScreen((struct Cfg *)w);
    func_02041B6C(func_021D5FA0(*(u32 *)(p + 0x50)));
}
