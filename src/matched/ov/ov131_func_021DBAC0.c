/*
 * function: P_STA_OAM_DeleteManager
 * address:  0x021DBAC0
 * packet:   pkt_021DBAC0
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   P_STA_OAM_FreeCellRes  0x021DBF0C  thumb
 *   func_020307B0  0x020307B0  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void P_STA_OAM_FreeCellRes(int *p);
extern u32 func_020307B0(void *p);

void P_STA_OAM_DeleteManager(u8 *p)
{
    P_STA_OAM_FreeCellRes((int *)p);
    func_020307B0(p);
}
