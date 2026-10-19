/*
 * unit: yes
 * function: ZUKAN_INFO_DrawMainPage
 * address: 0x021BAA4C
 * packet: pkt_ov206_021BAA4C
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: *(p+0x1e0) is read first into a local, so 0x1e0 is the first constant built and the
 *   0x1e4..0x1f0 and 0x2b0 offsets derive from it. The last loop stores the constant 0 (a copy of k's 0).
 * symbols:
 *   ZUKAN_INFO_DrawMessage 0x021BAA08 thumb ov206
 *   ZUKAN_INFO_DrawText 0x021BA960 thumb ov206
 *   ZUKAN_INFO_FlushSlotWindows 0x021BAF7C thumb ov206
 *   POKE_PERSONAL_LoadFormTable 0x0201AF80 thumb
 *   func_020307B0 0x020307B0 arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_Delete 0x0201ED04 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   gSpeciesNameBank 0x020A7370 data
 */
#include "../include/Obj00031.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *gSpeciesNameBank;
struct MsgBank;
extern void ZUKAN_INFO_DrawMessage(int heap, int window, struct MsgBank *bank, void *printer, int font, int message, unsigned short x, unsigned short y, unsigned short color, int alignment, int expansion);
extern void ZUKAN_INFO_DrawText(int heap, int window, void *printer, int font, int input, unsigned short right, unsigned short y, unsigned short color, int alignment, int expansion);
extern void ZUKAN_INFO_FlushSlotWindows(char *p);
struct MsgBank;
struct U16Vec;
extern u16 *POKE_PERSONAL_LoadFormTable(u32 heap, u16 *countOut);
extern u32 func_020307B0(void *p);
struct WordSet;
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u32 WORDSET_Delete(struct WordSet *p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void STRBUF_Delete(struct U16Vec *vec);
void ZUKAN_INFO_DrawMainPage(char *p)
{
    int l2c = ((struct Obj00031 *)p)->f1E0;
    int l28 = ((struct Obj00031 *)p)->f1E4;
    int l24 = ((struct Obj00031 *)p)->f1E8;
    int l20 = ((struct Obj00031 *)p)->f1EC;
    int l1c = ((struct Obj00031 *)p)->f1F0;
    u16 t = ((struct Obj00031 *)p)->fC;
    u16 i = 0;
    u32 h2;
    u16 r7;
    u16 r6;
    u16 m;
    void *name;
    u8 k;
    if (((struct Obj00031 *)p)->fE != 0) {
        u16 *arr = *(u16 * *)&((struct Obj00031 *)p)->f2B0;
        do {
            t = arr[t];
            if (t == 0) break;
            i = (u16)(i + 1);
        } while (i != ((struct Obj00031 *)p)->fE);
    }
    if (t == 0) t = ((struct Obj00031 *)p)->fC;
    if (((struct Obj00031 *)p)->f18 != 2) {
        ZUKAN_INFO_DrawMessage(((struct Obj00031 *)p)->f0, ((struct Obj00031 *)p)->f6C, (struct MsgBank *)l2c, (void *)(((struct Obj00031 *)p)->f2C), ((struct Obj00031 *)p)->f28, 0x90, 0, 5, 0x3c40, 2, 0);
    }
    r7 = ((struct Obj00031 *)p)->fC;
    if (((struct Obj00031 *)p)->f4 == 0) {
        u16 *tab = POKE_PERSONAL_LoadFormTable(((struct Obj00031 *)p)->f0, 0);
        r7 = tab[((struct Obj00031 *)p)->fC];
        func_020307B0(tab);
    }
    if (r7 != 0x3e7) {
        h2 = (u32)WORDSET_CreateDefault(((struct Obj00031 *)p)->f0);
        WORDSET_SetSlotNumber((struct WordSet *)h2, 0, r7, 3, 2, 1);
        ZUKAN_INFO_DrawText(((struct Obj00031 *)p)->f0, *(int *)&((struct Obj00031 *)p)->f70, (void *)(((struct Obj00031 *)p)->f2C), ((struct Obj00031 *)p)->f28, ((struct Obj00031 *)p)->f270, 8, 5, 0x3e7 + 0x59, 0, h2);
        WORDSET_Delete((struct WordSet *)h2);
    } else {
        ZUKAN_INFO_DrawText(((struct Obj00031 *)p)->f0, *(int *)&((struct Obj00031 *)p)->f70, (void *)(((struct Obj00031 *)p)->f2C), ((struct Obj00031 *)p)->f28, ((struct Obj00031 *)p)->f274, 8, 5, 0x3e7 + 0x59, 0, 0);
    }
    name = func_02045EC0(gSpeciesNameBank, ((struct Obj00031 *)p)->fC);
    PRINTSYS_PrintQueColor((void *)(((struct Obj00031 *)p)->f2C), (u32)BMP_WIN_GetBmp(((struct Obj00031 *)p)->f70), 0x30, 5, (u32)name, ((struct Obj00031 *)p)->f28, 0x440);
    STRBUF_Delete(name);
    m = 0;
    if (((struct Obj00031 *)p)->f8 != 0) m = ((struct Obj00031 *)p)->fC;
    ZUKAN_INFO_DrawMessage(((struct Obj00031 *)p)->f0, *(int *)&((struct Obj00031 *)p)->f70, (struct MsgBank *)l28, (void *)(((struct Obj00031 *)p)->f2C), ((struct Obj00031 *)p)->f28, m, 0, 0x16, 0x440, 2, 0);
    ZUKAN_INFO_DrawText(((struct Obj00031 *)p)->f0, ((struct Obj00031 *)p)->f74, (void *)(((struct Obj00031 *)p)->f2C), ((struct Obj00031 *)p)->f28, ((struct Obj00031 *)p)->f278, 0, 4, 0x440, 0, 0);
    ZUKAN_INFO_DrawText(((struct Obj00031 *)p)->f0, ((struct Obj00031 *)p)->f74, (void *)(((struct Obj00031 *)p)->f2C), ((struct Obj00031 *)p)->f28, ((struct Obj00031 *)p)->f27C, 0, 0x14, 0x440, 0, 0);
    r6 = 0;
    if (((struct Obj00031 *)p)->f8 != 0) r6 = t;
    ZUKAN_INFO_DrawMessage(((struct Obj00031 *)p)->f0, ((struct Obj00031 *)p)->f74, (struct MsgBank *)l24, (void *)(((struct Obj00031 *)p)->f2C), ((struct Obj00031 *)p)->f28, r6, 0x65, 4, 0x440, 1, 0);
    r6 = 0;
    if (((struct Obj00031 *)p)->f8 != 0) r6 = t;
    ZUKAN_INFO_DrawMessage(((struct Obj00031 *)p)->f0, ((struct Obj00031 *)p)->f74, (struct MsgBank *)l20, (void *)(((struct Obj00031 *)p)->f2C), ((struct Obj00031 *)p)->f28, r6, 0x66, 0x14, 0x440, 1, 0);
    t = 0;
    if (((struct Obj00031 *)p)->f8 != 0) t = ((struct Obj00031 *)p)->fC;
    ZUKAN_INFO_DrawMessage(((struct Obj00031 *)p)->f0, ((struct Obj00031 *)p)->f78, (struct MsgBank *)l1c, (void *)(((struct Obj00031 *)p)->f2C), ((struct Obj00031 *)p)->f28, t, 4, 5, 0x3c40, 0, 0);
    for (k = 0; k < 4; k++) {
        *(int *)(p + k * 4 + 0x7c) = 0;
    }
    ZUKAN_INFO_FlushSlotWindows(p);
}
