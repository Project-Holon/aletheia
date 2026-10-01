/*
 * function: func_021B9A80
 * address: 0x021B9A80
 * packet: pkt_ov218_021B9A80
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201CE48 0x0201CE48 thumb
 *   func_020452E8 0x020452E8 arm
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_02031140 0x02031140 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_020307B0 0x020307B0 arm
 */
struct Rec3;
struct Descriptor;
struct U16Vec;
struct Rec;
struct PrintSys;
struct S02031140;
struct WordSet;
extern void func_0201CE48(struct Rec3 *);
extern void func_020452E8(struct Descriptor *);
extern void func_02045808(struct U16Vec *);
extern void func_02045C04(struct Rec *);
extern void func_0201C4C0(struct PrintSys *);
extern void func_0201D83C(void *);
extern void func_02031140(struct S02031140 *);
extern void func_0201ED04(struct WordSet *);
extern void func_020307B0(void *);
void func_021B9A80(char *p)
{
    if (*(struct Rec3 **)(p + 0x20) != 0) {
        func_0201CE48(*(struct Rec3 **)(p + 0x20));
        *(struct Rec3 **)(p + 0x20) = 0;
    }
    func_020452E8(*(struct Descriptor **)(p + 0x28));
    func_020452E8(*(struct Descriptor **)(p + 0x24));
    func_02045808(*(struct U16Vec **)(p + 0x18));
    func_02045808(*(struct U16Vec **)(p + 0x1c));
    func_02045C04(*(struct Rec **)(p + 8));
    func_0201C4C0(*(struct PrintSys **)(p + 0x10));
    func_0201D83C(*(void **)(p + 0xc));
    func_02031140(*(struct S02031140 **)(p + 4));
    func_0201ED04(*(struct WordSet **)(p + 0x14));
    func_020307B0(p);
}
