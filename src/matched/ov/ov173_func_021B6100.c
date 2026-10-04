/*
 * function: func_021B6100
 * address: 0x021B6100
 * packet: pkt_ov173_021B6100
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0203101C 0x0203101C arm
 *   func_021B63AC 0x021B63AC thumb ov173
 *   func_021B7ADC 0x021B7ADC thumb ov173
 *   func_0203D34C 0x0203D34C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0203064C(u32,u32,u32);
extern u8 *func_0203159C(u32,u32,int);
extern void func_02082BCC(void *,int,u32);
struct GfFont;
struct Tcbl;
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct Tcbl *func_0203101C(u32 heap, u16 tag, u32 count, u32 workSize);
extern void func_021B63AC(u8 *p);
extern void func_021B7ADC(u8 *,u8,int);
extern void func_0203D34C(u32 a, u32 b);
int func_021B6100(u32 obj, int unused, u8 *input)
{
    u8 *p;
    func_0203064C(1,79,0x50000);
    p=func_0203159C(obj,0x228,79);
    func_02082BCC(p,0,0x228);
    *(u8 **)p=input;
    *(u32 *)(p+0x60)=(u32)func_0201D7EC(23,0,0,0,79);
    *(u32 *)(p+0x64)=(u32)func_0203101C(79,79,32,32);
    func_021B63AC(p);
    func_021B7ADC(p,*(u16 *)(*(u8 **)p+0x14),3);
    *(u32 *)(p+0x1b0)=1;
    func_0203D34C(1,79);
    return 1;
}
