/*
 * function: FS_NormalizePath
 * address:  0x02078078
 * packet:   pkt_02078078
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libfs fs archive.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 *
 * symbols:
 *   g_02150B0C                     0x02150B0C  data
 *   g_02150C1C                     0x02150C1C  data
 *   g_020A84A0                     0x020A84A0  data
 *   FSi_CopySafeString             0x02078018  arm
 *   FS_FindArchive                 0x02077EB8  arm
 *   FSi_DecrementSjisPositionToSlash 0x02078834  arm
 *   FSi_TrimSjisTrailingSlash      0x02078868  arm
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int BOOL;

typedef struct FSArchive FSArchive;

/* fs_archive.o .bss: arc_list at +0, current_dir_pos (arc, own_id, index, pos) at +4 */
typedef struct FsArchiveBss {
    FSArchive *arc_list;
    FSArchive *cur_arc;
    u16 cur_own_id;
    u16 cur_index;
    u32 cur_pos;
} FsArchiveBss;

extern FsArchiveBss g_02150B0C;
extern char g_02150C1C[260];    /* current_dir_path */
extern const char g_020A84A0[]; /* "/" */

extern int FSi_CopySafeString(char *dst, int dstlen, const char *src, int srclen, BOOL *stickyFailure);
extern FSArchive *FS_FindArchive(const char *name, int name_len);
extern int FSi_DecrementSjisPositionToSlash(const char *str, int pos);
extern int FSi_TrimSjisTrailingSlash(char *str);

static inline BOOL FSi_IsSlash(u32 c)
{
    return (c == '/') || (c == '\\');
}

static inline BOOL STD_IsSjisLeadByte(u32 c)
{
    return ((c ^ 0x20) - 0xA1) < 0x3C;
}

static inline BOOL STD_IsSjisTrailByte(int c)
{
    return (c != 0x7F) && ((u8)(c - 0x40) <= 0xBC);
}

static inline BOOL STD_IsSjisCharacter(const char *s)
{
    return STD_IsSjisLeadByte((u8)s[0]) && STD_IsSjisTrailByte(s[1]);
}

FSArchive *FS_NormalizePath(const char *path, u32 *baseid, char *relpath)
{
    FSArchive *arc = 0;
    int pathlen = 0;
    BOOL stickyFailure = 0;

    if (g_02150B0C.cur_arc == 0) {
        g_02150B0C.cur_arc = g_02150B0C.arc_list;
        g_02150B0C.cur_own_id = 0;
        g_02150B0C.cur_pos = 0;
        g_02150B0C.cur_index = 0;
        g_02150C1C[0] = '\0';
    }

    if (FSi_IsSlash((u8)*path)) {
        arc = g_02150B0C.cur_arc;
        ++path;
        if (baseid) {
            *baseid = 0;
        }
    } else {
        int i;

        for (i = 0;;) {
            u32 c = (u8)path[i];

            if ((c == '\0') || FSi_IsSlash(c)) {
                arc = g_02150B0C.cur_arc;
                if (baseid) {
                    *baseid = g_02150B0C.cur_own_id;
                }
                if (relpath && (g_02150B0C.cur_own_id == 0) && (g_02150C1C[0] != '\0')) {
                    pathlen += FSi_CopySafeString(relpath, 0x104, g_02150C1C, 0x104, &stickyFailure);
                    pathlen += FSi_CopySafeString(&relpath[pathlen], 0x104 - pathlen, g_020A84A0, 1, &stickyFailure);
                }
                break;
            } else if (c == ':') {
                arc = FS_FindArchive(path, i);
                path += i + 1;
                if (FSi_IsSlash((u8)*path)) {
                    ++path;
                }
                if (baseid) {
                    *baseid = 0;
                }
                break;
            }
            i = i + 1 + STD_IsSjisLeadByte(c);
        }
    }

    if (relpath) {
        int curlen = 0;

        while (!stickyFailure) {
            char c = path[curlen];

            if ((c != '\0') && !FSi_IsSlash((u8)c)) {
                curlen += STD_IsSjisCharacter(&path[curlen]) ? 2 : 1;
            } else {
                if (curlen == 0) {
                } else if ((curlen == 1) && (path[0] == '.')) {
                } else if ((curlen == 2) && (path[0] == '.') && (path[1] == '.')) {
                    if (pathlen > 0) {
                        --pathlen;
                    }
                    pathlen = FSi_DecrementSjisPositionToSlash(relpath, pathlen) + 1;
                } else {
                    pathlen += FSi_CopySafeString(&relpath[pathlen], 0x104 - pathlen, path, curlen, &stickyFailure);
                    if (c != '\0') {
                        pathlen += FSi_CopySafeString(&relpath[pathlen], 0x104 - pathlen, g_020A84A0, 1, &stickyFailure);
                    }
                }
                if (c == '\0') {
                    break;
                }
                path += curlen + 1;
                curlen = 0;
            }
        }
        relpath[pathlen] = '\0';
        pathlen = FSi_TrimSjisTrailingSlash(relpath);
    }

    return stickyFailure ? 0 : arc;
}
