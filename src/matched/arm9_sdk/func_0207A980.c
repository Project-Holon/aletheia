/*
 * function: FSi_IsUnreadableRomOffset
 * address:  0x0207A980
 * packet:   pkt_0207A980
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FSi_IsUnreadableRomOffset (fs_proc_rom.o)
 *
 * symbols:
 *   FS_GetArchiveName                0x02078530 arm
 *   STD_CompareString                0x0208cd94 arm
 *   OS_IsRunOnTwl                    0x02085d3c arm
 *   CARD_GetOwnRomHeader             0x02075df8 arm
 *   g_020A84B0                       0x020a84b0 data
 */

typedef struct FSArchive FSArchive;

typedef struct CARDRomHeader {
    unsigned char head[0x92];
    unsigned short twl_ltd_area_rom_offset;
} CARDRomHeader;

extern char *func_02078530(FSArchive *arc);
extern int func_0208CD94(const char *str1, const char *str2);
extern int OS_IsRunOnTwl(void);
extern const char g_020A84B0[]; /* "rom", the vendor object's @12296 */
extern CARDRomHeader *CARD_GetOwnRomHeader(void);

int FSi_IsUnreadableRomOffset(FSArchive *arc, unsigned long offset)
{
    int result = 0;

    if (func_0208CD94(func_02078530(arc), g_020A84B0) == 0 && !OS_IsRunOnTwl()) {
        CARDRomHeader *header = CARD_GetOwnRomHeader();
        if (offset >= (unsigned long)header->twl_ltd_area_rom_offset * 0x80000) {
            result = 1;
        }
    }
    return result;
}
