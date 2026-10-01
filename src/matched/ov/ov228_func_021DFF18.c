/*
 * function: func_021DFF18
 * address: 0x021DFF18
 * packet: pkt_ov228_021DFF18
 * region: ov228
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * arity: 033478 overwrites incoming r3 from global +520 before forwarding to 0335AC; caller sets only r0-r2, so omit legacy fourth argument.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082A7C 0x02082A7C arm
 *   func_02033478 0x02033478 arm
 *   func_020307B0 0x020307B0 arm
 *   d_021DFF60 0x021DFF60 data a1
 * trailing: after 68-byte function are zero padding, save_outside.c string, then zeros through handed end 021DFF80; no follower.
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u32 heap,u32 size,int clear,const char *site,u16 tag);
extern void func_02082A7C(u32 data,void *dest,u32 size);
extern void func_02033478(int a,int b,int c);
extern void func_020307B0(void *p);
extern const char d_021DFF60[];
void func_021DFF18(u32 heap)
{
    void *p;
    p=func_02030734(heap,2048,0,d_021DFF60,339);
    func_02082A7C(0xFFFFFFFF,p,2048);
    func_02033478(0x7F800,(int)p,2048);
    func_020307B0(p);
}
