/*
 * function: func_021B6338
 * address: 0x021B6338
 * packet: pkt_ov172_021B6338
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Trailing extent: 0x021B638E is a two-byte alignment nop, before the existing ARM veneer.
 * Loop lever: goto into the do-while test keeps a named result across the probe.
 * symbols:
 *   func_02085A38 0x02085A38 arm
 *   OS_IsRunOnTwl 0x02085D3C arm
 *   func_021B6390 0x021B6390 arm ov172
 *   func_021B6398 0x021B6398 arm ov172
 *   func_021B63A0 0x021B63A0 arm ov172
 *   func_021B63A8 0x021B63A8 arm ov172
 *   func_021B63B0 0x021B63B0 arm ov172
 *   func_021B6868 0x021B6868 thumb ov172
 */
typedef unsigned int   u32;
extern void func_02085A38(u32 msec);
extern int OS_IsRunOnTwl(void);
extern int func_021B6390(void);
extern void func_021B6398(void);
extern void func_021B63A0(void);
extern void func_021B63A8(int);
extern void func_021B63B0(void);
extern void func_021B6868(char *);
void func_021B6338(char *p)
{
    int result;
    goto test;
    do {
        func_02085A38(10);
test:
        result = 0;
        if (OS_IsRunOnTwl() != 0) result = func_021B6390();
    } while (result == 1);
    if (OS_IsRunOnTwl() != 0) func_021B6398();
    func_021B6868(p);
    if (OS_IsRunOnTwl() == 1) func_021B63A0();
    func_021B63A8(1);
    if (OS_IsRunOnTwl() == 1) func_021B63B0();
}
