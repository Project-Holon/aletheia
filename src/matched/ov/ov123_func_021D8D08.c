/*
 * function: func_021D8D08
 * address: 0x021D8D08
 * packet: pkt_ov123_021D8D08
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0x020071D8 is unlabelled and lacks an outside witness;
 *   Run 2 also left ov114 0x021B973C unresolved; S23 has since verified its
 *   pkt_ov114_021B973C shard. No caller retry while ARM9 remains blocked.
 * blocker: 0x020071D8 Thumb, verified EXACT in blocker-71D8-r1.log:
 *   extern unsigned int func_02031994(void *, int *);
 *   unsigned int func_020071D8(char *p, int *out) {
 *       return func_02031994(*(void **)(p + 0x10), out);
 *   }
 *   symbols: func_02031994 0x02031994 arm
 * symbols:
 *   func_020071D8 0x020071D8 thumb
 *   func_021D580C 0x021D580C thumb ov123
 *   func_021D6E70 0x021D6E70 thumb ov123
 *   func_021B95D4 0x021B95D4 thumb ov114
 *   func_021B973C 0x021B973C thumb ov114
 *   func_021B9748 0x021B9748 thumb ov114
 *   func_021BE79C 0x021BE79C arm ov114
 *   func_021D66D0 0x021D66D0 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D8C04 0x021D8C04 thumb ov123
 */
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Sub02009448Obj;
extern struct Sub02009448Obj *func_02009448(void *sys);
extern int func_021D580C(char *);
extern int func_021D6E70(u8 *p);
extern int func_021B95D4(int index, u8 *p);
extern int func_021B973C(char *p);
extern int func_021B9748(u8 *p);
extern int func_021BE79C(void *handle, void *value_p, unsigned long length);
struct Ctrl020071D8;
extern void *func_020071D8(struct Ctrl020071D8 *ctrl, int *out);
extern void func_021D66D0(u8 *p, int n);
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern void func_021D8C04(char *p);
void func_021D8D08(char *p)
{
    int x;
    unsigned int v;
    func_02009448(*(void **)(p+0x28));
    if (func_021D580C(*(char **)(p+0x18))) {
        *(int *)(p+0x74)=0;
        if (func_021D6E70((u8 *)p)) {
            if (func_021B95D4(3,*(void **)(p+0x10))) {
                v=(unsigned int)func_020071D8(*(void **)(p+0x28),&x);
                func_021BE79C((void *)func_021B973C(*(void **)(p+0x10)),(void *)v,0x80000);
                func_021D66D0(*(void **)(p+0x14),0);
                *(int *)(p+0x70)=0;
                if (!func_021B9748(*(void **)(p+0x10)))
                    func_021D6EE0((u8 *)p,(int)func_021D8C04,0x986);
            }
        } else {
            func_021D66D0(*(void **)(p+0x14),0);
            func_021D6EE0((u8 *)p,(int)func_021D8C04,0x98c);
        }
    }
}
