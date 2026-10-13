/*
 * function: VS_MULTI_LIST_InitIcons
 * address: 0x021F6F24
 * packet: pkt_ov097_021F6F24
 * region: ov097
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   VS_MULTI_LIST_InitClact 0x021F6F50 thumb ov097
 *   VS_MULTI_LIST_LoadIconResources 0x021F6F88 thumb ov097
 *   VS_MULTI_LIST_CreateActors 0x021F714C thumb ov097
 */
struct P;
extern void VS_MULTI_LIST_InitClact(void);
extern void VS_MULTI_LIST_LoadIconResources(int);
extern void VS_MULTI_LIST_CreateActors(struct P *);
void VS_MULTI_LIST_InitIcons(struct P *p)
{
    VS_MULTI_LIST_InitClact();
    VS_MULTI_LIST_LoadIconResources((int)p);
    VS_MULTI_LIST_CreateActors(p);
}
