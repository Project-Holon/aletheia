/*
 * function: func_021776A0
 * address:  0x021776A0
 * packet:   pkt_02156B70
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021AB180  0x021AB180  data
 *
 * Zeroes the live fields of element `i` of the 0x38-byte array reached
 * through the global pointer at 0x021AB180.  A null array is a no-op.
 */

extern char g_021AB180[];

void func_021776A0(int i)
{
    if (*(char **)g_021AB180 == 0)
        return;

    *(int *)(*(char **)g_021AB180 + i * 0x38 + 0x0c) = 0;
    *(int *)(*(char **)g_021AB180 + i * 0x38 + 0x10) = 0;
    *(int *)(*(char **)g_021AB180 + i * 0x38 + 0x14) = 0;
    *(int *)(*(char **)g_021AB180 + i * 0x38 + 0x18) = 0;
    *(char *)(*(char **)g_021AB180 + i * 0x38 + 0x1c) = 0;
    *(int *)(*(char **)g_021AB180 + i * 0x38 + 0x04) = 0;
    *(int *)(*(char **)g_021AB180 + i * 0x38 + 0x08) = 0;
    *(char *)(*(char **)g_021AB180 + i * 0x38 + 0x1d) = 0;
    *(short *)(*(char **)g_021AB180 + i * 0x38 + 0x22) = 0;
}
