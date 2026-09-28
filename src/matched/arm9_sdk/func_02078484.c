/*
 * function: func_02078484
 * address:  0x02078484
 * packet:   pkt_02078484
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FS_ReleaseArchiveName (libfs.TWL.HYB.a fs_archive.o)
 *
 * symbols:
 *   OS_Terminate  0x02088234  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   fsi_archive_state  0x02150B0C  data
 *   arc_list  0x02150B0C  data
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
    FSArchive *current;
} FSiArchiveList;

extern FSiArchiveList fsi_archive_state;
extern FSArchive *arc_list;

extern void OS_Terminate(void);
extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32 state);

void func_02078484(FSArchive *p_arc)
{
    if (p_arc == fsi_archive_state.list)
    {
        OS_Terminate();
    }
    if (p_arc->name.pack)
    {
        FSArchive **pp;
        u32 bak_psr = OS_DisableInterrupts();

        FSArchive *cur;

        pp = &arc_list;
        for (cur = fsi_archive_state.list; cur; cur = *pp)
        {
            if (cur == p_arc)
            {
                *pp = cur->next;
                break;
            }
            pp = &cur->next;
        }
        if (p_arc->name.ptr[3] != '\0')
        {
            *p_arc->name.name = '\0';
        }
        p_arc->name.pack = 0;
        p_arc->next = 0;
        p_arc->flag &= ~1;
        if (fsi_archive_state.current == p_arc)
        {
            fsi_archive_state.current = 0;
        }
        (void)OS_RestoreInterrupts(bak_psr);
    }
}
