/*
 * function: func_02089ED8
 * address:  0x02089ED8
 * packet:   pkt_02089ED8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      RequestCommandProc (snd_command.o)
 *
 * symbols:
 *   PXI_SendWordByFifo  0x02088610  arm
 */

typedef unsigned long u32;
typedef int BOOL;

extern int PXI_SendWordByFifo(int fifotag, u32 data, BOOL err);

void func_02089ED8(void)
{
    while (PXI_SendWordByFifo(7, 0, 0) < 0) {
    }
}
