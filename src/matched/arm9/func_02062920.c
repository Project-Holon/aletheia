/*
 * function: func_02062920
 * address:  0x02062920
 * packet:   pkt_02062884
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02062B64    0x02062B64  arm
 *   func_0206296C    0x0206296C  arm

 * Blocking class: label.  Same shape as src/pending/func_02062634.c one tag over:
 * every concrete byte is right, the only unresolved site is the tail
 * `bl func_0206296C` at 0x02062934, and this call is the only branch to
 * 0x0206296C in the image.  The `bl func_02062B64` site resolves (`label x40`).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct MultiCellBank;
struct NitroFileHeader;
extern void *func_02062B64(struct NitroFileHeader *file, u32 signature);
extern void func_0206296C(volatile struct MultiCellBank *bank);

int func_02062920(u32 a, u32 *out)
{
    u32 r = (u32)func_02062B64((struct NitroFileHeader *)a, 0x4D43424B);

    if (r == 0) {
        *out = 0;
        return 0;
    }
    func_0206296C((volatile struct MultiCellBank *)(r + 8));
    *out = r + 8;
    return 1;
}
