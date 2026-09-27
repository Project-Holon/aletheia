/*
 * function: MBi_BlockHeaderEnd
 * address:  0x021F3C80
 * packet:   pkt_ov107_021F3C80
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlSDK/libmb.TWL.HYB.a(mb_common.o).  Rebuilt from the Rom object's
 * DWARF (decl_line 49, params body_len/pollbmp/sendbuf) and the ROM
 * disassembly; tail of the body returns MBi_SendMP's result.
 */

typedef unsigned long u32;
typedef unsigned short u16;

extern void DC_FlushRange(const void *p, u32 size);
extern void DC_WaitWriteBufferEmpty(void);
extern int MBi_SendMP(u32 *sendbuf, int body_len, u16 pollbmp);

int MBi_BlockHeaderEnd(int body_len, u16 pollbmp, u32 *sendbuf)
{
    DC_FlushRange(sendbuf, (body_len + 31) & ~31);
    DC_WaitWriteBufferEmpty();
    return MBi_SendMP(sendbuf, body_len, pollbmp);
}
