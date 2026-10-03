/*
 * function: func_021C7110
 * address:  0x021C7110
 * packet:   pkt_ov136_021C7110
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020260E0 0x020260E0 thumb
 *   func_0202CC70  0x0202CC70  thumb
 *   func_021C62F4 0x021C62F4 thumb
 *   func_021C66B8 0x021C66B8 thumb
 *   func_021C7298 0x021C7298 thumb
 *   func_021C76D0 0x021C76D0 thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;
struct WinMgr;
extern void func_021C62F4(u8 *);
extern void func_0202CC70(struct WinMgr *mgr, u32 idx);
extern int func_020260E0(void *);
extern void func_021C76D0(u8 *, int);
extern void func_021C66B8(u8 *, int, u32);
extern void func_021C7298(u8 *, int);
int func_021C7110(u8 *p)
{
    func_021C62F4(p);
    func_0202CC70(**(void ***)(p + 8), 10);
    func_021C76D0(p, func_020260E0(*(void **)(*(u8 **)(p + 8) + 0x294)));
    func_021C66B8(*(u8 **)(p + 8), 2, 1);
    func_021C7298(*(u8 **)(p + 8), 0);
    return 9;
}
