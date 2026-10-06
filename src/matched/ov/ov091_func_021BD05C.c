/*
 * function: func_021BD05C
 * address: 0x021BD05C
 * packet: pkt_ov091_021BD05C
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * accepted 2026-10-05 by the user: the held form (see the notes below) is accepted as plausible original source.
 *
 * 2026-10-05 (wave P7 lane V9): byte-exact in c99 and c, but two casts are unsure
 * human forms, parked for the integrator. (1) `(u8)col` in the first call: col is only 0 or 4,
 * the cast only forces the lsls/lsrs the image has; without it 24 B differ. (2) `(u32)w >> 1` in
 * the tail: w is u8 and `w >> 1` gives asrs, the image has lsrs. Levers that closed the rest:
 * x, y and w as u8 parameters (x and y narrow moves their entry spill stores to the image order),
 * the i < n test inside the loop with the else store of 0, par ? 0 : 4 as if-assign. Callers pass
 * five arguments (p, list, x, y, w); w is the stack argument. No pragma changed anything.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_021BD218 0x021BD218 thumb ov091
 *   func_020450F0 0x020450F0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045924 0x02045924 arm
 *   func_02045770 0x02045770 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   d_021BED48 0x021BED48 data ov091 a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_0201AA18(void *list);
extern void *func_0201AB28(void *list, u32 i);
struct Descriptor;
struct Strbuf;
struct U16Vec;
extern u32 *func_021BD218(u8 *p, void *mon, s16 x, u16 y);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C724(u32 a, u32 b, s16 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02045808(struct U16Vec *vec);
extern const char d_021BED48[];

u32 *func_021BD05C(u8 *p, u32 *list, u8 x, u8 y, u8 w)
{
    u32 *r;
    u8 n;
    u8 i;
    u32 bmp;
    u32 flag;

    r = (u32 *)func_02030734(*(u16 *)p, 0x20, 0, d_021BED48, 0x143);
    n = func_0201AA18((void *)list[0]);
    for (i = 0; i < 6; i++) {
        if (i < n) {
            int par = i % 2;
            u8 xx = x + par * (w + 5);
            u8 yy = y + (i / 2) * 6 + 4;
            int col = 4;
            if (par != 0) col = 0;
            r[2 + i] = (u32)func_021BD218(p, func_0201AB28((void *)list[0], i), (u8)((u8)col + (xx << 3)), (u8)(yy << 3));
        } else {
            r[2 + i] = 0;
        }
    }
    flag = 1;
    r[1] = func_020450F0(4, (u8)(x + 1 + ((u32)w >> 1)), (u8)(y + 1), 10, 2, 0xe, flag);
    bmp = (u32)func_020457B0(0x10, *(u16 *)p);
    func_02045924((struct Strbuf *)bmp, (const u16 *)list[1]);
    func_0201C724(*(u32 *)(p + 0x140), (u32)func_02045770((struct Descriptor *)r[1]), 0, 0, bmp, *(u32 *)(p + 0x138), 0x3c40);
    func_02045808((struct U16Vec *)bmp);
    r[0] = flag;
    return r;
}
