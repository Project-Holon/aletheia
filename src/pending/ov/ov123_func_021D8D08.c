/*
 * function: func_021D8D08
 * address: 0x021D8D08
 * packet: pkt_ov123_021D8D08
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH
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
extern void *func_02009448(void *);
extern int func_021D580C(char *);
extern int func_021D6E70(char *);
extern int func_021B95D4(int,void *);
extern int func_021B973C(void *);
extern int func_021B9748(void *);
extern int func_021BE79C(int,unsigned int,unsigned int);
extern unsigned int func_020071D8(void *,int *);
extern void func_021D66D0(void *,int);
extern void func_021D6EE0(char *,int,int);
extern void func_021D8C04(void);
void func_021D8D08(char *p)
{
    int x;
    unsigned int v;
    func_02009448(*(void **)(p+0x28));
    if (func_021D580C(*(char **)(p+0x18))) {
        *(int *)(p+0x74)=0;
        if (func_021D6E70(p)) {
            if (func_021B95D4(3,*(void **)(p+0x10))) {
                v=func_020071D8(*(void **)(p+0x28),&x);
                func_021BE79C(func_021B973C(*(void **)(p+0x10)),v,0x80000);
                func_021D66D0(*(void **)(p+0x14),0);
                *(int *)(p+0x70)=0;
                if (!func_021B9748(*(void **)(p+0x10)))
                    func_021D6EE0(p,(int)func_021D8C04,0x986);
            }
        } else {
            func_021D66D0(*(void **)(p+0x14),0);
            func_021D6EE0(p,(int)func_021D8C04,0x98c);
        }
    }
}
