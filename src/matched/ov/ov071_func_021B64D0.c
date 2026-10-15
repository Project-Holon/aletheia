/*
 * function: MONOLITH_TOOL_InitDisplay
 * address:  0x021B64D0
 * packet:   pkt_ov071_021B64D0
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   BG_SYS_Create  0x0203F8F4  arm
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *   func_02082A7C  0x02082A7C  arm
 *   d_021BA7D4     0x021BA7D4  data  ov071  a4
 *   d_021BA764     0x021BA764  data  a4
 */

extern char d_021BA7D4;
extern char d_021BA764;

typedef unsigned short u16;
struct DispConfig;
struct DispVram;
void MONOLITH_TOOL_InitDisplay(void)
{
    void BG_SYS_SetVramBanks(const struct DispVram *c);
    void BG_SYS_Create(u16 heapId);
    void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
    void func_02082A7C(int, int, int);

    BG_SYS_SetVramBanks((const struct DispVram *)(&d_021BA7D4));
    BG_SYS_Create(0x61);
    BG_SYS_SetGraphicsMode((struct DispConfig *)(&d_021BA764));
    func_02082A7C(0, 0x06000000, 0x80000);
    func_02082A7C(0, 0x06200000, 0x20000);
    func_02082A7C(0, 0x06400000, 0x40000);
    func_02082A7C(0, 0x06600000, 0x20000);
}
