/*
 * file:     unit_021E0000.c
 * unit:     yes
 * function: func_021E0000, func_021E0040, func_021E0070, func_021E0080
 * address:  0x021E0000
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021E0504  0x021E0504  arm  ov175
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern u8 *func_021E0504(u8 *dst, u32 v);
int func_021E0000(u8 *p);
int func_021E0040(u32 *p);
int func_021E0070(u32 *p);
int func_021E0080(u32 *p);


/*
 * SDK provenance: sciReportBeginNewPlayer (TwlDWC/libdwcgssc.TWL.HYB.a,
 * scireport.o), ov175.  Close the previous player block and start a new one
 * at +0x120, byte-swapping the zeroed two-byte player id.
 */
int func_021E0000(u8 *p)
{
    u32 a = *(u32 *)(p + 0x120);
    u8 *q = *(u8 **)(p + 0x124);

    *(u16 *)(p + 8) = 0;
    *(u32 *)(p + 4) = a;
    *(u32 *)(p + 0x120) = a + 2;
    func_021E0504(q + a, 0);
    *(u32 *)(q + 0x3c) += 2;
    return 0;
}


/*
 * SDK provenance: sciReportBeginGlobalData (TwlDWC/libdwcgssc.TWL.HYB.a,
 * scireport.o), ov175.  Open a global-data block: state 2, and the running
 * +0x120 offset advanced past the header it just summed.
 */
int func_021E0040(u32 *p)
{
    u32 *q = (u32 *)p[0x124 / 4];

    p[0] = 2;
    p[0x120 / 4] = q[0x2c / 4] + 0x44 + q[0x30 / 4] + q[0x34 / 4];
    return 0;
}


/*
 * SDK provenance: sciReportBeginPlayerData (TwlDWC/libdwcgssc.TWL.HYB.a,
 * scireport.o), ov175.
 */
int func_021E0070(u32 *p)
{
    p[0] = 3;
    return 0;
}


int func_021E0080(u32 *p)
{
    p[0] = 4;
    return 0;
}
