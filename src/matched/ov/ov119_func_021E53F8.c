/*
 * function: func_021E53F8
 * address:  0x021E53F8
 * packet:   pkt_ov119_021E53F8
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020433E0 0x020433E0 arm
 *   func_0204A48C 0x0204A48C arm
 *   func_021E57E8 0x021E57E8 thumb
 *   func_02043534 0x02043534 arm
 *   func_020435F4 0x020435F4 arm
 *   d_021E7D40 0x021E7D40 data a4
 *   d_021E7CC8 0x021E7CC8 data a4
 */
extern void func_020433E0(const void *);
extern void func_0204A48C(const void *, const void *, unsigned int);
extern void func_021E57E8(int);
extern void func_02043534(int);
extern void func_020435F4(int);
extern const char d_021E7D40[];
extern const char d_021E7CC8[];
void func_021E53F8(char *p)
{
    func_020433E0(d_021E7D40);
    func_0204A48C(d_021E7CC8, d_021E7D40, *(unsigned short *)(p + 0x5F4));
    func_021E57E8(0);
    func_02043534(0);
    func_020435F4(0);
}
