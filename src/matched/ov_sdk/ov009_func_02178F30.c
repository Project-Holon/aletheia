/*
 * function: DWCi_Auth_IsConsoleUserIdAuthentic
 * address:  0x02178F30
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Reads a word back out of a 0x14-byte frame filled by DWC_Auth_GetId.
 *
 * symbols:
 *   DWC_Auth_GetId  0x02058FB4  arm

 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int DWCi_Auth_IsConsoleUserIdAuthentic(void)
{
    void DWC_Auth_GetId(void *);
    char buf[0x14];
    DWC_Auth_GetId(buf);
    return *(int *)(buf + 0x10);
}
