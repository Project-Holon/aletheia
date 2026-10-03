/*
 * function: func_021DF510
 * address: 0x021DF510
 * packet: pkt_ov119_021DF510
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045CAC 0x02045CAC arm
 *   func_021E1024 0x021E1024 thumb ov119
 *   func_021E1030 0x021E1030 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DF4CC 0x021DF4CC thumb ov119
 */
typedef unsigned int   u32;
struct MsgBank;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021E1024(void *);
extern void func_021E1030(char *p);
extern void func_021D8E84(void *, int);
extern void func_021DF4CC(char *p);
void func_021DF510(char *p)
{
    func_02045CAC(*(void **)(p + 0x720), 0x88, *(void **)(p + 0x738));
    func_021E1024(p);
    func_021E1030(p);
    *(unsigned char *)(p + 0x11F1) = 0x78;
    func_021D8E84(p, (int)func_021DF4CC);
}
