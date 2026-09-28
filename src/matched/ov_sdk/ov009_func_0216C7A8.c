/*
 * function: DWCi_GT2SocketErrorCallback
 * address:  0x0216C7A8
 * packet:   pkt_ov009_0216C7A8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_GT2SocketErrorCallback (dwc_main.o)
 *
 * symbols:
 *   func_02195E60  0x02195E60  arm  ov009
 *   func_0217ED54  0x0217ED54  arm  ov009
 *   func_02059F54  0x02059F54  arm
 *   g_021AA878     0x021AA878  data
 */

extern int func_02195E60(const void *p);
extern int func_0217ED54(void);
extern void func_02059F54(int error, int errorCode);
extern char g_021AA878[];

void DWCi_GT2SocketErrorCallback(void *socket)
{
    func_02195E60(socket);
    *(int *)g_021AA878 = func_0217ED54();
    func_02059F54(9, (int)0xfffe8515);
    *(int *)(*(char **)(g_021AA878 + 4)) = 0;
}
