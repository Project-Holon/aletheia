/*
 * function: func_021BAC0C
 * address: 0x021BAC0C
 * packet: pkt_ov223_021BAC0C
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandle 0x02049BDC arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned short u16;
extern void *func_020490F4(unsigned int id, unsigned int heap);
typedef unsigned int   u32;
extern void ARC_UTIL_UploadPaletteFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *,unsigned,unsigned,unsigned,unsigned,unsigned,u16);
extern void ARC_TOOL_DeleteHandle(void *);
extern void func_020409B4(unsigned);
void func_021BAC0C(u16 *p)
{
    void *object;
    object=func_020490F4(205,*p);
    ARC_UTIL_UploadPaletteFromHandle(object,6,4,256,256,256,*p);
    func_02049658(object,15,4,0,0,0,*p);
    func_020498F4(object,18,4,0,0,0,*p);
    ARC_TOOL_DeleteHandle(object);
    func_020409B4(4);
}
