/*
 * function: func_02077F44
 * address:  0x02077F44
 * packet:   pkt_02077F44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FS_SetCurrentDirectory (libfs.TWL.HYB.a fs_archive.o)
 *
 * symbols:
 *   FS_NormalizePath  0x02078078  arm
 *   STD_CopyLString  0x0208CB10  arm
 *   FS_InitFile  0x020788AC  arm
 *   FSi_SendCommand  0x02077D80  arm
 *   arc_list  0x02150B0C  data
 *   current_dir_path  0x02150C1C  data
 */

typedef unsigned char u8;
typedef unsigned long u32;
typedef long s32;
typedef int BOOL;

typedef struct OSThread OSThread;

typedef struct OSThreadQueue
{
    OSThread *head;
    OSThread *tail;
} OSThreadQueue;

typedef struct FSArchive FSArchive;

typedef struct FSFile
{
    struct FSFile *next;
    void *userdata;
    FSArchive *arc;
    u32 stat;
    void *argument;
    int error;
    OSThreadQueue queue[1];
    u8 prop[16];
    u8 arg[24];
} FSFile;

extern BOOL FSi_SendCommand(FSFile *file, u32 command, BOOL blocking);

typedef unsigned short u16;

typedef struct FSArchiveInterface
{
    void *unk00[4];
    void *FindPath;
} FSArchiveInterface;

struct FSArchive
{
    u8 pad00[0x24];
    const FSArchiveInterface *vtbl;
};

typedef struct FSFilePosition
{
    FSArchive *arc;
    u16 own_id;
    u16 index;
    u32 pos;
} FSFilePosition;

typedef struct FSiArchiveList
{
    FSArchive *list;
    FSFilePosition current_dir_pos;
} FSiArchiveList;

typedef struct FSArgumentForFindPath
{
    u32 baseid;
    const char *path;
    u32 target_id;
    BOOL target_is_directory;
} FSArgumentForFindPath;

extern FSiArchiveList arc_list;
extern char current_dir_path[260];

extern FSArchive *FS_NormalizePath(const char *path, u32 *baseid, char *relpath);
extern int STD_CopyLString(char *destp, const char *srcp, int siz);
extern void FS_InitFile(FSFile *file);

BOOL func_02077F44(const char *path)
{
    BOOL retval = 0;
    u32 baseid = 0;
    FSArgumentForFindPath arg[1];
    char relpath[260];
    FSFile dir[1];
    FSArchive *arc = FS_NormalizePath(path, &baseid, relpath);

    if (arc)
    {
        arc_list.current_dir_pos.arc = arc;
        arc_list.current_dir_pos.own_id = 0;
        arc_list.current_dir_pos.index = 0;
        arc_list.current_dir_pos.pos = 0;
        (void)STD_CopyLString(current_dir_path, relpath, sizeof(current_dir_path));
        if (arc->vtbl->FindPath)
        {
            FS_InitFile(dir);
            dir->arc = arc;
            dir->argument = arg;
            arg->baseid = baseid;
            arg->path = relpath;
            arg->target_is_directory = 1;
            if (FSi_SendCommand(dir, 4, 1))
            {
                arc_list.current_dir_pos.own_id = (u16)arg->target_id;
                (void)STD_CopyLString(current_dir_path, relpath, sizeof(current_dir_path));
            }
        }
        retval = 1;
    }
    return retval;
}
