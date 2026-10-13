/*
 * function: FATFS_UnmountAll
 * address:  0x02704328
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   FATFSi_AllocateEmergencyCommandBuffer  0x027041E8  arm twl
 *   FATFSi_PostRequest  0x02704258  arm twl
 *   FATFSi_WaitForRequest  0x02704264  arm twl
 *   FATFSi_FreeCommandBuffer  0x02704230  arm twl
 */

typedef unsigned int u32;
typedef int BOOL;

typedef struct FsEntry {
    u32 arg;
    u32 state;
} FsEntry;

extern FsEntry *FATFSi_AllocateEmergencyCommandBuffer(u32);
extern void FATFSi_PostRequest(FsEntry *);
extern void FATFSi_WaitForRequest(FsEntry *);
extern void FATFSi_FreeCommandBuffer(FsEntry *);

BOOL FATFS_UnmountAll(void) {
    FsEntry *e = FATFSi_AllocateEmergencyCommandBuffer(0x1a);
    BOOL ok;
    FATFSi_PostRequest(e);
    FATFSi_WaitForRequest(e);
    ok = (e->state == 0);
    FATFSi_FreeCommandBuffer(e);
    return ok;
}
