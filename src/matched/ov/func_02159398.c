/*
 * function: SCRIPT_WORK_CmdCompareWorkConst
 * address:  0x02159398
 * packet:   pkt_02159398
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Halfword out of the record the overlay looks up, classified through an
 * arm9 call, and the class byte stored back on the object.
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer   0x02159AE8  thumb  ov010
 *   SCRIPT_WORK_CompareValues   0x0215932C  thumb  ov010
 *   VM_GetU16   0x02011330  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
struct Stream;
extern u16 VM_GetU16(struct Stream *s);
extern int SCRIPT_WORK_CompareValues(unsigned int a, unsigned int b);

int SCRIPT_WORK_CmdCompareWorkConst(void *a0, void *a1)
{
    u16 v = *SCRIPT_WORK_ReadWorkPointer(a0, a1);

    *(u8 *)((char *)a0 + 0xE) = SCRIPT_WORK_CompareValues(v, VM_GetU16(a0));

    return 0;
}

