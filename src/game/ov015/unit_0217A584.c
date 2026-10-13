/*
 * file:     unit_0217A584.c
 * unit:     yes
 * function: func_0217A584, func_0217A594, func_0217A5A4
 * address:  0x0217A584
 * region:   ov015
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_0217ABA8                   0x0217ABA8  data
 *   d_0217AAB0                   0x0217AAB0  data
 */
void IRC_SetRecvCallback(void *cb);
void IRC_SetUnitNumber(unsigned int n);
unsigned int IRC_GetUnitNumber(void);
extern unsigned char d_0217ABA8[];
extern unsigned char d_0217AAB0[];


void IRC_SetRecvCallback(void *cb)
{
	*(void **)(d_0217ABA8 + 8) = cb;
}


void IRC_SetUnitNumber(unsigned int n)
{
	d_0217AAB0[0] = (unsigned char)n;
}


unsigned int IRC_GetUnitNumber(void)
{
	return d_0217AAB0[1];
}
