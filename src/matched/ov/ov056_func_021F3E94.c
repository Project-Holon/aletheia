/*
 * unit:     yes
 * function: func_021F3E94, func_021F3EC8
 * address:  0x021F3E94
 * packet:   pkt_ov056_021F3E94
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     first entry of the callback triple at 0x021F4364
 *           {0x021F3E95, 0x021F3EC9, 0x021F3ECD}; r0 is unused. The second
 *           entry, func_021F3EC8, is an unlabelled empty callback (bx lr)
 *           right after the lead's pool, then 2 bytes of padding.
 * symbols:
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_0218DC6C  0x0218DC6C  thumb  ov021
 *   func_0218C654  0x0218C654  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012A30  0x02012A30  thumb
 *   d_021F4284     0x021F4284  data  a4
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Ctx;
struct BigObj;
extern u32 func_02188C98(u8 *p);
extern u32 func_0218DC6C(u8 *p);
extern int func_0218C654(int a, int b, int c);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02012A30(const struct BigObj *p);
extern u8 d_021F4284[];

void func_021F3E94(void *unused, u8 *b, u8 *c)
{
    u32 r;

    r = func_0218DC6C((u8 *)func_02188C98(b));
    *(int *)(c + 0x4) = func_0218C654((int)r, 0, (int)d_021F4284);
    *(u32 *)(c + 0x0) = r;
    *(u32 *)(c + 0xC) = func_02012A30((const struct BigObj *)func_020120F4((const struct Ctx *)func_02188C80(b)));
}

void func_021F3EC8(void *unused, u8 *b, u8 *c)
{
}
