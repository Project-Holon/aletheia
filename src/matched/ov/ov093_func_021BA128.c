/*
 * function: BTL_MAIN_SetClientParty
 * address:  0x021BA128
 * packet:   pkt_ov093_021BA128
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKEPARTY_Init  0x0201A948  thumb
 *   POKEPARTY_Copy  0x0201AC2C  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 */

typedef unsigned int u32;

struct Party;
struct Rec534;
extern void POKEPARTY_Init(struct Party *p);
extern void POKEPARTY_Copy(const struct Rec534 *src, struct Rec534 *dst);
extern u32 POKEPARTY_GetCount(void *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);

struct S {
    char pad[0x298];
    void *a[4];
    void *b[4];
    void *c;
};

void BTL_MAIN_SetClientParty(struct S *p, int i, void *x)
{
    if (p->a[i]) {
        POKEPARTY_Init(p->a[i]);
        POKEPARTY_Init(p->b[i]);
        POKEPARTY_Copy(x, p->a[i]);
        POKEPARTY_Copy(x, p->b[i]);
        if (POKEPARTY_GetCount(p->b[i])) {
            POKEPARTY_GetMember(p->b[i], 0);
        }
    }
}
