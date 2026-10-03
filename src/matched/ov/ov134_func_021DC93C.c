/*
 * function: func_021DC93C
 * address: 0x021DC93C
 * packet: pkt_ov134_021DC93C
 * region: ov134
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_02FFFC3C 0x02FFFC3C data a4
 *   func_021B6114 0x021B6114 thumb ov090
 *   func_02034AC4 0x02034AC4 arm
 *   func_02031348 0x02031348 arm
 *   func_02031330 0x02031330 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_0201AB28 0x0201AB28 thumb
 *   func_0201A98C 0x0201A98C thumb
 *   func_020399A8 0x020399A8 arm
 *   func_0201A918 0x0201A918 thumb
 *   func_0203D3F8 0x0203D3F8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0203CD98 0x0203CD98 arm
 *   func_02157170 0x02157170 thumb ov009
 *   d_021BED00 0x021BED00 data a4 ov091
 *   d_021DC800 0x021DC800 data a4 ov131
 *   ov91_id 0x0000005B data a1
 *   ov131_id 0x00000083 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 g_02FFFC3C;
extern void func_021B6114(u8 *);
extern int func_02034AC4(int);
extern void func_02031348(void *, int, const void *, void *);
extern u32 func_02031330(void *);
extern void func_02034A5C(int);
extern void *func_0201AB28(void *, u32);
extern u32 func_0201A98C(void *, const void *);
extern void *func_020399A8(void);
extern int func_0201A918(void);
extern u32 func_0203D3F8(u32, u32, u32, u32, u32, u32, u32, u32);
extern void func_02039C68(void *, u32, u32);
extern u32 func_02039CB4(void *, u32, u32);
extern int func_0200FB24(void);
extern int func_0203CD98(void);
extern int func_02157170(int, int);
extern const u32 d_021BED00[], d_021DC800[];
extern const char ov91_id[], ov131_id[];
int func_021DC93C(void *unused0, void *unused1, u8 *q, u8 *p)
{
    u32 frame;
    u8 elapsed;
    u8 i;
    void *ctx;
    int code;
    if (*(u32 *)(p + 148) == 1 && *(u16 *)(p + 100) != 0) {
        frame = g_02FFFC3C;
        elapsed = frame - *(u32 *)(p + 200);
        p[196] += elapsed;
        *(u32 *)(p + 200) = frame;
        if (p[196] > 60) {
            *(u16 *)(p + 100) -= 1;
            p[196] -= 60;
        }
    }
    func_021B6114(p + 4);
    switch (*(u32 *)p) {
    case 0:
        func_02034AC4((int)ov91_id);
        func_02031348(*(void **)(p + 204), -1, d_021BED00, p + 4);
        *(u32 *)p = 1;
        break;
    case 1:
        if (func_02031330(*(void **)(p + 204)) == 0) *(u32 *)p = 2;
        break;
    case 2:
        func_02034A5C((int)ov91_id);
        if (*(u32 *)(p + 68) == 1) {
            p[171] = *(u32 *)(p + 64);
            *(u32 *)p = 3;
        } else {
            *(u32 *)(q + 40) = 0;
            *(u32 *)p = 6;
        }
        break;
    case 6:
        for (i = 0; i < 6; i++) {
            if (p[77 + i] != 0) {
                void *mon;
                mon = func_0201AB28(*(void **)(q + 4), p[77 + i] - 1);
                func_0201A98C(*(void **)(q + 28), mon);
            }
        }
        *(u32 *)p = 7;
        break;
    case 7:
        ctx = func_020399A8();
        code = func_0201A918();
        if (func_0203D3F8((u32)ctx, 255, 0x2f00, code, *(u32 *)(q + 28), 0, 0, 1) != 0) {
            func_02039C68(func_020399A8(), 20, 47);
            *(u32 *)p = 8;
        }
        break;
    case 8:
        if (func_02039CB4(func_020399A8(), 20, 47) != 0) return 1;
        break;
    case 3:
        func_02034AC4((int)ov131_id);
        func_02031348(*(void **)(p + 204), -1, d_021DC800, p + 156);
        *(u32 *)p = 4;
        break;
    case 4:
        if (*(u32 *)(p + 148) == 1 && *(u16 *)(p + 100) == 0) *(u32 *)(p + 192) = 1;
        if (func_0200FB24() != 0) *(u32 *)(p + 192) = 1;
        if (func_02031330(*(void **)(p + 204)) == 0) *(u32 *)p = 5;
        break;
    case 5:
        func_02034A5C((int)ov131_id);
        *(u32 *)(p + 64) = p[171];
        *(u32 *)p = 0;
        break;
    }
    if (func_0203CD98() != 0 && *(u32 *)p != 1 && *(u32 *)p != 2 && *(u32 *)p != 4 && *(u32 *)p != 5) {
        if (func_02157170(1, 1) != 0) {
            *(u32 *)(q + 40) = 1;
            return 1;
        }
    }
    return 0;
}
