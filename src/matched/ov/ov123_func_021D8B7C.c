/*
 * function: func_021D8B7C
 * address: 0x021D8B7C
 * packet: pkt_ov123_021D8B7C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: func_02012F2C leaves its return in r0 for func_02008DF0.
 * symbols:
 *   func_0203F4E4 0x0203F4E4 arm
 *   func_020093D8 0x020093D8 thumb
 *   func_02009428 0x02009428 thumb
 *   func_020093F0 0x020093F0 thumb
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D8B0C 0x021D8B0C thumb ov123
 */
typedef unsigned int u32;
struct RtcDate { u32 year, month, day, week; };
extern void *func_02009448(void *);
extern void func_0203F4E4(struct RtcDate *);
extern void func_020093CC(void *,u32);
extern int func_020093D8(void *);
extern void func_02009428(void *,int);
extern void func_020093F0(void *,int);
extern int func_02012F2C(void *);
extern void func_02008DF0(int,int);
extern int func_02012DAC(void *);
extern void func_021D6EE0(char *,int,int);
extern void func_021D8B0C(void);
void func_021D8B7C(char *p)
{
    void *q;
    struct RtcDate date;
    q=func_02009448(*(void **)(p+0x28));
    p[0xaa]=0;
    func_0203F4E4(&date);
    func_020093CC(q, (date.year << 24) | ((date.month & 255) << 16) | ((date.day & 255) << 8) | date.week);
    if (func_020093D8(q)!=127) {
        func_02009428(q,1);
        func_020093F0(q,126);
    }
    *(int *)(p+0x70)=50;
    func_02008DF0(func_02012F2C(*(void **)(p+0x2c)),119);
    p[0xad]=1;
    func_02012DAC(*(void **)(p+0x2c));
    func_021D6EE0(p,(int)func_021D8B0C,0x914);
}
