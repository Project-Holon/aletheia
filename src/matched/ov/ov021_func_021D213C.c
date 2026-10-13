/*
 * function: SCRCMD_CheckPmsWordPair
 * address:  0x021D213C
 * packet:   pkt_ov021_021D213C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Callee witnesses filed in wave A1 (witness lane).
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   PMS_WORD_IsSameGroup  0x020249B0  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern int PMS_WORD_IsSameGroup(u32 a, u16 b);

int SCRCMD_CheckPmsWordPair(u32 a, u32 b)
{
    u32 base, s, r7, r4;
    u16 *p;

    r4 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    s = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    r7 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    p = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    switch (r4) {
    case 1:
        base = 0x5C0;
        r4 = base + 0xBB;
        break;
    case 2:
        base = 0x664;
        r4 = base + 0x53;
        break;
    default:
        *p = 0;
        return 0;
    }
    if (PMS_WORD_IsSameGroup(base, s & 0x7FF) && PMS_WORD_IsSameGroup(r4, r7 & 0x7FF)) {
        *p = 1;
    } else {
        *p = 0;
    }
    return 0;
}
