/*
 * function: BTL_MAIN_CollectLivingPokeIds
 * address:  0x021B8D38
 * packet:   pkt_ov093_021B8D38
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_DecodeMessageCode  0x021B8778  thumb  ov093
 *   BTL_SIDE_GetPokeAtPosThunk  0x021B98A4  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Unk021B8CB0;
extern u8 BTL_MAIN_DecodeMessageCode(struct Unk021B8CB0 **p, int k, u8 *out);
extern u8 *BTL_SIDE_GetPokeAtPosThunk(char *const *q, u8 b);
extern int BTL_POKEPARAM_IsFainted(void *m);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);

u8 BTL_MAIN_CollectLivingPokeIds(void *p, int a, int k, u8 *out)
{
    u8 buf[8];
    u8 n;
    u8 cnt;
    u8 i;
    u8 *m;

    n = BTL_MAIN_DecodeMessageCode(p, k, buf);
    i = 0;
    cnt = 0;
    for (; i < n; i++) {
        m = BTL_SIDE_GetPokeAtPosThunk((char *const *)a, buf[i]);
        if (m && !BTL_POKEPARAM_IsFainted(m)) {
            out[cnt++] = BTL_POKEPARAM_GetPokeId(m);
        }
    }
    return cnt;
}
