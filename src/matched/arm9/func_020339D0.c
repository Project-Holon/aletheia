/*
 * function: SAVEDATA_InitBuffer
 * address:  0x020339D0
 * packet:   pkt_020339D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   MIi_CpuClear32  0x02082A7C  arm
 */

typedef unsigned int u32;

extern void MIi_CpuClear32(u32 fill, void *dst, u32 size);

typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
} T;

typedef struct {
    u32 f0;
    u32 size;
    u32 off;
} Ent;

typedef struct {
    u32 f0;
    u32 f4;
    u32 fn;
} PtrEnt;

void SAVEDATA_InitBuffer(u32 a, T *sb)
{
    PtrEnt *ptrs = (PtrEnt *)sb->f00;
    u32 n = sb->f04;
    int i;

    MIi_CpuClear32(0, (void *)a, sb->f10);
    for (i = 0; i < n; i++) {
        u32 off = ((Ent *)sb->f14)[i].off;
        MIi_CpuClear32(0, (void *)(a + off), ((Ent *)sb->f14)[i].size);
        ((void (*)(u32))ptrs[i].fn)(a + off);
    }
}
