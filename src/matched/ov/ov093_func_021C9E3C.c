/*
 * function: func_021C9E3C
 * address:  0x021C9E3C
 * packet:   pkt_ov093_021C9E3C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021DCF78  0x021DCF78  thumb  ov093
 *   func_021DCF9C  0x021DCF9C  thumb  ov093
 *   func_021CD4FC  0x021CD4FC  thumb  ov093
 *   func_021CD568  0x021CD568  thumb  ov093
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 *   func_021C6E00  0x021C6E00  thumb  ov093
 *   func_021C88E4  0x021C88E4  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Cmd {
    u32 a : 8;
    u32 id : 5;
    u32 pad : 19;
    u8 b4;
    u8 b5;
    u16 h6;
};

extern u8 *func_021B9934(char *p, int i);
extern int func_021D5B68(void *p);
extern int func_021DCF78(void *p, u16 x);
extern void func_021DCF9C(int x);
extern int func_021CD4FC(void *p, int k);
extern void func_021CD568(void *p, int a, int k, u32 b);
extern u32 func_021CC8D8(void *lock, int line);
extern void func_021CC95C(void *lock, u32 v, int line);
extern void func_021C6E00(void *w, int a, u8 b);
extern int func_021C88E4(u8 *p);

int func_021C9E3C(u8 *w, struct Cmd *c)
{
    int r = (int)func_021B9934(*(char **)(w + 8), c->b4);
    int x;
    int t;
    u32 s;
    if (func_021D5B68((void *)r) == 0) {
        x = func_021DCF78((void *)r, c->h6);
        if (x != 0) {
            t = func_021CD4FC(*(void **)(w + 0xC), 0x42);
            s = func_021CC8D8(w + 0x1D74, 15755);
            func_021C6E00(w, r, c->id);
            if (func_021C88E4(w) == 2) {
                func_021CD568(*(void **)(w + 0xC), t, 0x42, c->b4);
            }
            func_021CC95C(w + 0x1D74, s, 15762);
            func_021DCF9C(x);
            return 1;
        }
    }
    return 0;
}
