/*
 * function: func_021BB0B4
 * address: 0x021BB0B4
 * packet: pkt_ov099_021BB0B4
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 242-byte function followed only by 00 00 alignment at 021BB1A6.
 * symbols:
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_021BA8BC 0x021BA8BC thumb ov099
 *   func_020452E8 0x020452E8 arm
 *   func_0202020C 0x0202020C thumb
 *   func_0201F868 0x0201F868 thumb
 *   func_020456F8 0x020456F8 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0201FEF4 0x0201FEF4 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
struct Obj;
extern void func_021BA8EC(char *p);
extern int func_021BA8BC(void *);
extern void func_020452E8(struct Descriptor *);
extern void func_0202020C(struct Obj *, u16 *, u16 *);
extern void func_0201F868(void *);
extern void func_020456F8(struct Descriptor *);
extern void func_02041B6C(u32);
extern void func_0201FEF4(u8 *);
void func_021BB0B4(char *p)
{
    func_021BA8EC(p);
    if (*(void **)(p + 0x1a4)) {
        func_020452E8(*(struct Descriptor **)(p + 0x1a4));
        func_0202020C(*(struct Obj **)(p + 0xbc), 0, 0);
        func_0201F868(*(void **)(p + 0xb8));
        *(void **)(p + 0xb8) = 0;
    }
    if (*(void **)(p + 0x198)) { func_020452E8(*(struct Descriptor **)(p + 0x198)); *(void **)(p + 0x198) = 0; }
    if (*(void **)(p + 0x190)) { func_020452E8(*(struct Descriptor **)(p + 0x190)); *(void **)(p + 0x190) = 0; }
    if (*(void **)(p + 0x1a8)) { func_020452E8(*(struct Descriptor **)(p + 0x1a8)); *(void **)(p + 0x1a8) = 0; }
    if (*(void **)(p + 0x194)) { func_020452E8(*(struct Descriptor **)(p + 0x194)); *(void **)(p + 0x194) = 0; }
    if (*(void **)(p + 0x1a0)) { func_020452E8(*(struct Descriptor **)(p + 0x1a0)); *(void **)(p + 0x1a0) = 0; }
    if (*(void **)(p + 0x19c)) {
        func_020456F8(*(struct Descriptor **)(p + 0x19c));
        func_02041B6C(2);
        func_021BA8BC(*(void **)(p + 0x19c));
        *(void **)(p + 0x19c) = 0;
    }
    if (*(void **)(p + 0xb4)) { func_0202020C(*(struct Obj **)(p + 0xb4), 0, 0); *(void **)(p + 0xb4) = 0; }
    if (*(void **)(p + 0xb0)) { func_0201F868(*(void **)(p + 0xb0)); *(void **)(p + 0xb0) = 0; }
    if (*(void **)(p + 0x108)) { func_0201FEF4(*(u8 **)(p + 0x108)); *(void **)(p + 0x108) = 0; }
}
