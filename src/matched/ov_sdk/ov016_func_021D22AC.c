/*
 * function: DWCi_MOV_MBP_IsBootableAll
 * address:  0x021D22AC
 * packet:   pkt_ov016_021D22AC
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_MOV_MBP_IsBootableAll (libdwcutil.TWL.HYB.a(dwc_mov_mbp.o))
 *
 * symbols:
 *   MB_CommIsBootable                0x021F1BE0  arm
 *   gDwcMovMbpWork                       0x021DE65C  data
 */

typedef unsigned short u16;

typedef struct {
    u16 pad0;
    u16 bmp;
} Wb;

extern Wb *gDwcMovMbpWork;
extern int MB_CommIsBootable(u16 child_aid);

int DWCi_MOV_MBP_IsBootableAll(void)
{
    u16 i;
    if (gDwcMovMbpWork->bmp == 0)
        return 0;
    for (i = 1; i < 16; i++) {
        if ((gDwcMovMbpWork->bmp & (1 << i)) && !MB_CommIsBootable(i))
            return 0;
    }
    return 1;
}
