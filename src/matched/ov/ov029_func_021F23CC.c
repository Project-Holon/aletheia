/*
 * function: func_021F23CC
 * address:  0x021F23CC
 * packet:   pkt_ov029_021F23CC
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * base is a u32 holding (u16)p->f14 and re-cast (u16) in the palette add:
 * that is the second lsls/lsrs pair.  The 0x0200910C result goes to a
 * local before base is loaded (the load sits between the call and cmp);
 * declaring i before buf gives i r4 and buf r5.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_020072CC  0x020072CC  thumb
 *   func_0203F1FC  0x0203F1FC  arm
 *   func_02009210  0x02009210  thumb
 *   func_0200910C  0x0200910C  thumb
 *   func_0200C6F0  0x0200C6F0  thumb
 *   func_02040B1C  0x02040B1C  arm
 *   func_02040E78  0x02040E78  arm
 *   func_02040AE0  0x02040AE0  arm
 *   func_0204162C  0x0204162C  arm
 *   func_020409B4  0x020409B4  arm
 *   func_0200734C  0x0200734C  thumb
 *   func_020307B0  0x020307B0  arm
 *   d_021F3554     0x021F3554  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int d_021F3554;

extern void *func_02030734(u32 heap, u32 size, u32 flag, void *file, u32 line);
extern u32 func_020120F4(u32 a);
extern u32 func_02012EBC(u32 a);
extern int func_020072CC(u32 sv, u32 id, u32 heap, void *buf, u32 size);
extern u16 func_0203F1FC(const void *src, u32 size);
extern void *func_02009210(u32 sv);
extern u16 func_0200910C(void *p);
extern u32 func_0200C6F0(void *p);
extern void func_02040B1C(u8 index, const void *src, u32 size, u32 tile);
extern void func_02040E78(u32 a, void *src, u32 size, u32 ofs);
extern void func_02040AE0(u32 index, const void *src, u32 mode);
extern u16 *func_0204162C(int channel);
extern void func_020409B4(u32 a);
extern void func_0200734C(u32 sv, u32 id);
extern void func_020307B0(void *p);

int func_021F23CC(u8 *p, u32 a)
{
    int result;
    u32 h;
    u16 crc;
    u32 base;
    u16 x;
    int i;
    u8 *buf;
    u16 *pal;

    result = 0;
    buf = func_02030734(0x70, 0x3000, 0, &d_021F3554, 0x104E);
    h = func_02012EBC(func_020120F4(a));
    if (func_020072CC(h, 4, 0x70, buf, 0x3000) == 1) {
        crc = func_0203F1FC(buf, 0x2600);
        x = func_0200910C(func_02009210(h));
        base = (u16)*(u32 *)(p + 0x14);
        if (crc == x && func_0200C6F0(buf) != 0) {
            result = 1;
            for (i = 0; i < 15; i++) {
                func_02040B1C(6, buf + i * 0x220, 0x220, base + (i + 5) * 0x20);
            }
            func_02040E78(6, buf + 0x1FE0, 0x20, 0x140);
            func_02040AE0(5, buf + 0x2000, 0x600);
            pal = func_0204162C(5);
            for (i = 0; i < 0x600 / 2; i++) {
                pal[i] += (u16)base;
            }
            func_020409B4(5);
        }
    }
    func_0200734C(h, 4);
    func_020307B0(buf);
    return result;
}
