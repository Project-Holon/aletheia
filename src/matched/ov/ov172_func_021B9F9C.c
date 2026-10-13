/*
 * function: func_021B9F9C
 * address: 0x021B9F9C
 * packet: pkt_ov172_021B9F9C
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_0208B24C 0x0208B24C arm
 *   func_0208B8B0 0x0208B8B0 arm
 *   func_0208BEF0 0x0208BEF0 arm
 *   func_0208BF54 0x0208BF54 arm
 *   OS_IsRunOnTwl 0x02085D3C arm
 *   func_021BA014 0x021BA014 arm ov172
 *   func_021BA1B4 0x021BA1B4 thumb ov172
 *   GFL_NET_AllocAligned 0x0203D7C8 arm
 *   func_02005654 0x02005654 thumb
 *   d_021C7218 0x021C7218 data a4
 *   d_021C720C 0x021C720C data a4
 *   g_021C88EC 0x021C88EC data a4
 *   func_021BA098 0x021BA098 thumb ov172
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_0208B24C(void);
extern void func_0208B8B0(void);
extern u32 func_0208BEF0(u32);
extern u32 func_0208BF54(u8);
extern int OS_IsRunOnTwl(void);
extern void func_021BA014(int, void *);
extern void func_021BA1B4(char *, u32);
extern void *GFL_NET_AllocAligned(u32, u32, const char *, u16);
extern int func_02005654(int, int);
extern const char d_021C7218[], d_021C720C[];
extern void *g_021C88EC;
extern void func_021BA098(void);
void *func_021B9F9C(u32 heap)
{
    u32 *p = func_02030734(heap, 36, 1, d_021C7218, 87);
    func_0208B24C();
    func_0208B8B0();
    func_0208BEF0(1);
    func_0208BF54(80);
    if (OS_IsRunOnTwl() == 1) func_021BA014(0, (void *)d_021C720C);
    func_021BA1B4((char *)p, heap);
    p[1] = (u32)GFL_NET_AllocAligned(heap, 51200, d_021C7218, 134);
    p[0] = 0;
    p[2] = 0;
    *((u8 *)p + 16) = 0;
    g_021C88EC = p;
    func_02005654((int)func_021BA098, 0);
    return p;
}
