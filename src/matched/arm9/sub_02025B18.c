/*
 * function: BMP_OAM_ReleaseModeSlots
 * address:  0x02025B18
 * packet:   pkt_02025774
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;
typedef signed int    s32;

struct Obj02025774 {
    u8  pad[0xc];
    s32 slots[3];
};

extern void CLACT_ReleaseCellAnim(u32 slot);

void BMP_OAM_ReleaseModeSlots(struct Obj02025774 *p)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (p->slots[i] != -1) {
            CLACT_ReleaseCellAnim(p->slots[i]);
            p->slots[i] = -1;
        }
    }
}
