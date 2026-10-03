/*
 * function: func_021D485C
 * address: 0x021D485C
 * packet: pkt_ov124_021D485C
 * region: ov124
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020452E8 0x020452E8 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0201DD68 0x0201DD68 thumb
 */
typedef unsigned char  u8;
struct Descriptor;
struct PrintSys;
struct Rec;
struct TaskMenuState;
extern void func_02028148(u8 *p);
extern void func_02027FD8(struct TaskMenuState *s);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_020452E8(struct Descriptor *d);
extern void func_02045C04(struct Rec *rec);
extern void *func_0201D83C(void *);
extern void func_0201DD68(void *);
void func_021D485C(char *p)
{
    if (*(void **)(p + 0x3c)) func_02028148(*(void **)(p + 0x3c));
    if (*(void **)(p + 0x38)) func_02028148(*(void **)(p + 0x38));
    func_02028148(*(void **)(p + 0x40));
    func_02027FD8(*(void **)(p + 0x34));
    func_0201C4C0(*(void **)(p + 0x30));
    func_020452E8(*(void **)(p + 0x20));
    func_020452E8(*(void **)(p + 0x24));
    func_02045C04(*(void **)(p + 0x2c));
    func_0201DD68(func_0201D83C(*(void **)(p + 0x28)));
}
