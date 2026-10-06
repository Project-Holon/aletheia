/*
 * function: func_0203B7F8
 * address:  0x0203B7F8
 * packet:   pkt_0203B6EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469DC     0x021469DC  data
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B7F8.c \
 *       --func func_0203B7F8 --addr 0x0203B7F8 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern u8 *g_021469DC;

struct B794 {
    u8     pad_00[0x2C];
    void (*unk_2C)(u32);
};

extern void *func_0203D798(void);
struct NetState;
extern void func_0203AD80(struct NetState *s, void *p, u16 v, int line);
typedef signed int     s32;
struct Entry;
extern struct Entry *func_0203996C(s32 idx);
struct Entry;
extern struct Entry *func_020399A8(void);
extern u32 func_020399EC(u32 a);
extern u16 func_02039338(void);
extern u32 func_0203D650(void);

void func_0203B7F8(struct B794 *p)
{
    func_0203D798();

    func_0203996C(0xFF);
    if ((int)func_020399EC((u32)func_020399A8()) < 2)
        return;

    func_02039338();

    if (p->unk_2C != 0) {
        p->unk_2C(func_0203D650());
        p->unk_2C = 0;
    }

    func_0203AD80((struct NetState *)g_021469DC, (void *)0x0203C00C, 0, 0x33F);
}
