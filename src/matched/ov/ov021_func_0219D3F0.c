/*
 * function: FLDMMDL_BLACT_AddResSlot
 * address:  0x0219D3F0
 * packet:   pkt_ov021_0219D3F0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_BLACT_AddVramSlot  0x0219C4AC  thumb  ov021
 *   BILLBOARD_ACT_CreateSlots  0x020500F0  arm
 *   sBlactTexFmt     0x021D8064  data a2
 *   sBlactCellSize     0x021D75C4  data ov021 a2
 */

typedef unsigned int   u32;
extern int FLDMMDL_BLACT_AddVramSlot(u32 a, u32 b, u32 c, u32 d);
typedef unsigned short u16;
struct BbActRec;
struct BbActSys;
extern u16 BILLBOARD_ACT_CreateSlots(struct BbActSys *o, const struct BbActRec *recs, u32 n);
extern unsigned short sBlactTexFmt[];
extern unsigned short sBlactCellSize[];

unsigned short FLDMMDL_BLACT_AddResSlot(int *o, int a1, int a2, int a3, int a4, int a5)
{
    unsigned short *q;
    struct {
        int w0;
        unsigned char b4;
        unsigned char b5;
        unsigned char b6;
        unsigned char b7;
        int w2;
    } s;

    if (a5 == -1) {
        return (unsigned short)FLDMMDL_BLACT_AddVramSlot(o[1], a4, a2, a3);
    }
    s.w0 = a4;
    s.b4 = 0;
    s.b5 = sBlactTexFmt[a3];
    q = sBlactCellSize + a2 * 2;
    s.b6 = q[0];
    s.b7 = q[1];
    s.w2 = a5;
    return BILLBOARD_ACT_CreateSlots((struct BbActSys *)o[1], (const struct BbActRec *)(&s), 1);
}
