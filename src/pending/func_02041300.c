/*
 * function: func_02041300
 * address:  0x02041300
 * packet:   pkt_02041300
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH*
 *
 * symbols:
 *   g_02146A44     0x02146A44  data
 *   func_02042D2C  0x02042D2C  arm
 *   func_02042E34  0x02042E34  arm
 *   func_02042ED8  0x02042ED8  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Entry {
    u8 pad_00[8];
    u8 unk_08[0x14];
    u8 unk_1c;
    u8 pad_1d[0xf];
};

extern struct Entry *g_02146A44;

extern void func_02042D2C(void *surf, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5, u8 a6);
extern void func_02042E34(void *surf, u8 a1, u32 a2, u32 a3, u8 a4, u8 a5);
extern void func_02042ED8(void *surf, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5, u8 a6);

void func_02041300(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5, u8 a6)
{
    u8 kind = g_02146A44[index].unk_1c;

    if (kind == 0) {
        func_02042D2C((u8 *)g_02146A44 + 8 + index * sizeof(struct Entry),
                      a1, a2, a3, a4, a5, a6);
    } else if (kind == 1) {
        func_02042E34((u8 *)g_02146A44 + 8 + index * sizeof(struct Entry),
                      a1, a2, a3, a4, a5);
    } else {
        func_02042ED8((u8 *)g_02146A44 + 8 + index * sizeof(struct Entry),
                      a1, a2, a3, a4, a5, a6);
    }
}
