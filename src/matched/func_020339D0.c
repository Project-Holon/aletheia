/*
 * function: func_020339D0
 * address:  0x020339D0
 * packet:   pkt_020339D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_02082A7C  0x02082A7C  arm
 */

typedef unsigned int u32;

extern void func_02082A7C(u32 fill, void *dst, u32 size);

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

void func_020339D0(u32 a, T *sb)
{
    PtrEnt *ptrs = (PtrEnt *)sb->f00;
    u32 n = sb->f04;
    int i;

    func_02082A7C(0, (void *)a, sb->f10);
    for (i = 0; i < n; i++) {
        u32 off = ((Ent *)sb->f14)[i].off;
        func_02082A7C(0, (void *)(a + off), ((Ent *)sb->f14)[i].size);
        ((void (*)(u32))ptrs[i].fn)(a + off);
    }
}
