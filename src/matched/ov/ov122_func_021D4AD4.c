/*
 * function: func_021D4AD4
 * address: 0x021D4AD4
 * packet: pkt_ov122_021D4AD4
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201DD68 0x0201DD68 thumb
 *   func_021D45E8 0x021D45E8 thumb ov122
 *   func_02040DA8 0x02040DA8 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_020403F4 0x020403F4 arm
 *   func_02045C04 0x02045C04 arm
 *   func_02045808 0x02045808 arm
 *   func_020452E8 0x020452E8 arm
 */
typedef unsigned short u16;
extern void func_0201DD68(void);
extern void func_021D45E8(char *);
extern void func_02040DA8(int, int, int);
extern void func_0203FB44(int, u16, u16);
extern void func_020403F4(int);
extern void func_02045C04(void *);
extern void func_0201D83C(void *);
extern void func_02045808(void *);
extern void func_020452E8(void *);
void func_021D4AD4(char *p)
{
    unsigned ranges;
    func_0201DD68();
    func_021D45E8(p);
    func_02040DA8(5, 1, 0);
    ranges = *(unsigned *)(p + 0x5c);
    func_0203FB44(5, (u16)ranges, (u16)(ranges >> 16));
    func_020403F4(5);
    func_020403F4(4);
    func_02045C04(*(void **)(p + 0x44));
    func_0201D83C(*(void **)(p + 0x4c));
    func_02045808(*(void **)(p + 0x54));
    func_02045808(*(void **)(p + 0x50));
    func_02045808(*(void **)(p + 0x58));
    func_020452E8(*(void **)(p + 0x3c));
}
