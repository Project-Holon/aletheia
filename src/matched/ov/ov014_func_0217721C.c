/*
 * function: func_0217721C
 * address: 0x0217721C
 * packet: pkt_ov014_0217721C
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 0217723A; existing code starts 0217723C.
 * symbols:
 *   func_0203D5D4 0x0203D5D4 arm
 *   func_02010848 0x02010848 thumb
 *   func_0208EE9C 0x0208EE9C arm
 */
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 func_0203D5D4(void);
extern u16 func_02010848(void);
extern int func_0208EE9C(void);
int func_0217721C(void)
{
    if (func_0203D5D4() == 3) return 3 - func_02010848();
    return 3 - func_0208EE9C();
}
