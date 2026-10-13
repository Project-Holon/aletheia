/*
 * function: FLDMMDL_ACMD_Update
 * address:  0x02197EDC
 * packet:   pkt_ov021_02197EDC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetAcmdCode  0x0216D7C4  thumb  ov010
 *   FLDMMDL_ACMD_RunCmds  0x02197EB4  thumb  ov021
 *   FLDMMDL_CheckMoveBit  0x0216D57C  thumb  ov010
 *   FLDMMDL_ClearMoveBit  0x0216D570  thumb  ov010
 *   FLDMMDL_SetAcmdCode  0x0216D7C0  thumb  ov010
 *   FLDMMDL_SetAcmdSeq  0x0216D7C8  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 FLDMMDL_GetAcmdCode(u8 *);
extern void FLDMMDL_ACMD_RunCmds(u32 a);
extern u32 FLDMMDL_CheckMoveBit(void *p, u32 v);
extern char *FLDMMDL_ClearMoveBit(char *p, u32 v);
extern void FLDMMDL_SetAcmdCode(void *p, u16 v);
extern void *FLDMMDL_SetAcmdSeq(void *p, u16 v);

u32 FLDMMDL_ACMD_Update(u8 *p)
{
    if (FLDMMDL_GetAcmdCode(p) != 0xff) {
        FLDMMDL_ACMD_RunCmds((u32)p);
        if (FLDMMDL_CheckMoveBit(p, 0x400) == 0) {
            return 0;
        }
    }
    FLDMMDL_ClearMoveBit((char *)p, 0x400);
    FLDMMDL_SetAcmdCode(p, 0xff);
    FLDMMDL_SetAcmdSeq(p, 0);
    return 1;
}
