/*
 * function: func_0218F818
 * address:  0x0218F818
 * packet:   pkt_ov021_0218F818
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0218E13C  0x0218E13C  thumb
 *   func_0218F780  0x0218F780  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

typedef struct {
    u32 saved;
    u8 body[0x94];
    u32 active;
} Sub;

extern void func_0218E13C(void *a, u32 s);
extern void func_0218F780(void *a, void *b);

void func_0218F818(u8 *a)
{
    if (a != 0) {
        Sub *s = (Sub *)(a + 0xf0);
        if (s->active == 0) {
            s->saved = *(u32 *)(a + 0x14);
            func_0218E13C(a, 0);
            func_0218F780(a, s->body);
            s->active = 1;
        }
    }
}
