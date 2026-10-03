/*
 * function: func_021EF274
 * address: 0x021EF274
 * packet: pkt_ov170_021EF274
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two zero alignment bytes at 0x021EF30E.
 * symbols:
 *   func_021EB744 0x021EB744 thumb ov170
 *   func_021EF630 0x021EF630 thumb ov170
 *   func_021EB79C 0x021EB79C thumb ov170
 *   func_021EB7C8 0x021EB7C8 thumb ov170
 *   func_021EF31C 0x021EF31C thumb ov170
 *   func_021EB95C 0x021EB95C thumb ov170
 *   func_021EF4C0 0x021EF4C0 thumb ov170
 *   func_0202C9B4 0x0202C9B4 thumb
 *   func_0202CA3C 0x0202CA3C thumb
 */
typedef unsigned int u32;
struct WinMgr;
extern struct WinMgr *func_0202C9B4(u32 a0, u32 a1, u32 heap);
extern void func_0202CA3C(struct WinMgr *mgr, u32 idx, u32 bg, u32 w, u32 h);
extern void func_021EB744(char *);
extern void func_021EF630(char *);
extern void func_021EB79C(char *);
extern void func_021EB7C8(char *);
extern void func_021EF31C(struct WinMgr *mgr,int,int);
extern void func_021EB95C(char *);
extern void func_021EF4C0(struct WinMgr *mgr);
#define MGR(w) (*(struct WinMgr **)((w)+0x74))
void func_021EF274(char *p)
{
    char *w=*(char **)(p+0x2c);
    MGR(w)=func_0202C9B4(2,12,0x4c);
    func_021EB744(w);
    func_021EF630(p);
    func_021EB79C(p);
    func_021EB7C8(p);
    func_0202CA3C(MGR(w),8,1,11,15);
    if(*(int *)(*(char **)p+0x24)==4) func_021EF31C(MGR(w),8,8);
    else func_021EF31C(MGR(w),8,9);
    func_0202CA3C(MGR(w),7,1,11,15);
    func_021EF31C(MGR(w),7,10);
    func_021EB95C(p);
    func_0202CA3C(MGR(w),9,1,11,21);
    func_021EF31C(MGR(w),9,11);
    func_021EF4C0(MGR(w));
}
