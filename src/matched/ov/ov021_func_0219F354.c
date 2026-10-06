/*
 * function: func_0219F354
 * address:  0x0219F354
 * packet:   pkt_ov021_0219F354
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D6F0  0x0216D6F0  thumb  ov010
 *   func_0216D910  0x0216D910  thumb  ov010
 *   func_0216D678  0x0216D678  thumb  ov010
 *   func_0219C9DC  0x0219C9DC  thumb  ov021
 *   func_0219FFD4  0x0219FFD4  thumb  ov021
 *   func_0219FEB0  0x0219FEB0  thumb  ov021
 *   func_0219FFBC  0x0219FFBC  thumb  ov021
 *   func_02197CCC  0x02197CCC  thumb  ov021
 *   func_021A000C  0x021A000C  thumb  ov021
 *   func_0205082C  0x0205082C  arm
 *   func_02050080  0x02050080  arm
 *   func_0204F638  0x0204F638  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 id;
    u8 pad[2];
    u8 f4;
    u8 f5;
    u8 f6;
} St;

typedef signed int     s32;
extern void *func_0216D6F0(void *p);
extern int func_0216D910(int a0);
struct Trip;
extern u16 func_0216D678(void *p);
extern u32 func_0219C9DC(u8 *p);
extern u32 func_0219FFD4(u32);
extern void func_0219FEB0(u8 *s, u32 a, u32 r, u16 id);
extern void func_0219FFBC(u32, u32 *);
extern void func_02197CCC(u8 *p, s32 *out);
extern void func_021A000C(u32, u32, u32, u32, u32);
extern void func_0205082C(void *p, int idx, u32 h);
extern u32 func_02050080(u32 *p);
extern void func_0204F638(u8 *a0, int i, struct Trip *src);

void func_0219F354(u32 a)
{
    St *p;
    u32 h;
    u32 n;
    u32 v;
    u8 flag;
    u32 buf[3];

    p = func_0216D6F0((void *)a);
    if (p->id != 0xFFFF) {
        h = func_0219C9DC((u8 *)func_0216D910(a));
        n = func_0216D678((void *)a);
        if (n >= 10) {
            flag = 0;
            v = func_0219FFD4(a);
            if (n != p->f5) {
                flag = 1;
                p->f4 = v;
                p->f5 = n;
                p->f6 = 0;
                func_0205082C((void *)h, p->id, (u16)(n + 30));
            }
            func_021A000C(a, h, p->id, flag, 0);
        } else {
            func_0219FEB0(&p->f4, a, h, p->id);
        }
        func_02197CCC((u8 *)a, (s32 *)buf);
        func_0219FFBC(a, buf);
        func_0204F638((u8 *)func_02050080((u32 *)h), p->id, (struct Trip *)buf);
    }
}
