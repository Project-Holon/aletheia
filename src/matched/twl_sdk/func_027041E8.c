/*
 * function: FATFSi_AllocateEmergencyCommandBuffer
 * address:  0x027041E8
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020879EC  0x020879EC  arm twl
 *   FATFSi_AllocateCommandBuffer  0x0270410C  arm twl
 *   data_027343E0  0x027343E0  data twl
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

extern u32 func_020879EC(void);
extern Big *FATFSi_AllocateCommandBuffer(u32 arg);
extern FsRoot data_027343E0;

Big *FATFSi_AllocateEmergencyCommandBuffer(u32 a0) {
    if (func_020879EC() != 0x12) {
        return FATFSi_AllocateCommandBuffer(a0);
    } else {
        Big *e = data_027343E0.cur;
        e->arg = a0;
        e->state = 2;
        e->f0C = 0;
        e->mode = 0;
        return e;
    }
}
