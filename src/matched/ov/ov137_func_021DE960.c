/*
 * function: func_021DE960
 * address: 0x021DE960
 * packet: pkt_ov137_021DE960
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 wave P14 C10: EXACT first compile. Callees all void except func_020351A0 (int, result unused); no older draft existed.
 * symbols:
 * func_0201C6EC 0x0201C6EC thumb
 * func_0201C4C0 0x0201C4C0 thumb
 * func_0202F038 0x0202F038 thumb
 * func_02030DA4 0x02030DA4 arm
 * func_020307B0 0x020307B0 arm
 * func_02047E54 0x02047E54 arm
 * func_02046788 0x02046788 arm
 * func_02030EAC 0x02030EAC arm
 * func_02049238 0x02049238 arm
 * func_020315D4 0x020315D4 arm
 * func_020306F0 0x020306F0 arm
 * func_020351A0 0x020351A0 arm
 * func_021E0E1C 0x021E0E1C thumb ov137
 * func_021E0F54 0x021E0F54 thumb ov137
 * func_021E1080 0x021E1080 thumb ov137
 * func_021E11E4 0x021E11E4 thumb ov137
 * func_021E13F0 0x021E13F0 thumb ov137
 * func_021E14BC 0x021E14BC thumb ov137
 * func_021E0678 0x021E0678 thumb ov137
 * func_021E0554 0x021E0554 thumb ov137
 * func_021E073C 0x021E073C thumb ov137
 * func_021DF83C 0x021DF83C thumb ov137
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct PrintSys;
struct S020315D4;
extern void func_0201C6EC(struct PrintSys *);
extern void func_0201C4C0(struct PrintSys *);
extern void func_0202F038(u8 *);
extern void func_02030DA4(void *);
extern void func_020307B0(void *);
struct Node;
struct Rec;
extern void func_02047E54(struct Rec *p);
extern void func_02046788(void);
extern void func_02030EAC(struct Node *n);
extern void func_02049238(void *);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(u32);
extern int func_020351A0(u32);
extern void func_021E0E1C(u8 *);
extern void func_021E0F54(u8 *);
extern void func_021E1080(u8 *);
extern void func_021E11E4(u8 *);
extern void func_021E13F0(u8 *);
extern void func_021E14BC(u8 *);
extern void func_021E0678(char *);
extern void func_021E0554(u8 *);
extern void func_021E073C(char *);
extern void func_021DF83C(char *);
int func_021DE960(struct S020315D4 *a, int b, int c, u8 *p)
{
    func_0201C6EC(*(struct PrintSys **)(p + 0xD38));
    func_0201C4C0(*(struct PrintSys **)(p + 0xD38));
    if (*(u8 **)(p + 0xDA8) != 0) func_0202F038(*(u8 **)(p + 0xDA8));
    func_021E0E1C(p);
    func_021E0F54(p);
    func_021E1080(p);
    func_021E11E4(p);
    func_021E13F0(p);
    func_021E14BC(p);
    func_02030DA4(*(void **)(p + 0xD98));
    func_020307B0(*(void **)(p + 0xD94));
    func_021E0678((char *)p);
    func_021E0554(p);
    func_021E073C((char *)p);
    func_02047E54(*(void **)(p + 0xAF4));
    func_02046788();
    func_021DF83C((char *)p);
    func_02030EAC(*(void **)(p + 0xD9C));
    func_02049238(*(void **)(p + 0xD58));
    func_020315D4(a);
    func_020306F0(0x72);
    func_020351A0(8);
    return 1;
}
