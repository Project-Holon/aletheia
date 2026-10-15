/*
 * function: FS_MountArchive
 * address:  0x02078540
 * packet:   pkt_02078540
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FS_MountArchive (libfs.TWL.HYB.a fs_archive.o)
 *
 * symbols:
 *   FS_InitFile  0x020788AC  arm
 *   FSi_InvokeCommand  0x02077758  arm
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


typedef struct FSArchiveInterface FSArchiveInterface;

struct FSArchive
{
    u8 pad00[0x14];
    u32 flag;
    u8 pad18[8];
    void *userdata;
    const FSArchiveInterface *vtbl;
};

extern void FS_InitFile(FSFile *file);
extern int FSi_InvokeCommand(FSFile *file, u32 command);

BOOL FS_MountArchive(FSArchive *arc, void *userdata, const FSArchiveInterface *vtbl)
{
    FSFile tmp[1];

    arc->userdata = userdata;
    arc->vtbl = vtbl;
    FS_InitFile(tmp);
    tmp->arc = arc;
    (void)FSi_InvokeCommand(tmp, 17);
    arc->flag |= 2;
    return 1;
}
