/*
 * function: func_021C4B5C
 * address:  0x021C4B5C
 * packet:   pkt_ov136_021C4B5C
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SDK_AUTOLOAD_MAIN_TWL_START 0x02FE0000 data
 *   func_021C4B5C 0x021C4B5C thumb
 *   PALANM_TransferPalettes 0x02021D50 thumb
 *   func_0204A648 0x0204A648 arm
 *   func_020419E4 0x020419E4 arm
 */
typedef unsigned int u32;
typedef unsigned char u8;
extern u32 SDK_AUTOLOAD_MAIN_TWL_START[];
struct S02021D50;
extern void PALANM_TransferPalettes(struct S02021D50 *p);
extern void func_0204A648(void);
extern void func_020419E4(void);
void func_021C4B5C(void *a, u32 *p)
{
    if (p[14]) PALANM_TransferPalettes((struct S02021D50 *)p[14]);
    func_0204A648();
    func_020419E4();
    *(u32 *)((u8 *)SDK_AUTOLOAD_MAIN_TWL_START + 0x3FF8) |= 1;
}
