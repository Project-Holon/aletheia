/*
 * function: func_0217F9DC
 * address: 0x0217F9DC
 * packet: pkt_ov019_0217F9DC
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_02180814 0x02180814 data ov019 a4
 *   func_02034714 0x02034714 arm
 *   func_0217FB30 0x0217FB30 thumb ov019
 *   func_0217FA10 0x0217FA10 thumb ov019
 */

typedef unsigned int u32;
typedef unsigned short u16;
struct E { u32 a,b,c,d; u16 h; };
extern const char d_02180814[];
extern void func_02034714(const char *expr, u32 line, const char *file);
extern struct E *func_0217FB30(struct E *p);
extern void func_0217FA10(char *p, u32 *out, u32 a, u16 b);
void func_0217F9DC(char *p, u32 a)
{
    struct E *e;
    if (*(u32 *)(p+0x14) == 0) func_02034714(d_02180814,0,d_02180814);
    e=func_0217FB30((struct E *)p);
    func_0217FA10(p,(u32 *)e,a,*(u16 *)(p+0x1c));
    (*(u16 *)(p+0x1c))++;
}
