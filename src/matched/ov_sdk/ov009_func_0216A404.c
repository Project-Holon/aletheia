/*
 * function: func_0216A404
 * address:  0x0216A404
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Clears the word at 0x021AA874 after DWCi_Auth_AbortAuthentication when func_02178E70 reports zero.
 *
 * symbols:
 *   func_02178E70  0x02178E70  arm  ov009
 *   DWCi_Auth_AbortAuthentication  0x02178DA4  arm  ov009
 *   g_021AA874  0x021AA874  data

 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

void func_0216A404(void)
{
    extern int g_021AA874;
    int func_02178E70(void);
    void DWCi_Auth_AbortAuthentication(void);
    if (func_02178E70() == 0) DWCi_Auth_AbortAuthentication();
    g_021AA874 = 0;
}
