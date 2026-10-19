/*
 * function: ITEMMENU_GetRowColorKind
 * address:  0x021BA1D0
 * packet:   pkt_ov070_021BA1D0
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FILE_UTIL_IsMachineItem  0x02021288  thumb
 *   FILE_UTIL_GetMachineMove  0x020212B0  thumb
 */

typedef unsigned int   u32;
extern u32 FILE_UTIL_IsMachineItem(u32 id);
extern int FILE_UTIL_GetMachineMove(int);

int ITEMMENU_GetRowColorKind(int x)
{
    if (FILE_UTIL_IsMachineItem(x) == 1) {
        switch (FILE_UTIL_GetMachineMove(x)) {
        case 0xF:
        case 0x13:
        case 0x39:
        case 0x46:
        case 0x7F:
        case 0x123:
            return 1;
        }
    }
    return 0;
}
