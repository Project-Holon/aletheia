/*
 * function: BTL_ABILITY_SturdyEndureFromFullHp
 * address: 0x021DA748
 * packet: pkt_ov093_021DA748
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte alignment padding.
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_OverwriteVar 0x021D76BC thumb ov093
 *   BTL_POKEPARAM_IsHpFull 0x021D5B48 thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
extern int BTL_EVENT_OverwriteVar(int, unsigned int);
typedef unsigned char u8;
extern int BTL_POKEPARAM_IsHpFull(u8 *p);
extern void *func_021C7CF4(int *, int);

void BTL_ABILITY_SturdyEndureFromFullHp(int a, int *b, int c, int *d)
{
    int k = 4;
    if (c == BTL_EVENT_GetVar(k)) {
        if (BTL_POKEPARAM_IsHpFull(func_021C7CF4(b, c)) != 0) {
            *d = BTL_EVENT_OverwriteVar(0x3a, k);
            return;
        }
        *d = 0;
    }
}
