/*
 * function: ZUKAN_DETAIL_AREA_UpdateTerrainIcons
 * address: 0x021C2238
 * packet: pkt_ov208_021C2238
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 (D6-04): closed by declaring data_021C8E1A non-const; the
 *   image keeps the x0 table load below the stack argument stores (a plain
 *   extern cannot move past them).
 * symbols:
 *   func_020413B0  0x020413B0  arm
 *   func_02041B6C  0x02041B6C  arm
 *   data_021C8E14  0x021C8E14  data
 *   data_021C8E1A  0x021C8E1A  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 f0;
    u8 f1;
    u8 b[0x3c];
} Entry;

extern const u8 data_021C8E14[3][2];
extern u8 data_021C8E1A[3][4];

extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(u32 bit);

#define W(o) (*(u32 *)(p + (o)))

void ZUKAN_DETAIL_AREA_UpdateTerrainIcons(u16 *heap, u8 *p, int key)
{
    u8 on[3] = {0, 0, 0};
    u8 idx, k, i;

    if (W(0x90) == 1 && p[0x79] != 0xff) {
        idx = W(0x8c) != 0 ? p[0x78] : 0;
        k = (p + p[0x79])[0x3cc];
        if ((*(Entry **)(p + 0x94))[idx].b[k] & 7)
            on[0] = 1;
        if ((*(Entry **)(p + 0x94))[idx].b[k] & 0x18)
            on[1] = 1;
        if ((*(Entry **)(p + 0x94))[idx].b[k] & 0x60)
            on[2] = 1;
    }
    for (i = 0; i < 3; i++)
        func_020413B0(7, data_021C8E1A[i][0], data_021C8E1A[i][1], data_021C8E1A[i][2],
                      data_021C8E1A[i][3], data_021C8E14[i][on[i]]);
    func_02041B6C(7);
}
