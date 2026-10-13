/*
 * function: EVENT_FIELD_PROCLINK_IsAnimFlagSet
 * address:  0x02161B74
 * packet:   pkt_02161B74
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_ACMD_ListCheckEnd  0x02197DA0  thumb
 *   FLDMMDL_ACMD_ListDelete  0x02197DAC  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int FLDMMDL_ACMD_ListCheckEnd();
extern int FLDMMDL_ACMD_ListDelete();

int EVENT_FIELD_PROCLINK_IsAnimFlagSet(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = FLDMMDL_ACMD_ListCheckEnd(a0);
loc_02161B7C:
    if (a0 != 1) goto loc_02161B8A;
loc_02161B80:
a0 = t4 + 0;
    a0 = FLDMMDL_ACMD_ListDelete(a0);
loc_02161B86:
a0 = 1;
    return a0;
loc_02161B8A:
a0 = 0;
    return a0;}
