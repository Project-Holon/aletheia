/*
 * function: FS_RegisterArchiveName
 * address:  0x02078384
 * packet:   pkt_02078384
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FS_RegisterArchiveName (libfs.TWL.HYB.a fs_archive.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   FS_FindArchive  0x02077EB8  arm
 *   STD_CopyLString  0x0208CB10  arm
 *   OS_Terminate  0x02088234  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   fsi_archive_state  0x02150B0C  data
 *   arc_list  0x02150B0C  data
 *   FSiLongNameTable  0x02150B1C  data
 */

typedef unsigned char u8;
typedef unsigned long u32;
typedef int BOOL;

typedef struct FSArchive
{
    union
    {
        char ptr[4];
        u32 pack;
        char *name;
    } name;
    struct FSArchive *next;
    u8 pad08[0xC];
    u32 flag;
} FSArchive;

typedef struct FSiArchiveList
{
    FSArchive *list;
} FSiArchiveList;

extern FSiArchiveList fsi_archive_state;
extern FSArchive *arc_list;
extern char FSiLongNameTable[16][16];

extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32 state);
extern FSArchive *FS_FindArchive(const char *name, int name_len);
extern int STD_CopyLString(char *destp, const char *srcp, int siz);
extern void OS_Terminate(void);

BOOL FS_RegisterArchiveName(FSArchive *p_arc, const char *name, u32 name_len)
{
    BOOL retval = 0;
    u32 bak_intr = OS_DisableInterrupts();

    if (!FS_FindArchive(name, (int)name_len))
    {
        FSArchive **pp = &arc_list;
        FSArchive *cur;

        for (cur = fsi_archive_state.list; cur; cur = cur->next)
        {
            pp = &cur->next;
        }
        *pp = p_arc;
        if (name_len <= 3)
        {
            p_arc->name.pack = 0;
            (void)STD_CopyLString(p_arc->name.ptr, name, (int)(name_len + 1));
        }
        else if (name_len <= 15)
        {
            int i;

            for (i = 0;; ++i)
            {
                if (i >= 16)
                {
                    OS_Terminate();
                }
                else if (FSiLongNameTable[i][0] == 0)
                {
                    (void)STD_CopyLString(FSiLongNameTable[i], name, (int)(name_len + 1));
                    p_arc->name.name = FSiLongNameTable[i];
                    break;
                }
            }
        }
        else
        {
            OS_Terminate();
        }
        p_arc->flag |= 1;
        retval = 1;
    }
    (void)OS_RestoreInterrupts(bak_intr);
    return retval;
}
