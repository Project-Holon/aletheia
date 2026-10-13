/*
 * function: ISS_SWITCH_SET_CreateSwitches
 * address:  0x0202C3A8
 * packet:   pkt_0202C3A8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ISS_SWITCH_Create  0x0202C538  thumb
 */

extern int ISS_SWITCH_Create(int v);
void ISS_SWITCH_SET_CreateSwitches(char *p, int a1)
{
    int i;
    for (i = 0; i < 9; i++)
        *(int *)(p + 0x18 + i * 4) = ISS_SWITCH_Create(a1);
}
