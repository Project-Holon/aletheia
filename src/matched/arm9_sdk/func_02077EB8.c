/*
 * function: func_02077EB8
 * address:  0x02077EB8
 * packet:   pkt_02077EB8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FS_FindArchive (libfs.TWL.HYB.a fs_archive.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   FS_GetArchiveName  0x02078530  arm
 *   STD_CompareNString  0x0208CE4C  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   arc_list  0x02150B0C  data
 */

typedef unsigned char u8;
typedef unsigned long u32;
typedef int BOOL;

typedef struct FSArchive
{
    u8 pad00[4];
    struct FSArchive *next;
    u8 pad08[0xC];
    u32 flag;
} FSArchive;

extern FSArchive *arc_list;

extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32 state);
extern const char *FS_GetArchiveName(const FSArchive *arc);
extern int STD_CompareNString(const char *str1, const char *str2, int len);

static inline BOOL FS_IsArchiveLoaded(volatile const FSArchive *arc)
{
    return (arc->flag & 2) ? 1 : 0;
}

FSArchive *func_02077EB8(const char *name, int name_len)
{
    u32 bak_psr = OS_DisableInterrupts();
    FSArchive *arc;

    for (arc = arc_list; arc; arc = arc->next)
    {
        if (FS_IsArchiveLoaded(arc))
        {
            const char *arcname = FS_GetArchiveName(arc);

            if ((STD_CompareNString(arcname, name, name_len) == 0) && (arcname[name_len] == 0))
            {
                break;
            }
        }
    }
    (void)OS_RestoreInterrupts(bak_psr);
    return arc;
}
