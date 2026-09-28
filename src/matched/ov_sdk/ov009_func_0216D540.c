/*
 * function: DWCi_SendStateChanged
 * address:  0x0216D540
 * packet:   pkt_ov009_0216D540
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SendStateChanged (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   qr2_think         0x0219B1E8 arm
 *   DWCi_GetMatchCnt  0x02175F3C arm
 */

typedef unsigned char u8;
typedef unsigned long u32;

struct DWCstMatchControl
{
    u8 pad0[0x14];
    u8 qr2MatchType;
};

struct qr2_implementation_s
{
    u8 pad0[0xbc];
    u32 f_bc;
};

extern void qr2_think(struct qr2_implementation_s *qr2Obj);
extern struct DWCstMatchControl * DWCi_GetMatchCnt(void);

void DWCi_SendStateChanged(struct qr2_implementation_s *qr2Obj)
{
    if (qr2Obj == 0)
        return;
    qr2_think(qr2Obj);
    if (qr2Obj->f_bc != 0)
        return;
    switch (DWCi_GetMatchCnt()->qr2MatchType) {
    case 0:
    case 2:
    case 3:
        DWCi_GetMatchCnt();
        break;
    }
}
