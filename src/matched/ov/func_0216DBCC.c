/*
 * function: FLDMMDL_SetMoveBitSplash
 * address:  0x0216DBCC
 * packet:   pkt_0216DBCC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The first argument picks which of the pair of field setters
 * takes the shifted mask and the value.
 *
 * symbols:
 *   FLDMMDL_SetMoveBit   0x0216D568  thumb  ov010
 *   FLDMMDL_ClearMoveBit   0x0216D570  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *FLDMMDL_SetMoveBit(void *p, u32 v);
extern char *FLDMMDL_ClearMoveBit(char *p, u32 v);

int FLDMMDL_SetMoveBitSplash(void *a0, u32 a1, int a2)
{
    if (a1 == 1)
        return (int)FLDMMDL_SetMoveBit(a0, 0x40000);

    return (int)FLDMMDL_ClearMoveBit(a0, 0x40000);
}

