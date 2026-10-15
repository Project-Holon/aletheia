/*
 * function: MUSICAL_EVENT_SendLocalPerformer
 * address:  0x02155FB4
 * packet:   pkt_ov010_02155FB4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 2026-10-05 (D9 lane 02): callee 0x021FD948 is the ov132 setter, already matched in ov132_func_021FD938.c. Region hint ov132 added.
 *
 * symbols:
 *   STA_NET_SetState18Value  0x021FD948  thumb  ov132
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Work {
    u8 pad00[0x14];
    u32 f14;            /* 0x14 */
    u8 pad18[0x24 - 0x18];
    void *f24;          /* 0x24 */
    void *f28;          /* 0x28 */
    u8 pad2C[0x38 - 0x2C];
    void *f38;          /* 0x38 */
    void *f3C;          /* 0x3C */
} Work;

extern void STA_NET_SetState18Value(char *p, u32 value);

void MUSICAL_EVENT_SendLocalPerformer(Work *w)
{
    if (w->f14 == 1)
        STA_NET_SetState18Value(w->f28, (u32)w->f3C);
}
