/*
 * function: SCRCMD_MUSICAL_BeginCommSession
 * address:  0x0215DE38
 * packet:   pkt_0215DE38
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Forwards three of its four incoming argument registers to a callee whose
 * first parameter is the constant 4. The callee takes four arguments, so a
 * tail call is impossible (bx would spend an argument register on the
 * target), which is why the image keeps a frame and emits a direct bl.
 * The listing extent is two bytes long because of the trailing alignment
 * padding.
 *
 * symbols:
 *   MUS_COMM_FUNC_Create  0x021FC644  thumb  ov132
 */

extern void MUS_COMM_FUNC_Create(int a, void *b, void *c, int d);

void SCRCMD_MUSICAL_BeginCommSession(int a, void *b, void *c, int d)
{
    MUS_COMM_FUNC_Create(4, (void *)b, (void *)c, d);
}
