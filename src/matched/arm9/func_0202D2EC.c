/*
 * unit:     no
 * function: func_0202D2EC
 * address:  0x0202D2EC
 * packet:   pkt_0202D2EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734   0x02030734  arm
 *   func_020307B0   0x020307B0  arm
 *   MIi_CpuCopyFast 0x02082B0C  arm
 *   sFile_020A77AC  0x020A77AC  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  func_020307B0(void *p);
extern void  MIi_CpuCopyFast(const void *src, void *dst, u32 len);
extern char  sFile_020A77AC[];

void func_0202D2EC(u32 *obj, u32 heap)
{
    u8 *dst;
    u8 *buf;
    s32 i;
    s32 off;

    dst = (u8 *)obj[5];
    buf = (u8 *)func_02030734((u16)((heap & 0x7fff) | 0x8000), 0x1200,
                              1, sFile_020A77AC, 313);
    MIi_CpuCopyFast(dst, buf, 0x1200);

    off = 0;
    for (i = 0; i < 8; i++) {
        MIi_CpuCopyFast(buf + i * 0x180, dst + off, 0x100);
        off += 0x100;
    }
    for (i = 0; i < 8; i++) {
        MIi_CpuCopyFast(buf + (i * 12 + 8) * 32, dst + off, 0x80);
        off += 0x80;
    }
    for (i = 0; i < 4; i++) {
        MIi_CpuCopyFast(buf + (0xc00 + i * 0x180), dst + off, 0x100);
        off += 0x100;
    }
    for (i = 0; i < 4; i++) {
        MIi_CpuCopyFast(buf + (i * 12 + 0x68) * 32, dst + off, 0x80);
        off += 0x80;
    }
    func_020307B0(buf);
}
