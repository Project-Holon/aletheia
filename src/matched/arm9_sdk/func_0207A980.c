/*
 * function: func_0207A980
 * address:  0x0207A980
 * packet:   pkt_0207A980
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK symbol: FSi_IsUnreadableRomOffset (TwlSDK libfs.TWL.HYB.a fs_proc_rom.o)
 *
 * symbols:
 *   FS_GetArchiveName      0x02078530  arm
 *   STD_CompareString      0x0208CD94  arm
 *   OS_IsRunOnTwl          0x02085D3C  arm
 *   CARD_GetOwnRomHeader   0x02075DF8  arm
 *   d_020A84B0             0x020A84B0  data
 */

typedef int BOOL;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef struct CARDRomHeader
{
    u8 pad[0x92];
    u16 twl_ltd_area_rom_offset;
} CARDRomHeader;

extern const char *FS_GetArchiveName(const void *arc);
extern int STD_CompareString(const char *s1, const char *s2);
extern BOOL OS_IsRunOnTwl(void);
extern const CARDRomHeader *CARD_GetOwnRomHeader(void);
extern const char d_020A84B0[];

BOOL func_0207A980(const void *arc, u32 offset)
{
    BOOL result = 0;

    if (STD_CompareString(FS_GetArchiveName(arc), d_020A84B0) == 0)
    {
        if (!OS_IsRunOnTwl())
        {
            const CARDRomHeader *header = CARD_GetOwnRomHeader();
            if (offset >= (u32)header->twl_ltd_area_rom_offset * 0x80000)
            {
                result = 1;
            }
        }
    }
    return result;
}
