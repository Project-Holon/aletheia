/*
 * function: FATFSi_FreeCommandBuffer
 * address:  0x02704230
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_027343E0  0x027343E0  data twl
 *   data_0273442C  0x0273442C  data twl
 *   func_02086078  0x02086078  arm twl
 */

typedef unsigned int u32;
typedef unsigned char u8;

typedef struct FsWait {
    struct FsWait *next;
    u32 key;
    struct Big *slot;
} FsWait;

typedef struct Big {
    u32 arg;
    u32 state;
    u32 mode;
    u32 f0C;
    u8 buf[0x7F0];
    u32 key;
    u32 f804;
    u32 f808;
    struct Big *next;
} Big;

typedef struct FsRoot {
    u32 f00;
    FsWait *waiters;
    u32 f08[6];
    Big *busy;
    u32 f24[16];
    Big *spare;
    Big *cur;
} FsRoot;

extern void func_02086078(void *mutex);
extern FsRoot data_027343E0;
extern u32 data_0273442C[];

void FATFSi_FreeCommandBuffer(Big *a0) {
    if (a0 == data_027343E0.spare) {
        func_02086078(data_0273442C);
    }
}
