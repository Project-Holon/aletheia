/*
 * function: func_021D48E4
 * address: 0x021D48E4
 * packet: pkt_ov131_021D48E4
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH*
 * blocker: ARM9 func_02061C30 has no outside witness; Ilias owns it.
 *   Verified prior lane C in ov091_func_021B6FEC.c reaches DIFF (8 bytes):
 *   extern void func_02061B5C(void *); extern char d_02146B80[];
 *   void func_02061C30(void) { func_02061B5C(d_02146B80); }
 *   Its two loads and two pool words are swapped. No ARM9 source filed.
 * 2026-10-02 lane B2-07: re-verified MATCH*; func_02061C30 re-tried with a literal
 *   address, an int return and a function-pointer local, all DIFF (5-8 bytes,
 *   the ldr ip / ldr r0 transposition of docs/idioms/a-tail-calls-pool-word-is-
 *   scheduled-before-the-last-argument-write.md). Still no arm9 witness.
 * extent: Two zero padding bytes at 0x021D493E.
 * symbols:
 *   func_02061C30 0x02061C30 arm
 *   func_02014BA8 0x02014BA8 thumb
 *   func_02048AC4 0x02048AC4 arm
 *   func_02046788 0x02046788 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 */
extern void func_02061C30(void);
extern void func_02014BA8(void *);
extern void func_02048AC4(void *);
extern void func_02046788(void);
extern void func_0204B1CC(void *);
extern void func_0204A5AC(void);
extern void func_020403F4(unsigned int);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
void func_021D48E4(char *p)
{
    func_02061C30();
    func_02014BA8(*(void **)(p+0x78));
    func_02048AC4(*(void **)(p+0x70));
    func_02046788();
    func_0204B1CC(*(void **)(p+0x174));
    func_0204A5AC();
    func_020403F4(5);
    func_020403F4(6);
    func_020403F4(7);
    func_020403F4(3);
    func_020403F4(2);
    func_020403F4(1);
    func_020403F4(0);
    func_020450C8();
    func_0203F9B4();
}
