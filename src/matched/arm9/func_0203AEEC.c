/*
 * function: func_0203AEEC
 * address:  0x0203AEEC
 * packet:   pkt_0203AEEC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203D788  0x0203D788  arm
 *   func_0203A53C  0x0203A53C  arm
 *   func_020370C8  0x020370C8  arm
 *   func_02037B08  0x02037B08  arm
 *   func_020307B0  0x020307B0  arm
 *
 * Shuts the network down when the transport's +0x74 virtual answers non-zero:
 * tears the tables down, saves the completion callback out of +0x28, drops
 * the context and finally calls the saved callback.  The callback load is
 * scheduled before func_020307B0 rather than after it and the context is
 * zeroed after that call too - the store-landing-after-the-next-call shape,
 * so the C keeps the callback in a local across the call.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203AEEC.c \
 *       --func func_0203AEEC --addr 0x0203AEEC --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u8   *func_0203D788(void);
extern void  func_0203A53C(void);
extern void  func_020370C8(void);
extern void  func_02037B08(void);
extern void  func_020307B0(void *p);

void func_0203AEEC(void)
{
    void (*f)(void);

    if (((u32 (*)(void))*(u32 *)(*(u32 *)((char *)func_0203D788() + 0x340) + 0x74))() == 0)
        return;
    func_0203A53C();
    func_020370C8();
    func_02037B08();
    f = (void (*)(void))*(u32 *)(*(u32 *)((char *)(0x21469DC)) + 0x28);
    func_020307B0((void *)*(u32 *)((char *)(0x21469DC)));
    *(u32 *)((char *)(0x21469DC)) = 0;
    if (f != 0)
        f();
}
