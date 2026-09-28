/*
 * function: DWCi_PingCallback
 * address:  0x02177398
 * packet:   pkt_ov009_02177398
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_PingCallback (libdwcmatch.TWL.HYB.a dwc_transport.o)
 * symbols:
 *   DWCi_GetConnectionAID  0x0216BB54 arm
 *   g_021AB180             0x021AB180 data
 */

extern unsigned char DWCi_GetConnectionAID(void *connection);
extern char g_021AB180[];

typedef void (*DWCiPingCallback_t)(int latency, unsigned char aid, int arg);

void DWCi_PingCallback(void *connection, int latency)
{
    unsigned char aid;

    if (*(DWCiPingCallback_t *)(*(char **)g_021AB180 + 0x70c) == 0)
        return;
    aid = DWCi_GetConnectionAID(connection);
    (*(DWCiPingCallback_t *)(*(char **)g_021AB180 + 0x70c))(latency, aid,
        *(int *)(*(char **)g_021AB180 + 0x71c));
}
