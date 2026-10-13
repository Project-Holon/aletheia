/*
 * function: FIELD_WFBC_PEOPLE_SetUp
 * address:  0x02193F80
 * packet:   pkt_ov021_02193F80
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm  arm9
 *   EVENT_FIELD_PROCLINK_IsReturnEntryValid  0x02161ECC  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct E50 {
    u16 f00;
    u16 f02;
    u8  f04[0x30];
    u8  f34[0x18];
    u16 f4c;
    u16 f4e;
} E50;

extern void EVENT_FIELD_PROCLINK_IsReturnEntryValid(void *a);
extern void MI_CpuCopy8(void *src, void *dst, int n);

void FIELD_WFBC_PEOPLE_SetUp(E50 *e, void *a, u8 *b, void *c)
{
    EVENT_FIELD_PROCLINK_IsReturnEntryValid(a);
    e->f00 = 1;
    MI_CpuCopy8(a, e->f34, 0x18);
    MI_CpuCopy8(c, e->f04, 0x30);
    e->f4c = b[0];
    e->f4e = b[1];
}
