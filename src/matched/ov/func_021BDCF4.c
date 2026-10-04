/*
 * function: func_021BDCF4
 * address:  0x021BDCF4
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201283C  0x0201283C  thumb
 *   func_02009C24  0x02009C24  thumb
 *
 * Same handle at +0xC4 of the third argument, its accessor result forwarded
 * together with the first two arguments.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

struct BigObj;
extern u32 func_0201283C(const struct BigObj *p);
struct Sub020097BCObj;
extern void func_02009C24(struct Sub020097BCObj *obj, int src, int dest);

void func_021BDCF4(int a, int b, char *p)
{
    func_02009C24((struct Sub020097BCObj *)func_0201283C(*(void **)(p + 0xC4)), a, b);
}
