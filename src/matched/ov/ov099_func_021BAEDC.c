/*
 * function: func_021BAEDC
 * address: 0x021BAEDC
 * packet: pkt_ov099_021BAEDC
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: the -1 test is written with the -1 arm first and its own
 *   func_02045CAC call; the image's bne/b pair at 021BAF80/021BAF82 is the
 *   cross-jumped copy of the else call.
 * volatile: none.
 * symbols:
 *   func_02008730 0x02008730 thumb
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02008510 0x02008510 thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02008550 0x02008550 thumb
 *   func_0201DD78 0x0201DD78 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_02045808 0x02045808 arm
 *   func_021BDD48 0x021BDD48 thumb ov099
 *   func_021BDD54 0x021BDD54 thumb ov099
 *   func_021BB918 0x021BB918 thumb ov099
 *   DWC_RAP_GetTargetFriendIndex 0x02156A3C thumb ov009
 *   func_02009864 0x02009864 thumb
 *   func_020099E4 0x020099E4 thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_021BE4BC 0x021BE4BC thumb ov099
 *   func_021C27E0 0x021C27E0 thumb ov099
 *   func_021BE3CC 0x021BE3CC thumb ov099
 *   func_020456F8 0x020456F8 arm
 *   func_02045374 0x02045374 arm
 *   func_02045334 0x02045334 arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
struct Save;
struct Friends;
struct S;
struct Descriptor;
struct CharBuf;
struct U16Vec;
struct Cfg;
struct MsgBank;
struct Sub0200852CObj;
struct Sub020097BCObj;
extern struct Sub0200852CObj *func_02008730(void *sys);
extern void func_0201DD68(void);
extern void *func_02008510(void *a, int tag);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *, u8);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_0201DD78(u32, u32, u32);
extern void func_0201C7A4(void *, s16, s16, void *, void *);
extern void func_02045808(struct U16Vec *);
extern u8 func_021BDD48(int, struct S *);
extern u8 func_021BDD54(int, struct S *);
extern int func_021BB918(void *, u32, int *);
extern int DWC_RAP_GetTargetFriendIndex(void);
extern u32 func_02009864(const struct Sub020097BCObj *obj, u32 i, u32 field);
extern void func_020099E4(struct Sub020097BCObj *obj, int i, void *dest);
extern void func_02045CAC(struct MsgBank *, u32, void *);
extern void func_021BE4BC(char *, int, int, int, int, unsigned int, int);
extern int func_021C27E0(struct S *);
extern void func_021BE3CC(char *p, int a, u8 b, u8 c, u32 d, int e);
extern void func_020456F8(struct Descriptor *);
extern void func_02045374(struct Cfg *);
extern void func_02045334(struct Descriptor *);
extern void func_020409B4(u32);
void func_021BAEDC(char *p)
{
    struct Save *a;
    struct U16Vec *temp;
    u8 kind;
    u8 other;
    int n;
    int unused;
    int v;
    int icon;
    a = (struct Save *)func_02008730(*(void **)(p + 0xc0));
    if (*(void **)(p + 0x194) == 0)
        return;
    func_0201DD68();
    temp = func_02008510(a, 33);
    func_02043B5C(func_02045770(*(struct Descriptor **)(p + 0x194)), 255);
    if (func_02008550((const struct Sub0200852CObj *)a) == 0)
        func_0201DD78(5, 6, 0);
    else
        func_0201DD78(3, 4, 0);
    func_0201C7A4(func_02045770(*(struct Descriptor **)(p + 0x194)), 32, 0, temp, *(void **)(p + 0xe8));
    func_02045808(temp);
    kind = func_021BDD48((int)p, *(struct S **)(p + 8));
    other = func_021BDD54((int)p, *(struct S **)(p + 8));
    n = func_021BB918((void *)kind, other, &unused);
    if (other == 4 && kind == 4) {
        if (DWC_RAP_GetTargetFriendIndex() == -1) {
            func_02045CAC(*(struct MsgBank **)(p + 0xe0), n, *(void **)(p + 0xf0));
        } else {
            v = func_02009864((const struct Sub020097BCObj *)(*(struct Friends **)(p + 4)), DWC_RAP_GetTargetFriendIndex(), 9);
            if (v == 0)
                func_0201DD78(5, 6, 0);
            else if (v == 1)
                func_0201DD78(3, 4, 0);
            func_020099E4((struct Sub020097BCObj *)(*(struct Friends **)(p + 4)), DWC_RAP_GetTargetFriendIndex(), *(void **)(p + 0xf0));
        }
    } else {
        func_02045CAC(*(struct MsgBank **)(p + 0xe0), n, *(void **)(p + 0xf0));
    }
    func_0201C7A4(func_02045770(*(struct Descriptor **)(p + 0x194)), 102, 0, *(void **)(p + 0xf0), *(void **)(p + 0xe8));
    func_021BE4BC(p + 0x898, 1, 2, 1, kind, other, 48);
    if (func_021C27E0(*(struct S **)(p + 8))) icon = 15;
    else icon = 11;
    func_021BE3CC(p + 0x898, 1, 26, 1, icon + 48, 0);
    func_020456F8(*(struct Descriptor **)(p + 0x194));
    func_02045374(*(struct Cfg **)(p + 0x194));
    func_02045334(*(struct Descriptor **)(p + 0x194));
    func_020409B4(3);
}
