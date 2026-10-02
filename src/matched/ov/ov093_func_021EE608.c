/*
 * function: func_021EE608
 * address:  0x021EE608
 * packet:   pkt_ov093_021EE608
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02082D44  0x02082D44  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_02082D44(const void *, void *, u32);

void func_021EE608(u8 *p, const u8 *src, int n)
{
    u32 pos;
    u32 end;

    if (p[2] == 0) {
        pos = *(u16 *)p;
        n = n - 1;
        end = pos + n;
        if (end <= 0xC00) {
            func_02082D44(src + 1, p + 8 + pos, n);
            *(u16 *)p = end;
        } else {
            p[2] = 1;
        }
    }
}
