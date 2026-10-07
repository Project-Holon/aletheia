/*
 * file:     net_whpipe_p01.c
 * unit:     yes
 * function: func_0217721C, func_0217723C
 * address:  0x0217721C
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203D5D4 0x0203D5D4 arm
 *   func_02010848 0x02010848 thumb
 *   func_0208EE9C 0x0208EE9C arm
 *   func_02178E68  0x02178E68  thumb  ov014
 *   func_02177AEC  0x02177AEC  thumb  ov014
 */
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

extern u32 func_0203D5D4(void);
extern u16 func_02010848(void);
extern int func_0208EE9C(void);
int func_02178E68(void);
int func_02177AEC(void);
int func_0217721C(void);
int func_0217723C(void);

/*
 * extent: two zero alignment bytes at 0217723A; existing code starts 0217723C.
 */
int func_0217721C(void)
{
    if (func_0203D5D4() == 3) return 3 - func_02010848();
    return 3 - func_0208EE9C();
}


/*
 * Normalises a queried mode: 5 maps to 0, and a zero mode with the predicate
 * set maps to 0x14.
 */
int func_0217723C(void)
{
    int r4 = func_02178E68();

    if (r4 == 5)
        r4 = 0;
    if (func_02177AEC() != 0 && r4 == 0)
        r4 = 0x14;
    return r4;
}
