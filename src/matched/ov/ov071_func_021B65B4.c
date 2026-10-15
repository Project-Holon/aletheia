/*
 * function: MONOLITH_TOOL_InitBackgrounds
 * address:  0x021B65B4
 * packet:   pkt_ov071_021B65B4
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   func_02041300  0x02041300  arm
 *   func_02040588  0x02040588  arm
 *   d_021BA794     0x021BA794  data  a4
 *   d_021BA7B4     0x021BA7B4  data  a4
 */

typedef unsigned char u8;

extern char d_021BA794;
extern char d_021BA7B4;

typedef unsigned int   u32;
struct BgTemplate;
void MONOLITH_TOOL_InitBackgrounds(void)
{
    void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
    void func_02041300(int, int, int, int, int, int, int);
    void func_02040588(unsigned char which, unsigned char enable);
    int i;

    BG_SYS_InitBgLayer((int)3, (const struct BgTemplate *)(&d_021BA794), (int)0);
    BG_SYS_InitBgLayer((int)7, (const struct BgTemplate *)(&d_021BA7B4), (int)0);
    func_02041300(3, 0, 0, 0, 0x20, 0x20, 0x11);
    func_02041300(7, 0, 0, 0, 0x20, 0x20, 0x11);
    for (i = 0; i <= 7; i++) {
        func_02040588((u8)i, (int)0);
    }
    func_02040588((u8)3, (int)1);
    func_02040588((u8)7, (int)1);
}
