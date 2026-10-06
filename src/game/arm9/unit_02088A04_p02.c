/*
 * file:     unit_02088A04_p02.c
 * unit:     yes
 * function: func_02088EC4, func_02088ED4
 * address:  0x02088EC4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_02151428  0x02151428  data  a4
 *   g_0215142C 0x0215142C data
 */
extern void g_0215142C(void);
void func_02088EC4(int result);
asm void func_02088ED4(void);
extern int g_02151428[];


/*
 * note:     librtc external.o RtcGetResultCallback.
 */
void func_02088EC4(int result)
{
    g_02151428[9] = result;
}


asm void func_02088ED4(void)
{
    ldr ip, =g_0215142C
loc_02088ED8:
    ldr	r0, [ip]
    cmp	r0, #1
    beq loc_02088ED8
    bx	lr
}
