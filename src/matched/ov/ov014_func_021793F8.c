/*
 * function: func_021793F8
 * address: 0x021793F8
 * packet: pkt_ov014_021793F8
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: final counter store uses unsigned address arithmetic rather than
 *   pointer arithmetic, so its offset is reloaded independently of the flag.
 * symbols:
 *   g_021797A8 0x021797A8 data ov014 a4
 *   func_02178138 0x02178138 thumb ov014
 *   func_0217863C 0x0217863C thumb ov014
 */
typedef unsigned char u8;
typedef short s16;
extern u8 *g_021797A8;
extern void func_02178138(int);
extern int func_0217863C(void);
void func_021793F8(void)
{
    if (g_021797A8 != 0 && *(s16 *)(g_021797A8 + 0x1EBE) > 0) {
        *(s16 *)(g_021797A8 + 0x1EBE) =
            (*(int *)(g_021797A8 + 0x1E70) != 2) ? 0 : *(s16 *)(g_021797A8 + 0x1EBE) - 1;
        if (*(s16 *)(g_021797A8 + 0x1EBE) == 0) {
            if (*(int *)(g_021797A8 + 0x1E70) == 2 && g_021797A8[0x1EDE] == 0) {
                if (func_0217863C() == 0) func_02178138(9);
            } else {
                *(s16 *)((unsigned int)g_021797A8 + 0x1EBE) = 1;
            }
        }
    }
}
