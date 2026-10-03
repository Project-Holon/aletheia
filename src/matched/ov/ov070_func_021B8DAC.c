/*
 * function: func_021B8DAC
 * address: 0x021B8DAC
 * packet: pkt_ov070_021B8DAC
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Return-observed exception: 02035C08's legacy definition says void,
 * but the original retains its r0 result in r4 and returns it.
 * symbols:
 *   func_02035C08 0x02035C08 arm
 *   func_020355D8 0x020355D8 arm
 *   d_021BB978 0x021BB978 data a4
 */
extern const char d_021BB978[];
extern int func_02035C08(const void *p);
typedef unsigned char  u8;
extern void func_020355D8(u8 v);
int func_021B8DAC(void)
{
    int result;
    result = func_02035C08(d_021BB978);
    if (result != -1)
        func_020355D8(1);
    return result;
}
