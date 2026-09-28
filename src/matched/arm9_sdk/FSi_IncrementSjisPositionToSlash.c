/*
 * function: FSi_IncrementSjisPositionToSlash
 * address:  0x020787E0
 * packet:   pkt_020787E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libfs fs_file.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  Steps pos
 * forward over Shift-JIS characters until a slash, backslash or the end of
 * the string, and returns the position reached.  The lead-byte test takes
 * the byte re-read and masked with `& 0xFF`; a `(u8)` cast is CSEd with the
 * slash test's mask and loses the separate `and` from the saved char.
 */

typedef unsigned long u32;
typedef unsigned char u8;
typedef int BOOL;

static inline BOOL FSi_IsSlash(u32 c)
{
    return (c == '/') || (c == 0x5C);
}

static inline BOOL STD_IsSjisLeadByte(u32 c)
{
    return ((c ^ 0x20) - 0xA1) < 0x3C;
}

int FSi_IncrementSjisPositionToSlash(const char *str, int pos)
{
    while ((str[pos] != '\0') && !FSi_IsSlash((u8)str[pos])) {
        pos = pos + 1 + STD_IsSjisLeadByte((u32)str[pos] & 0xFF);
    }
    return pos;
}
