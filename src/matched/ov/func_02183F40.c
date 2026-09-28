/*
 * function: func_02183F40
 * address:  0x02183F40
 * packet:   pkt_02183F40
 * region:   ov168
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02061C44  0x02061C44  arm
 *   func_02184144  0x02184144  thumb  ov168
 *   func_021842B4  0x021842B4  thumb  ov168
 *   SDK_AUTOLOAD_MAIN_TWL_START  0x02FE0000  data
 */
typedef unsigned char u8;
typedef unsigned int u32;

extern void func_02061C44(void);
extern void func_02184144(void *p);
extern void func_021842B4(void *p);
extern u32 SDK_AUTOLOAD_MAIN_TWL_START[];

void func_02183F40(void *unused, char *p)
{
    func_02061C44();
    func_02184144(p);
    func_021842B4(p + 0xe4);
    *(u32 *)((u8 *)SDK_AUTOLOAD_MAIN_TWL_START + 0x3FF8) |= 1;
}
