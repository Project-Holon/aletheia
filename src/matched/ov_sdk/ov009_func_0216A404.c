/*
 * function: DWCi_ShutdownLogin
 * address:  0x0216A404
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Clears the word at 0x021AA874 after DWCi_Auth_AbortAuthentication when DWCi_Auth_IsFinished reports zero.
 *
 * symbols:
 *   DWCi_Auth_IsFinished  0x02178E70  arm  ov009
 *   DWCi_Auth_AbortAuthentication  0x02178DA4  arm  ov009
 *   gDwcLoginControl  0x021AA874  data

 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

void DWCi_ShutdownLogin(void)
{
    extern int gDwcLoginControl;
    int DWCi_Auth_IsFinished(void);
    void DWCi_Auth_AbortAuthentication(void);
    if (DWCi_Auth_IsFinished() == 0) DWCi_Auth_AbortAuthentication();
    gDwcLoginControl = 0;
}
