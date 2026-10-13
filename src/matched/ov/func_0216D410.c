/*
 * function: FLDMMDL_SetAcmd
 * address:  0x0216D410
 * packet:   pkt_0216D410
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocked:  listing 40 compiled 38
 *
 * symbols:
 *   FLDMMDL_SetAcmdCode  0x0216D7C0  thumb  ov010
 *   FLDMMDL_SetAcmdSeq  0x0216D7C8  thumb  ov010
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 *   FLDMMDL_ClearMoveBit  0x0216D570  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void FLDMMDL_SetAcmdCode(void *p, u16 v);
extern void *FLDMMDL_SetAcmdSeq(void *p, u16 v);
extern void *FLDMMDL_SetMoveBit(void *p, u32 v);
extern char *FLDMMDL_ClearMoveBit(char *p, u32 v);

void FLDMMDL_SetAcmd(void *a0, u16 a1)
{
    u32 t4;

    FLDMMDL_SetAcmdCode(a0, a1);
    FLDMMDL_SetAcmdSeq(a0, 0);
    t4 = 2;
    t4 = t4 << 8;
    FLDMMDL_SetMoveBit(a0, t4);
    FLDMMDL_ClearMoveBit(a0, t4 << 1);
}
