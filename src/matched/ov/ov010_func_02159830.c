/*
 * function: SCRIPT_WORK_CmdModWork
 * address: 0x02159830
 * packet: pkt_ov010_02159830
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding at 0x02159852.
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer 0x02159AE8 thumb ov010
 *   SCRIPT_WORK_ReadWorkValue 0x02159B10 thumb ov010
 *   _u32_div_f 0x0209C2B0 arm
 * prototype: named runtime helper has opaque combined scalar return;
 * the original and compiled helper arguments are numerator r0, divisor r1.
 * low word is original r0 output, high word is original r1 remainder.
 * The original admits zero divisors. Direct helper call preserves that
 * behavior without expressing undefined C remainder on a zero divisor.
 * Fixed-flag run 1 proves u64 return in r0/r1: high-word extraction emits
 * no shift, and strh r1 immediately follows the original helper call.
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern u32 SCRIPT_WORK_ReadWorkValue(void *, void *);
extern u64 _u32_div_f(u32, u32);
int SCRIPT_WORK_CmdModWork(void *a, void *b)
{
    u16 *p = SCRIPT_WORK_ReadWorkPointer(a, b);
    u32 divisor = SCRIPT_WORK_ReadWorkValue(a, b);
    *p = (u32)(_u32_div_f(*p, divisor) >> 32);
    return 0;
}
