/*
 * unit:     no
 * function: BG_SYS_InitRun
 * address:  0x02040B94
 * packet:   pkt_02040B94
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_020A7E5C     0x020A7E5C  data
 *   sub_02030734   0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_020425B4  0x020425B4  arm
 *
 * TU: bg_sys.c.
 *
 * Fill a run of the layer's tilemap with zeroes: take a scratch buffer of
 * `size` bytes off the heap (the heap id arrives as a plain argument here,
 * not out of the background system object, so it is masked and re-tagged the
 * same way the constructor's own allocation is), zero it, hand it to the
 * tilemap writer and release it again.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_InitRun.c \
 *       --func BG_SYS_InitRun --addr 0x02040B94 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern char g_020A7E5C[];

extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site,
                          u16 tag);
extern u32 func_020307B0(void *p);
extern void  MI_CpuFill8(void *dst, u32 value, u32 size);
extern void  func_020425B4(u32 layer, const void *src, u32 offset, u32 size);

void BG_SYS_InitRun(u8 layer, u32 size, u32 offset, u32 heapId)
{
    void *buf = sub_02030734((u16)((heapId & 0x7fff) | 0x8000), size, 0,
                             g_020A7E5C, 1362);

    MI_CpuFill8(buf, 0, size);
    func_020425B4(layer, buf, offset, size);
    func_020307B0(buf);
}
