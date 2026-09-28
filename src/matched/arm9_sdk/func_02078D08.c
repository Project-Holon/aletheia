/*
 * function: func_02078D08
 * address:  0x02078D08
 * packet:   pkt_02078D08
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FS_GetOverlayFileID (fs_overlay.o)
 *
 * symbols:
 *   _ZZ15FS_StartOverlayP13FSOverlayInfoE4once 0x02150d20 data
 *   .bss                             0x02150d20 data
 */

typedef struct FSArchive FSArchive;

typedef struct FSFileID {
    FSArchive *arc;
    unsigned long file_id;
} FSFileID;

typedef struct FSOverlayInfoHeader {
    unsigned long id;
    void *ram_address;
    unsigned long ram_size;
    unsigned long bss_size;
    void *sinit_init;
    void *sinit_init_end;
    unsigned long file_id;
    unsigned long flag;
} FSOverlayInfoHeader;

typedef struct FSOverlayInfo {
    FSOverlayInfoHeader header;
    int target;
    unsigned long file_pos[2];
} FSOverlayInfo;

typedef struct FSiOverlayContextType {
    FSArchive *arc;
    unsigned char rest[24];
} FSiOverlayContextType;

/* .bss of the object: FS_StartOverlay's function-static `once` at +0, then
 * FSiOverlayContext at +4 */
static int once_slot = 0;
static FSiOverlayContextType FSiOverlayContext = { 0 };

FSFileID func_02078D08(FSOverlayInfo *p_ovi)
{
    FSFileID ret;

    ret.arc = FSiOverlayContext.arc;
    ret.file_id = p_ovi->header.file_id;
    return ret;
}
