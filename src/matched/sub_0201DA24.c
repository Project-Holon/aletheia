/*
 * function: func_0201DA24
 * address:  0x0201DA24
 * packet:   pkt_0201DA00
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201DA24_File  0x020A7358  data
 *   func_020493D4       0x020493D4  arm
 *   func_02030734       0x02030734  arm
 *   sub_0204944C        0x0204944C  arm
 *   func_0201DBBC       0x0201DBBC  thumb
 *   func_0201DE40       0x0201DE40  thumb
 *   func_0201E538       0x0201E538  thumb
 *   func_0201E738       0x0201E738  thumb
 *   func_0201E928       0x0201E928  thumb
 */
typedef unsigned char  u8;
typedef unsigned int   u32;

struct Font {
    u32   unk00;
    u32   unk04;
    u32   unk08;
    void *unk0C;
    u8    pad10[0x40];
    void *unk50;
    u32   unk54;
    u8    pad58[0x34];
    u32   unk8C;
};

extern const char func_0201DA24_File[];

extern u32   func_020493D4(void *handle, u32 id);
extern void *func_02030734(u32 heap, u32 size, u32 align, const char *file,
                           u32 line);
extern void  sub_0204944C(void *handle, u32 id, u32 offset, u32 size,
                          void *dest);

extern void func_0201DBBC(void);
extern void func_0201DE40(void);
extern void func_0201E538(void);
extern void func_0201E738(void);
extern void func_0201E928(void);

void func_0201DA24(struct Font *f, u32 a, u32 b, u8 heap)
{
    u32 size;
    u32 p;

    size = func_020493D4(f->unk50, f->unk54) - f->unk8C;
    f->unk0C = func_02030734(heap, size, 0, func_0201DA24_File, 363);
    sub_0204944C(f->unk50, f->unk54, f->unk8C, size, f->unk0C);
    f->unk04 = (u32)func_0201DBBC;
    if (a == 1) {
        p = (u32)func_0201DE40;
        if (b != 1) {
            p = (u32)func_0201E538;
        }
        f->unk08 = p;
    } else {
        p = (u32)func_0201E738;
        if (b != 1) {
            p = (u32)func_0201E928;
        }
        f->unk08 = p;
    }
}
