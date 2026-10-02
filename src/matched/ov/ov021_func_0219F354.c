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

extern St *func_0216D6F0(u32);
extern u32 func_0216D910(u32);
extern u32 func_0216D678(u32);
extern u32 func_0219C9DC(u32);
extern u32 func_0219FFD4(u32);
extern void func_0219FEB0(u8 *, u32, u32, u32);
extern void func_0219FFBC(u32, u32 *);
extern void func_02197CCC(u32, u32 *);
extern void func_021A000C(u32, u32, u32, u32, u32);
extern void func_0205082C(u32, u32, u16);
extern u32 func_02050080(u32);
extern void func_0204F638(u32, u32, u32 *);

void func_0219F354(u32 a)
{
    St *p;
    u32 h;
    u32 n;
    u32 v;
    u8 flag;
    u32 buf[3];

    p = func_0216D6F0(a);
    if (p->id != 0xFFFF) {
        h = func_0219C9DC(func_0216D910(a));
        n = func_0216D678(a);
        if (n >= 10) {
            flag = 0;
            v = func_0219FFD4(a);
            if (n != p->f5) {
                flag = 1;
                p->f4 = v;
                p->f5 = n;
                p->f6 = 0;
                func_0205082C(h, p->id, n + 30);
            }
            func_021A000C(a, h, p->id, flag, 0);
        } else {
            func_0219FEB0(&p->f4, a, h, p->id);
        }
        func_02197CCC(a, buf);
        func_0219FFBC(a, buf);
        func_0204F638(func_02050080(h), p->id, buf);
    }
}
