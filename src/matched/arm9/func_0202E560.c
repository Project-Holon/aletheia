/*
 * unit:     no
 * function: func_0202E560
 * address:  0x0202E560
 * packet:   pkt_0202E560
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_020A033C     0x020A033C  data
 *   g_020A77E0     0x020A77E0  data
 *   func_02030734  0x02030734  arm
 *   func_02046C94  0x02046C94  arm
 *   func_02046C9C  0x02046C9C  arm
 *   func_02069FD0  0x02069FD0  arm
 *   func_02069FF8  0x02069FF8  arm
 *   func_0206E964  0x0206E964  arm
 *   func_02080C44  0x02080C44  arm
 *   func_02082D44  0x02082D44  arm
 *
 * Screen-texture setup (the __FILE__ anchor for this address is
 * screentex.c, 0x020A77E0). Allocates a small control block and a 0x8C-byte
 * work buffer off the heap in a0, seeds the buffer from a template with
 * MI_CpuCopy8 (func_02082D44), binds it to the control block, then builds a
 * packed VRAM descriptor: bits of the bank word returned by func_02080C44
 * are folded into an accumulator under a fall-through switch on a1, and the
 * result is combined with the texture size from func_0206E964 /
 * func_02069FD0 before the final publish through func_02069FF8.
 *
 * BLOCKED: every concrete byte is correct; the single unresolved relocation
 * is the ABS32 to the 0x8C-byte template at 0x020A033C. No evidence class
 * reaches it. The only pool word naming that address anywhere in the image
 * is the one at 0x0202E60C, inside this function's own range, so `literal`
 * and `sole-ref/data` both refuse it (layout/data_objects.txt line for
 * 0x020A033C records exactly that one referrer site, twice-listed from the
 * two unit spellings of the same listing). `tu --suggest-split` confirms no
 * cut exists: 1 witness image wide, 1 of them inside this range. Unsticking
 * this needs a second referrer of 0x020A033C, i.e. another function that
 * loads the same template, to reach EXACT.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0202E560.c \
 *       --func func_0202E560 --addr 0x0202E560 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;
typedef int s32;

extern char g_020A033C[];
extern char g_020A77E0[];

typedef unsigned short u16;
extern int func_02046C94(void);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082D44(void *src, void *dst, u32 n);
struct Rec;
extern void func_02046C9C(struct Rec *rec, u32 mode, u32 value);
extern unsigned char *func_0206E964(unsigned char *p);
extern int func_02069FD0(int p);
extern u16 func_02080C44(void);
extern void func_02069FF8(char *p, int a, int b);

void *func_0202E560(u32 heap, u32 sel)
{
    void *blk;
    void *buf;
    void *tex;
    u32 size;
    u32 bank;
    u32 acc;

    blk = func_02030734(heap, func_02046C94(), 0, g_020A77E0, 0x3b);
    buf = func_02030734(heap, 0x8c, 0, g_020A77E0, 0x3c);
    func_02082D44(g_020A033C, buf, 0x8c);
    func_02046C9C(blk, 2, (u32)buf);
    tex = func_0206E964(buf);
    size = func_02069FD0((int)tex);
    bank = func_02080C44();
    acc = 0;
    switch (sel) {
    case 3:
        bank |= 4;
        if (bank) {
            acc = acc + (4 << 15);
        }
    case 2:
        bank |= 2;
        if (bank) {
            acc = acc + (2 << 16);
        }
    case 1:
        bank |= 1;
        if (bank) {
            acc = acc + (1 << 17);
        }
    case 0:
        break;
    }
    func_02069FF8(tex, ((size >> 4) << 16) | ((acc << 13) >> 16), 0);
    return blk;
}
