/*
 * function: func_02211998
 * address: 0x02211998
 * packet: pkt_ov198_02211998
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: enum offset retains 0x218C across calls and derives 0x2184.
 * ABI: 02211A24 explicitly receives the forwarded entry r2 as its r1.
 * symbols:
 *   func_02025CD0 0x02025CD0 thumb
 *   func_02025D1C 0x02025D1C thumb
 *   func_02025D24 0x02025D24 thumb
 *   func_02211A24 0x02211A24 thumb ov198
 *   d_022122D4 0x022122D4 data a4
 *   d_022122A0 0x022122A0 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
typedef enum { task_offset=0x218c } Offset;
struct Struct_02025CD0;
struct Struct_02025D1C;
struct Struct_02025D24;
extern struct Struct_02025CD0 *func_02025CD0(u32,u32,u32,u32,u8,u16);
extern void func_02025D1C(struct Struct_02025D1C *);
extern void func_02025D24(struct Struct_02025D24 *);
extern void func_02211A24(u8 *,u32);
extern const u32 d_022122D4[],d_022122A0[];
void func_02211998(u8 *p,u32 index,u32 b)
{
    Offset offset=task_offset;
    struct Struct_02025CD0 *result;
    result=func_02025CD0(d_022122D4[index],(u32)d_022122A0,(u32)p,*(u32 *)(p+offset),b,*(u16 *)(*(u8 **)p+0x10));
    *(struct Struct_02025CD0 **)(p+(offset-8))=result;
    func_02025D1C((struct Struct_02025D1C *)result);
    offset-=8;
    func_02025D24(*(struct Struct_02025D24 **)(p+offset));
    func_02211A24(p,b);
}
