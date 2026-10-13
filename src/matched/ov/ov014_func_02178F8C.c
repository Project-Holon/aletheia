/*
 * function: WIH_StateOutMeasureChannel
 * address: 0x02178F8C
 * packet: pkt_ov014_02178F8C
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 wave P16 lane E8: older draft was DIFF 101 B / 136 B because the
 *   two arms kept separate copies of the u16 store. Per-function pragma
 *   opt_dead_assignments off gives 132 B EXACT (also with plain literal offsets).
 *   Without the pragma the same source stays 136 B. Callee types from matched
 *   definitions: WIH_SetError and WIH_ChangeSysState void(int), WIH_StateInMeasureChannel int(u16).
 * symbols:
 *   gWihWork 0x021797A8 data ov014 a4
 *   WIH_SetError 0x0217814C thumb ov014
 *   WIH_ChangeSysState 0x02178138 thumb ov014
 *   WIH_StateInMeasureChannel 0x02178F1C thumb ov014
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u16 f0, err, f4, f6, channel, level; } Msg;
extern u8 *gWihWork;
extern void WIH_SetError(int);
extern void WIH_ChangeSysState(int);
extern int WIH_StateInMeasureChannel(u16);
#pragma opt_dead_assignments off
void WIH_StateOutMeasureChannel(const Msg *m)
{
    u32 a;
    u32 b;
    u32 t;
    int r;
    if (m->err != 0) {
        WIH_SetError(m->err);
        WIH_ChangeSysState(9);
        return;
    }
    a = m->channel;
    b = m->level;
    t = *(u16 *)(gWihWork + 0x1EAE);
    if (t > b) {
        *(u16 *)(gWihWork + 0x1EAE) = b;
        t = 1 << (a - 1);
        *(u16 *)(gWihWork + 0x1EB0) = t;
    } else if (t == b) {
        t = (u16)(1 << (a - 1)) | *(u16 *)(gWihWork + 0x1EB0);
        *(u16 *)(gWihWork + 0x1EB0) = t;
    }
    r = WIH_StateInMeasureChannel(a + 1);
    if (r == 0x18 && *(u32 *)(gWihWork + 0x1E70) != 9) {
        WIH_ChangeSysState(7);
        return;
    }
    if (r != 2) WIH_ChangeSysState(9);
}

#pragma opt_dead_assignments reset
