/*
 * function: FLDMMDL_SetMoveBitReflect
 * address:  0x0216DC18
 * packet:   pkt_0216DC18
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

int FLDMMDL_SetMoveBitReflect(void *a0, int a1)
{
    int a2;
    if (a1 == 1)
        return (int)FLDMMDL_SetMoveBit(a0, 0x20000);

    return (int)FLDMMDL_ClearMoveBit(a0, 0x20000);
}

