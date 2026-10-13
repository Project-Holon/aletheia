/*
 * function: INTRUDE_CMD_RecvEntryIndex
 * address: 0x02173D00
 * packet: pkt_ov011_02173D00
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: Two alignment bytes follow; existing pkt_ov011_02173D2C covers
 *       the next function's push at 02173D2C. No unit is created.
 * symbols:
 *   func_0203D378 0x0203D378 arm
 *   INTRUDE_COMM_SetMemberEntry 0x02175F34 thumb ov011
 *   INTRUDE_COMM_SetSessionEntrySendFlag 0x02175914 thumb ov011
 */
typedef unsigned char u8;
typedef unsigned int u32;
u32 func_0203D378(void);
typedef unsigned short u16;
typedef struct Ent {
    u16 h[8];
    u8 f10, f11, f12, pad13;
    u8 f14[0x14];
} Ent;
void INTRUDE_COMM_SetMemberEntry(void *w, Ent *tbl, u32 arg, int idx);
void INTRUDE_COMM_SetSessionEntrySendFlag(int a, int b);

void INTRUDE_CMD_RecvEntryIndex(u32 a, int b, int *c, u8 *d)
{
    if (func_0203D378()) {
        INTRUDE_COMM_SetMemberEntry(d, (Ent *)(d + 0x1ac), a, *c);
        INTRUDE_COMM_SetSessionEntrySendFlag((int)(d + 0x1ac), *c);
    }
}
