/*
 * function: func_021B68B4
 * address: 0x021B68B4
 * packet: pkt_ov071_021B68B4
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: MATCH
 * blocker: ARM9 func_02025358 at +0x26 has no outside witness.
 * split: TU confirms one image-wide witness, inside this caller; no cuts.
 * ARM9 stub: 02025358 ldr r3,[pc,#0]; bx r3; pool 020307B0.
 * symbols:
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_02025588 0x02025588 thumb
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_02025358 0x02025358 thumb
 */
typedef unsigned int u32;
struct Bank;
extern void func_020434DC(u32, u32);
extern void func_02043598(u32, u32);
extern void func_02025588(void *);
extern void func_0204B1CC(struct Bank *);
extern void func_0204A5AC(void);
extern void func_02025358(void *);
void func_021B68B4(void **p)
{
    func_020434DC(0x10, 0);
    func_02043598(0x10, 0);
    func_02025588(p[11]);
    func_0204B1CC(p[5]);
    func_0204A5AC();
    func_02025358(p[1]);
}
