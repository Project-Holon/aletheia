/*
 * function: func_021BC090
 * address:  0x021BC090
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
 *   TIME_ICON_CreateNode  0x0202EE8C  thumb
 *
 * Guarded release of the handle at +0x100, then a fresh object from the
 * five-argument factory, built from the blocks at +0x1C0 and +0x190 and stored
 * back at +0x100.  The 5th argument rides on the stack (`str r0, [sp]`).
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef int BOOL;

extern void TIME_ICON_Delete(u8 *p);
extern u8 *TIME_ICON_CreateNode(u32 a, void *b, u8 c, u8 d, u16 e);

typedef struct {
    char pad[0x100];
    u32 f100;
    char pad2[0x8C];
    u32 f190;
    char pad3[0x2C];
    u32 f1C0;
} S;

void func_021BC090(S *s)
{
    if (s->f100 != 0) {
        TIME_ICON_Delete((u8 *)s->f100);
        s->f100 = 0;
    }

    s->f100 = (u32)TIME_ICON_CreateNode(s->f1C0, (void *)s->f190, 0xF, 0x10, 0x21);
}
