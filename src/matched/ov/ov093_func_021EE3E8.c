/*
 * function: func_021EE3E8
 * address:  0x021EE3E8
 * packet:   pkt_ov093_021EE3E8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0201DD78 0x0201DD78 thumb
 *   func_02045374 0x02045374 arm
 *   func_020454E0 0x020454E0 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_021EF71C 0x021EF71C thumb ov093
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02040618 0x02040618 arm
 *   func_020061E4 0x020061E4 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct C {
    u8 pad00[8];
    void *f08;
    int f0c;
    u32 f10;
    u8 pad14[0x10];
    int f24;
    u8 pad28[0xc];
    u32 f34;
    u8 pad38[0x138];
    u16 f170, f172, f174, f176, f178, f17a, f17c;
};
extern void func_0201DD78(int, int, int);
extern void func_02045374(void *);
extern void func_020454E0(void *, u16, u32);
extern void func_02043B5C(int, int);
extern u8 func_02045730(void *);
extern void func_020409B4(u8);
extern void func_021EF71C(u32, u32, u32, u32, u32, u32, u32);
extern void func_0201C7A4(int, int, int, int, int);
extern void func_02045334(void *);
extern void func_02040618(int, int, int);
extern void func_020061E4(int);
int func_021EE3E8(int *st, struct C *c)
{
    switch (*st) {
    case 0:
        func_0201DD78(1, 9, 12);
        func_02045374(c->f08);
        func_020454E0(c->f08, c->f10, 3);
        func_02043B5C(c->f0c, 12);
        func_020409B4(func_02045730(c->f08));
        (*st)++;
        break;
    case 1:
        func_021EF71C(c->f34, c->f172, c->f174, c->f176, c->f178, c->f17a, c->f17c);
        func_0201C7A4(c->f0c, 0, 0, c->f34, c->f24);
        (*st)++;
        break;
    case 2:
        func_02045334(c->f08);
        (*st)++;
        break;
    case 3:
        func_02040618(3, 0, 0);
        func_02040618(3, 3, 0x100);
        func_020061E4(0x547);
        (*st)++;
        break;
    case 4:
        return 1;
    }
    return 0;
}
