/*
 * function: func_021D8C04
 * address: 0x021D8C04
 * packet: pkt_ov123_021D8C04
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6934 0x021D6934 thumb ov123
 *   func_021D6EA4 0x021D6EA4 thumb ov123
 *   func_021D6E70 0x021D6E70 thumb ov123
 *   func_021D5950 0x021D5950 thumb ov123
 *   func_021D59E4 0x021D59E4 thumb ov123
 *   func_021D5A60 0x021D5A60 thumb ov123
 *   func_021D66D0 0x021D66D0 thumb ov123
 *   func_021D6E08 0x021D6E08 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D8B7C 0x021D8B7C thumb ov123
 *   func_021D6FF0 0x021D6FF0 thumb ov123
 *   func_021B99DC 0x021B99DC thumb ov114
 *   func_021B9790 0x021B9790 thumb ov114
 *   func_021B97F4 0x021B97F4 thumb ov114
 */
typedef unsigned char u8;
extern void *func_02009448(void *);
extern void func_021D6934(void *);
extern int func_021D6EA4(char *);
extern int func_021D6E70(char *);
extern int func_021D5950(u8 *,int);
extern void func_021D59E4(char *);
extern void func_021D5A60(char *);
extern void func_021D66D0(u8 *,int);
extern int func_021D6E08(char *,int);
extern int func_021B99DC(void *);
extern int func_021B9790(void *);
extern char *func_021B97F4(void *);
extern void func_021D6EE0(char *,int,int);
extern void func_021D8B7C(char *);
extern void func_021D6FF0(char *);
void func_021D8C04(char *p)
{
    char *q;
    int state;
    func_02009448(*(void **)(p+0x28));
    func_021D6934(*(void **)(p+0x14));
    if (func_021D6EA4(p)) {
        if (*(int *)(p+0x74)==0) {
            func_021D5950(*(u8 **)(p+0x18),42);
            func_021D59E4(*(char **)(p+0x18));
        } else if (*(int *)(p+0x74)==360) {
            func_021D5950(*(u8 **)(p+0x18),43);
            func_021D59E4(*(char **)(p+0x18));
        } else if (*(int *)(p+0x74)==720) {
            func_021D5950(*(u8 **)(p+0x18),44);
            func_021D59E4(*(char **)(p+0x18));
        }
        ++*(int *)(p+0x74);
    }
    if (func_021D6E70(p)) {
        if (*(int *)(p+0x70)<50) ++*(int *)(p+0x70);
        func_021D66D0(*(u8 **)(p+0x14),*(int *)(p+0x70));
        if (func_021D6E08(p,func_021B99DC(*(void **)(p+0x10)))) return;
        if (func_021B9790(*(void **)(p+0x10))) return;
        q=func_021B97F4(*(void **)(p+0x10));
        if (func_021D6EA4(p)) func_021D5A60(*(char **)(p+0x18));
        state=*(int *)q;
        if (state==0) {
            func_021D6EE0(p,(int)func_021D8B7C,0x955);
            return;
        }
        *(int *)(p+0x80)=state;
        func_021D6EE0(p,(int)func_021D6FF0,0x959);
        return;
    } else {
        func_021D66D0(*(u8 **)(p+0x14),*(int *)(p+0x68));
        if (++*(int *)(p+0x68)==100) {
            if (func_021D6EA4(p)) func_021D5A60(*(char **)(p+0x18));
            func_021D6EE0(p,(int)func_021D8B7C,0x967);
        }
    }
}
