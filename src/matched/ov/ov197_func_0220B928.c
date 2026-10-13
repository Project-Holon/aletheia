/*
 * function: func_0220B928
 * address: 0x0220B928
 * packet: pkt_ov197_0220B928
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: func_02012FFC() called inside the argument list (as the ov010
 *   0x02169EBC twin does) with its real signed char return; a font local
 *   computed before the call let mwcc CSE the two *p reads (DIFF 42).
 * prototypes: from the matched arm9 definitions, except PRINTSYS_PrintStream,
 *   whose definition is declared void although it forwards PRINTSYS_PrintStreamCallBack's
 *   r0; the return type is the ov010 twin's void *.
 * symbols:
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
struct Cfg;
extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);
extern signed char func_02012FFC(void);
extern void *PRINTSYS_PrintStream(void *a0, u32 a1, u32 a2, void *a3, u32 a4, u32 a5, void *a6, u32 a7, u16 a8, u32 a9);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
void func_0220B928(char *p)
{
    void *d;
    GF_FONT_SetTextColor(1, 2, 0);
    *(void **)(p + 0x1c) = PRINTSYS_PrintStream(*(void **)(p + 0x24), 0, 0, *(void **)(p + 0x14),
        *(u32 *)(*(char **)p + 4), func_02012FFC(), *(void **)(p + 4), 10,
        *(u16 *)(*(char **)p + 0xc), 15);
    d = *(void **)(p + 0x24);
    BMP_WIN_TransferChars(d);
    BMP_WIN_MakeScreen(d);
    func_02041B6C(func_02045730(d));
}
