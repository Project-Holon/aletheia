/*
 * function: func_021B9C08
 * address:  0x021B9C08
 * packet:   pkt_ov088_021B9C08
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_0201D83C  0x0201D83C  thumb
 *   func_020452E8  0x020452E8  arm
 */

struct Descriptor;
struct PrintSys;
struct Rec;
struct U16Vec;
extern void func_02045808(struct U16Vec *vec);
extern unsigned int func_02045C04(struct Rec *rec);
extern void func_0201C4C0(struct PrintSys *p);
typedef unsigned int   u32;
extern u32 func_0201D83C(void *ptr);
extern u32 func_020452E8(struct Descriptor *d);

void func_021B9C08(int *p)
{
    func_02045808((struct U16Vec *)p[9]);
    func_02045C04((struct Rec *)p[8]);
    func_0201C4C0((struct PrintSys *)p[6]);
    func_0201D83C((void *)p[5]);
    func_020452E8((struct Descriptor *)p[0]);
}
