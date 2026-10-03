/*
 * function: func_021C20C0
 * address:  0x021C20C0
 * packet:   pkt_ov208_021C20C0
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204B3F4  0x0204B3F4  arm
 *   func_02045EC0  0x02045EC0  arm
 *   sub_0201D304  0x0201D304  thumb
 *   func_02045770  0x02045770  arm
 *   func_020437DC  0x020437DC  arm
 *   sub_0201C724  0x0201C724  thumb
 *   func_02045808  0x02045808  arm
 *   func_021C0740  0x021C0740  thumb  ov208
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_021C0CC0  0x021C0CC0  thumb  ov208
 *   func_021C0C8C  0x021C0C8C  thumb  ov208
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

extern int func_0204B3F4(int a0);
struct MsgBank;
struct StrObj;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 sub_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_02045770(void *p);
extern u16 func_020437DC(u32 win);
extern void sub_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
extern void func_021C0740(void *a0, u8 *st, void *a2, u8 i);
extern void func_0204B3DC(int a, int b);
extern int func_021C0CC0(void *a0, u8 *st, void *a2);
extern void func_021C0C8C(void *a0, u8 *st, void *a2, int on);

void func_021C20C0(void *a0, u8 *st, void *a2)
{
    int res = func_0204B3F4(*(int *)(st + 0xc8));

    if (*(u32 *)(st + 0x90) == 0) {
        if (res == 0) {
            void *msg;
            u32 w;
            int d;
            int h;
            u32 t;

            msg = func_02045EC0(*(void **)(st + 0xc), 0x80);
            w = (u16)sub_0201D304(msg, *(u32 *)(st + 4), 0);
            h = func_020437DC(func_02045770(*(void **)(st + 0x20)));
            t = func_02045770(*(void **)(st + 0x20));
            d = h - w;
            sub_0201C724(*(void **)(st + 0x40), t, (s16)(u16)(d / 2), 1, (u32)msg, *(u32 *)(st + 4), 0x3c40);
            func_02045808(msg);
            *(u32 *)(st + 0x30) = 1;
            func_021C0740(a0, st, a2, 3);
            func_0204B3DC(*(int *)(st + 0xc8), 1);
        }
    } else {
        u8 i;
        u8 v;
        u8 *tbl;

        v = *(u32 *)(st + 0x8c) == 0 ? 0 : st[0x78];
        for (i = 0; i < 0x3d; i++) {
            tbl = *(u8 **)(st + 0x94);
            if (tbl[v * 0x3e + st[0x3cc + i] + 2] != 0 && *(u32 *)(st + 0x1e0 + i * 8) != 1) {
                func_0204B3DC(*(int *)(st + 0xdc + i * 4), 1);
            }
        }
        if (func_021C0CC0(a0, st, a2) == 0) {
            func_021C0C8C(a0, st, a2, 1);
        }
    }
}
