/*
 * function: BTL_NET_PollSync
 * address:  0x021D4B18
 * packet:   pkt_ov093_021D4B18
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlNet     0x021F3B88  data  ov093
 *   func_02039CB4  0x02039CB4  arm
 *   GFL_NET_HANDLE_SetUserInfo  0x0203A424  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S {
    void *f00;
    u32 f04;
    u16 f08;
    u8 pad0a[5];
    u8 f0f;
    u8 f10;
};

extern struct S *gBtlNet;
struct Link;
extern unsigned int func_02039CB4(struct Link *a0, unsigned int a1, unsigned int a2);
extern void GFL_NET_HANDLE_SetUserInfo(char *p, int a, int b, int c);

int BTL_NET_PollSync(int a)
{
    struct S *p = gBtlNet;
    int r;

    if (p != 0) {
        if (p->f10 != 0) {
            r = func_02039CB4((struct Link *)p->f00, p->f0f, 1);
            if (r != 0) {
                gBtlNet->f0f = 0;
                gBtlNet->f10 = 0;
                return r;
            }
        } else {
            GFL_NET_HANDLE_SetUserInfo(p->f00, a, 1, p->f08);
        }
        return 0;
    }
    return 1;
}
