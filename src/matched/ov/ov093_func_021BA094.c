/*
 * function: BTL_MAIN_CreateParties
 * address: 0x021BA094
 * packet: pkt_ov093_021BA094
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKEPARTY_Create 0x0201A920 thumb
 */
typedef unsigned int u32;
struct Party;
extern struct Party *POKEPARTY_Create(u32);
struct S { char pad[0x298]; void *a[4]; void *b[4]; void *c; };
void BTL_MAIN_CreateParties(struct S *p)
{
    unsigned int i;
    for (i = 0; i < 4; i++) {
        p->a[i] = POKEPARTY_Create(0x12);
        p->b[i] = POKEPARTY_Create(0x12);
    }
    p->c = POKEPARTY_Create(0x12);
}
