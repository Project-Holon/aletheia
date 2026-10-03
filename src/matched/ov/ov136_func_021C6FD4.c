/*
 * unit: yes
 * function: func_021C6FD4, func_021C7018
 * address: 0x021C6FD4
 * packet: pkt_ov136_021C6FD4
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C7360 0x021C7360 thumb ov136
 *   func_021C76D0 0x021C76D0 thumb ov136
 *   func_021C61D0 0x021C61D0 thumb ov136
 *   func_021C66B8 0x021C66B8 thumb ov136
 *   func_021C7298 0x021C7298 thumb ov136
 *   func_021C71BC 0x021C71BC thumb ov136
 *   func_020260E0 0x020260E0 thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct WinMgr;
extern void func_021C7360(u8 *);
extern u8 func_020260E0(void *);
extern void func_021C76D0(void *, int);
extern void func_021C61D0(void *);
extern void func_0202CC70(struct WinMgr *mgr, u32 idx);
extern void func_021C66B8(void *, int, int);
extern void func_021C7298(void *, int);
extern int func_021C71BC(char *, int);
int func_021C6FD4(u8 *p)
{
    func_021C7360(p);
    func_021C76D0(p, func_020260E0(*(void **)(*(u8 **)(p + 8) + 0x294)));
    func_021C61D0(*(void **)(p + 8));
    func_0202CC70(**(void ***)(p + 8), 10);
    func_021C66B8(*(void **)(p + 8), 2, 1);
    func_021C7298(*(void **)(p + 8), 0);
    return 9;
}
int func_021C7018(char *p)
{
    return func_021C71BC(p, 0);
}
