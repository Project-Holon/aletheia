/*
 * file:     trial_house_p06.c
 * unit:     yes
 * function: func_021CF32C, func_021CF378
 * address:  0x021CF32C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3F8  0x0203D3F8  arm
 *   func_021CE70C  0x021CE70C  thumb  ov021
 *   func_0203996C  0x0203996C  arm
 *   func_0203D3A8  0x0203D3A8  arm
 */
struct Entry;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

extern struct Entry *func_020399A8(void);
extern u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern void func_021CE70C(u8 *p);
extern struct Entry *func_0203996C(s32 idx);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
u32 func_021CF32C(u32 flag);
void func_021CF36C(u32 a, u32 b, u32 c, u32 d);
void func_021CF378(int mode);


/*
 * func_021CF36C (unlabelled) is a tail-call stub into func_021CE70C.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021CF32C(u32 flag)
{
    if (flag == 1)
        func_0203D3F8((u32)func_020399A8(), 0xff, 0x2704, 0, 0, 0, 0, 0);
    else
        return func_0203D3F8((u32)func_020399A8(), 0, 0x2704, 0, 0, 0, 0, 0);
}


void func_021CF36C(u32 a, u32 b, u32 c, u32 d)
{
    func_021CE70C((u8 *)d);
}


void func_021CF378(int mode)
{
    if (mode == 1) {
        func_0203D3A8(func_0203996C(0xff), 0x2705, 0, 0);
    } else {
        func_0203D3A8(func_020399A8(), 0x2705, 0, 0);
    }
}
