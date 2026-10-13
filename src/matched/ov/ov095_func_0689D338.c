/*
 * function: BTL_POSPOKE_RotateInPoke
 * address:  0x0689D338
 * packet:   pkt_ov095_0689D338
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note: 2026-10-05 closed from an older DIFF draft (docs/notes/pkt_ov095_0689D338.c.txt).
 *   Fixes: idx is a separate u8[5] local declared before the 3-byte temp (frame is 8 bytes;
 *   the original overwrites the pad slot when six records match), and the record swap is
 *   written with plain struct element copies p->r[idx[k]] instead of raw casts.
 *   The else store uses i after the loop (i == 6, one record past the table): a bug of the
 *   original, reproduced. Callees 0689D408..0689D438 are linker veneers (int results).
 * symbols:
 *   func_0689D408 0x0689D408 thumb ov095
 *   func_0689D418 0x0689D418 thumb ov095
 *   func_0689D428 0x0689D428 thumb ov095
 *   func_0689D438 0x0689D438 thumb ov095
 *   BTL_POSPOKE_SetPoke 0x0689D320 thumb ov095
 *   BTL_POSPOKE_UpdatePosOfPoke 0x0689D544 thumb ov095
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u8 a, b, c; } Rec;
typedef struct { Rec r[6]; u8 idx[6]; } T;
extern int func_0689D408(int);
extern int func_0689D418(int);
extern int func_0689D428(int);
extern int func_0689D438(int);
extern void BTL_POSPOKE_SetPoke(T *, int, int, int);
extern void BTL_POSPOKE_UpdatePosOfPoke(T *, int);
void BTL_POSPOKE_RotateInPoke(T *p, u32 size, u32 category, int key, int extra)
{
    u32 n;
    u32 i;
    int first;
    int second;
    u8 idx[5];
    Rec tr;
    if (size <= 1) return;
    n = 0;
    for (i = 0; i < 6; i++) {
        if (category == p->r[i].b) idx[n++] = i;
    }
    first = func_0689D408(size);
    second = func_0689D418(size);
    tr = p->r[idx[0]];
    p->r[idx[first]] = p->r[idx[second]];
    p->r[idx[second]] = tr;
    if (func_0689D428(key) == 0)
        BTL_POSPOKE_SetPoke(p, idx[0], func_0689D438(key), extra);
    else
        p->r[i].c = 0x1f;
    for (i = 0; i < n; i++) BTL_POSPOKE_UpdatePosOfPoke(p, idx[i]);
}
