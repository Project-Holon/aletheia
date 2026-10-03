/*
 * function: func_021B9DEC
 * address: 0x021B9DEC
 * packet: pkt_ov225_021B9DEC
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9F8C 0x021B9F8C thumb ov225
 *   func_021B9E80 0x021B9E80 thumb ov225
 *   func_021B9F20 0x021B9F20 thumb ov225
 *   func_021B9BA4 0x021B9BA4 thumb ov225
 *   func_02049238 0x02049238 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_021B99A0 0x021B99A0 thumb ov225
 *   func_020307B0 0x020307B0 arm
 */
struct Rec;struct PrintSys;
extern void func_021B9F8C(char *p);
extern void func_021B9E80(char *,unsigned);
extern void func_021B9F20(void *);
extern void func_021B9BA4(char *p);
extern void func_02049238(void *);
extern void func_02045C04(struct Rec *);
extern void func_0201C6EC(struct PrintSys *);
extern void func_0201C4C0(struct PrintSys *);
extern void func_0201D83C(void *);
extern void func_021B99A0(char *);
extern void func_020307B0(void *);
void func_021B9DEC(char *p)
{
    func_021B9F8C(*(void **)(p+0x34));func_021B9E80(p,0xffff);func_021B9F20(p);
    func_021B9BA4(*(void **)(p+0x2c));func_02049238(*(void **)(p+0x24));func_02049238(*(void **)(p+0x28));
    func_02045C04(*(struct Rec **)(p+0x1c));func_02045C04(*(struct Rec **)(p+0x20));
    func_0201C6EC(*(struct PrintSys **)(p+0x10));func_0201C4C0(*(struct PrintSys **)(p+0x10));
    func_0201C6EC(*(struct PrintSys **)(p+0x14));func_0201C4C0(*(struct PrintSys **)(p+0x14));
    func_0201C6EC(*(struct PrintSys **)(p+0x18));func_0201C4C0(*(struct PrintSys **)(p+0x18));
    func_0201D83C(*(void **)(p+0xc));func_021B99A0(*(char **)(p+8));func_020307B0(p);
}
