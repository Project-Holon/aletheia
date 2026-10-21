/*
 * function: FLDMMDL_ACMD_ListDelete
 * address:  0x02197DAC
 * packet:   pkt_ov021_02197DAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   TCBL_GetOwnedWork  0x02030EE8  arm
 *   FLDMMDL_EndAcmd  0x0216D480  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 *   func_02030EAC  0x02030EAC  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

struct S02030EE8;
extern u32 TCBL_GetOwnedWork(struct S02030EE8 *p);
extern int FLDMMDL_EndAcmd(char *p);
extern u32 func_020307B0(void *p);
struct Node;
extern void func_02030EAC(struct Node *n);

void FLDMMDL_ACMD_ListDelete(void *a)
{
    u32 *p;

    p = (u32 *)TCBL_GetOwnedWork(a);
    FLDMMDL_EndAcmd((char *)p[3]);
    func_020307B0(p);
    func_02030EAC(a);
}
