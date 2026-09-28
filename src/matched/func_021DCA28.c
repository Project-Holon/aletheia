/*
 * function: func_021DCA28
 * address:  0x021DCA28
 * packet:   pkt_021DCA28
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02008510              0x02008510  thumb
 *   MI_CpuFill8                0x02082BCC  arm
 *   func_02045A90              0x02045A90  arm
 *   func_020458F8              0x020458F8  arm
 *   func_02045A98              0x02045A98  arm
 *   DWC_CheckProfanityExAsync  0x0217BC44  arm  ov009
 *   func_02045808              0x02045808  arm
 *
 * Starts a profanity check of the string in window a1: copies it into the 20-character buffer at +0x1468 (the terminator code 0x02045A98 returns becomes 0), and submits it with DWC_CheckProfanityExAsync (one word, results at +0x1484/+0x1488, region 0x80).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

extern u32 func_02008510(u32 win, u16 id);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern u16 *func_02045A90(u32 str);
extern u16 func_020458F8(u32 str);
extern u16 func_02045A98(void);
extern int DWC_CheckProfanityExAsync(u16 **words, int wordsnum, char *reserved, int timeout,
                                     char *result, int *badwordsnum, int region);
extern void func_02045808(u32 str);

void func_021DCA28(char *obj, u32 win, u16 tag)
{
    u32 str;
    u16 *src;
    u32 i;

    *(u32 *)(obj + 0x1490) = win;
    str = func_02008510(win, *(u16 *)(obj + 0x124));
    MI_CpuFill8(obj + 0x1468, 0, 0x28);
    *(u16 *)(obj + 0x148c) = tag;
    src = func_02045A90(str);
    for (i = 0; i < func_020458F8(str) + 1; i++) {
        u16 c = src[i];
        if (c == func_02045A98())
            *(u16 *)(obj + 0x1468 + i * 2) = 0;
        else
            *(u16 *)(obj + 0x1468 + i * 2) = c;
    }
    *(u16 **)(obj + 0x1480) = (u16 *)(obj + 0x1468);
    *(int *)(obj + 0x1488) = 0;
    DWC_CheckProfanityExAsync((u16 **)(obj + 0x1480), 1, 0, 0, obj + 0x1484, (int *)(obj + 0x1488), 0x80);
    func_02045808(str);
}
