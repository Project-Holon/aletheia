/*
 * function: FLDMMDL_ACMD_ListCreate
 * address:  0x02197D3C
 * packet:   pkt_ov021_02197D3C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysGetHeapId  0x0216D4F8  thumb  ov010
 *   FLDMMDL_SysGetTcbPriority  0x0216D4F4  thumb  ov010
 *   FLDMMDL_SysGetTcbSys  0x0216D514  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   d_021DDBE0     0x021DDBE0  data  a4
 *   FLDMMDL_ACMD_ListTaskMain  0x02197DCC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *FLDMMDL_GetMmdlSys(void *a0);
extern u32 FLDMMDL_SysGetHeapId(u8 *p);
extern u16 FLDMMDL_SysGetTcbPriority(void *p);
extern u32 FLDMMDL_SysGetTcbSys(void *p);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_02030DA8(u32, void (*)(), u32 *, u32);
extern u8 d_021DDBE0;
extern void FLDMMDL_ACMD_ListTaskMain(void *a, int *b);

void FLDMMDL_ACMD_ListCreate(u32 p0, u32 p1)
{
    u32 h;
    u32 *r;
    u32 n;

    h = (u32)FLDMMDL_GetMmdlSys((void *)p0);
    r = func_02030734((u16)(0x8000 | (FLDMMDL_SysGetHeapId((u8 *)h) & 0x7fff)), 0x14, 1, (const char *)&d_021DDBE0, 0x115);
    n = FLDMMDL_SysGetTcbPriority(FLDMMDL_GetMmdlSys((void *)p0)) - 2;
    func_02030DA8(FLDMMDL_SysGetTcbSys((void *)h), FLDMMDL_ACMD_ListTaskMain, r, n);
    r[3] = p0;
    r[4] = p1;
}
