/*
 * function: func_021DD080
 * address: 0x021DD080
 * packet: pkt_ov119_021DD080
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_PROC_IsNetSession 0x021D8A24 thumb ov119
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 */
extern int POKETRADE_PROC_IsNetSession(void *);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *, unsigned int, unsigned int);
void func_021DD080(void *a, void *b, void *c)
{
    if (POKETRADE_PROC_IsNetSession(c))
        GFL_NET_HANDLE_SetTimingSyncRange(a, (unsigned int)b, 8);
}
