/*
 * function: FIELD_MSGBG_MsgPrintPrintStr
 * address:  0x02190590
 * packet:   pkt_ov021_02190590
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201C6FC  0x0201C6FC  thumb  arm9
 *   func_02045770  0x02045770  arm  arm9
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct Slot {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u8  f20;
} Slot;

struct Descriptor;
extern void *func_02045770(struct Descriptor *a);
struct PrintSys;
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);

void FIELD_MSGBG_MsgPrintPrintStr(Slot *s, int x, int y, u32 z)
{
    u32 t;

    t = s->f0c;
    func_0201C6FC((struct PrintSys *)t, (u32)func_02045770((struct Descriptor *)s->f1c), (s16)x, (s16)y, (void *)z, s->f08);
    s->f20 = 1;
}
