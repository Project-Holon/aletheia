/*
 * function: func_02078C40
 * address:  0x02078C40
 * packet:   pkt_02078C40
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FSi_InitOverlay (libfs.TWL.HYB.a fs_overlay.o)
 *
 * symbols:
 *   OS_GetBootType  0x02087B04  arm
 *   FS_FindArchive  0x02077EB8  arm
 *   fsi_overlay_state  0x02150D20  data
 *   fsi_def_digest_key  0x020A19C4  data
 *   fsi_str_rom  0x020A84A4  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef struct FSArchive FSArchive;

typedef struct FSiOverlayState
{
    u32 once;
    FSArchive *arc;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    const u8 *digest_key;
    u32 digest_key_len;
} FSiOverlayState;

extern FSiOverlayState fsi_overlay_state;
extern const u8 fsi_def_digest_key[64];
extern const char fsi_str_rom[];

extern u16 OS_GetBootType(void);
extern FSArchive *FS_FindArchive(const char *name, int name_len);

void func_02078C40(void)
{
    if (OS_GetBootType() == 2)
    {
        fsi_overlay_state.unk08 = 0xFFFFFFFF;
        fsi_overlay_state.unk0C = 0;
        fsi_overlay_state.unk10 = 0xFFFFFFFF;
        fsi_overlay_state.unk14 = 0;
    }
    else
    {
        fsi_overlay_state.unk08 = 0;
        fsi_overlay_state.unk0C = 0;
        fsi_overlay_state.unk10 = 0;
        fsi_overlay_state.unk14 = 0;
    }
    fsi_overlay_state.digest_key = fsi_def_digest_key;
    fsi_overlay_state.digest_key_len = sizeof(fsi_def_digest_key);
    fsi_overlay_state.arc = FS_FindArchive(fsi_str_rom, 3);
}
