/*
 * function: func_0203B4DC
 * address:  0x0203B4DC
 * packet:   pkt_0203B4DC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *
 * Calls the transport's +0x10 virtual with (1, 0) and reports at line 0x282
 * (642) when it answers non-zero.  The zero argument and the report's third
 * argument are the same `mov r4, #0` local, which is what puts the two
 * together in one register.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B4DC.c \
 *       --func func_0203B4DC --addr 0x0203B4DC --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *func_0203D788(void);
typedef unsigned short u16;
struct NetState;
extern void func_0203AD80(struct NetState *s, void *p, u16 v, int line);

void func_0203B4DC(void)
{
    if (((u32 (*)(u32, u32))*(u32 *)(*(u32 *)((char *)func_0203D788() + 0x340) + 0x10))(1, 0) != 0)
        func_0203AD80((struct NetState *)((int)*(int *)((char *)(0x21469DC))), (void *)0x203B390, 0, (int)0x282);
}
