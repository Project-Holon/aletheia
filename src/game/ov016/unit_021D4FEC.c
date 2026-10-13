/*
 * file:     unit_021D4FEC.c
 * function: DWCi_CELLlGetState
 * address:  0x021D4FEC
 * packet:   pkt_021D4FE0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_CELLlGetState   0x021D4FEC  arm
 *
 * Byte at +0x0c of the argument.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_CELLlGetState.c \
 *       --func DWCi_CELLlGetState --addr 0x021D4FEC --region ov016 --cc dsi/1.1p1 --arm
 */

/* Cell object of the DWC GUI cell list (cell.o); only the state byte is read here. */
typedef struct CellObj {
    unsigned char pad00[0x0C];
    unsigned char state;
} CellObj;

unsigned char DWCi_CELLlGetState(CellObj *cell)
{
    return cell->state;
}
