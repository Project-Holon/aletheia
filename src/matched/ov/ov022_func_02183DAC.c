/*
 * function: func_02183DAC
 * address: 0x02183DAC
 * packet: pkt_ov022_02183DAC
 * region: ov022
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Original 02183DBA consumes pointer result of 020399A8 in r0,
 * passed to 0203D1A4; 020399A8 ends with 0203996C and leaves result live.
 * The ov012 02174010 leaves 0203D4D0 result live, read at 02183DD0.
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_02174010 0x02174010 thumb ov012
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Link;
struct Entry;
extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *);
extern u32 func_02174010(u32 a, void *p);
void func_02183DAC(u8 *p)
{
    u32 i;
    if (p[13] != 0) {
        i = func_0203D1A4((struct Link *)func_020399A8());
        if (func_02174010(p[13], p + 0x2c + i * 40) == 1) p[13] = 0;
    }
}
