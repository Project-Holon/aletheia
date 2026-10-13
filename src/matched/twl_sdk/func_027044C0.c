/*
 * function: SNDEXi_SetVolumeExAsync
 * address:  0x027044C0
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_IsRunOnTwl  0x02085D3C  arm twl
 *   SNDEXi_SetVolumeAsync  0x02704448  arm twl
 */

typedef unsigned int u32;

typedef void (*Cb)(u32, void *);

extern u32 OS_IsRunOnTwl(void);
u32 SNDEXi_SetVolumeAsync(u32 a0, Cb a1, void *a2, u32 a3);

u32 SNDEXi_SetVolumeExAsync(u32 a0, Cb a1, void *a2) {
    if (OS_IsRunOnTwl() == 0) {
        return 4;
    }
    return SNDEXi_SetVolumeAsync(a0, a1, a2, 0);
}
