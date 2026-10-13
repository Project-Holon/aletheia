/*
 * function: BTL_CLIENT_StepPlayMultiMonAnim
 * address:  0x021D215C
 * packet:   pkt_ov093_021D215C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_SERVER_CMD_ReadU8Wrapper  0x021CD644  thumb  ov093
 *   func_021EA280  0x021EA280  thumb  ov093
 *   func_021EA2BC  0x021EA2BC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 unk00[0x54];
    void *win;            /* 0x54 */
    u8 unk58[0x134 - 0x58];
    u32 unk134;
} Seq;

extern u8 BTL_SERVER_CMD_ReadU8Wrapper(u8 *p);
extern void func_021EA280(char *ctx, u32 n, int b, const u8 *c, u16 e);
extern int func_021EA2BC(char *ctx);

int BTL_CLIENT_StepPlayMultiMonAnim(Seq *s, int *state, u32 *a)
{
    u8 buf[8];
    u8 i;
    u16 n;
    u32 p1;
    u16 p2;

    switch (*state) {
    case 0:
        n = a[0];
        p1 = a[1];
        p2 = a[2];
        for (i = 0; i < n; i++) {
            buf[i] = BTL_SERVER_CMD_ReadU8Wrapper((u8 *)s->unk134);
        }
        func_021EA280(s->win, n, p1, buf, p2);
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA2BC(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}
