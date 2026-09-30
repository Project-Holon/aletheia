/*
 * function: func_021D9158
 * address: 0x021D9158
 * packet: pkt_ov123_021D9158
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0200F7C0 0x0200F7C0 thumb
 *   func_021D5D58 0x021D5D58 thumb ov123
 *   func_021B9774 0x021B9774 thumb ov114
 *   func_021D8F58 0x021D8F58 thumb ov123
 *   func_02157170 0x02157170 thumb ov009
 *   func_021D5D7C 0x021D5D7C thumb ov123
 *   func_021D5E60 0x021D5E60 thumb ov123
 *   func_021D562C 0x021D562C thumb ov123
 *   func_0200FB24 0x0200FB24 thumb
 */
typedef unsigned char u8;
extern int func_020221A4(void *);
extern int func_0200FB24(void);
extern void func_021D5D58(void *);
extern void func_021B9774(void *);
extern void func_02012E08(void *);
extern void func_021D8F58(char *);
extern void func_0200F7C0(int);
extern void func_0202223C(int,int);
extern void func_02157170(int,int);
extern void func_02027974(void *);
extern void func_021D5D7C(void *);
extern void func_021D5E60(void *);
extern void func_021D562C(void *);
int func_021D9158(void *a, int b, int c, char *p)
{
    void (*callback)(char *);
    int result;
    callback=*(void (**)(char *))(p+0x50);
    result=1;
    if (func_020221A4(a) && !*(u8 *)(p+0xae) && func_0200FB24()) {
        if (*(void **)(p+8)) func_021D5D58(*(void **)(p+8));
        func_021B9774(*(void **)(p+0x10));
        if (*(u8 *)(p+0xad)) {
            func_02012E08(*(void **)(p+0x2c));
            *(u8 *)(p+0xad)=0;
        }
        func_021D8F58(p);
        if (*(u8 *)(p+0xab)) func_0200F7C0(41);
        func_0202223C(0,0);
        func_0202223C(1,0);
        func_02157170(1,0);
        *(int *)(*(char **)(p+0x20)+0x1c8)=7;
        return 1;
    }
    if (callback) { callback(p); result=0; }
    if (*(void **)(p+0x1c)) func_02027974(*(void **)(p+0x1c));
    if (*(void **)(p+8)) func_021D5D7C(*(void **)(p+8));
    func_021D5E60(*(void **)(p+0x14));
    func_021D562C(*(void **)(p+0x18));
    return result;
}
