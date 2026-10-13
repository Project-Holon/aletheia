/*
 * function: func_021B9960
 * address: 0x021B9960
 * packet: pkt_ov220_021B9960
 * region: ov220
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 118-byte body, then zero alignment at 021B99D6..021B99D8; following 99D8 is separate code.
 * prototype: 02049238 asm forwarder preserves entry r0 to 02078A80; original caller loads object into r0, so retain pointer input despite legacy void(void).
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned short u16;
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049B68(void *,unsigned,unsigned,unsigned,unsigned,u16);
typedef unsigned int   u32;
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *,unsigned,unsigned,unsigned,unsigned,unsigned,u16);
extern void ARC_TOOL_DeleteHandle(void *),func_020409B4(unsigned);
void func_021B9960(u16 *p)
{
    void *object;
    object=func_020490F4(201,*p);
    func_02049B68(object,0,0,0,64,*p);
    func_02049658(object,2,2,0,0,0,*p);
    func_020498F4(object,4,2,0,0,0,*p);
    func_020498F4(object,5,1,0,0,0,*p);
    ARC_TOOL_DeleteHandle(object);
    func_020409B4(2);
    func_020409B4(1);
}
