/*
 * function: func_021D4EF0
 * address: 0x021D4EF0
 * packet: pkt_ov123_021D4EF0
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020450F0(int, u8, u8, u8, u8, int, int);
extern void *func_02045770(void *);
extern void func_02043B5C(void *, int);
extern void func_0201DD78(int, int, int);
extern void *func_02012FFC(void);
extern void *func_0201CCE4(void *, int, int, void *, void *, void *, void *, int, u16, int);
extern void func_0201C7A4(void *, int, int, void *, void *);
extern void func_0201F73C(void *, int, u16, int);
extern void func_02045334(void *);
extern void func_02045374(void *);
extern void func_02041B6C(int);
void func_021D4EF0(char *p, int n, int flag)
{
    void *obj;
    if (*(void **)(p + 0x224) == 0)
        *(void **)(p + 0x224) = func_020450F0(5, 1, 3, 30, (u8)n, 13, 1);
    obj = *(void **)(p + 0x224);
    func_02043B5C(func_02045770(obj), 15);
    func_0201DD78(1, 2, 15);
    if (flag) {
        void *value;
        value = func_02012FFC();
        *(void **)(p + 0x228) = func_0201CCE4(obj, 0, 0, *(void **)(p + 0x38), *(void **)(p + 0x30), value, *(void **)(p + 0x230), 2, *(u16 *)(p + 12), 15);
    } else {
        func_0201C7A4(func_02045770(obj), 0, 0, *(void **)(p + 0x38), *(void **)(p + 0x30));
    }
    func_0201F73C(obj, 1, *(u32 *)(p + 0x3c), 12);
    func_02045334(obj);
    func_02045374(obj);
    func_02041B6C(5);
}
