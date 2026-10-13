/*
 * function: GFL_NET_STATE_GetError
 * address:  0x0203CA98
 * packet:   pkt_0203C494
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *   func_02034714   0x02034714  arm
 *   unk_021469DC    0x021469DC  data
 *   file_020A7BA8   0x020A7BA8  data
 *   file_020A7C70   0x020A7C70  data
 *
 * Returns the object's work area at +0x30, reporting through func_02034714
 * with the source file at 0x020A7BA8 and line 0x8CA (2250) when the object has
 * not been created - the report is not fatal, the address of the null object's
 * field is still what comes back.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_GetError.c \
 *       --func GFL_NET_STATE_GetError --addr 0x0203CA98 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void func_02034714(const char *file, u32 line, const char *fmt);
extern u32  unk_021469DC;
extern const char file_020A7BA8[];
extern const char file_020A7C70[];

u32 GFL_NET_STATE_GetError(void)
{
    if (unk_021469DC == 0)
        func_02034714(file_020A7BA8, 0x8CA, file_020A7C70);
    return unk_021469DC + 0x30;
}
