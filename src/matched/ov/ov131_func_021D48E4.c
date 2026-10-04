/*
 * function: func_021D48E4
 * address: 0x021D48E4
 * packet: pkt_ov131_021D48E4
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * 2026-10-02 R3: closed by the arm9 witness src/matched/arm9/func_02061C30.c
 *   (the tail-call stub matches under ../2.0/sp2; see its header).
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
#include "../include/Obj10503.h"
extern void func_02061C30(void);
typedef unsigned char  u8;
struct Bank;
extern void func_02014BA8(u8 *a0);
extern void func_02048AC4(void *);
extern void func_02046788(void);
extern void func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_020403F4(unsigned int);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
void func_021D48E4(char *p)
{
    func_02061C30();
    func_02014BA8(((struct Obj10503 *)p)->f78);
    func_02048AC4(((struct Obj10503 *)p)->f70);
    func_02046788();
    func_0204B1CC(((struct Obj10503 *)p)->f174);
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
