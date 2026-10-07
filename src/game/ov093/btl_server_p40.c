/*
 * file:     btl_server_p40.c
 * unit:     yes
 * function: func_021C024C, func_021C0274
 * address:  0x021C024C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C02CC 0x021C02CC thumb ov093
 *   func_021C0450 0x021C0450 thumb ov093
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 */
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021C02CC(u8 *, u8 *, u32, int);
extern void func_021C0450(u8 *, u8 *, u32, int);
extern void func_021D74F8(int line);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int key, u32 val);
extern void func_021D7630(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern int func_021D775C(int key);
extern void func_021D7540(int line);
int func_021C024C(u8 *p, u8 *a, u32 c);
int func_021C0274(u8 *p, u8 *a, u32 c, u32 d);

/*
 * lever: Wide third extern argument preserves the full r2 passed by the image.
 */
int func_021C024C(u8 *p, u8 *a, u32 c)
{
    int result;
    if (c != 0xa5) {
        result = func_021C02CC(p, a, c, 0x1f);
        if (result != 0) {
            func_021C0450(p, a, c, result);
            return 1;
        }
    }
    return 0;
}


int func_021C0274(u8 *p, u8 *a, u32 c, u32 d)
{
    int r;
    func_021D74F8(5537);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(0x22, d);
    func_021D75EC(0x12, c);
    func_021D7630(0x41, 0);
    func_021D70F0(p, 0x1D);
    r = func_021D775C(0x41);
    func_021D7540(5544);
    return r;
}
