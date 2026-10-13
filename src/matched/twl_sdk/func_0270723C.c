/*
 * function: DSPi_OpenStaticComponentG711Core
 * address:  0x0270723C
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 */

typedef unsigned int u32;

extern u32 FS_IsAvailable(void);
extern void FS_Init(u32 a);
extern void FS_InitFile(u32 *file);
extern u32 FS_CreateFileFromMemory(u32 *file, void *addr, u32 size);

void DSPi_OpenStaticComponentG711Core(u32 *file) {
    if (FS_IsAvailable() == 0) {
        FS_Init(-1);
    }
    FS_InitFile(file);
    FS_CreateFileFromMemory(file, (void *)0x02707CB4, 0x1000000);
}
