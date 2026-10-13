/*
 * function: VS_MULTI_LIST_ExitIcons
 * address: 0x021F6F3C
 * packet: pkt_ov097_021F6F3C
 * region: ov097
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   VS_MULTI_LIST_DeleteActors 0x021F72BC thumb ov097
 *   VS_MULTI_LIST_ReleaseIconResources 0x021F7108 thumb ov097
 *   VS_MULTI_LIST_ExitClact 0x021F6F80 thumb ov097
 */
extern void VS_MULTI_LIST_DeleteActors(char *);
extern void VS_MULTI_LIST_ReleaseIconResources(char *);
extern void VS_MULTI_LIST_ExitClact(void);
void VS_MULTI_LIST_ExitIcons(char *p)
{
    VS_MULTI_LIST_DeleteActors(p);
    VS_MULTI_LIST_ReleaseIconResources(p);
    VS_MULTI_LIST_ExitClact();
}
