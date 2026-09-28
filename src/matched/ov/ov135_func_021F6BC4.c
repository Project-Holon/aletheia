/*
 * function: func_021F6BC4
 * address:  0x021F6BC4
 * packet:   pkt_021F6BC4
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
  *
 * symbols:
 *   tbl_02202C58  0x02202C58  data  a4
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern u32 func_02017DBC(void *sav);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern u32 func_02017DE4(void *sav, u32 f);
extern const u32 tbl_02202C58[];

u32 func_021F6BC4(void *sav)
{
    u32 f = func_02017DBC(sav);
    u32 i;
    u32 r;

    for (i = 0; i < 15; i++) {
        r = func_02017E88(sav, tbl_02202C58[i], 0);
        if (r == 1) {
            break;
        }
    }
    func_02017DE4(sav, f);
    return r;
}
