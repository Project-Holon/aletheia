/*
 * function: func_021BB544
 * address:  0x021BB544
 * packet:   pkt_ov088_021BB544
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_02030734  0x02030734  arm
 *   func_02049EF4  0x02049EF4  arm
 *   func_02082A60  0x02082A60  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02049238  0x02049238  arm
 *   d_021BD5EC     0x021BD5EC  data  ov088  a2
 *   d_021BDA00     0x021BDA00  data  ov088  a1
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct { u16 a; u16 b; } Ent;
extern const Ent d_021BD5EC[8];
extern char d_021BDA00[];

extern void *func_020490F4(unsigned int id, u16 heap);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *file, u16 line);
extern void *func_02049EF4(void *o, u32 a, u32 b, void **out, u16 e);
extern void func_02082A60(void *srcp, void *destp, unsigned long size);
extern void func_020307B0(void *p);
extern void func_02049238(void *h);

void func_021BB544(char *p)
{
    void *h = func_020490F4(0x23, 0x800B);
    u32 i;
    for (i = 0; i < 8; i++) {
        u32 sz = d_021BD5EC[i].b * 0x34;
        void *out;
        void *r;
        *(u32 *)(p + i * 4 + 0xf8) = (u32)func_02030734(0xb, sz, 0, d_021BDA00, 0x7e9);
        r = func_02049EF4(h, d_021BD5EC[i].a, 1, &out, 0xb);
        func_02082A60((char *)out + 0xc, *(void **)(p + i * 4 + 0xf8), sz);
        func_020307B0(r);
    }
    func_02049238(h);
}
