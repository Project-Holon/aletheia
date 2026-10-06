/*
 * function: func_0220E2B4
 * address: 0x0220E2B4
 * packet: pkt_ov198_0220E2B4
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 0220E2F6 alignment padding.
 * symbols:
 *   func_0220E2F8 0x0220E2F8 thumb ov198
 *   func_0220E340 0x0220E340 thumb ov198
 *   func_0220E3F0 0x0220E3F0 thumb ov198
 *   func_0220E518 0x0220E518 thumb ov198
 *   func_0220E460 0x0220E460 thumb ov198
 *   func_0220E584 0x0220E584 thumb ov198
 *   func_0220E5FC 0x0220E5FC thumb ov198
 *   func_0220E6E0 0x0220E6E0 thumb ov198
 *   func_0220F1F4 0x0220F1F4 thumb ov198
 *   func_02043598 0x02043598 arm
 */
extern void func_0220E2F8(char *);
typedef unsigned char  u8;
extern void func_0220E340(u8 *p);
extern void func_0220E3F0(char *);
extern void func_0220E518(char *);
extern void func_0220E460(char *);
extern void func_0220E584(char *);
extern void func_0220E5FC(char *);
extern void func_0220E6E0(char *);
extern void func_0220F1F4(u8 *p);
typedef unsigned int   u32;
extern void func_02043598(u32 mask, u32 enable);
void func_0220E2B4(char *p)
{
    func_0220E2F8(p);
    func_0220E340((u8 *)p);
    func_0220E3F0(p);
    func_0220E518(p);
    func_0220E460(p);
    func_0220E584(p);
    func_0220E5FC(p);
    func_0220E6E0(p);
    func_0220F1F4((u8 *)p);
    func_02043598(16, 1);
}
