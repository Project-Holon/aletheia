/*
 * function: func_021C68A0
 * address:  0x021C68A0
 * packet:   pkt_ov136_021C68A0
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201C4E4            0x0201C4E4  thumb
 *   func_0201C6C4            0x0201C6C4  thumb
 *   func_0202CD94 0x0202CD94 thumb
 *   func_0202DBC4  0x0202DBC4  thumb
 *   func_020310C4            0x020310C4  arm
 *   func_02045334            0x02045334  arm
 *   func_02045770            0x02045770  arm
 *   func_021C6594 0x021C6594 thumb
 *   d_021C7DA8 0x021C7DA8 data a4
 */

typedef unsigned char u8;
typedef unsigned int u32;
struct WinMgr;
extern int (*const d_021C7DA8[])(u8 *);
extern void func_0202CD94(struct WinMgr *mgr);
extern void func_021C6594(u8 *);
extern void func_0201C4E4(void *);
extern void func_02045334(void *);
extern u32 func_02045770(void *);
extern int func_0201C6C4(void *, u32);
extern void func_020310C4(void *);
extern void func_0202DBC4(void *);
int func_021C68A0(u8 *p, int *st)
{
    int i;
    int j;
    *st = d_021C7DA8[*st](p);
    if (*st == 0x1B) {
        return 0;
    }
    if (*(u8 **)(p + 8) != 0) {
        func_0202CD94(**(struct WinMgr ***)(p + 8));
        func_021C6594(*(u8 **)(p + 8));
        if (*(void **)(*(u8 **)(p + 8) + 0x1C4) != 0) {
            func_0201C4E4(*(void **)(*(u8 **)(p + 8) + 0x1C4));
            for (i = 0; i < 0x1B; i++) {
                void *h = *(void **)(*(u8 **)(p + 8) + 0x1C4);
                u8 *e = *(u8 **)(p + 8) + 0xC4 + i * 8;
                if (e[4] != 0) {
                    if (func_0201C6C4(h, func_02045770(*(void **)e)) == 0) {
                        func_02045334(*(void **)e);
                        e[4] = 0;
                    }
                }
            }
        }
        if (*(void **)(*(u8 **)(p + 8) + 0x1CC) != 0) {
            func_020310C4(*(void **)(*(u8 **)(p + 8) + 0x1CC));
        }
        if (*(void **)(*(u8 **)(p + 8) + 0x36C) != 0) {
            func_0202DBC4(*(void **)(*(u8 **)(p + 8) + 0x35C));
            func_0201C4E4(*(void **)(*(u8 **)(p + 8) + 0x36C));
            for (j = 0x1B; j < 0x20; j++) {
                void *g = *(void **)(*(u8 **)(p + 8) + 0x1C4);
                u8 *f = *(u8 **)(p + 8) + 0xC4 + j * 8;
                if (f[4] != 0) {
                    if (func_0201C6C4(g, func_02045770(*(void **)f)) == 0) {
                        func_02045334(*(void **)f);
                        f[4] = 0;
                    }
                }
            }
        }
    }
    return 1;
}
