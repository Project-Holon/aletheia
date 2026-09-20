/*
 * function: func_02041300
 * address:  0x02041300
 * packet:   pkt_02041300
 * status:   MATCH
 * symbols:
 *   g_BgConfig     0x02146A44  data
 *   func_02042D2C  0x02042D2C  arm
 *   func_02042E34  0x02042E34  arm
 *   func_02042ED8  0x02042ED8  arm
 */

typedef unsigned int u32;
typedef unsigned char u8;

struct BgConfigLayer {
    char pad_00[0x1C];
    u8 mode;
    char pad_1D[0x0F];
};

extern struct BgConfigLayer *g_BgConfig;

extern void func_02042D2C(void *p, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern void func_02042E34(void *p, u8 a1, int a2, int a3, u8 a4, u8 a5);
extern void func_02042ED8(void *p, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);

void func_02041300(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6)
{
    u32 offset = layer * 0x2C;
    struct BgConfigLayer *bg = (struct BgConfigLayer *)((u8 *)g_BgConfig + offset);

    if (bg->mode == 0) {
        func_02042D2C((u8 *)g_BgConfig + 8 + offset, a1, a2, a3, a4, a5, a6);
    } else if (bg->mode == 1) {
        func_02042E34((u8 *)g_BgConfig + 8 + offset, (u8)a1, a2, a3, a4, a5);
    } else {
        func_02042ED8((u8 *)g_BgConfig + 8 + offset, a1, a2, a3, a4, a5, a6);
    }
}
