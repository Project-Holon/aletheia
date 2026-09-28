/*
 * function: func_02168E50
 * address:  0x02168E50
 * packet:   pkt_ov009_02168E50
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_StopFriendProcess (dwc_friend.o)
 *
 * symbols:
 *   g_021AA860    0x021AA860  data
 *   func_02059F54  0x02059F54  arm
 *   func_02168D7C  0x02168D7C  arm
 *   func_0205A1B0  0x0205A1B0  arm
 *   func_02169294  0x02169294  arm
 */

extern char g_021AA860[];
extern void func_02059F54(int error, int errorCode);
extern int func_02168D7C(void);
extern void func_0205A1B0(int name, void *ptr, int flag);
extern void func_02169294(void);

void func_02168E50(int error, int errorCode)
{
    if (*(char **)(g_021AA860 + 0xc) == 0 || error == 0) return;
    func_02059F54(error, errorCode);
    if (func_02168D7C() != 0) {
        if (*(void **)(*(char **)(g_021AA860 + 0xc) + 0x5c) != 0) {
            func_0205A1B0(4, *(void **)(*(char **)(g_021AA860 + 0xc) + 0x5c), 0);
            *(int *)(*(char **)(g_021AA860 + 0xc) + 0x5c) = 0;
        }
        (*(void (*)(int, unsigned char, int))(*(int *)(*(char **)(g_021AA860 + 0xc) + 0x2c)))(
            error,
            *(unsigned char *)(*(char **)(g_021AA860 + 0xc) + 0x1d),
            *(int *)(*(char **)(g_021AA860 + 0xc) + 0x30));
    }
    func_02169294();
}
