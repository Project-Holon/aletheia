/*
 * function: func_021B6B8C
 * address: 0x021B6B8C
 * packet: pkt_ov098_021B6B8C
 * region: ov098
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 EXACT. The flag byte at +0x38 is stored in each arm (0 after the create
 *   call, 1 after the else calls); a shared local x gave a colour swap (10 bytes). PRINTSYS_PrintStream
 *   is declared here to return a pointer (str r0,[r5] after the bl); the arm9 definition
 *   src/matched/arm9/PRINTSYS_PrintStream.c declares it void and needs the return fixed.
 * symbols:
 *   func_02045770  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   func_02040588  0x02040588  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   func_020409B4  0x020409B4  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb
 *   PRINTSYS_PrintStreamStop  0x0201CE0C  thumb
 *   PRINTSYS_Print  0x0201C7A4  thumb
 */

typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;
struct Descriptor;
struct CharBuf;
struct Cfg;

extern void *func_02045770(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *, u8);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BMP_WIN_MakeScreen(struct Cfg *);
extern void func_020409B4(u32);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void GF_FONT_SetTextColor(u32, u32, u32);
extern void *PRINTSYS_PrintStream(u32, u32, u32, u32, u32, u32, u32, u32, u16, u16);
extern void PRINTSYS_PrintStreamStop(void *);
extern void PRINTSYS_Print(void *, short, short, void *, void *);

void func_021B6B8C(char *a, int b)
{
    BMP_Clear(func_02045770(*(struct Descriptor **)(a + 0x1c)), 0xc);
    GF_FONT_SetTextColor(1, 9, 0xc);
    func_02040588(1, 1);
    if (b != 0) {
        PRINTSYS_PrintStreamStop(*(void **)a = PRINTSYS_PrintStream(*(u32 *)(a + 0x1c), 0, 0,
                                  *(int *)(a + 0x2c), *(int *)(a + 0x24),
                                  *(int *)(a + 0x34), *(int *)(a + 0x28), 0,
                                  *(u16 *)(a + 0x44), 0xc));
        *(char *)(a + 0x38) = 0;
    } else {
        PRINTSYS_Print(func_02045770(*(struct Descriptor **)(a + 0x1c)), 0, 0,
                      *(void **)(a + 0x2c), *(void **)(a + 0x24));
        BMP_WIN_MakeScreen(*(struct Cfg **)(a + 0x1c));
        func_020409B4(1);
        BMP_WIN_TransferChars(*(struct Descriptor **)(a + 0x1c));
        *(char *)(a + 0x38) = 1;
    }
    *(char *)(a + 0x39) = 0;
    *(u16 *)(a + 0x40) = b;
    *(u16 *)(a + 0x42) = b;
    *(char *)(a + 0x3a) = 0;
}
