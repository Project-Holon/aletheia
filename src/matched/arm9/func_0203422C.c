/*
 * function: func_0203422C
 * address:  0x0203422C
 * packet:   pkt_0203422C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   Areaman_RunMask   0x020A048C  data
 *   Areaman_TailMask  0x020A0495  data
 *
 * areaman.c.  Clear `len` bits starting at bit `start` of the bitmap: a run
 * inside one byte goes to func_02034394 (q, bit, len); otherwise the head
 * bits are cleared with the tail mask, whole bytes are zeroed and the run
 * mask clears the head of the last byte.  func_020344C8 then refreshes the
 * manager.
 *
 * What closed it (wave 17, from 17 out): the byte cursor past the head is
 * the PARAMETER reused, `start = idx + 1;`, not idx incremented.  That puts
 * the cursor in start's own register r1 and rotates the zero and the count
 * to the image's r2 / r3; the same lever closed sub_020343C0.
 * docs/idioms/a-dead-parameter-reused-as-the-index-rotates-the-loop-registers.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203422C.c \
 *       --func func_0203422C --addr 0x0203422C --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct AreaMan {
    u16 unk00;
    u16 unk02;
    u32 *guard;
    u32 unk08;
    u8 bits[1];
};

extern const u8 Areaman_RunMask[];
extern const u8 Areaman_TailMask[];

extern void func_02034394(u8 *q, u32 bit, u32 len);
extern void func_020344C8(struct AreaMan *p);

void func_0203422C(struct AreaMan *p, u32 start, s32 len)
{
    u32 bit = start % 8;
    u32 idx = start / 8;
    s32 avail;
    s32 rest;
    u32 nfull;
    u32 tail;
    u32 mask;

    if ((bit + len) <= 8) {
        func_02034394(&p->bits[idx], bit, len);
    } else {
        avail = 8 - bit;
        mask = Areaman_TailMask[avail];
        rest = len - avail;
        nfull = rest / 8;
        tail = rest % 8;
        p->bits[idx] &= (u8)~mask;
        start = idx + 1;
        while (nfull-- != 0) {
            p->bits[start] = 0;
            start++;
        }
        p->bits[start] &= (u8)~Areaman_RunMask[tail];
    }
    func_020344C8(p);
}
