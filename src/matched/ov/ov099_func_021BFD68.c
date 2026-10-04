/*
 * function: func_021BFD68
 * address: 0x021BFD68
 * packet: pkt_ov099_021BFD68
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_02039C68 0x02039C68 arm
 */
typedef unsigned short u16;

extern int func_021BA928(char *, int);
typedef unsigned int   u32;
struct Entry;
extern struct Entry *func_020399A8(void);
extern int func_0203D3A8(struct Entry *a, u16 b, u16 c, u32 d);
struct Link;
extern void func_02039C68(struct Link *p, unsigned int lo, unsigned int hi);
int func_021BFD68(char *p, int ret)
{
    if (!func_021BA928(p, ret)) return ret;
    if (func_0203D3A8(func_020399A8(), 0xa08, 0, 0)) {
        func_02039C68((struct Link *)func_020399A8(), 0x12, 0xa);
        *(int *)(p + 0x1cc) = 0x93;
    }
    return ret;
}
