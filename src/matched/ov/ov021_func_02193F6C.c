/*
 * function: FIELD_WFBC_PEOPLE_Clear
 * address:  0x02193F6C
 * packet:   pkt_ov021_02193F6C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct E50 {
    u16 f00;
    u8  pad02[0x4E];
} E50;

extern void MI_CpuFill8(void *p, int v, int n);

void FIELD_WFBC_PEOPLE_Clear(E50 *e)
{
    MI_CpuFill8(e, 0, 0x50);
    e->f00 = 0;
}
