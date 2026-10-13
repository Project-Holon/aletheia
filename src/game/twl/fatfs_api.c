/*
 * file:     fatfs_api.c
 * unit:     yes
 * function: FATFSi_IsInitialized, FATFS_UnmountAll
 * address:  0x02704318
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * sdk:      libfatfs.TWL.HYB.a fatfs_api.o
 * status:   EXACT
 *
 * symbols:
 *   FATFSi_AllocateEmergencyCommandBuffer  0x027041E8  arm
 *   FATFSi_FreeCommandBuffer  0x02704230  arm
 *   FATFSi_PostRequest  0x02704258  arm
 *   FATFSi_WaitForRequest  0x02704264  arm
 */
typedef unsigned int u32;
typedef int BOOL;

typedef struct FsEntry {
    u32 arg;
    u32 state;
} FsEntry;

extern BOOL g_0273444C;  /* fatfs_api.o static `initialized` */
extern FsEntry *FATFSi_AllocateEmergencyCommandBuffer(u32);
extern void FATFSi_PostRequest(FsEntry *);
extern void FATFSi_WaitForRequest(FsEntry *);
extern void FATFSi_FreeCommandBuffer(FsEntry *);

BOOL FATFSi_IsInitialized(void) {
    return g_0273444C;
}

BOOL FATFS_UnmountAll(void) {
    FsEntry *e = FATFSi_AllocateEmergencyCommandBuffer(0x1a);
    BOOL ok;
    FATFSi_PostRequest(e);
    FATFSi_WaitForRequest(e);
    ok = (e->state == 0);
    FATFSi_FreeCommandBuffer(e);
    return ok;
}
