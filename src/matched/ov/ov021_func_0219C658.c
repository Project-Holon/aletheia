/*
 * function: func_0219C658
 * address:  0x0219C658
 * packet:   pkt_ov021_0219C658
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_0216E2E8  0x0216E2E8  thumb  ov010
 *   func_0219CB64  0x0219CB64  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0216D520(void *p);
struct Record;
extern void func_0216E2E8(const char *ctx, u32 id, struct Record *out);
extern void func_0219CB64(u32, u8 *, u32);

void func_0219C658(u32 a, u32 b)
{
    u8 buf[28];
    u32 s = func_0216D520((void *)a);
    func_0216E2E8((const char *)a, b, (struct Record *)buf);
    func_0219CB64(s, buf, 0);
}
