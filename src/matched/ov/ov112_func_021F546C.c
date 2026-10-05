/*
 * function: func_021F546C
 * address:  0x021F546C
 * packet:   pkt_ov112_021F546C
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Slot writer (172 bytes): mode >= 7 sets track mode-7 (stride 0x38, array at p+0x14) enabled and copies four
 * Vec records plus two halfwords; mode 4 and 5 copy in->b.x/y into f524/f528 and f536/f540 style word groups
 * of the 0x22C scene slot and set a flag. The callback is registered by func_021F51F4 through func_021F56BC.
 * 2026-10-05 (wave D9r lane 195): closed. The index is a compound product on a u32 byte offset:
 * `off = mode - 7; off *= 0x38;` with `base = (u32)p` and the first store at `base + off + 0x14`, then
 * `base += off` for the copies. This is the docs/idioms compound-multiply form: one web for the index and
 * the product gives the original colours (index in r4, product copy in r1). Every array-subscript spelling
 * (`p->slots[idx]`, 20+ variants over D5 to D9r) coloured the index first and left 5 bytes.
 * symbols:
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int x,y,z; } Vec;
typedef struct { Vec a,b,c,d; u16 e,f; } Input;
typedef struct { int pad[5]; u32 tracks[126]; /* 9 tracks of 0x38 bytes */ Vec t[2]; int flag[2]; } Big;
void func_021F546C(unsigned mode, Input *in, Big *p)
{
    if (mode >= 7) {
        u32 off = mode - 7;
        u32 base = (u32)p;
        off *= 0x38;
        *(int *)(base + off + 0x14) = 1;
        base += off;
        *(Vec *)(base + 0x18) = in->a;
        *(Vec *)(base + 0x24) = in->b;
        *(u16 *)(base + 0x48) = in->e;
        *(u16 *)(base + 0x4a) = in->f;
        *(Vec *)(base + 0x30) = in->c;
        *(Vec *)(base + 0x3c) = in->d;
        return;
    }
    if (mode == 4) {
        int y = in->b.y;
        p->t[0].x = in->b.x;
        p->t[0].y = y;
        p->t[0].z = 0;
        p->flag[0] = 1;
        return;
    }
    if (mode == 5) {
        int y = in->b.y;
        p->t[1].x = in->b.x;
        p->t[1].y = y;
        p->t[1].z = 0;
        p->flag[1] = 1;
    }
}
