/*
 * file:     trial_house_p05.c
 * unit:     yes
 * function: func_021CF220, func_021CF288, func_021CF2F0
 * address:  0x021CF220
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
 *   func_0203996C  0x0203996C  arm
 *   func_02008468  0x02008468  thumb
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3F8  0x0203D3F8  arm
 *   func_021CF110  0x021CF110  thumb  ov021
 *   func_021CE724  0x021CE724  thumb  ov021
 *   func_0203D3A8  0x0203D3A8  arm
 */
struct Entry;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

extern struct Entry *func_0203996C(s32 idx);
extern int func_02008468(void);
extern struct Entry *func_020399A8(void);
extern u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern void func_021CF110(u8 *p, u32 v, void *a);
extern void func_021CE724(u8 *p);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
void func_021CF220(u32 a, u32 flag, u32 c);
void func_021CF27C(u32 a, u32 b, u32 c, u32 d);
void func_021CF288(u32 a, u32 flag, u32 c);
void func_021CF2E4(u32 a, u32 b, u32 c, u32 d);
void func_021CF2F0(int mode);


void func_021CF220(u32 a, u32 flag, u32 c)
{
    u32 h;

    if (flag == 1) {
        h = (u32)func_0203996C(0xff);
        func_0203D3F8(h, a, 0x2701, func_02008468(), c, 0, 0, 0);
    } else {
        h = (u32)func_020399A8();
        func_0203D3F8(h, a, 0x2701, func_02008468(), c, 0, 0, 0);
    }
}


/*
 * func_021CF27C (unlabelled) is a tail-call stub into func_021CF110.
 *
 * Addresses are Black-image addresses.
 */
void func_021CF27C(u32 a, u32 b, u32 c, u32 d)
{
    func_021CF110((u8 *)d, 2, (void *)c);
}


/*
 * func_021CF2E4 (unlabelled) is a tail-call stub into func_021CE724.
 *
 * Addresses are Black-image addresses.
 */
void func_021CF288(u32 a, u32 flag, u32 c)
{
    u32 h;

    if (flag == 1) {
        h = (u32)func_0203996C(0xff);
        func_0203D3F8(h, a, 0x2702, func_02008468(), c, 0, 0, 0);
    } else {
        h = (u32)func_020399A8();
        func_0203D3F8(h, a, 0x2702, func_02008468(), c, 0, 0, 0);
    }
}


void func_021CF2E4(u32 a, u32 b, u32 c, u32 d)
{
    func_021CE724((u8 *)d);
}


void func_021CF2F0(int mode)
{
    if (mode == 1) {
        func_0203D3A8(func_0203996C(0xff), 0x2703, 0, 0);
    } else {
        func_0203D3A8(func_020399A8(), 0x2703, 0, 0);
    }
}
