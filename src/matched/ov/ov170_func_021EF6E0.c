/*
 * function: func_021EF6E0
 * address: 0x021EF6E0
 * packet: pkt_ov170_021EF6E0
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two zero alignment bytes at 0x021EF736.
 * symbols:
 *   func_0202CF98 0x0202CF98 thumb
 *   func_0202CDD4 0x0202CDD4 thumb
 *   func_021ED8A4 0x021ED8A4 thumb ov170
 */
typedef unsigned int u32;
typedef signed char s8;
struct WinMgr;
extern void func_0202CF98(struct WinMgr *mgr, u32 idx, s8 *x, s8 *y);
extern u32 func_0202CDD4(struct WinMgr *mgr, u32 idx);
extern void func_021ED8A4(char *);
#define MGR(p) (*(struct WinMgr **)(*(char **)((p)+0x2c)+0x74))
unsigned func_021EF6E0(char *p)
{
    signed char a[2], b[2];
    unsigned r;
    func_0202CF98(MGR(p),7,&a[1],&a[0]);
    r=func_0202CDD4(MGR(p),7);
    func_0202CF98(MGR(p),7,&b[1],&b[0]);
    if(a[1]!=b[1] || a[0]!=b[0]) func_021ED8A4(p);
    return r;
}
