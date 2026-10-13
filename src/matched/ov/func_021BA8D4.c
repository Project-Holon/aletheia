/*
 * function: WIFICLUB_DeleteTimeIcon
 * address:  0x021BA8D4
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TIME_ICON_Delete  0x0202F038  thumb
 *
 * Guarded release of the pointer at +0x100.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void TIME_ICON_Delete(u8 *p);

typedef struct {
    char pad[0x100];
    void *f100;
} S;

void WIFICLUB_DeleteTimeIcon(S *s)
{
    if (s->f100 != 0) {
        TIME_ICON_Delete(s->f100);
        s->f100 = 0;
    }
}
